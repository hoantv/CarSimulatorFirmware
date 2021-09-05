02/09/2021 2.6.1.4
+ Added: Constraints to grid lines' positions when doing auto adjustment
* Fixed: Empty newline in log files
+ Added: Some more logs to shifter calibration
* Fixed: Shifter grid scaling issue
* Fixed: Removed wheelbase compatibility warning for 2.6.x

29/08/2021 2.6.1.3
* Fixed: Frame scaling issue on high dpi screens

23/08/2021 2.6.1.3
* Fixed: Old Handbrake presets backwards compatibility
* Fixed: Old wheelbase profile backwards compatibility
* Fixed: Enabled indentation to saved json files

23/08/2021 2.6.1.2
* Fixed: Broken query input function 

22/08/2021 2.6.1.2
* Fixed: Ack command now requires objects to work properly
+ Added: Save/load shifter customcolors to/from configuration file
* Fixed: Device manager initialization issue

20/08/2021 2.6.1.1
* Fixed: Increased CmdQueue size from 10 to 32
* Fixed: Minor TvDevice adjustments
* Fixed: SendQueue procedure using constants as parameters

04/08/2021 2.6.1.1
* Fixed: Pedal presets

03/08/2021 2.6.1.1
* Fixed: Changed pedal axis min/max to signed int
* Fixed: Moved log related functions from main form
* Fixed: Adjusted some packet constants
+ Added: Pedal preference page
+ Added: Load shaping preset when selecting axis
* Fixed:  Pedal chart and UI adjustments

02/08/2021 2.6.1.1
+ Added: Pedal packet handling procedures
+ Added: 0xA3DF as Pedal PID
+ Added: Handbrake axis to pedal page
* Fixed: Logging levels reworked

01/08/2021 2.6.1.1
* Fixed: Adjusted logging functions
+ Added: Implemented ILogEvent interface
+ Added: Internal eventbus

24/07/2021 2.6.1.1
* Fixed: Device Manager minor adjustments
* Fixed: Invalid current pedal device

18/07/2021 2.6.1.1
* Fixed: Forced log window to stick with main window
* Fixed: Replaced embedded forms with frames

18/07/2021 2.6.0.4
* Fixed: Updater failed with path containing spaces
* Fixed: Shifter grid over-scaled issue
* Fixed: UI adjustments

17/07/2021 2.6.0.4
* Fixed: Improved image transparency
* Fixed: Shifter crosshair coords not correctly scaled on high dpi screens

07/07/2021 2.6.0.3
+ Added: Shifter - Static LED color

06/07/2021 2.6.0.3
+ Added: $A3D7 as shifter PID
* Fixed: Another attempt to fix Panel Slider AV

04/07/2021 2.6.0.3
* Fixed: Constraints added to some windows
+ Added: Current counters to Stats window
* Fixed: Replaced MessageDlg in some units
+ Added: Debug LED effect values
* Fixed: Code refactorings

03/07/2021 2.6.0.3
+ Added: Device Stats window (showing message rate)
* Fixed: Renamed command messages
+ Added: Balloon help for Effect group

02/07/2021 2.6.0.3
+ Added: Balloon help for advanced filter
* Fixed: Increased groupboxes caption height by 2px  on high dpi screens

30/06/2021 2.6.0.2
* Fixed: High dpi scaling issue on Debug window and Serial Port window
+ Added: Left margin to combobox items
* Fixed: Replaced scrolling info with faded info
* Fixed: Vertical aligned most of the components
* Fixed: Disabled AutoSize property on all edit boxes
* Fixed: Grid lines dragging on high dpi screens
* Fixed: Shifter grid on high dpi screens
* Fixed: Ring images on high dpi screens
* Fixed: Statusbar icons on high dpi screens

29/06/2021 2.6.0.2
* Fixed: Multiple scaling issues on high dpi screens

28/06/2021 2.6.0.1
* Fixed: Replaced some icons with png
* Fixed: Incorrect scaling on high-dpi screens

27/06/2021 2.5.1.4
* Fixed: Simplified axis labels
* Fixed: Axis enabling sliders not working correctly when dragging

24/06/2021 2.5.1.3
+ Added: Shifter; led speed and brightness configurable options

22/06/2021 2.5.1.3
* Fixed: Auto grid adjustments failed to work when gear 11 or 12 is on

22/06/2021 2.5.1.2
* Fixed: Flickering when changing gear 11 or 12
* Fixed: Shifter code cleanups
+ Added: Shifter; auto adjusting grid lines after finishing calibration

15/06/2021 2.5.1.2
* Fixed: Re-enabled shifter gear 11 and 12 states (for truck)
* Fixed: Removed shifter gear 9

11/06/2021 2.5.1.2
* Fixed: Hide related tabs on Preferences page if no relevant device selected
+ Added: Handbrake initialized RXMin/Max options

10/06/2021 2.5.1.2
+ Added: QueueDelayMs option. Default: 500 ms

09/06/2021 2.5.1.1
* Fixed: Improved packet queue system to prevent duplicate queue items
* Fixed: Shifter selector not working
* Fixed: Normalized sent packets
+ Added: [IN] and [OUT] to packet logs
+ Added: CaptureRawSendPkts option

08/06/2021 2.5.1.1
* Fixed: Replaced MessageBox with a custom confirmation dialog
* Fixed: Version check when doing update

07/06/2021 2.5.0.2
+ Added: Auto select devices when related tabs are showing
+ Added: Load shifter positions once when loading config

04/06/2021 2.5.0.1
+ Added: Background on device count (status bar)
* Fixed: Attempted to fix AV when auto closing device panel
+ Added: Implemented new Packet queue system 
* Fixed: Wheelbase axis max collision with pedal axis max
+ Added: Hints on axis bars (pedal, handbrake)
* Fixed: Separated request queue for each device

03/06/2021 2.5.0.1
* Fixed: Loadmotor config on startup to sync advanced filter max values
* Fixed: CapturePkts option not loaded at startup
* Fixed: Device selection reworked
* Fixed: Specify objects when sending packets
+ Added: Pedal shaping load/save procedures
* Fixed: Refactored packet related constants
* Fixed: Code cleanups

02/06/2021 2.4.0.2
+ Added: Drop packet when the size exceeds 64 bytes
* Fixed: Recalculated command checksums
+ Added: Device disconnection notification
+ Added: Some more internal procedures for Pedal
* Fixed: DeviceManager reworked
+ Added: Pedal plugin handler
* Fixed: Config strings efactoring

01/06/2021 2.4.0.1
+ Added: Custom inputquery function
+ Added: Pedal device support
* Fixed: Refactored huge amount of code to support Pedal
+ Added: Pedal page with presets management feature
+ Added: Considered wheelbase as a multi-device
* Fixed: AV when removing a corrupted device (unamed)
+ Added: Warning message when using 0.x wheelbase firmwares
* Fixed: Supported new wheelbase version (1.x)

30/05/2021 2.3.1.1
* Fixed: Attempted to avoid RichEdit line insertion error

30/05/2021 2.3.1.0
* Fixed: Adjusted handbrake page
* Fixed: Wheelbase debug mode being disabled
* Fixed: AV when closing wheel test window while doing the test
* Fixed: Disabled wheel test when a working wheelbase is connected
+ Added: Configurable max angle (Preferences/Wheelbase). Default: 1080, max: 7200

29/05/2021 2.3.1.0
+ Added: General option to capture recv packets and save to debug.log

29/05/2021 2.3.0.4
* Fixed: Issues with data handling between firmwares and UI
* Fixed: Replaced bool with Boolean to avoid data type incorrectness

27/05/2021 2.3.0.4
* Fixed: TPanelSlider; replaced SetPanel procedure with published Panel property

24/05/2021 2.3.0.4
* Fixed: Changed Show Devices menu to Show/Hide Devices
* Fixed: DeviceManager; Autohiding triggers immediately on the first show
* Fixed: Incorrect theme cursor on some components
* Fixed: Changed pressed shifter button color from clGreen to clLime
* Fixed: Shifter page minor adjustments

22/05/2021 2.3.0.3
* Fixed: Update check not working 
+ Added: Embedded libeay32.dll and ssleay32.dll for SSL connections

20/05/2021 2.3.0.3
+ Added: Wheel animation test form (Dbl click on the wheel image)

20/05/2021 2.3.0.2
+ Added: Device count on status icon
* Fixed: Removed device selection restriction on device arrival

19/05/2021 2.3.0.2
* Fixed: Check device when loading shifter configuration

18/05/2021 2.3.0.2
* Fixed: Disable deviceupdates when form not fully initialized to avoid AV

17/05/2021 2.3.0.1
+ Added: Help file

16/05/2021 2.3.0.1
* Fixed: Add size constraints to Log window
* Fixed: Refactored all json related procedures
+ Added: TRec4Json class for record de/serialization

15/05/2021 2.3.0.1
+ Added: Handbrake RX real time drawing serie
* Fixed: Some incorrect label sizes on debug page
* Fixed: Moved debug tab to a separated form (embedded)
* Fixed: Replaced standard confirmation/information dialogs with a custom dialog

14/05/2021 2.3.0.1
* Fixed: Wheel angle step not correctly loaded from saved config
* Fixed: Code refactored 1

14/05/2021 2.2.1.6
+ Added: Custom HPresets save/load
+ Added: Configurable Handbrake RBuf Size
+ Added: Read handbrake config feature

13/05/2021 2.2.1.5
+ Added: Read chart points from device
+ Added: Load handbrake version info

12/05/2021 2.2.1.5
* Fixed: logs directory not created automatically
* Fixed: A bug where xAxis slider can be changed
+ Added: Handbrake supported when clicking on Device on DevPanel
+ Added: Sine preset & fixed map function
* Fixed: Broken Show Log function when ShowLogWindow config set to False
+ Added: Some handbrake presets
+ Added: Handbrake device supported
* Fixed: Device plug/unplug issues

11/05/2021 2.2.0.4
+ Added: Internal handbrake related procedures
* Fixed: Cleanups
+ Added: Enabled IMAGE_FILE_RELOCS_STRIPPED flag
+ Added: Configurable wheel angle step

10/05/2021 2.2.0.3
* Fixed: Incorrect wheel animation angle

09/05/2021 2.2.0.2
* Fixed: Refactored theme selection function
+ Added: Settings saved to statusbar
* Fixed: Adjusted Settings page (changed OK to Save)
+ Added: Replaced TCustomControl with TEsCustomControl on some component for flicker-free
+ Added: Internal functions/procedures for Handbrake

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