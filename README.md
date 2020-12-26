# CarSimulatorFirmware 

CarSimulatorFirmware is the Open firmwares of VNM Simulation. It will include required firmwares for car simulator such as wheelbase, pedal, shifter, etc.

For discussion, please visit: https://discord.gg/NDk4pYd or https://www.facebook.com/groups/2303223886447618/?ref=share

1. Wheelbase features:

- 12 effects and can configurable individual effect gains.
- Built in DAC (PA4,PA5) ~ PE9,PE11 PWM
- FFB frequency upto 4k (it can increase more but i think it is enough, it requires you have a high resolution encoder) the low resolution encoder should use low ffb frequency.
- Configurable filters, user effects.

The feature roadmap for VNM Wheelbase Firmware includes:
* load cells with high resolution and  frequency
* 24 bit mutil channel ADC
* Angle sensors
* Absolute encoder
* Configure the servo driver from the GUI
* Displays configuration in LCD on-device
* Button for steering wheel, button box, paddles.

2. Shifter
- Hpattern and sequential modes supported
- 2 analog inputs 
- Configurable LED 
- 2 buttons for truck knob

# Bug report
For bug reporting, please fill out the following form with as much details as possible, so we can track down the issue

<pre>
1. Brief description of the issue
2. What firmware and UI version are you using?
3. Windows version?
4. Which feature is broken?
5. Does it occur frequently? (Rarely, sometimes, always, etc.)
6. Steps to re-produce the issue?
7. Screenshots and logs
8. Other information

(A github issue is preferred for better bug tracking)
</pre>