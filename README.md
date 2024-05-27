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
  <img src="https://github.com/ChollatisP/Ankylosaurus-Robot-Using-CPG/assets/154317545/70354047-444d-4235-b26e-a5317d0c8089" width="700"/>
</p>

In our hormone system, we use the motor torque to represent the robot's fatigue. We calculate the sum of the servo torque over five time windows and determine the standard deviation (SD) of this torque. This SD is then used in the hormone equation:

Hc[t]=(a⋅SD(Torque))+(b⋅Hc[t−1])

where 
a (alpha) and 
b (beta) are constants. The output 
Hc from this equation is used to adjust the motor speed. This system allows the hormone levels to influence the walking speed of the robot.

### - Robot design

* Body
    - After choosing the Ankylosaurus as a reference for our robot, we based our design on a four-legged animal. Studying the skeleton of the Ankylosaurus, which has different leg lengths, we designed the front legs to be 86 centimeters long and the rear legs to be 115 centimeters long.

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
