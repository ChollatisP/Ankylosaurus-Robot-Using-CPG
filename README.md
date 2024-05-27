# Ankylosaurus Robot

## Description

The goal of this Mini-Project is to design and develop a robotic system inspired by the Ankylosaurus, an armored dinosaur. This robot will utilize a Central Pattern Generator (CPG), Virtual Rhythmic Networks (VRNs), and Virtual Hormones to simulate the nervous system found in living organisms. 

## Table of Content
- Ankylosaurus-Robot-Using-CPG
  - Description
  - Table of Content
  - Concept
    - Hormone
    - CPG-VRN
    - Robot design
  - Part
    - Tail
    - Neck-Head
    - Body
    - Left-Rear-Leg
    - Right-Rear-Leg
    - Left-Front-Leg
    - Right-Front-Leg
  - Assembly
  - Component
    - Software
    - Hardware
  - Authors
  - Acknowledgments
    - Manual and Datasheet
    - Reference

## Concept

### - CPG and VRN

<p align="center">
  <img src="https://github.com/ChollatisP/Ankylosaurus-Robot-Using-CPG/assets/154317545/24042258-8aa3-4511-b7de-ab74b57d706e" width="300"/>
</p>
  
The robotic system, inspired by an ankylosaurus, features shoulder joints (M0-M3) and knee joints (M4-M7). SO2 is employed with O1 and O2 as outputs. Output from O1 controls knee joints, with weights of 1 and -1 causing Front Left and Rear Right knees to move in sync, while Front Right and Rear Left knees move oppositely, mimicking ankylosaurus limb coordination. Additionally, output from O2 is combined with Input 1 and 2 to allow inputs to influence shoulder movement, termed VRNs (Variable Response Networks), enabling input values to affect robot motion. 

### - Hormone

<p align="center">
  <img src="https://github.com/ChollatisP/Ankylosaurus-Robot-Using-CPG/assets/154317545/0db755f7-66a4-4fca-9a44-6b13c1f81264" width="700"/>
</p>

In our hormone system, we use the motor torque to represent the robot's fatigue. We calculate the sum of the servo torque over five time windows and determine the standard deviation (SD) of this torque. This SD is then used in the hormone equation:

Hc[t]=(a⋅SD(Torque))+(b⋅Hc[t−1])

where 
a (alpha) and 
b (beta) are constants. The output 
Hc from this equation is used to adjust the motor speed. This system allows the hormone levels to influence the walking speed of the robot.

### - Robot design

* Materials and Equipment
  - PLA
  - Acrylic,2 mm and 4 mm
  - Wooden board 4 mm
  - Bearing(623RS) 3 mm
  - Screw
  - Nut
  - Inner tube
  - PVC pipe

* Body
  * Reference
    <p align="center">
      <img src="https://github.com/ChollatisP/Ankylosaurus-Robot-Using-CPG/assets/154317545/37c52bce-65c4-4ef9-9caa-2a8e39d26326" width="500"/>
    </p>

  * After choosing the Ankylosaurus as a reference for our robot, we based our design on a four-legged animal. Studying the skeleton of the Ankylosaurus, which has different leg lengths, we designed the front legs to be 86 centimeters long and the rear legs to be 115 centimeters long.

  * Free body diagram and Calculate force max in the home position. [Click hear](https://github.com/ChollatisP/Ankylosaurus-Robot-Using-CPG/blob/main/Prove/Free_body_diagram.pdf)
  * Experiment
    * Design testing showed that one leg can support 1500 grams, allowing the robot to support a total weight of 3000 grams with two legs. The robot's overall weight is approximately 1500 grams, with a tolerance of up to 50 percent (or 1500 grams). [Click hear](https://github.com/ChollatisP/Ankylosaurus-Robot-Using-CPG/blob/main/Prove/Experiment.mp4)
    * Energy consumption. [Click hear](https://github.com/ChollatisP/Ankylosaurus-Robot-Using-CPG/blob/main/Prove/Battery_Calculation.pdf)

* Tail
  * Reference
    <p align="center">
      <img src="https://github.com/ChollatisP/Ankylosaurus-Robot-Using-CPG/assets/154317545/97f1a28b-8aec-4e17-a96e-8ee542018c32" width="450"/>
      <img src="https://github.com/ChollatisP/Ankylosaurus-Robot-Using-CPG/assets/154317545/e6935cec-1c71-4bc3-9a23-b6e6ac818ea6)" width="450"/>
    </p>

  * We design 3D-printable joints for assembling a tail using PLA filament, with a total weight of 36 grams. Drawing inspiration from dragon models, the joints feature a grab mechanism, enabling the tail to move left and right.

* Head
  * Reference
    <p align="center">
      <img src="https://github.com/ChollatisP/Ankylosaurus-Robot-Using-CPG/assets/154317545/3e25c1e6-cdeb-4427-aadf-12d72b768a26" width="450"/>
      <img src="https://github.com/ChollatisP/Ankylosaurus-Robot-Using-CPG/assets/154317545/652792c7-629e-4e3f-ad38-e2ccd06bdce9" width="450"/>
    </p>

  * We designed the head structure based on Ankylosaurus anatomy. Its structure is similar to that of a turtle. But it has sharp spines and bone-like armor to protect it from predators. We also designed the mouth to have a jaw-like structure. This allows the servo to control the movement of the mouth. It also has a long neck so that the servo can move the neck up and down.

## Part

### - Tail

<p align="center">
  <img src="https://github.com/ChollatisP/Ankylosaurus-Robot-Using-CPG/assets/154317545/eba4127e-1134-43ff-8ab5-4f68a62fa76f" width="700"/>
</p>

### - Neck-Head

https://github.com/ChollatisP/Ankylosaurus-Robot-Using-CPG/assets/154317545/061143af-20ef-42ed-8587-2f487bc01352

### - Body

https://github.com/ChollatisP/Ankylosaurus-Robot-Using-CPG/assets/154317545/31a39d6f-0629-42f6-9094-0288651878a0

### - Left-Rear-Leg

https://github.com/ChollatisP/Ankylosaurus-Robot-Using-CPG/assets/154317545/f0d755fc-a621-4187-81f4-3e616c87f374

### - Right-Rear-Leg

https://github.com/ChollatisP/Ankylosaurus-Robot-Using-CPG/assets/154317545/73323a92-11e0-47a3-b45a-8f9a36d1330e

### - Left-Front-Leg

https://github.com/ChollatisP/Ankylosaurus-Robot-Using-CPG/assets/154317545/a362d214-d938-400e-98b1-ab38c1122920

### - Right-Front-Leg

https://github.com/ChollatisP/Ankylosaurus-Robot-Using-CPG/assets/154317545/f60c23ce-5cd6-48cf-a238-8bfbbe61a805

## Assembly

https://github.com/ChollatisP/Ankylosaurus-Robot-Using-CPG/assets/154317545/6cbdc5d4-3189-4b34-b544-ea275060897f

## Component

### - Software

* [Arduino IDE](https://www.arduino.cc/en/software) (Any version)
  * Library
    * Normal
      * math.h
      * WiFi.h
      * PubSubClient.h
      * ESP32Servo.h
      * [How to install arduino library](https://support.arduino.cc/hc/en-us/articles/5145457742236-Add-libraries-to-Arduino-IDE) 

    * Additional

      * [SCS15 Servo arduino driver](https://github.com/IS2511/SCServo.git)

      * [How to install additional arduino library](https://docs.arduino.cc/software/ide-v1/tutorials/installing-libraries/)  

* SOLIDWORKS or Fusion 360 or any cad design software.

* RDWorksV8 (Laser Cut and Engrave Software)

* PrusaSlicer (Up to your 3D printer)

* [Node-RED](https://www.influxdata.com/blog/guide-installing-node-red/)

* [FD 1.9.8.2](https://github.com/ChollatisP/Ankylosaurus-Robot-Using-CPG/tree/main/Feetech%20SCSservo%20Software) (SCSservo Software)


### - Hardware

* Feetech SCS15 Motor 
   * quantity 8
 * FE-URT-1 
   * quantity 1
 * Step Down (LM2596) 
   * quantity 1
 * MG90S Servo Motor 
   * quantity 2
 * Arduimo UNO R4 WIFI 
   * quantity 1
 * Node32S
   * quantity 1
 * Photo Board (8.5*5.5 cm.)
   * quantity 1
 * 3000 mAh Li-Po Battery
   * quantity 1
 * Jumper wire

### - Diagram & Wiring

<p align="center">
  <img src="https://github.com/ChollatisP/Ankylosaurus-Robot-Using-CPG/assets/154317545/217aee18-ee77-4d6e-bcb5-e33e80466897" width="500"/>
  <img src="https://github.com/ChollatisP/Ankylosaurus-Robot-Using-CPG/assets/154317545/2c12d810-dc2b-4f72-a08a-95d1fe9f8f5f" width="500"/>
</p>

## Group members 

* Nipitpon Phumchoedchan 6452500015 (Hormone system Design and Coding)

* Chollatis Petchsing 6452500023 (CPG and VRN Coding)

* Akaraphon Trakoolwiya 6452500180 (Mechanic and Desiner)

* Kantawit Panyateang 6452500198 (Head of Mechanic and Desiner)

* Wiraphat panma 6452500350 (Mechanic and Desiner)

* Komgrid Petchpayub 6452500392 (Project Manager)

## Acknowledgments
### - Manual and Datasheet

* [Arduino® UNO R4 WiFi](https://docs.arduino.cc/resources/datasheets/ABX00087-datasheet.pdf)

* [Servo motor SCS 15](https://www.feetechrc.com/Data/feetechrc/upload/file/20201127/start%20%20tutorial201015.pdf)

* [Servo motor SCS 15 manual](https://grobotronics.com/images/companies/1/datasheets/SCS15&SCS115%20Manual.pdf?1516269264467)

* [FE-URT-1](https://www.mantech.co.za/datasheets/products/FE-URT-1%20specs.pdf)

* [Step Down (LM2596)](https://www.ti.com/lit/ds/symlink/lm2596.pdf)

* [MG90S Servo Motor](https://www.electronicoscaldas.com/datasheet/MG90S_Tower-Pro.pdf)

* [Node32S](https://www.es.co.th/Schemetic/PDF/ESP32.PDF)

### - [Reference](https://github.com/ChollatisP/Ankylosaurus-Robot-Using-CPG/tree/main/Reference)
