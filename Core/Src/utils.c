/*
 * utils.c
 *
 *  Created on: Mar 18, 2020
 *      Author: HoanTV
 */
#include "usb_device.h"

int mapInt(int x, int in_min, int in_max, int out_min, int out_max){
  return (int)(1.00*(x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min);
}

//int _write(int32_t file, uint8_t *ptr, int32_t len)
//{
///* Implement your write code here, this is used by puts and printf for example */
//int i=0;
//for(i=0 ; i<len ; i++)
//ITM_SendChar((*ptr++));
//return len;
//
//}
