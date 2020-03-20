/*
 * ffb_report_handler.cpp
 *
 *  Created on: Mar 18, 2020
 *      Author: HoanTV
 */

//
//void FfbReportHandler::FfbOnCreateNewEffect(USB_FFBReport_CreateNewEffect_Feature_Data_t* inData)
//{
//  pidBlockLoad.reportId = 6;
//  pidBlockLoad.effectBlockIndex = GetNextFreeEffect();
//
//  if (pidBlockLoad.effectBlockIndex == 0)
//  {
//    pidBlockLoad.loadStatus = 2;    // 1=Success,2=Full,3=Error
//  }
//  else
//  {
//    pidBlockLoad.loadStatus = 1;    // 1=Success,2=Full,3=Error
//
//    volatile TEffectState* effect = &gEffectStates[pidBlockLoad.effectBlockIndex];
//
//    memset((void*)effect, 0, sizeof(TEffectState));
//    effect->state = MEFFECTSTATE_ALLOCATED;
//    pidBlockLoad.ramPoolAvailable -= SIZE_EFFECT;
//  }
//}

#include "ffb_report_handler.h"

FfbReportHandler::FfbReportHandler() {
  nextEID = 1;
  devicePaused = 0;
}

FfbReportHandler::~FfbReportHandler() {
  FreeAllEffects();
}

void FfbReportHandler::FreeAllEffects(void)
{
  nextEID = 1;
  memset((void*)&gEffectStates, 0, sizeof(gEffectStates));
  pidBlockLoad.ramPoolAvailable = MEMORY_SIZE;
}

uint8_t* FfbReportHandler::FfbOnPIDPool()
{
  FreeAllEffects();

  pidPoolReport.reportId = 7;
  pidPoolReport.ramPoolSize = MEMORY_SIZE;
  pidPoolReport.maxSimultaneousEffects = MAX_EFFECTS;
  pidPoolReport.memoryManagement = 3;
  return (uint8_t*)&pidPoolReport;
}

uint8_t* FfbReportHandler::FfbOnPIDBlockLoad()
{
  return (uint8_t*)&pidBlockLoad;
}

uint8_t* FfbReportHandler::FfbOnPIDStatus()
{
  return (uint8_t*)&pidState;
}


void FfbReportHandler::FfbOnCreateNewEffect(USB_FFBReport_CreateNewEffect_Feature_Data_t* inData)
{
  pidBlockLoad.reportId = 6;
  pidBlockLoad.effectBlockIndex = GetNextFreeEffect();

  if (pidBlockLoad.effectBlockIndex == 0)
  {
    pidBlockLoad.loadStatus = 2;    // 1=Success,2=Full,3=Error
  }
  else
  {
    pidBlockLoad.loadStatus = 1;    // 1=Success,2=Full,3=Error

    volatile TEffectState* effect = &gEffectStates[pidBlockLoad.effectBlockIndex];

    memset((void*)effect, 0, sizeof(TEffectState));
    effect->state = MEFFECTSTATE_ALLOCATED;
    pidBlockLoad.ramPoolAvailable -= SIZE_EFFECT;
  }
}

