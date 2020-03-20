/*
 * wheel_controller.h
 *
 *  Created on: Mar 15, 2020
 *      Author: HoanTV
 */

#ifndef INC_WHEEL_CONTROLLER_H_
#define INC_WHEEL_CONTROLLER_H_

#include "usbd_custom_hid_if.h"
#include "usb_device.h"


#ifdef __cplusplus
extern "C" {
#endif
class WheelController {
public:
	WheelController();
	~WheelController();
	void begin();
	void end();
	void setX(int16_t value);
	void setY(int16_t value);
	void setZ(int16_t value);
	void setRX(int16_t value);
	void setRY(int16_t value);
	void setRZ(int16_t value);
	void press(uint16_t b);
	void release(uint16_t b);
	void releaseAll(void);
	void update(void);
private:
	WheelReport _wheelreport;
	void sendReport(void);
	void _init();
};

#ifdef __cplusplus
}
#endif




#endif /* INC_WHEEL_CONTROLLER_H_ */
