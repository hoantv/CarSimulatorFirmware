02/05/2021 2.2.0.2
* Fixed: Removed global ThreadFileLogger
+ Added: madExcept for bug report 
* Fixed: Mouse cursor on Game effect panel
* Fixed: Used ExitProcess to force application exit

01/05/2021 2.2.0.2
+ Added: Show no device connected message on DevPanel

30/04/2021 2.2.0.1
* Fixed: Divbyzero check added to map function

29/04/2021 2.2.0.1
* Fixed: Adjusted statusbar width

28/04/2021 2.2.0.1
* Fixed: Attempted to fix a bug where AV occurred when unplugging devices
+ Added: Made DevPanel clickable
+ Added: Icon and shortcut key to Show Devices menu (F6)
* Fixed: Adjusted DevicePanel height and margin

27/04/2021 2.2.0.1
+ Added: Wheel to Device Manager
+ Added: Device type support to Device Manager
+ Added: Wheel, pedal, handbrake icons
+ Added: Customized TGroupBox with ShowCaption option

26/04/2021 2.2.0.1
+ Added: Show Devices menu
* Fixed: Complete rework of DevicePanel

25/04/2021 2.2.0.1
+ Added; TPanelSlider; Autohide option. Default: False;
* Fixed: TPanelSlider; TPanel replaced with generic TControl

22/04/2021 2.2.0.1
+ Added: Handbrake status icon

20/04/2021 2.1.1.2
* Fixed: Cleanups

19/04/2021 2.1.1.2
* Fixed: Check updates now runs in a separated thread to avoid UI freeze
* Fixed: Use system log for update errorlog instead of messsagebox
* Fixed: Log menu not checked when Log window is showing
* Fixed: Better TPopupMenu custom cursor handling
* Fixed: Removed autosize property from most of the labels
* Fixed: Debug page reworked

18/04/2021 2.1.1.1
* Fixed: Removed FFoundWheelbase variable
* Fixed: Check for updates activity now only runs after form is fully shown
+ Added: Show calculated led effect on statusbar on mouse hovering
* Fixed: Preferences form revamped
+ Added: Option to show/hide log window at startup
+ Added: Auto select shifter when shifter page is active
+ Added: Showing grid coordinates when moving mouse withing the grid
* Fixed: Re-organized shifter stats
+ Added: DevCnt field to statusbar indicating the number of connected devices
* Fixed: DeviceManager reworked

17/04/2021 2.1.0.3
+ Added: Auto scroll log window
* Fixed: Show log vertical scrollbar
* Fixed: Flickering issue on some components due to cursor change
* Fixed: Cursor not handled on Color selector dialog
+ Added: Theme based cursor
* Fixed: Cursor not properly changed on TPopupMenu

14/04/2021 2.1.0.3
+ Added: Custom cursors
+ Added: Auto select shifter if there is only one device

14/04/2021 2.1.0.2
* Fixed: Increased grid linewidth
* Fixed: Workaround for shifter mode switching issue

13/04/2021 2.1.0.2
* Fixed: Hide buttons from 11 to 16
* Fixed: Diagnose function did not send Ack command
* Fixed: Shifter struct cleanup (Removed hMode field)
+ Added: Warning message when firmware version is lower than 1.2.x

12/04/2021 2.1.0.1
* Fixed: Disabled mode selection combobox
+ Added: Handled new shifter firmware 1.1+

11/04/2021 2.0.0.2
* Fixed: Shifter VID/PID display
* Fixed: Replaced Syslog with richedit

10/04/2021 2.0.0.2
* Fixed: Update previously selected shifter index when device being removed
* Fixed: Diag datain/out check

09/04/2021 2.0.0.2
* Fixed: Diagnostic function showing incorrect results
+ Added: ComPort reader

08/04/2021 2.0.0.2
+ Added: Shifter diagnostic feature
* Fixed: Shifter buttons not properly disabled while calibrating

04/04/2021 2.0.0.1
+ Added: A 1-minute shifter health-check log
* Fixed: Gridlines's color changed to red on Light theme
* Fixed: Auto position button 9-16
* Fixed: Proper handling of device unplug
* Fixed: Shifter page reworked
* Fixed: Refactored device enumeration procedure
+ Added: Multiple VID/PID detection
* Fixed: Show error when unable to read device info
+ Added: Backwards compatiblility with Shifter_V1

02/04/2021 2.0.0.1
+ Added: Button 16 display
* Fixed: Duplicated items in shifter selection box

28/03/2021 2.0.0.1
+ Added: Shortcuts to Window/Log (Ctrl + F9) and Window/Debug (Ctrl + F12)
* Fixed: Properly show/hide log window on menu selection
+ Added: No updates message
* Fixed: Updater reworked with indy instead of wininet
+ Added: Multi-device internal prepration
* Fixed: Logging system reworked

27/03/2021 2.0.0.1
+ Added: Window/Debug menu to show/hide Debug tab
* Fixed: Debug tab hidden by default

16/03/2021 1.4.0.15
+ Added: CAN/CANopen support to controller selection

13/02/2021 1.4.0.13
+ Added: Calibration confirmation dialog

01/02/2021 1.4.0.11
* Fixed: Invalid typecast on checkboxes

28/01/2021 1.4.0.10
+ Added: Log shifter config when saving
+ Added: GUI eventlog
+ Fixed: Some error messages rewritten

18/01/2021 1.4.0.9
* Fixed: Adjusted info text

09/01/2021 1.4.0.9
* Fixed: Updated self-upgrade mechanism
* Fixed: Reduced binary size

09/01/2021 1.4.0.8
* Fixed: Upgrade feature optimized
+ Added: VNMUpdater binary

09/01/2021 1.4.0.7
+ Added: Joystick axis enable/disable feature

05/01/2021 1.4.0.6
+ Added: Check for update option
* Fixed: Optimized update feature

03/01/2021 1.4.0.5
+ Added: UI update check feature
* Fixed: Hotkeys not working

02/01/2021 1.4.0.4
+ Added: Build date to log and about form
* Fixed: Optimized UI control alignment
* Fixed: Light skin issue

01/01/2021 1.4.0.3
* Fixed: Updated themes
* Fixed: Replaced light skin

01/01/2021 1.4.0.2
+ Added: Auto align controls by code (more precision)
+ Added: Show device version info based on current tab
+ Added: Single instance check
* Fixed: Adjusted statusbar icons
* Fixed: Reconnect function

31/12/2020 1.4.0.2
+ Added: Logging system with log rotation

29/12/2020 1.4.0.1
+ Added: Notification system
+ Added: Docked log window

28/12/2020 1.3.3.3
* Fixed: Removed themes folder (embedded resources)
* Fixed: Profile switching not properly handled

27/12/2020 1.3.3.1
* Fixed: Removed tabcontrol showfocus
+ Added: Menu tab
* Fixed: Removed Mainmenu bar
* Fixed: Replaced MainIcon
+ Added: User profile feature

27/12/2020 1.3.2.1
* Fixed: GUI Adjustments
* Fixed: Attempted to reduce hint flickering

26/12/2020 1.3.2.1
* Fixed: GUI adjustments
+ Added: Showing trackbar pos on changed
+ Added: Custom balloon hint class

25/12/2020 1.3.1.6
* Fixed: Set default profile to 0
+ Added: Hardware save timeout (Default: 5s)
+ Added: Reconnect button on Hardware tab

23/12/2020 1.3.1.5
* Fixed: Duplicated device enumeration

23/12/2020 1.3.1.4
+ Added: Delay 3s when saving hardware

22/12/2020 1.3.1.3
* Fixed: Failure to restart wheelbase because save action takes too long

21/12/2020 1.3.1.2
* Fixed: Disabled profile related buttons when no profile selected
+ Added: Profiles renaming feature
* Fixed: Refactored Hardware tab

16/12/2020 1.3.1.1
+ Added: Composite wheelbase handling functions

13/12/2020 1.2.0.2
* Fixed: Updated wheel image
+ Added: Game effects; reverse force
+ Added: Angle input box

12/12/2020 1.2.0.1
* Fixed: Refactored shifter page
+ Added: Automatically load version from file
+ Added: Shifter config refresh button

12/12/2020 1.1.0.9
* Fixed: Removed firmware report selector

09/12/2020 1.1.0.9
* Fixed: Adjusted related structs for FFB frequency settings
* Fixed: Moved FFB Frequency settings to Hardware tab

09/12/2020 1.1.0.8
+ Added: Fade color selector

08/12/2020 1.1.0.8
* Fixed: Replaced TImage32Ex with TImage32
+ Added: Windows hibernate, sleep check
+ Fixed: Gridlines on high dpi screens
* Fixed: Button 9-11 auto adjustments

07/12/2020 1.1.0.8
* Fixed: Incorrect statusbar display on 4k screens

06/12/2020 1.1.0.8
* Fixed: Disabled force multiplier (deprecated and will be removed in later builds)
+ Added: FFBFrequency implemented
+ Added: MaxForce implemented

06/12/2020
* Fixed: Wheel drawing may cause GUI freezing
* Fixed: AV at startup when current device not detected yet

05/12/2020 1.1.0.7
* Fixed: Memory leaks on some functions/procedures
+ Added: ScaleMM memory management
* Fixed: Attempted to fix statusbar on 4k screen

03/12/2020 
* Fixed: GUI adjustments
* Fixed: Disabled other tabs when clicking calibrate

02/12/2020 
* Fixed: Minor GUI adjustments
+ Added: Shifter calibration cancellation when device disconnected
* Fixed: Shifter calibration issues
* Fixed: Re-ordered tabstops
* Fixed: Disabled related trackbars when unchecking effects
* Added: Rotating wheel on wheelbase page

01/12/2020
+ Added: Related procedures for drawing a rotating wheel feature
* Fixed: Shifter grid not properly updated when switching modes
* Fixed: Flickering issue while calibrating
* Fixed: Shifter S mode calibration

30/11/2020
* Fixed: Reduced min range from 300 to 200
* Fixed: Faulty  calibration button on shifter page
+ Added: Axis legends on shifter grid
+ Added: Shifter configuration reload when re-connecting
* Fixed: Added an instruction message when clicking Calibrate
* Fixed: Adjusted shifter gear positions by code

29/11/2020
* Fixed: Restrict shifter mininum ranges of min.x, max.x and min.y, max.y to 300
* Fixed: Disabled various components when calibrating shifter
+ Added: Shifter config reloading
* Fixed: Shifter mode switching
* Fixed: Broken shifter calibration
* Fixed: GUI adjustments
28/11/2020
+ Added: Implemented button pressed display feature
* Fixed: Auto select shifter mode based on button 11
* Fixed: Changed color of gear numbers
* Fixed: Auto selecting proper report when clicking Calibrate
* Fixed: Removed axis reversion (moved this part to firmware) 

26/11/2020
* Fixed: Removed second interface checks (as the feature not yet implemented)
+ Added: Shifter filtering factor

24/11/2020
+ Added: Shifter Inversion mode settings

23/11/2020
+ Added: Shifter calibration feature

22/11/2020
* Fixed: Clicking save not restore shifter runmode to 0
* Fixed: Swapped status icons to the front of labels
* Fixed: Bumped to v1.1
+ Added: Implemented shifter page

05/11/2020
* Fixed: Max angle pagesize changed to 90

02/11/2020
* Fixed: Incorrect sine gain settings
* Fixed: Disabled numbers only on edits that allow floating point numbers

02/11/2020
* Fixed: Hardware save not applying configuration
+ Added: Debug enable/disable option
* Fixed: Configuration load/save issue

01/11/2020
+ Added: Timestamps to debug log
+ Added: General Config save/load
+ Added: Settings form
+ Added: Load settings on device connect

31/10/2020
+ Added: Biquad debug report
+ Added: Load settings on device connect
+ Added: Show progress on all trackbars
* Fixed: Disable posOnClick on some trackbars
* Fixed: Set default page on startup =Base
* Fixed: Changed pwmReport record to match firmware changes
* Fixed: Logging moved to a separated thread
+ Added: A default timeout of 10s when sending/receiving data to/from device
* Fixed: GUI adjustments

30/10/2020
* Fixed: Removed unused imports
* Fixed: Disabled Maximize and added form size constraints (630x1100)
* Fixed: Default max angle changed to 900
* Fixed: Scaling issue
* Fixed: Unable to parse QFactor and PeakGain as floating point

29/10/2020
+ Added Themes menu and configuration related procedures
+ Added: Light theme
* Fixed: Dark theme

27/10/2020
+ Added: Dark theme

25/10/2020
* Fixed: Packed records

24/10/2020
* Fixed: Device not auto reconnected
* FIxed: Race condition when loading profile
+ Added: application.log file
+ Added: Power state listener; disconnect device when entering hibernating/standby mode
23/10/2020

+ Added: Configuration loading at startup
+ Added: Configuration save/load

19/10/2020
+ Added: User effect configuration

14/10/2020
+ Added: Debug page with multiple stats

7/10/2020
+ Added: Hardware page and save/load
+ Added: More packet structures and constants

6/10/2020
+ Added: Mutiple functions
* Fixed: UI redesigned

26/9/2020
+ Added: Structures and packet handling functions

18/9/2020
+ Added: GUI

17/9/2020
* Initial release