# Cyber-physical-systems-project
LEGO Mindstorms EV3 robot programming with C++, Matlab, Simulink and LabVIEW

Task 1

In this Task, the robot shall be programmed in a way that it can drive towards an object autonomously and can follow a moving object.
Initially the robot shall be in the state Standby. After pressing the touch sensor, the robot shall enter the state Active. Another push and the robot shall re-enter the Standby
state. The ultrasonic sensor shall evaluate the surrounding and check for objects. The object recognition shall be only activated in the Active state. In case the robot is in the Active state, it shall drive towards the nearest object. If no object is in reach, the robot shall stop. The robot shall also stop if the distance towards the nearest object is too little.

Software: C++

Task 2

In this Task, the robot shall follow a line which is placed on the floor (more detailed: the left edge of that line) and simultaneously keep a minimum distance of 20 cm to
a possible robot in front. After turning on the robot, it should do small rotation to both directions in order to determine the brightness values of the surface. While this
calibration the text “Calibrating color values...” should be printed on the display of the EV3. Afterwards the robot shall be in the state Ready. The display shall now show
“Calibrated. Press touch sensor to start.”. The Active state shall be entered after pressing the touch sensor. In this state the robot shall follow the line and keep the mentioned minimum distance of 20 cm. The display text shall be changed to “Now driving.”. If the touch sensor is pressed again, the robot shall re-enter the Ready state. In case the robot can not find the edge of the line for more than 2 seconds, it should stop and signalize an error via showing “Help!” on the display.

Software: LabVIEW

Task 3

In this Task the robot will perform the same functionality as described in the Task 1, but this time with the Matlab/Simulink software. Instead of the previous control written in C++, a PI-controller and a PID-controller is designed for this purpose. 

Software: Matlab/Simulink
