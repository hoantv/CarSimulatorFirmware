/*
 * encoder.h
 *
 *  Created on: Mar 15, 2020
 *      Author: HoanTV
 */

#ifndef INC_ENCODER_H_
#define INC_ENCODER_H_


#include "stm32f4xx_hal.h"
#include <stdint.h>
#include <stdbool.h>


#ifdef __cplusplus
extern "C" {
#endif

#ifndef ENCODER_TIM
#define ENCODER_TIM                            htim2
#endif

#ifndef ENCODER_GPIO_PORT
#define ENCODER_GPIO_PORT                      GPIOA
#endif
#ifndef ENCODER_GPIO_CH1
#define ENCODER_GPIO_CH1                       GPIO_PIN_0
#endif

#ifndef ENCODER_GPIO_CH2
#define ENCODER_GPIO_CH2                       GPIO_PIN_1
#endif


extern TIM_HandleTypeDef htim2;

typedef enum {
  Incremented = 1,
  Decremented = -1,
  Neutral = 0,
} Encoder_Status;


class Encoder{
public:
	Encoder();
	~Encoder();
	void Encoder_Config(void);
	void Encoder_Init(void);
	uint16_t Encoder_Read();
	Encoder_Status Encoder_Get_Status();
	int16_t encoderValue;
	void update();
private:



};








#ifdef __cplusplus
}
#endif

#endif /* INC_ENCODER_H_ */
