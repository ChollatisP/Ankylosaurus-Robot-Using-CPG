#include<math.h>
#include <SCServo.h>
#define GPIO_PIN_1 7 // กำหนดหมายเลขของ GPIO ที่ต้องการใช้รับข้อมูล 1
#define GPIO_PIN_2 4 // กำหนดหมายเลขของ GPIO ที่ต้องการใช้รับข้อมูล 2
SCSCL sc;

float MI = 0.1;
#define Alpha 1.01
#define phi M_PI/6
float speed = 700 ;
const int arraySize = 9;
float sensorValues[arraySize];
float sensorValues2[arraySize];
int currentIndex = 0;
int currentIndex1 = 0;
float Hc[2] = {0, 0};
float Hc2[2] = {0, 0};
const long interval12 = 250; 
const long interval1 = 250; 
unsigned long previousMillis12 = 0;
unsigned long previousMillis1 = 0;
//----------W_for_CPG--------//
/*#define w11 1.5//Alpha*(cos(phi+MI))//1.5
#define w22 1.5//Alpha*(cos(phi+MI))//1.5
#define w12 -(0.4+MI)//Alpha*(-sin(phi+MI))//-(0.6+MI)
#define w21 0.4+MI//Alpha*(sin(phi+MI))//0.6+MI
*/
float w11 = Alpha*(cos(phi+MI));//1.5
float w22 = Alpha*(cos(phi+MI));//1.5
float w12 = Alpha*(-sin(phi+MI));//-(0.6+MI)
float w21 = Alpha*(sin(phi+MI));//0.6+MI
#define w_for_C3579_and_o2 1.7246
#define w_for_C46810_and_o2 -1.7246
#define w_for_C36710_and_oinput 1.7246
#define w_for_C4589_and_oinput -1.7246
#define w_for_C11and12minus -0.5
#define w_for_C11and12plus 0.5

#define C1 0.5
#define C2 0.5
#define BIAS -2.48285
#define CPG_BIAS 0.01
#define Motor_4to7_Bias -0.5

//-----------W_for_M------------//
#define weight_for_M_4and7 -1
#define weight_for_M_5and6 1
#define weight_for_M_0and3 -1.3
#define weight_for_M_1and2 1.3

//------------MinMaxforMotor------------//
/*#define M0_MAX 0.774393239//0.15
#define M0_MIN -0.775747801//-0.2
#define M1_MAX 0.775747801//0.2
#define M1_MIN -0.774393239//-0.15
#define M2_MAX 0.418318016//0.2
#define M2_MIN 0.367229335//-0.2
#define M3_MAX -0.367229335//0.2
#define M3_MIN -0.418318016//-0.2
#define M4_MAX 0.425807758//-0.3
#define M4_MIN -1.430628636//-0.7
#define M5_MAX 0.430628636//-0.3
#define M5_MIN -1.425807758//-0.7
#define M6_MAX 0.430628636//-0.3
#define M6_MIN -1.425807758//-0.7
#define M7_MAX 0.425807758//-0.3
#define M7_MIN -1.430628636//-0.7

*/
#define M0_MAX 0.15
#define M0_MIN -0.2
#define M1_MAX 0.2
#define M1_MIN -0.15
#define M2_MAX 0.2
#define M2_MIN -0.2
#define M3_MAX 0.2
#define M3_MIN -0.2
#define M4_MAX 0-0.3
#define M4_MIN -0.7
#define M5_MAX -0.3
#define M5_MIN -0.7
#define M6_MAX -0.3
#define M6_MIN -0.7
#define M7_MAX -0.3
#define M7_MIN -0.7

int INPUT1 = -2;
int INPUT2 = 1;
float O_INTPUT1 = tanh(INPUT1);
float O_INTPUT2 = tanh(INPUT2);

//----------CPG-Value---------//
float Current_C1_Values;
float Current_C2_Values;
float Current_O1_Values;
float Current_O2_Values;
float Prev_C1_Values;
float Prev_C2_Values;
float Prev_O1_Values;
float Prev_O2_Values;
float C3_Values;
float C4_Values;
float C5_Values;
float C6_Values;
float C7_Values;
float C8_Values;
float C9_Values;
float C10_Values;
float C11_Values;
float C12_Values;
float O3_Values;
float O4_Values;
float O5_Values;
float O6_Values;
float O7_Values;
float O8_Values;
float O9_Values;
float O10_Values;
float O11_Values;
float O12_Values;

//---------Motor_home_positon---------//
#define M0_Home 420
#define M1_Home 400
#define M2_Home 500
#define M3_Home 600
#define M4_Home 520
#define M5_Home 450
#define M6_Home 600
#define M7_Home 520


//------------Motor_define_shoulder-----------//
#define M0 12
#define M1 7
#define M2 9
#define M3 6
//------------Motor_define_foot-----------//
#define M4 11
#define M5 8
#define M6 10
#define M7 5

/*
#define M4 12
#define M5 7
#define M6 9
#define M7 6
//------------Motor_define_foot-----------//
#define M0 11
#define M1 8
#define M2 10
#define M3 5
*/
//--------------Motor_value--------------//
float M0val,M1val,M2val,M3val,M4val,M5val,M6val,M7val;

//----------Motor-limitation---------------//
//ขาหน้าขวา
#define MIN_ID11 360 //ยกขาลง
#define MAX_ID11 560  //ยกขาขึ้น
#define MIN_ID12 420 //ก้าวขาหน้า
#define MAX_ID12 520  //ก้าวขาถอย

//ขาหน้าซ้าย
#define MIN_ID9 500//ยกขาลง
#define MAX_ID9 600//ยกขาขึ้น
#define MIN_ID10 500  //ก้าวขาถอย
#define MAX_ID10 700  //ก้าวขาหน้า

//ขาหลังขวา
#define MIN_ID7 382 //ยกขาลงสุด
#define MAX_ID7 582 //ยกขาขึ้นสุด
#define MIN_ID8 540 //ก้าวขาหน้า(เดินหน้า) 152-342
#define MAX_ID8 340 //ก้าวขาถอยหลัง(ถอยหลัง)

//ขาหลังซ้าย
#define MIN_ID5 650  //ยกขาขึ้น
#define MAX_ID5 450 //ยกขาลง
#define MIN_ID6 400 //ก้าวขาถอย
#define MAX_ID6 600  //ก้าวขาหน้า

void setup() 
{
  Serial.begin(115200);

   for (int i = 0; i < arraySize; i++) {
    sensorValues[i] = 0;
  }
  pinMode(GPIO_PIN_1, INPUT); // กำหนด GPIO เป็นโหมด INPUT
  pinMode(GPIO_PIN_2, INPUT); // กำหนด GPIO เป็นโหมด INPUT
  Serial.println("Start");
  Serial1.begin(1000000);
  sc.pSerial = &Serial1;
  Prev_C1_Values = C1;
  Prev_O1_Values = tanh(Prev_C1_Values);
  Prev_C2_Values = C2;
  Prev_O2_Values = tanh(Prev_C2_Values);
  sc.RegWritePos(M0,M0_Home,0,1000);
  sc.RegWritePos(M1,M1_Home,0,1000);
  sc.RegWritePos(M2,M2_Home,0,1000);
  sc.RegWritePos(M3,M3_Home,0,1000);
  sc.RegWritePos(M4,M4_Home,0,1000);
  sc.RegWritePos(M5,M5_Home,0,1000);
  sc.RegWritePos(M6,M6_Home,0,1000);
  sc.RegWritePos(M7,M7_Home,0,1000);
  sc.RegWriteAction();
  delay(1000);
}

float map(float x, float in_min, float in_max, float out_min, float out_max) {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

//int i=0;
void loop() 
{
  CPGLOOP();
  int data_1 = digitalRead(GPIO_PIN_1);
  // ส่งข้อมูลที่รับไปทาง Serial
  //Serial.println(data_1);
  if(data_1 == 0)
  {
    speed = 1;
  }
}


void CPGLOOP()
{
  //Serial.println("Start");
  
  //-----------CPG----------------//
  Current_C1_Values = (Prev_O1_Values * w11) + (Prev_O2_Values * w21) + CPG_BIAS;
  Current_C2_Values = (Prev_O2_Values * w22) + (Prev_O1_Values * w12) + CPG_BIAS;

  Current_O1_Values = tanh(Current_C1_Values);
  Current_O2_Values = tanh(Current_C2_Values);
  
  C3_Values = (Current_O2_Values*w_for_C3579_and_o2)+(O_INTPUT2*w_for_C36710_and_oinput)+BIAS;
  C4_Values = (Current_O2_Values*w_for_C46810_and_o2)+(O_INTPUT2*w_for_C4589_and_oinput)+BIAS;
  C5_Values = (Current_O2_Values*w_for_C3579_and_o2)+(O_INTPUT2*w_for_C4589_and_oinput)+BIAS;
  C6_Values = (Current_O2_Values*w_for_C46810_and_o2)+(O_INTPUT2*w_for_C36710_and_oinput)+BIAS;
  C7_Values = (Current_O2_Values*w_for_C3579_and_o2)+(O_INTPUT2*w_for_C36710_and_oinput)+BIAS;
  C8_Values = (Current_O2_Values*w_for_C46810_and_o2)+(O_INTPUT2*w_for_C4589_and_oinput)+BIAS;
  C9_Values = (Current_O2_Values*w_for_C3579_and_o2)+(O_INTPUT2*w_for_C4589_and_oinput)+BIAS;
  C10_Values = (Current_O2_Values*w_for_C46810_and_o2)+(O_INTPUT2*w_for_C36710_and_oinput)+BIAS;
  O3_Values = tanh(C3_Values);
  O4_Values = tanh(C4_Values);
  O5_Values = tanh(C5_Values);
  O6_Values = tanh(C6_Values);
  O7_Values = tanh(C7_Values);
  O8_Values = tanh(C8_Values);
  O9_Values = tanh(C9_Values);
  O10_Values = tanh(C10_Values);  
  C11_Values = (w_for_C11and12plus*(O3_Values+O4_Values))+(w_for_C11and12minus*(O5_Values+O6_Values));
  C12_Values = (w_for_C11and12plus*(O7_Values+O8_Values))+(w_for_C11and12minus*(O9_Values+O10_Values));
  O11_Values = tanh(C11_Values);
  O12_Values = tanh(C12_Values); 
  M0val = (O11_Values*weight_for_M_0and3);
  M1val = (O11_Values*weight_for_M_1and2);
  M2val = (O12_Values*weight_for_M_1and2);
  M3val = (O12_Values*weight_for_M_0and3);
  M4val = (Current_O1_Values*weight_for_M_4and7)+Motor_4to7_Bias;
  M5val = (Current_O1_Values*weight_for_M_5and6)+Motor_4to7_Bias;
  M6val = (Current_O1_Values*weight_for_M_5and6)+Motor_4to7_Bias;
  M7val = (Current_O1_Values*weight_for_M_4and7)+Motor_4to7_Bias;
  mapmotor(M0val,M1val,M2val,M3val,M4val,M5val,M6val,M7val);
  delay(50);
  Prev_C1_Values = Current_C1_Values;
  Prev_O1_Values = Current_O1_Values;
  Prev_C2_Values = Current_C2_Values;
  Prev_O2_Values = Current_O2_Values;
}
void mapmotor(float M0val,float M1val,float M2val,float M3val,float M4val,float M5val,float M6val,float M7val)
{
  // Serial.print("M0:");
  // Serial.print(M0val , 7);
  // Serial.print("\tM1:");
  // Serial.print(M1val , 7);
  // Serial.print("\tM2:");
  // Serial.print(M2val , 7);
  // Serial.print("\tM3:");
  // Serial.print(M3val , 7);
  // Serial.print("\tM4:");
  // Serial.print(M4val , 7);
  // Serial.print("\tM5:");
  // Serial.print(M5val, 7);
  // Serial.print("\tM6:");
  // Serial.print(M6val, 7);
  // Serial.print("\tM7:");
  // Serial.println(M7val, 7);

  float posM0 = map(M0val, M0_MIN, M0_MAX, MAX_ID12, MIN_ID12);
  float posM4 = map(M4val, M4_MIN, M4_MAX, MAX_ID11, MIN_ID11);

  //ขาหลังขวา
  float posM1 = map(M1val, M1_MIN, M1_MAX, MIN_ID7, MAX_ID7);
  float posM5 = map(M5val, M5_MIN, M5_MAX, MIN_ID8, MAX_ID8);

  //ขาหน้าซ้าย
  float posM2 = map(M2val, M2_MIN, M2_MAX, MIN_ID9, MAX_ID9);
  float posM6 = map(M6val, M6_MIN, M6_MAX, MIN_ID10, MAX_ID10);

  //ขาหลังซ้าย
  float posM3 = map(M3val, M3_MIN, M3_MAX, MAX_ID6, MIN_ID6);
  float posM7 = map(M7val, M7_MIN, M7_MAX, MAX_ID5, MIN_ID5);

  // sc.WritePos(11,pos11,0,1500);
  sc.WritePos(M0,posM0,0,speed);
  sc.WritePos(M1,posM1,0,speed);
  sc.WritePos(M2,posM2,0,speed);
  sc.WritePos(M3,posM3,0,speed);
  sc.WritePos(M4,posM4,0,speed);
  sc.WritePos(M5,posM5,0,speed);
  sc.WritePos(M6,posM6,0,speed);
  sc.WritePos(M7,posM7,0,speed);
  //Serial.print("  Torqe:");
  //Serial.println(sumofload());
  sumofload();
}
int sumofload()
{
  int Torqe[7];
  int Torqe_total=0;
  for (int j=0 ;j <=7;j++)
  {
    Torqe[j]=abs(sc.ReadLoad(5+j));
    Torqe_total = Torqe_total+Torqe[j];
  }
  unsigned long currentMillis1 = millis();
  unsigned long currentMillis2 = millis();
  if (currentMillis2 - previousMillis1 >= interval1) {
    previousMillis1 = currentMillis2;
      float torque = Torqe_total;
      torque = torque/1000;
      
      sensorValues[currentIndex] = torque;
      currentIndex = (currentIndex + 1) % arraySize;
      float sum = 0;
      int validCount = 0;
      for (int i = 0; i < arraySize; i++) {
        if (sensorValues[i] > 0) {
          sum += sensorValues[i];
          validCount++;
        }
      }
      float mean = (validCount > 0) ? sum / validCount : 0;
      float sumSqDiff = 0;

      for (int i = 0; i < arraySize; i++) {
        if (sensorValues[i] > 0) {
          sumSqDiff += pow(sensorValues[i] - mean, 2);
        }
      }

      float stdDev = (validCount > 1) ? sqrt(sumSqDiff / (validCount - 1)) : 0;
     
 
      float e = 2.71828;
      float a = 1;
      float b = 0.0;
      float reX = pow(e, (-stdDev));

      // คำนวณค่า first และ second
      float first = a * (tanh(reX));
      float second = b * Hc[0];
     
      // บวกค่า first และ second แล้วเก็บใน Hc[1]
      Hc[1] = first + second;
       Serial.print(torque);
      Serial.print(" ");
      Serial.print(stdDev);
      Serial.print(" ");
      Serial.print(reX);
      Serial.print(" ");
      Serial.print(first);
      Serial.print(" ");
      Serial.print(second);
      Serial.print(" ");
      Serial.println(Hc[1]);
      // แสดงผลค่าปัจจุบัน
      // Serial.print("Hc: ");
      // Serial.print(Hc[0]);
      // Serial.print(" -> ");
      // Serial.print(Hc[1]);
      // Serial.println();

      // อัพเดท Hc[0] สำหรับการทำงานรอบต่อไป
      Hc[0] = Hc[1];
      speed = map(Hc[1], 1, 0, 1, 1000);
  }
/////////////////////////////////////////////////////////////

}
