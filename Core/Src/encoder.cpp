/*
 * encoder.cpp
 *
 *  Created on: Mar 15, 2020
 *      Author: HoanTV
 */


#include "Encoder.h"


extern TIM_HandleTypeDef htim2;
static uint16_t newCount;
static uint16_t prevCount;

Encoder::Encoder(){
	encoderValue = 0;
}

Encoder::~Encoder(){
}

void Encoder::Encoder_Init(void) {
  HAL_TIM_Encoder_Start(&htim2, TIM_CHANNEL_ALL);
}

uint16_t  Encoder::Encoder_Read() {
  uint16_t val = __HAL_TIM_GET_COUNTER(&htim2);
  return val >> 1;
}

Encoder_Status Encoder::Encoder_Get_Status() {
  newCount = Encoder_Read();
  if (newCount != prevCount) {
    if (newCount > prevCount) {
      prevCount = newCount;
      return Incremented;
    } else {
      prevCount = newCount;
      return Decremented;
    }
  }
  return Neutral;
}

void Encoder::update(){
	switch(Encoder_Get_Status()) {
	    case Incremented:
	    	encoderValue++;
	      break;
	    case Decremented:
	    	encoderValue--;
	      break;
	    case Neutral:
	      // don't do anything
	      break;
	  }
}
/**
  * @brief TIM2 Initialization Function (Encoder Mode)
  * @param None
  * @retval None
  */
void Encoder::Encoder_Config(void)
{
  TIM_Encoder_InitTypeDef sConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  htim2.Instance = TIM2;
  htim2.Init.Prescaler = 0;
  htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim2.Init.Period = 65535;
  htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  sConfig.EncoderMode = TIM_ENCODERMODE_TI1;
  sConfig.IC1Polarity = TIM_ICPOLARITY_RISING;
  sConfig.IC1Selection = TIM_ICSELECTION_DIRECTTI;
  sConfig.IC1Prescaler = TIM_ICPSC_DIV1;     // Capture performed each time an edge is detected on the capture input
  sConfig.IC1Filter = 0;
  sConfig.IC2Polarity = TIM_ICPOLARITY_RISING;
  sConfig.IC2Selection = TIM_ICSELECTION_DIRECTTI;
  sConfig.IC2Prescaler = TIM_ICPSC_DIV1;     // Capture performed each time an edge is detected on the capture input
  sConfig.IC2Filter = 0;

  HAL_TIM_Encoder_Init(&htim2, &sConfig);

  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;

  HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig);
}


