/*
 * ffb_report_handler.h
 *
 *  Created on: Mar 18, 2020
 *      Author: HoanTV
 */

#ifndef INC_FFB_REPORT_HANDLER_H_
#define INC_FFB_REPORT_HANDLER_H_

//#include <stdio.h>
#include <string.h>
#include "hid_report_types.h"

#define MAX_EFFECTS     14
#define SIZE_EFFECT     sizeof(TEffectState)
#define MEMORY_SIZE     (uint16_t)(MAX_EFFECTS*SIZE_EFFECT)

#ifdef __cplusplus
extern "C" {
#endif

class FfbReportHandler {
  public:
    FfbReportHandler();
    ~FfbReportHandler();

    volatile uint8_t nextEID;  // FFP effect indexes starts from 1
      volatile TEffectState  gEffectStates[MAX_EFFECTS + 1];
      volatile uint8_t devicePaused;
      //variables for storing previous values
      volatile int32_t inertiaT = 0;
      volatile int16_t oldSpeed = 0;
      volatile int16_t oldAxisPosition = 0;
      volatile USB_FFBReport_PIDStatus_Input_Data_t pidState = {2, 30, 0};
      volatile USB_FFBReport_PIDBlockLoad_Feature_Data_t pidBlockLoad;
      volatile USB_FFBReport_PIDPool_Feature_Data_t pidPoolReport;
      volatile USB_FFBReport_DeviceGain_Output_Data_t deviceGain;


    //ffb state structures
    uint8_t GetNextFreeEffect(void);
    void StartEffect(uint8_t id);
    void StopEffect(uint8_t id);
    void StopAllEffects(void);
    void FreeEffect(uint8_t id);
    void FreeAllEffects(void);

    // Handle incoming data from USB
    void FfbOnCreateNewEffect(USB_FFBReport_CreateNewEffect_Feature_Data_t* inData);
    void FfbOnUsbData(uint8_t* data, uint16_t len);
    uint8_t* FfbOnPIDPool();
    uint8_t* FfbOnPIDBlockLoad();
    uint8_t* FfbOnPIDStatus();
};
FfbReportHandler ffbReportHandler;

#ifdef __cplusplus
}
#endif




#endif /* INC_FFB_REPORT_HANDLER_H_ */
