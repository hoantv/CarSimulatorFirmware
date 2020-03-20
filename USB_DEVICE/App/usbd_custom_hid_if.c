/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : usbd_custom_hid_if.c
  * @version        : v1.0_Cube
  * @brief          : USB Device Custom HID interface file.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "usbd_custom_hid_if.h"

/* USER CODE BEGIN INCLUDE */

/* USER CODE END INCLUDE */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/

/* USER CODE BEGIN PV */
/* Private variables ---------------------------------------------------------*/

/* USER CODE END PV */

/** @addtogroup STM32_USB_OTG_DEVICE_LIBRARY
  * @brief Usb device.
  * @{
  */

/** @addtogroup USBD_CUSTOM_HID
  * @{
  */

/** @defgroup USBD_CUSTOM_HID_Private_TypesDefinitions USBD_CUSTOM_HID_Private_TypesDefinitions
  * @brief Private types.
  * @{
  */

/* USER CODE BEGIN PRIVATE_TYPES */

/* USER CODE END PRIVATE_TYPES */

/**
  * @}
  */

/** @defgroup USBD_CUSTOM_HID_Private_Defines USBD_CUSTOM_HID_Private_Defines
  * @brief Private defines.
  * @{
  */

/* USER CODE BEGIN PRIVATE_DEFINES */

/* USER CODE END PRIVATE_DEFINES */

/**
  * @}
  */

/** @defgroup USBD_CUSTOM_HID_Private_Macros USBD_CUSTOM_HID_Private_Macros
  * @brief Private macros.
  * @{
  */

/* USER CODE BEGIN PRIVATE_MACRO */

/* USER CODE END PRIVATE_MACRO */

/**
  * @}
  */

/** @defgroup USBD_CUSTOM_HID_Private_Variables USBD_CUSTOM_HID_Private_Variables
  * @brief Private variables.
  * @{
  */

/** Usb HID report descriptor. */
__ALIGN_BEGIN static uint8_t CUSTOM_HID_ReportDesc_FS[USBD_CUSTOM_HID_REPORT_DESC_SIZE] __ALIGN_END =
{  0x05, 0x01, // USAGE_PAGE (Generic Desktop)
		  0x09, 0x04, // USAGE (Joystick)
		  0xA1, 0x01, // COLLECTION (Application)
		  //================================Input Report======================================//
		  0x09, 0x01, // USAGE (Pointer)
		  // WheelReport
		  0x85, HID_REPORTID_WHEEL, // REPORT_ID (1)
		  0xA1, 0x00, // COLLECTION (Physical)
		  // Button for Shifter
		  0x05, 0x09, // USAGE_PAGE  (Button)
		  0x19, 0x01, // USAGE_MINIMUM (Button 1)
		  0x29, 0x10, // USAGE_MAXIMUM (Button 8)
		  0x15, 0x00, // LOGICAL_MINIMUM (0)
		  0x25, 0x01, // LOGICAL_MAXIMUM (1)
		  0x75, 0x01, // REPORT_SIZE (1)
		  0x95, 0x10, // REPORT_COUNT (8)
		  0x81, 0x02, //INPUT (Data,Var,Abs)

		  //6 Axis for steering wheel, accelerator, brake, clutch, handbrake and spare
		  0x05, 0x01, // USAGE_PAGE (Generic Desktop)
		  0xa1, 0x00, // COLLECTION (Physical)
		  0x09, 0x30, // USAGE (X)
		  0x09, 0x31, // USAGE (Y)
		  0x09, 0x33, // USAGE (Rx)
		  0x09, 0x34, // USAGE (Ry)
		  0x09, 0x32, // USAGE (Z)
		  0x09, 0x35, // USAGE (Rz) */
		  0x16, 0x00, 0x80, //LOGICAL_MINIMUM (-32768)
		  0x26, 0xFF, 0x7F, //LOGICAL_MAXIMUM (32767)
		  0x75, 0x10, // REPORT_SIZE (16)
		  0x95, 0x06, // REPORT_COUNT (6)
		  0x81, 0x02, // INPUT (Data,Var,Abs)
		  0xc0, // END_COLLECTION */
		  0xc0, // END_COLLECTION */

		  // PIDStateReport
		  0x05, 0x0F,          // USAGE_PAGE (Physical Interface)
		  0x09, 0x92,          // USAGE (PID State Report)
		  0xA1, 0x02,          // COLLECTION (Logical)
		  0x85, 0x02,          // REPORT_ID (02)
		  0x09, 0x9F,          // USAGE (Device Paused)
		  0x09, 0xA0,          // USAGE (Actuators Enabled)
		  0x09, 0xA4,          // USAGE (Safety Switch)
		  0x09, 0xA5,          // USAGE (Actuator Override Switch)
		  0x09, 0xA6,          // USAGE (Actuator Power)
		  0x15, 0x00,          // LOGICAL_MINIMUM (00)
		  0x25, 0x01,           //  Logical Maximum (1)
		  0x35, 0x00,           //  Physical Minimum (0)
		  0x45, 0x01,           //  Physical Maximum (1)
		  0x75, 0x01,           //  Report Size (1)
		  0x95, 0x05,           //  Report Count (5)
		  0x81, 0x02,           //  Input (variable,absolute)
		  0x95, 0x03,           //  Report Count (3)
		  0x81, 0x03,           //  Input (Constant, Variable)
		  0x09, 0x94,           //  Usage (Effect Playing)
		  0x15, 0x00,           //  Logical Minimum (0)
		  0x25, 0x01,           //  Logical Maximum (1)
		  0x35, 0x00,           //  Physical Minimum (0)
		  0x45, 0x01,           //  Physical Maximum (1)
		  0x75, 0x01,           //  Report Size (1)
		  0x95, 0x01,           //  Report Count (1)
		  0x81, 0x02,           //  Input (variable,absolute)
		  0x09, 0x22,           //  Usage (Effect Block Index)
		  0x15, 0x01,           //  Logical Minimum (1)
		  0x25, 0x28,           //  Logical Maximum (40)
		  0x35, 0x01,           //  Physical Minimum (1)
		  0x45, 0x28,           //  Physical Maximum (40)
		  0x75, 0x07,           //  Report Size (7)
		  0x95, 0x01,           //  Report Count (1)
		  0x81, 0x02,           //  Input (variable,absolute)
		  0xC0,                 //End Collection Datalink (Logical) (OK)

		  //================================OutputReport======================================//

		  // SetEffectReport
		  0x09, 0x21,           //Usage (Set Effect Report)
		  0xA1, 0x02,           //Collection Datalink (Logical)
		  0x85, 0x01,           //Report ID 1
		  0x09, 0x22,           //  Usage (Effect Block Index)
		  0x15, 0x01,           //   Logical Minimum (1)
		  0x25, 0x28,           //   Logical Maximum (40)
		  0x35, 0x01,           //   Physical Minimum (1)
		  0x45, 0x28,           //   Physical Maximum (40)
		  0x75, 0x08,           //   Report Size (8)
		  0x95, 0x01,           //   Report Count (1)
		  0x91, 0x02,           //   Output (Data,Var,Abs)
		  0x09, 0x25,           //  Usage (Effect Type)
		  0xA1, 0x02,           //    Collection Datalink (Logical)
		  0x09, 0x26,           // USAGE (26)
		  0x09, 0x27,           // USAGE (27)
		  0x09, 0x30,           // USAGE (30)
		  0x09, 0x31,           // USAGE (31)
		  0x09, 0x32,           // USAGE (32)
		  0x09, 0x33,           // USAGE (33)
		  0x09, 0x34,           // USAGE (34)
		  0x09, 0x40,           // USAGE (40)
		  0x09, 0x41,           // USAGE (41)
		  0x09, 0x42,           // USAGE (42)
		  0x09, 0x43,           // USAGE (43)
		  0x09, 0x28,           // USAGE (28)
		  0x09, 0x28,           //      Usage (ET Custom Force Data)
		  0x15, 0x01,           //       Logical Minimum (1)
		  0x25, 0x0C,           //       Logical Maximum (12)
		  0x35, 0x01,           //       Physical Minimum (1)
		  0x45, 0x0C,           //       Physical Maximum (12)
		  0x75, 0x08,           //       Report Size (8)
		  0x95, 0x01,           //       Report Count (1)
		  0x91, 0x00,           //       Output (Data)
		  0xC0,                 //    End Collection Datalink (Logical)
		  0x09, 0x50,           //    Usage (Duration)
		  0x09, 0x54,           //    Usage (Trigger Repeat Interval)
		  0x09, 0x51,           //    Usage (Sample Period)
		  0x15, 0x00,           //     Logical Minimum (0)
		  0x26, 0xFF, 0x7F,     //     Logical Maximum (32767)
		  0x35, 0x00,           //     Physical Minimum (1)
		  0x46, 0xFF, 0x7F,     //     Physical Maximum (32767)
		  0x66, 0x03, 0x10,     //     Unit (4099)
		  0x55, 0xFD,           //     Unit Exponent (253)
		  0x75, 0x10,           //     Report Size (16)
		  0x95, 0x03,           //     Report Count (3)
		  0x91, 0x02,           //     Output (Data,Var,Abs)
		  0x55, 0x00,           //     Unit Exponent (0)
		  0x66, 0x00, 0x00,     //     Unit (0)
		  0x09, 0x52,           //    Usage (Gain)
		  0x15, 0x00,           //     Logical Minimum (0)
		  0x26, 0xFF, 0x00,     //     Logical Maximum (255)
		  0x35, 0x00,           //     Physical Minimum (1)
		  0x46, 0x10, 0x27,     //     Physical Maximum (10000)
		  0x75, 0x08,           //     Report Size (8)
		  0x95, 0x01,           //     Report Count (1)
		  0x91, 0x02,           //     Output (Data,Var,Abs)
		  0x09, 0x53,           //    Usage (Trigger Button)
		  0x15, 0x01,           //     Logical Minimum (1)
		  0x25, 0x08,           //     Logical Maximum (8)
		  0x35, 0x01,           //     Physical Minimum (1)
		  0x45, 0x08,           //     Physical Maximum (8)
		  0x75, 0x08,           //     Report Size (8)
		  0x95, 0x01,           //     Report Count (1)
		  0x91, 0x02,           //     Output (Data,Var,Abs)
		  0x09, 0x55,           //    Usage (Axes Enable)
		  0xA1, 0x02,           //      Collection Datalink (Logical)
		  0x05, 0x01,           //        Usage Page (Generic Desktop)
		  0x09, 0x30,           //        Usage (X)
		  0x09, 0x31,           //        Usage (Y)
		  0x15, 0x00,           //        Logical Minimum (0)
		  0x25, 0x01,           //        Logical Maximum (1)
		  0x75, 0x01,           //        Report Size (1)
		  0x95, 0x02,           //        Report Count (2)
		  0x91, 0x02,           //        Output (Data,Var,Abs)
		  0xC0,                 //      End Collection Datalink (Logical)

		  0x05, 0x0F,           //    Usage Page (Physical Interface)
		  0x09, 0x56,           //      Usage (Direction Enable)
		  0x95, 0x01,           //        Report Count (1)
		  0x91, 0x02,           //        Output (Data,Var,Abs)
		  0x95, 0x05,           //        Report Count (5)
		  0x91, 0x03,           //        Output (Constant, Variable)
		  0x09, 0x57,           //      Usage (Direction)
		  0xA1, 0x02,           //        Collection Datalink (Logical)
		  0x0B, 0x01, 0, 0x0A, 0,  //          Usage (Ordinals: Instance 1)
		  0x0B, 0x02, 0, 0x0A, 0,  //          Usage (Ordinals: Instance 2)
		  0x66, 0x14, 0x00,     //          Unit (20)
		  0x55, 0xFE,           //          Unit Exponent (254)
		  0x15, 0x00,           //          Logical Minimum (0)
		  0x26, 0xFF, 0x00,     //          Logical Maximum (255)
		  0x35, 0x00,           //          Physical Minimum (1)
		  0x47, 0xA0, 0x8C, 0, 0, //          Physical Maximum (36000)
		  0x66, 0x00, 0x00,     //          Unit (0)
		  0x75, 0x08,           //          Report Size (8)
		  0x95, 0x02,           //          Report Count (2)
		  0x91, 0x02,           //          Output (Data,Var,Abs)
		  0x55, 0x00,           //          Unit Exponent (0)
		  0x66, 0x00, 0x00,     //          Unit (0)
		  0xC0,                 //        End Collection Datalink (Logical)


		  0x05, 0x0F,           //    Usage Page (Physical Interface)
		  0x09, 0x58,           //      Usage (Type Specific Block Offset)
		  0xA1, 0x02,           //        Collection (Logical)
		  0x0B, 0x01, 0, 0x0A, 0,  //          Usage (Ordinals: Instance 1)
		  0x0B, 0x02, 0, 0x0A, 0,  //          Usage (Ordinals: Instance 2)
		  0x26, 0xFD, 0x7F,     //          Logical Maximum (32765); 32K RAM or ROM max.
		  0x75, 0x10,           //          Report Size (16)
		  0x95, 0x02,           //          Report Count (2)
		  0x91, 0x02,           //          Output (Data,Var,Abs)
		  0xC0,                 //        End Collection (Logical)
		  \
		  0xC0,                 //End Collection Datalink (Logical) (OK)

		  // SetEnvelopeReport
		  0x09, 0x5A,           //Usage (Set Envelope Report)
		  0xA1, 0x02,           //Collection Datalink (Logical)
		  0x85, 0x02,           //Report ID 2
		  0x09, 0x22,           //  Usage (Effect Block Index)
		  0x15, 0x01,           //   Logical Minimum (1)
		  0x25, 0x28,           //   Logical Maximum (40)
		  0x35, 0x01,           //   Physical Minimum (1)
		  0x45, 0x28,           //   Physical Maximum (40)
		  0x75, 0x08,           //   Report Size (8)
		  0x95, 0x01,           //   Report Count (1)
		  0x91, 0x02,           //   Output (Data,Var,Abs)
		  0x09, 0x5B,           //  Usage (Attack Level)
		  0x09, 0x5D,           //  Usage (Fade Level)
		  0x16, 0x00, 0x00,     //   Logical Minimum (0)
		  0x26, 0x10, 0x27,     //   Logical Maximum (10000)
		  0x36, 0x00, 0x00,     //   Physical Minimum (0)
		  0x46, 0x10, 0x27,     //   Physical Maximum (10000)
		  0x75, 0x10,           //   Report Size (16)
		  0x95, 0x02,           //   Report Count (2)
		  0x91, 0x02,           //   Output (Data,Var,Abs)
		  0x09, 0x5C,           //  Usage (Attack Time)
		  0x09, 0x5E,           //  Usage (Fade Time)
		  0x66, 0x03, 0x10,     //   Unit (1003h) English Linear, Seconds
		  0x55, 0xFD,           //   Unit Exponent (FDh) (X10^-3 ==> Milisecond)
		  0x27, 0xFF, 0x7F, 0, 0, //   Logical Maximum (4294967295)
		  0x47, 0xFF, 0x7F, 0, 0, //   Physical Maximum (4294967295)
		  0x75, 0x20,           //   Report Size (32)
		  0x91, 0x02,           //   Output (Data,Var,Abs)
		  0x45, 0x00,           //   Physical Maximum (0)
		  0x66, 0x00, 0x00,     //   Unit (0)
		  0x55, 0x00,           //   Unit Exponent (0)
		  0xC0,                 //End Collection Datalink (Logical) (OK)

		  // SetConditionReport
		  0x09, 0x5F,           //Usage (Set Condition Report)
		  0xA1, 0x02,           //Collection Datalink (Logical)
		  0x85, 0x03,           //Report ID 3
		  0x09, 0x22,           //  Usage (Effect Block Index)
		  0x15, 0x01,           //   Logical Minimum (1)
		  0x25, 0x28,           //   Logical Maximum (40)
		  0x35, 0x01,           //   Physical Minimum (1)
		  0x45, 0x28,           //   Physical Maximum (40)
		  0x75, 0x08,           //   Report Size (8)
		  0x95, 0x01,           //   Report Count (1)
		  0x91, 0x02,           //   Output (Data,Var,Abs)
		  0x09, 0x23,           //  Usage (Parameter Block Offset)
		  0x15, 0x00,           //   Logical Minimum (0)
		  0x25, 0x03,           //   Logical Maximum (3)
		  0x35, 0x00,           //   Physical Minimum (0)
		  0x45, 0x03,           //   Physical Maximum (3)
		  0x75, 0x04,           //   Report Size (4)
		  0x95, 0x01,           //   Report Count (1)
		  0x91, 0x02,           //   Output (Data,Var,Abs)
		  0x09, 0x58,           //  Usage (Type Specific Block Off...)
		  0xA1, 0x02,           //  Collection Datalink (Logical)
		  0x0B, 0x01, 0, 0x0A, 0,  //    Usage (Ordinals: Instance 1)
		  0x0B, 0x02, 0, 0x0A, 0,  //    Usage (Ordinals: Instance 2)
		  0x75, 0x02,           //     Report Size (2)
		  0x95, 0x02,           //     Report Count (2)
		  0x91, 0x02,           //     Output (Data,Var,Abs)
		  0xC0,                 //  End Collection Datalink (Logical)
		  0x16, 0xF0, 0xD8,       //  Logical Minimum (-10000)
		  0x26, 0x10, 0x27,       //  Logical Maximum (10000)
		  0x36, 0xF0, 0xD8,       //  Physical Minimum (-10000)
		  0x46, 0x10, 0x27,       //  Physical Maximum (10000)
		  0x09, 0x60,           //  Usage (CP Offset)
		  0x75, 0x10,           //   Report Size (16)
		  0x95, 0x01,           //   Report Count (1)
		  0x91, 0x02,           //   Output (Data,Var,Abs)
		  0x36, 0xF0, 0xD8,       //  Physical Minimum (-10000)
		  0x46, 0x10, 0x27,       //  Physical Maximum (10000)
		  0x09, 0x61,           //  Usage (Positive Coefficient)
		  0x09, 0x62,           //  Usage (Negative Coefficient)
		  0x95, 0x02,           //   Report Count (2)
		  0x91, 0x02,           //   Output (Data,Var,Abs)
		  0x16, 0x00, 0x00,       //   Logical Minimum (0)
		  0x26, 0x10, 0x27,       //   Logical Maximum (10000)
		  0x36, 0x00, 0x00,       //   Physical Minimum (0)
		  0x46, 0x10, 0x27,       //   Physical Maximum (10000)
		  0x09, 0x63,           //  Usage (Positive Saturation)
		  0x09, 0x64,           //  Usage (Negative Saturation)
		  0x75, 0x10,           //   Report Size (16)
		  0x95, 0x02,           //   Report Count (2)
		  0x91, 0x02,           //   Output (Data,Var,Abs)
		  0x09, 0x65,           //  Usage (Dead Band)
		  0x46, 0x10, 0x27,       //   Physical Maximum (10000)
		  0x95, 0x01,           //   Report Count (1)
		  0x91, 0x02,           //   Output (Data,Var,Abs)
		  0xC0,                 //End Collection Datalink (Logical) (OK)
		  // SetPeriodicReport

		  0x09, 0x6E,           //Usage (Set Periodic Report)
		  0xA1, 0x02,           //Collection Datalink (Logical)
		  0x85, 0x04,           //Report ID 4
		  0x09, 0x22,           //  Usage (Effect Block Index)
		  0x15, 0x01,           //   Logical Minimum (1)
		  0x25, 0x28,           //   Logical Maximum (40)
		  0x35, 0x01,           //   Physical Minimum (1)
		  0x45, 0x28,           //   Physical Maximum (40)
		  0x75, 0x08,           //   Report Size (8)
		  0x95, 0x01,           //   Report Count (1)
		  0x91, 0x02,           //   Output (Data,Var,Abs)
		  0x09, 0x70,           //  Usage (Magnitude)
		  0x16, 0x00, 0x00,     //   Logical Minimum (0)
		  0x26, 0x10, 0x27,     //   Logical Maximum (10000)
		  0x36, 0x00, 0x00,     //   Physical Minimum (0)
		  0x46, 0x10, 0x27,     //   Physical Maximum (10000)
		  0x75, 0x10,           //   Report Size (16)
		  0x95, 0x01,           //   Report Count (1)
		  0x91, 0x02,           //   Output (Data,Var,Abs)
		  0x09, 0x6F,           //  Usage (Offset)
		  0x16, 0xF0, 0xD8,     //   Logical Minimum (-10000)
		  0x26, 0x10, 0x27,     //   Logical Maximum (10000)
		  0x36, 0xF0, 0xD8,     //   Physical Minimum (-10000)
		  0x46, 0x10, 0x27,     //   Physical Maximum (10000)
		  0x95, 0x01,           //   Report Count (1)
		  0x75, 0x10,           //   Report Size (16)
		  0x91, 0x02,           //   Output (Data,Var,Abs)
		  0x09, 0x71,           //  Usage (Phase)
		  0x66, 0x14, 0x00,     //   Unit (14h) (Eng Rotation, Degrees)
		  0x55, 0xFE,           //   Unit Exponent (FEh) (X10^-2)
		  0x15, 0x00,           //   Logical Minimum (0)
		  0x27, 0x9F, 0x8C, 0, 0, //   Logical Maximum (35999)
		  0x35, 0x00,           //   Physical Minimum (0)
		  0x47, 0x9F, 0x8C, 0, 0, //   Physical Maximum (35999)
		  0x75, 0x10,           //   Report Size (16)
		  0x95, 0x01,           //   Report Count (1)
		  0x91, 0x02,           //   Output (Data,Var,Abs)
		  0x09, 0x72,           //  Usage (Period)
		  0x15, 0x00,           //   Logical Minimum (0)
		  0x27, 0xFF, 0x7F, 0, 0, //   Logical Maximum (32K)
		  0x35, 0x00,           //   Physical Minimum (0)
		  0x47, 0xFF, 0x7F, 0, 0, //   Physical Maximum (32K)
		  0x66, 0x03, 0x10,     //   Unit (1003h) (English Linear, Seconds)
		  0x55, 0xFD,           //   Unit Exponent (FDh) (X10^-3 ==> Milisecond)
		  0x75, 0x20,           //   Report Size (32)
		  0x95, 0x01,           //   Report Count (1)
		  0x91, 0x02,           //   Output (Data,Var,Abs)
		  0x66, 0x00, 0x00,     //  Unit (0)
		  0x55, 0x00,           //  Unit Exponent (0)
		  0xC0,                 //End Collection Datalink (Logical) (OK)

		  // SetConstantForceReport
		  0x09, 0x73,           //Usage (Set Constant Force Report)
		  0xA1, 0x02,           //Collection Datalink (Logical)
		  0x85, 0x05,           // Report ID 5
		  0x09, 0x22,           //  Usage (Effect Block Index)
		  0x15, 0x01,           //   Logical Minimum (1)
		  0x25, 0x28,           //   Logical Maximum (40)
		  0x35, 0x01,           //   Physical Minimum (1)
		  0x45, 0x28,           //   Physical Maximum (40)
		  0x75, 0x08,           //   Report Size (8)
		  0x95, 0x01,           //   Report Count (1)
		  0x91, 0x02,           //   Output (Data,Var,Abs)
		  0x09, 0x70,           //  Usage (Magnitude)
		  0x16, 0xF0, 0xD8,     //   Logical Minimum (-10000)
		  0x26, 0x10, 0x27,     //   Logical Maximum (10000)
		  0x36, 0xF0, 0xD8,     //   Physical Minimum (-10000)
		  0x46, 0x10, 0x27,     //   Physical Maximum (10000)
		  0x75, 0x10,           //   Report Size (16)
		  0x95, 0x01,           //   Report Count (1)
		  0x91, 0x02,           //   Output (Data,Var,Abs)
		  0xC0,                 //End Collection Datalink (Logical) (OK)

		  // SetRampForceReport
		  0x09, 0x74,           //Usage (Set Ramp Force Report)
		  0xA1, 0x02,           //Collection Datalink (Logical)
		  0x85, 0x06,           // Report ID 6
		  0x09, 0x22,           //  Usage (Effect Block Index)
		  0x15, 0x01,           //   Logical Minimum (1)
		  0x25, 0x28,           //   Logical Maximum (40)
		  0x35, 0x01,           //   Physical Minimum (1)
		  0x45, 0x28,           //   Physical Maximum (40)
		  0x75, 0x08,           //   Report Size (8)
		  0x95, 0x01,           //   Report Count (1)
		  0x91, 0x02,           //   Output (Data,Var,Abs)
		  0x09, 0x75,           //  Usage (Ramp Start)
		  0x09, 0x76,           //  Usage (Ramp End)
		  0x16, 0xF0, 0xD8,     //   Logical Minimum (-10000)
		  0x26, 0x10, 0x27,     //   Logical Maximum (10000)
		  0x36, 0xF0, 0xD8,     //   Physical Minimum (-10000)
		  0x46, 0x10, 0x27,     //   Physical Maximum (10000)
		  0x75, 0x10,           //   Report Size (16)
		  0x95, 0x02,           //   Report Count (2)
		  0x91, 0x02,           //   Output (Data,Var,Abs)
		  0xC0,                 //End Collection Datalink (Logical) (OK)

		  // CustomForceDataReport
		  0x09, 0x68,           //Usage (Custom Force Data Report)
		  0xA1, 0x02,           //Collection Datalink (Logical)
		  0x85, 0x07,           // Report ID 7
		  0x09, 0x22,           //  Usage (Effect Block Index)
		  0x15, 0x01,           //   Logical Minimum (1)
		  0x25, 0x28,           //   Logical Maximum (40)
		  0x35, 0x01,           //   Physical Minimum (1)
		  0x45, 0x28,           //   Physical Maximum (40)
		  0x75, 0x08,           //   Report Size (8)
		  0x95, 0x01,           //   Report Count (1)
		  0x91, 0x02,           //   Output (Data,Var,Abs)
		  0x09, 0x6C,           //  Usage (Custom Force Data Offset)
		  0x15, 0x00,           //   Logical Minimum (0)
		  0x26, 0x10, 0x27,     //   Logical Maximum (10000)
		  0x35, 0x00,           //   Physical Minimum (0)
		  0x46, 0x10, 0x27,     //   Physical Maximum (10000)
		  0x75, 0x10,           //   Report Size (16)
		  0x95, 0x01,           //   Report Count (1)
		  0x91, 0x02,           //   Output (Data,Var,Abs)
		  0x09, 0x69,           //  Usage (Custom Force Data)
		  0x15, 0x81,           //   Logical Minimum (-127)
		  0x25, 0x7F,           //   Logical Maximum (127)
		  0x35, 0x00,           //   Physical Minimum (0)
		  0x46, 0xFF, 0x00,     //   Physical Maximum (255)
		  0x75, 0x08,           //   Report Size (8)
		  0x95, 0x0C,           //   Report Count (12)
		  0x92, 0x02, 0x01,     //   Output (Variable, Buffered)
		  0xC0,                 //End Collection Datalink (Logical) (OK)

		  // DownloadForceSample
		  0x09, 0x66,           //Usage (Download Force Sample)
		  0xA1, 0x02,           //Collection Datalink (Logical)
		  0x85, 0x08,           //Report ID 8
		  0x05, 0x01,           //  Usage Page (Generic Desktop)
		  0x09, 0x30,           //    Usage (X)
		  0x09, 0x31,           //    Usage (Y)
		  0x15, 0x81,           //     Logical Minimum (-127)
		  0x25, 0x7F,           //     Logical Maximum (127)
		  0x35, 0x00,           //     Physical Minimum (0)
		  0x46, 0xFF, 0x00,     //     Physical Maximum (255)
		  0x75, 0x08,           //     Report Size (8)
		  0x95, 0x02,           //     Report Count (2)
		  0x91, 0x02,           //     Output (Data,Var,Abs)
		  0xC0,                 //End Collection Datalink (Logical) (OK)

		  // EffectOperationReport
		  0x05, 0x0F,           //Usage Page (Physical Interface)
		  0x09, 0x77,           //Usage (Effect Operation Report)
		  0xA1, 0x02,           //Collection Datalink (Logical)
		  0x85, 0x0A,          //Report ID 10
		  0x09, 0x22,           //  Usage (Effect Block Index)
		  0x15, 0x01,           //   Logical Minimum (1)
		  0x25, 0x28,           //   Logical Maximum (40)
		  0x35, 0x01,           //   Physical Minimum (1)
		  0x45, 0x28,           //   Physical Maximum (40)
		  0x75, 0x08,           //   Report Size (8)
		  0x95, 0x01,           //   Report Count (1)
		  0x91, 0x02,           //   Output (Data,Var,Abs)
		  0x09, 0x78,           //  Usage (Effect Operation)
		  0xA1, 0x02,           //  Collection Datalink (Logical)
		  0x09, 0x79,           //    Usage (Op Effect Start)
		  0x09, 0x7A,           //    Usage (Op Effect Start Solo)
		  0x09, 0x7B,           //    Usage (Op Effect Stop)
		  0x15, 0x01,           //     Logical Minimum (1)
		  0x25, 0x03,           //     Logical Maximum (3)
		  0x75, 0x08,           //     Report Size (8)
		  0x95, 0x01,           //     Report Count (1)
		  0x91, 0x00,           //     Output (Data)
		  0xC0,                 //  End Collection Datalink (Logical)
		  0x09, 0x7C,           //  Usage (Loop Count)
		  0x15, 0x00,           //   Logical Minimum (0)
		  0x26, 0xFF, 0x00,     //   Logical Maximum (255)
		  0x35, 0x00,           //   Physical Minimum (0)
		  0x46, 0xFF, 0x00,     //   Physical Maximum (255)
		  0x91, 0x02,           //   Output (Data,Var,Abs)
		  0xC0,                 //End Collection Datalink (Logical) (OK)

		  // PIDBlockFreeReport
		  0x09, 0x90,           //Usage (PID Block Free Report)
		  0xA1, 0x02,           //Collection Datalink (Logical)
		  0x85, 0x0B,           // Report ID 11
		  0x09, 0x22,           //  Usage (Effect Block Index)
		  0x15, 0x01,           //   Logical Minimum (1)
		  0x25, 0x28,           //   Logical Maximum (40)
		  0x35, 0x01,           //   Physical Minimum (1)
		  0x45, 0x28,           //   Physical Maximum (40)
		  0x75, 0x08,           //   Report Size (8)
		  0x95, 0x01,           //   Report Count (1)
		  0x91, 0x02,           //   Output (Data,Var,Abs)
		  0xC0,                 //End Collection Datalink (Logical) (OK)
		  //PIDDeviceControl
		  0x09, 0x96,           //Usage (PID Device Control)
		  0xA1, 0x02,           //Collection Datalink (Logical)
		  0x85, 0x0C,           // Report ID 12
		  0x09, 0x97,           //  Usage (DC Enable Actuators)
		  0x09, 0x98,           //  Usage (DC Disable Actuators)
		  0x09, 0x99,           //  Usage (DC Stop All Effects)
		  0x09, 0x9A,           //  Usage (DC Device Reset)
		  0x09, 0x9B,           //  Usage (DC Device Pause)
		  0x09, 0x9C,           //  Usage (DC Device Continue)
		  0x15, 0x01,           //   Logical Minimum (1)
		  0x25, 0x06,           //   Logical Maximum (6)
		  0x75, 0x08,           //   Report Size (8)
		  0x95, 0x01,           //   Report Count (1)
		  0x91, 0x00,           //   Output (Data)
		  0xC0,                 //End Collection Datalink (Logical) (OK)

		  // DeviceGainReport
		  0x09, 0x7D,           //Usage (Device Gain Report)
		  0xA1, 0x02,           //Collection Datalink (Logical)
		  0x85, 0x0D,           //Report ID 13
		  0x09, 0x7E,           //  Usage (Device Gain)
		  0x15, 0x00,           //   Logical Minimum (0)
		  0x26, 0xFF, 0x00,     //   Logical Maximum (255)
		  0x35, 0x00,           //   Physical Minimum (0)
		  0x46, 0x10, 0x27,     //   Physical Maximum (10000)
		  0x75, 0x08,           //   Report Size (8)
		  0x95, 0x01,           //   Report Count (1)
		  0x91, 0x02,           //   Output (Data,Var,Abs)
		  0xC0,                 //End Collection Datalink (Logical) (OK)

		  //SetCustomForceReport
		  0x09, 0x6B,           //Usage (Set Custom Force Report)
		  0xA1, 0x02,           //Collection Datalink (Logical)
		  0x85, 0x0E,           // Report ID 14
		  0x09, 0x22,           //  Usage (Effect Block Index)
		  0x15, 0x01,           //   Logical Minimum (1)
		  0x25, 0x28,           //   Logical Maximum (40)
		  0x35, 0x01,           //   Physical Minimum (1)
		  0x45, 0x28,           //   Physical Maximum (40)
		  0x75, 0x08,           //   Report Size (8)
		  0x95, 0x01,           //   Report Count (1)
		  0x91, 0x02,           //   Output (Data,Var,Abs)
		  0x09, 0x6D,           //  Usage (Sample Count)
		  0x15, 0x00,           //   Logical Minimum (0)
		  0x26, 0xFF, 0x00,     //   Logical Maximum (255)
		  0x35, 0x00,           //   Physical Minimum (0)
		  0x46, 0xFF, 0x00,     //   Physical Maximum (255)
		  0x75, 0x08,           //   Report Size (8)
		  0x95, 0x01,           //   Report Count (1)
		  0x91, 0x02,           //   Output (Data,Var,Abs)
		  0x09, 0x51,           //  Usage (Sample Period)
		  0x66, 0x03, 0x10,     //   Unit 4099
		  0x55, 0xFD,           //   Unit (Exponent 253)
		  0x15, 0x00,           //   Logical Minimum (0)
		  0x26, 0xFF, 0x7F,     //   Logical Maximum (32767)
		  0x35, 0x00,           //   Physical Minimum (0)
		  0x46, 0xFF, 0x7F,     //   Physical Maximum (32767)
		  0x75, 0x10,           //   Report Size (16)
		  0x95, 0x01,           //   Report Count (1)
		  0x91, 0x02,           //   Output (Data,Var,Abs)
		  0x55, 0x00,           //   Unit (Exponent 0)
		  0x66, 0x00, 0x00,     //   Unit 0
		  0xC0,                 //End Collection Datalink (Logical) (OK)

		  //=========================================FeatureReport======================================//

		  //CreateNewEffectReport
		  0x09, 0xAB, // USAGE (Create New Effect Report)
		  0xA1, 0x02, // COLLECTION (Logical)
		  0x85, 0x05, // REPORT_ID (05)
		  0x09, 0x25, // USAGE (Effect Type)
		  0xA1, 0x02, // COLLECTION (Logical)
		  0x09, 0x26, // USAGE (26)
		  0x09, 0x27, // USAGE (27)
		  0x09, 0x30, // USAGE (30)
		  0x09, 0x31, // USAGE (31)
		  0x09, 0x32, // USAGE (32)
		  0x09, 0x33, // USAGE (33)
		  0x09, 0x34, // USAGE (34)
		  0x09, 0x40, // USAGE (40)
		  0x09, 0x41, // USAGE (41)
		  0x09, 0x42, // USAGE (42)
		  0x09, 0x43, // USAGE (43)
		  0x09, 0x28, // USAGE (28)
		  0x25, 0x0C, // LOGICAL_MAXIMUM (0C)
		  0x15, 0x01, // LOGICAL_MINIMUM (01)
		  0x35, 0x01, // PHYSICAL_MINIMUM (01)
		  0x45, 0x0C, // PHYSICAL_MAXIMUM (0C)
		  0x75, 0x08, // REPORT_SIZE (08)
		  0x95, 0x01, // REPORT_COUNT (01)
		  0xB1, 0x00, // FEATURE (Data)
		  0xC0, // END COLLECTION ()
		  0x05, 0x01, // USAGE_PAGE (Generic Desktop)
		  0x09, 0x3B, // USAGE (Byte Count)
		  0x15, 0x00, // LOGICAL_MINIMUM (00)
		  0x26, 0xFF, 0x01, // LOGICAL_MAXIMUM (511)
		  0x35, 0x00, // PHYSICAL_MINIMUM (00)
		  0x46, 0xFF, 0x01, // PHYSICAL_MAXIMUM (511)
		  0x75, 0x0A, // REPORT_SIZE (0A)
		  0x95, 0x01, // REPORT_COUNT (01)
		  0xB1, 0x02, // FEATURE (Data,Var,Abs)
		  0x75, 0x06, // REPORT_SIZE (06)
		  0xB1, 0x01, // FEATURE (Constant,Ary,Abs)
		  0xC0, // END COLLECTION ()

		  // PIDBlockLoadReport
		  0x05, 0x0F, // USAGE_PAGE (Physical Interface)
		  0x09, 0x89, // USAGE (PID Block Load Report)
		  0xA1, 0x02, // COLLECTION (Logical)
		  0x85, 0x06, // REPORT_ID (06)
		  0x09, 0x22, // USAGE (Effect Block Index)
		  0x25, 0x28, // LOGICAL_MAXIMUM (28)
		  0x15, 0x01, // LOGICAL_MINIMUM (01)
		  0x35, 0x01, // PHYSICAL_MINIMUM (01)
		  0x45, 0x28, // PHYSICAL_MAXIMUM (28)
		  0x75, 0x08, // REPORT_SIZE (08)
		  0x95, 0x01, // REPORT_COUNT (01)
		  0xB1, 0x02, // FEATURE (Data,Var,Abs)
		  0x09, 0x8B, // USAGE (Block Load Status)
		  0xA1, 0x02, // COLLECTION (Logical)
		  0x09, 0x8C, // USAGE (Block Load Success)
		  0x09, 0x8D, // USAGE (Block Load Full)
		  0x09, 0x8E, // USAGE (Block Load Error)
		  0x25, 0x03, // LOGICAL_MAXIMUM (03)
		  0x15, 0x01, // LOGICAL_MINIMUM (01)
		  0x35, 0x01, // PHYSICAL_MINIMUM (01)
		  0x45, 0x03, // PHYSICAL_MAXIMUM (03)
		  0x75, 0x08, // REPORT_SIZE (08)
		  0x95, 0x01, // REPORT_COUNT (01)
		  0xB1, 0x00, // FEATURE (Data)
		  0xC0, // END COLLECTION ()
		  0x09, 0xAC, // USAGE (RAM Pool Available)
		  0x15, 0x00, // LOGICAL_MINIMUM (00)
		  0x27, 0xFF, 0xFF, 0x00, 0x00, // LOGICAL_MAXIMUM (00 00 FF FF)
		  0x35, 0x00, // PHYSICAL_MINIMUM (00)
		  0x47, 0xFF, 0xFF, 0x00, 0x00, // PHYSICAL_MAXIMUM (00 00 FF FF)
		  0x75, 0x10, // REPORT_SIZE (10)
		  0x95, 0x01, // REPORT_COUNT (01)
		  0xB1, 0x00, // FEATURE (Data)
		  0xC0, // END COLLECTION ()

		  // PIDPoolReport
		  0x09, 0x7F, // USAGE (PID Pool Report)
		  0xA1, 0x02, // COLLECTION (Logical)
		  0x85, 0x07, // REPORT_ID (07)
		  0x09, 0x80, // USAGE (RAM Pool Size)
		  0x75, 0x10, // REPORT_SIZE (10)
		  0x95, 0x01, // REPORT_COUNT (01)
		  0x15, 0x00, // LOGICAL_MINIMUM (00)
		  0x35, 0x00, // PHYSICAL_MINIMUM (00)
		  0x27, 0xFF, 0xFF, 0x00, 0x00, // LOGICAL_MAXIMUM (00 00 FF FF)
		  0x47, 0xFF, 0xFF, 0x00, 0x00, // PHYSICAL_MAXIMUM (00 00 FF FF)
		  0xB1, 0x02, // FEATURE (Data,Var,Abs)
		  0x09, 0x83, // USAGE (Simultaneous Effects Max)
		  0x26, 0xFF, 0x00, // LOGICAL_MAXIMUM (00 FF)
		  0x46, 0xFF, 0x00, // PHYSICAL_MAXIMUM (00 FF)
		  0x75, 0x08, // REPORT_SIZE (08)
		  0x95, 0x01, // REPORT_COUNT (01)
		  0xB1, 0x02, // FEATURE (Data,Var,Abs)
		  0x09, 0xA9, // USAGE (Device Managed Pool)
		  0x09, 0xAA, // USAGE (Shared Parameter Blocks)
		  0x75, 0x01, // REPORT_SIZE (01)
		  0x95, 0x02, // REPORT_COUNT (02)
		  0x15, 0x00, // LOGICAL_MINIMUM (00)
		  0x25, 0x01, // LOGICAL_MAXIMUM (01)
		  0x35, 0x00, // PHYSICAL_MINIMUM (00)
		  0x45, 0x01, // PHYSICAL_MAXIMUM (01)
		  0xB1, 0x02, // FEATURE (Data,Var,Abs)
		  0x75, 0x06, // REPORT_SIZE (06)
		  0x95, 0x01, // REPORT_COUNT (01)
		  0xB1, 0x03, // FEATURE ( Cnst,Var,Abs)
		  0xC0, // END COLLECTION ()
		  0xC0, // END COLLECTION ()
};

/* USER CODE BEGIN PRIVATE_VARIABLES */

/* USER CODE END PRIVATE_VARIABLES */

/**
  * @}
  */

/** @defgroup USBD_CUSTOM_HID_Exported_Variables USBD_CUSTOM_HID_Exported_Variables
  * @brief Public variables.
  * @{
  */
extern USBD_HandleTypeDef hUsbDeviceFS;

/* USER CODE BEGIN EXPORTED_VARIABLES */

/* USER CODE END EXPORTED_VARIABLES */
/**
  * @}
  */

/** @defgroup USBD_CUSTOM_HID_Private_FunctionPrototypes USBD_CUSTOM_HID_Private_FunctionPrototypes
  * @brief Private functions declaration.
  * @{
  */

static int8_t CUSTOM_HID_Init_FS(void);
static int8_t CUSTOM_HID_DeInit_FS(void);
static int8_t CUSTOM_HID_OutEvent_FS(uint8_t* report);
extern void ffbOnData();

/**
  * @}
  */

USBD_CUSTOM_HID_ItfTypeDef USBD_CustomHID_fops_FS =
{
  CUSTOM_HID_ReportDesc_FS,
  CUSTOM_HID_Init_FS,
  CUSTOM_HID_DeInit_FS,
  CUSTOM_HID_OutEvent_FS
};

/** @defgroup USBD_CUSTOM_HID_Private_Functions USBD_CUSTOM_HID_Private_Functions
  * @brief Private functions.
  * @{
  */

/* Private functions ---------------------------------------------------------*/

/**
  * @brief  Initializes the CUSTOM HID media low layer
  * @retval USBD_OK if all operations are OK else USBD_FAIL
  */
static int8_t CUSTOM_HID_Init_FS(void)
{
  /* USER CODE BEGIN 4 */
  return (USBD_OK);
  /* USER CODE END 4 */
}

/**
  * @brief  DeInitializes the CUSTOM HID media low layer
  * @retval USBD_OK if all operations are OK else USBD_FAIL
  */
static int8_t CUSTOM_HID_DeInit_FS(void)
{
  /* USER CODE BEGIN 5 */
  return (USBD_OK);
  /* USER CODE END 5 */
}

/**
  * @brief  Manage the CUSTOM HID class events
  * @param  event_idx: Event index
  * @param  state: Event state
  * @retval USBD_OK if all operations are OK else USBD_FAIL
  */
extern uint8_t usb_rx_buffer;
static int8_t CUSTOM_HID_OutEvent_FS(uint8_t* report)
{
  /* USER CODE BEGIN 6 */
	USBD_CUSTOM_HID_HandleTypeDef *myusb=(USBD_CUSTOM_HID_HandleTypeDef *)hUsbDeviceFS.pClassData;
	memcpy(usb_rx_buffer, myusb->Report_buf, sizeof(myusb->Report_buf));
  /* Start next USB packet transfer once data processing is completed */
  USBD_CUSTOM_HID_ReceivePacket(&hUsbDeviceFS);

  return (USBD_OK);
  /* USER CODE END 6 */
}

/* USER CODE BEGIN 7 */
/**
  * @brief  Send the report to the Host
  * @param  report: The report to be sent
  * @param  len: The report length
  * @retval USBD_OK if all operations are OK else USBD_FAIL
  */
/*
static int8_t USBD_CUSTOM_HID_SendReport_FS(uint8_t *report, uint16_t len)
{
  return USBD_CUSTOM_HID_SendReport(&hUsbDeviceFS, report, len);
}
*/
/* USER CODE END 7 */

/* USER CODE BEGIN PRIVATE_FUNCTIONS_IMPLEMENTATION */

/* USER CODE END PRIVATE_FUNCTIONS_IMPLEMENTATION */
/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/

