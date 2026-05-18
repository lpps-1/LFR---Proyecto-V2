### 1 - Introduction:
Hi! Line Follower Robot - Proyecto V2, is the second version of my line follower. The old one had some design flaws which I had solved in this design. So what I have made is a LFR with four TT motors for movement which will be paired with soft rubber tyre for extra traction as line followers need traction. Im using arduino nano for all the main processing, TB6612FNG as the motor driver for controlling the motors. What I have improved is that I have added a a 5 Channel TCRT5000 Array at the very front, which will be primarily detecting the line behind are two individual TCRT5000 Sensors on both sides that will be mainly used for detecting intersections and will also assist with turns. Two LEDs are also added that will turn on when the respective turn is being executed this will help in debugging and during a competition if the wrong LED turns on Ill know it will go off course and Ill be able to take the retry earlier instead of wasting time waiting for the robot to go off track. Lastly Im using a custom OS on the OLED which will show a starting animation which is also skippable then it will show multiple menu options. I have been working on it for about 4 months and its about to be completed but due to my upcoming final exams I have to delay it. The menu options will compromise of BLACK LINE, WHITE LINE, SENSOR CALIBRATION, MOTOR CALIBRATION, DIGITAL VALUES, and ANALOG VALUES. These modes will be selected through the installed four push buttons assigned as OKAY, CANCEL, UP and DOWN. My target is to make an OS which works like a programmer means during competition it will not leave the need of a laptop to change settings. All the threshold changes, sensor calibration and motor speed will be able to be changed using the buttons and the OS will make the robot more competitive and faster to edit the code instead of opening the laptop, going to the code file, changing the values and then finally uploading. 

### 2 - Reason for Making Proyecto:
Since 2020, I have been participating in national level events in Pakistan. At the start I used to participate at middle - high school competition but due to lack of competitiveness I moved towards university competitions. In which I have been victorious, I have won over 9+ national events University level last year alone. Due to being the only high schooler in the competitions the Unversity's directors had regarded and mentioned us too. They offered us different opportunities such as using their labs (tools not electronics) for creating our robot and for conducting team meetings. Regardless due to my interest in robotics I had been doing it and participating in competitions representing my school as well as my private robotics team. This robot is mainly for competition participation but after this robot Ill be moving towards encoders EDFs to provide enough down force allowing my robot to trace line even on the wall. This robot will be the most advance robot that I have worked on and after it Ill either make the EDF and encoder LFR afterwards or make a sumo robot afterwards. Either way Ill be making a sumo bot too. This robot will serve as the base for my future endeavors as Ill be doing different tests on it and will have to find a new a microcontroller faster, more pins and without any wifi or bt built in. Most probably tennesy 4.0.

### 3 - Usage:
Now lastly. How to operate Proyecto? Opearting Proyecto is very easy. First you will have to connect the battery connectors which will power up the circuit. After it the OLED will also lit up and start the animation with the robot name and the team name, if you want you can skip the animation by clicking the OKAY button. Once skipped or if the animation has completed the screen will show menu options through them you can scroll UP and DOWN through pressing the respective button and to select a function you will have to press OKAY then you will enter that mode, clicking OKAY will make the robot do the task (Sensor Readings, Line Following, etc). If you want to stop the robot from doing a specific task you can press the CANCEL button it will bring you back to the menu option. The robot can follow black line, white line and also can shift mid line tracing like after black line white lines starts it will adapt.

### 4 - Circuit Diagram:
![Circuit Diagram](1%20-%20Circuit%20Diagram/LFR%20Proyecto%20V2%20-%20Circuit%20Diagram.png)

### 5 - 3D Model:


TinkerCAD Links:
* [Proyecto V2](https://www.tinkercad.com/things/l9xJPmTRQzA-proyecto-v2?sharecode=hnvhtCH3v41c5K6T4RtM-VqiNpLFxgLBMW4Wglu9lU8)
* [Proyecto V2 - Electronics](https://www.tinkercad.com/things/5jzzp9ZvHWP-proyecto-v2-electronics?sharecode=e8wKs22imAD4GBXbVjDw6fI7VKfM8FQWDofzuGclVWU)
  
<div align="center">
  <table border="0">
    <tr>
      <td align="center" colspan="2">
        <p><strong>Top View</strong></p>
        <img src="4%20-%20Pictures%20of%203D%20Model/Without%20Electronics/1%20-%20Top%20VIew.png" width="350">
      </td>
    </tr>
    <tr>
      <td align="center">
        <p><strong>Left Side View</strong></p>
        <img src="4%20-%20Pictures%20of%203D%20Model/Without%20Electronics/2%20-%20Left%20Side%20VIew.png" width="280">
      </td>
      <td align="center">
        <p><strong>Right Side View</strong></p>
        <img src="4%20-%20Pictures%20of%203D%20Model/Without%20Electronics/3%20-%20Right%20Side%20VIew.png" width="280">
      </td>
    </tr>
    <tr>
      <td align="center" colspan="2">
        <p><strong>Back View</strong></p>
        <img src="4%20-%20Pictures%20of%203D%20Model/Without%20Electronics/4%20-%20Back%20Side%20VIew.png" width="350">
      </td>
    </tr>
  </table>
</div>

### 6 - Bill of Materials (BOM):
### Project Component List

| Name | Quantity | Total Price (USD) | Link |
| :--- | :--- | :--- | :--- |
| TB6612FNG Motor Driver | 5x | $5.74 | [aliexpress.com](https://www.aliexpress.com/item/1005010405309752.html) |
| Arduino Nano | 5x | $14.06 | [aliexpress.com](https://www.aliexpress.com/item/1005006725908213.html) |
| Oled Screen 1.3" | 4x | $7.24 | [aliexpress.com](https://www.aliexpress.com/item/1005008365029314.html) |
| Lipo 3s | 1x | $30.21 | [hobbylobby.com.pk](https://www.hobbylobby.com.pk/product/gen-ace-lipo-2200mah-3s-35c) |
| TCRT5000 5 Channel Array | 5x | $8.58 | [aliexpress.com](https://www.aliexpress.com/item/1005008733257121.html) |
| TCRT5000 Individual | 10x | $4.66 | [aliexpress.com](https://www.aliexpress.com/item/32866136486.html) |
| TT Motors | 4x | $9.72 | [aliexpress.com](https://www.aliexpress.com/item/1005006964177842.html) |
| Rubber Wheels Pair | 4x | $29.48 | [aliexpress.com](https://www.aliexpress.com/item/1005009333838697.html) |
| 6mm Hex Coupler | 4x | $7.36 | [aliexpress.com](https://www.aliexpress.com/item/1005009683741921.html) |
| Buck Convertor LM2956 | 5x | $6.52 | [aliexpress.com](https://www.aliexpress.com/item/1005010400036740.html) |
| Push Buttons | 1000x | $12.42 | [aliexpress.com](https://www.aliexpress.com/item/33029546857.html) |
| Perf Board | 1x | $10.55 | [aliexpress.com](https://www.aliexpress.com/item/1005007977139251.html) |
| Shrink Tube | 1x | $7.47 | [aliexpress.com](https://www.aliexpress.com/item/4000200124003.html) |
| Breadboard Hard Wires | 1x | $7.20 | [aliexpress.com](https://www.aliexpress.com/item/1005007079142852.html) |
| Male to Female Wires | 1x | $1.99 | [aliexpress.com](https://www.aliexpress.com/item/1005008070896908.html) |
| Male to Male Wires | 1x | $1.99 | [aliexpress.com](https://www.aliexpress.com/item/1005008070896908.html) |
| Female to Female Wires | 1x | $1.23 | [aliexpress.com](https://www.aliexpress.com/item/1005008070896908.html) |
| Female Header Pins | 1x | $1.99 | [aliexpress.com](https://www.aliexpress.com/item/1005010604381492.html) |
| Male Header Pins | 1x | $8.52 | [aliexpress.com](https://www.aliexpress.com/item/1005005509891182.html) |
| **Taxes** | - | $113.62 | N/A |
| **Shipping** | - | $9.69 | N/A |
| **Total Cost** | - | **$306.16** | N/A |

> 



