### 1 - Introduction:
Hi! Line Follower Robot - Proyecto V2, is the second version of my line follower. The old one had some design flaws which I had solved in this design. So what I have made is a LFR with four TT motors for movement which will be paired with soft rubber tyre for extra traction as line followers need traction. Im using arduino nano for all the main processing, TB6612FNG as the motor driver for controlling the motors. What I have improved is that I have added a a 5 Channel TCRT5000 Array at the very front, which will be primarily detecting the line behind are two individual TCRT5000 Sensors on both sides that will be mainly used for detecting intersections and will also assist with turns. Two LEDs are also added that will turn on when the respective turn is being executed this will help in debugging and during a competition if the wrong LED turns on Ill know it will go off course and Ill be able to take the retry earlier instead of wasting time waiting for the robot to go off track. Lastly Im using a custom OS on the OLED which will show a starting animation which is also skippable then it will show multiple menu options. I have been working on it for about 4 months and its about to be completed but due to my upcoming final exams I have to delay it. The menu options will compromise of BLACK LINE, WHITE LINE, SENSOR CALIBRATION, MOTOR CALIBRATION, DIGITAL VALUES, and ANALOG VALUES. These modes will be selected through the installed four push buttons assigned as OKAY, CANCEL, UP and DOWN. My target is to make an OS which works like a programmer means during competition it will not leave the need of a laptop to change settings. All the threshold changes, sensor calibration and motor speed will be able to be changed using the buttons and the OS will make the robot more competitive and faster to edit the code instead of opening the laptop, going to the code file, changing the values and then finally uploading. 

### 2 - Reason for Making Proyecto:
Since 2020, I have been participating in national level events in Pakistan. At the start I used to participate at middle - high school competition but due to lack of competitiveness I moved towards university competitions. In which I have been victorious, I have won over 9+ national events University level last year alone. Due to being the only high schooler in the competitions the Unversity's directors had regarded and mentioned us too. They offered us different opportunities such as using their labs (tools not electronics) for creating our robot and for conducting team meetings. Regardless due to my interest in robotics I had been doing it and participating in competitions representing my school as well as my private robotics team. This robot is mainly for competition participation but after this robot Ill be moving towards encoders EDFs to provide enough down force allowing my robot to trace line even on the wall. This robot will be the most advance robot that I have worked on and after it Ill either make the EDF and encoder LFR afterwards or make a sumo robot afterwards. Either way Ill be making a sumo bot too. This robot will serve as the base for my future endeavors as Ill be doing different tests on it and will have to find a new a microcontroller faster, more pins and without any wifi or bt built in. Most probably tennesy 4.0.

### 3 - Usage:
Now lastly. How to operate Proyecto? Opearting Proyecto is very easy. First you will have to connect the battery connectors which will power up the circuit. After it the OLED will also lit up and start the animation with the robot name and the team name, if you want you can skip the animation by clicking the OKAY button. Once skipped or if the animation has completed the screen will show menu options through them you can scroll UP and DOWN through pressing the respective button and to select a function you will have to press OKAY then you will enter that mode, clicking OKAY will make the robot do the task (Sensor Readings, Line Following, etc). If you want to stop the robot from doing a specific task you can press the CANCEL button it will bring you back to the menu option. The robot can follow black line, white line and also can shift mid line tracing like after black line white lines starts it will adapt.

### 4 - Circuit Diagram:
![Circuit Diagram](1%20-%20Circuit%20Diagram/LFR%20Proyecto%20V2%20-%20Circuit%20Diagram.png)

### 5 - 3D Model:
<div style="display:flex; gap:12px; align-items:center;">
  <img src="4%20-%20Pictures%20of%203D%20Model/2%20-%20Left%20Side%20VIew.png" width="280">
  <img src="4%20-%20Pictures%20of%203D%20Model/1%20-%20Top%20VIew.png" width="280">
  <img src="4%20-%20Pictures%20of%203D%20Model/3%20-%20Right%20Side%20VIew.png" width="280">
</div>

### 6 - Bill of Materials (BOM):
| #  | Component           | Specification / Notes                 | Quantity | Unit Price (USD) | Total (USD) | Link |
|----|-------------------|-------------------------------------|----------|-----------------|------------|------|
| 1  | Motor Driver       | TB6612FNG Dual Motor Driver          | 2        | 5.95            | 11.90      | [Pololu](https://www.pololu.com/product/713) |
| 2  | Microcontroller    | Arduino Nano (ATmega328P, 5V)       | 3        | 4.33            | 12.99      | [Amazon](https://www.amazon.com/AYWHP-ATmega328P-Microcontroller-Compatible-Arduino/dp/B0DFGX3MSL/) |
| 3  | Display            | OLED Display Module                   | 1        | 19.25           | 19.25      | [Pololu](https://www.pololu.com/product/3761) |
| 4  | Battery            | 11.1V 2200mAh 3S 100C LiPo           | 1        | 43.99           | 43.99      | [Spektrum](https://www.spektrumrc.com/product/11.1v-2200mah-3s-100c-smart-lipo-battery-ic3/SPMX22003S100.html) |
| 5  | IR Sensor Array    | 5-Sensor Array Board                  | 1        | 4.55            | 4.55       | [JSumo](https://www.jsumo.com/5-sensor-array-board) |
| 6  | IR Sensor          | TCRT5000 Infrared Sensor Module       | 5        | 1.578           | 7.89       | [Amazon](https://www.amazon.com/HiLetgo-TCRT5000-Intelligent-Infrared-Tracking/dp/B082WZZJ58/) |
| 7  | DC Gear Motor      | TT Metal Gear Motor (3V–6V)           | 4        | 2.495           | 9.98       | [Amazon](https://www.amazon.com/4Pcs-Metal-Motor-3V-6V-Ratio/dp/B099MX2J5B/) |
| 8  | Wheels             | 55×40 mm Robot Wheels (Pair)          | 2        | 33.00           | 66.00      | [JSumo](https://www.jsumo.com/jsumo-robot-wheel-55x40mm-pair) |
| 9  | Buck Converter     | LM2956 Adjustable Step-Down Converter | 2        | 3.995           | 7.99       | [Amazon](https://www.amazon.com/Converter-Adjustable-Regulator-Voltmeter-Display%EF%BC%88Pack/dp/B0F1M2SR31/) |
| 10 | Push Buttons       | 6×6×4.5 mm Momentary Tactile Switch   | 100      | 0.0499          | 4.99       | [Amazon](https://www.amazon.com/DAOKI-100Pcs-6x6x4-5mm-Momentary-Tactile/dp/B07XF3YMJ4/) |

**Total Cost: $189.54 USD**




