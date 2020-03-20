/*
 * wheel_controller.cpp
 *
 *  Created on: Mar 15, 2020
 *      Author: HoanTV
 */
#include "wheel_controller.h"

extern USBD_HandleTypeDef hUsbDeviceFS;

WheelController::WheelController(){
}

WheelController::~WheelController(){
}

void WheelController::begin(void) {
	MX_USB_DEVICE_Init();
	end();
}

void WheelController::end(void) {
  memset(&_wheelreport, 0x00, sizeof(_wheelreport));
  update();
}

void WheelController::setX(int16_t value){
	_wheelreport.xAxis = value;
}

void WheelController::setY(int16_t value){
	_wheelreport.yAxis = value;
}

void WheelController::setZ(int16_t value){
	_wheelreport.zAxis = value;
}

void WheelController::setRX(int16_t value){
	_wheelreport.rxAxis = value;
}

void WheelController::setRY(int16_t value){
	_wheelreport.ryAxis = value;
}

void WheelController::setRZ(int16_t value){
	_wheelreport.rzAxis = value;
}

void WheelController::press(uint16_t b){
	  if (b == 0) {
    _wheelreport.buttons = 0;
  } else {
    _wheelreport.buttons |= (uint16_t)1 << (b - 1);
  }
}

void WheelController::release(uint16_t b) {
  _wheelreport.buttons &= ~((uint16_t)1 << (b - 1));
}

void WheelController::releaseAll(void) {
  memset(&_wheelreport, 0x00, sizeof(_wheelreport));
}

void WheelController::_init()
{
	_wheelreport.xAxis = 0;
	_wheelreport.yAxis = -32767;
	_wheelreport.zAxis = -32767;
	_wheelreport.rxAxis = -32767;
	_wheelreport.ryAxis = -32767;
	_wheelreport.rzAxis = -32767;
	_wheelreport.buttons = 0;
}

#define AddAxisValue(m_val)		{data[i++] = m_val & 0xff; data[i++] = ((m_val & 0xff00) >> 8);}

void WheelController::update() {
	uint8_t data[15];
	int i=0;
	data[i++] = HID_REPORTID_WHEEL;
	AddAxisValue(_wheelreport.buttons);
	AddAxisValue(_wheelreport.xAxis);
	AddAxisValue(_wheelreport.yAxis);
	AddAxisValue(_wheelreport.zAxis);
	AddAxisValue(_wheelreport.rxAxis);
	AddAxisValue(_wheelreport.rxAxis);
	AddAxisValue(_wheelreport.rzAxis);
	USBD_CUSTOM_HID_SendReport( &hUsbDeviceFS, (uint8_t*)&data, sizeof(data) );
}

//void WheelController::sendReport(){
//	static uint16_t busycounter = 0;
//	uint8_t value=USBD_OK;
//	if(usbsuspended==0) {
//		value = USBD_CUSTOM_HID_SendReport( &hUsbDeviceFS, (uint8_t*)&_wheelreport, sizeof(_wheelreport));
//	} else {
//		/* to do */
//	}
//	if(value == USBD_BUSY) {
//		busycounter++;
//		if(busycounter>1500) {
//			/* to do */
//		} else {
//			/* to do */
//		}
//	} else {
//		busycounter=0;
//	}
//}


