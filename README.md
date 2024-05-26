# Ankylosaurus Robot

## Description

The goal of this Mini-Project is to create a robot that inspired by Ankylosuarus and using Central Pattern Generator (CPG), VRNs and also Virtual Hormones to simulate nervous system in 
living things. 


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
    - Manual
    - Library

## Concept

### - CPG and VRN

![Screenshot 2024-05-26 225831](https://github.com/ChollatisP/Ankylosaurus-Robot-Using-CPG/assets/154317545/24042258-8aa3-4511-b7de-ab74b57d706e)

  * From this picture. We assign M4-M7 as an Knee Joint and assign M0-M3 as an Shoulder Joint of our Ankylosaurua robot. So we use SO2 an Assign as O1 and O2. 
    * At O1, we use output from O1 to control Knee Joint an we use 1 and -1 as a weight of O1 os output from O1 will perform as Front Left Knee and Rear Right Knee will moving in the same direction and al Front Right Knee and Rear Left Knee

### - Hormone

![Subheading](https://github.com/ChollatisP/Ankylosaurus-Robot-Using-CPG/assets/154317545/70354047-444d-4235-b26e-a5317d0c8089)


## Part

### - Tail

![Tail](https://github.com/ChollatisP/Ankylosaurus-Robot-Using-CPG/assets/154317545/eba4127e-1134-43ff-8ab5-4f68a62fa76f)

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
 
## Group members 
+
* Nipitpon Phumchoedchan 6452500015 (Hormone system Design and Coding)

* Chollatis Petchsing 6452500023 (CPG and VRN Coding)

* Akaraphon Trakoolwiya 6452500180 (Mechanic and Desiner)

* Kantawit Panyateang 6452500198 (Head of Mechanic and Desiner)

* Wiraphat panma 6452500350 (Mechanic and Desiner)

* Komgrid Petchpayub 6452500392 (Project Manager)

## Acknowledgments
### Manual and Datasheet

* [Arduino® UNO R4 WiFi](https://docs.arduino.cc/resources/datasheets/ABX00087-datasheet.pdf)

* [Servo motor SCS 15](https://www.feetechrc.com/Data/feetechrc/upload/file/20201127/start%20%20tutorial201015.pdf)

* [Servo motor SCS 15 manual](https://grobotronics.com/images/companies/1/datasheets/SCS15&SCS115%20Manual.pdf?1516269264467)

