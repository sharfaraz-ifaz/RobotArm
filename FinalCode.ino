#include<USART.h>
#include<Wire.h>
#include<EVShield.h>
#include <EVs_NXTLight.h>

void setup() {
  Serial.begin(9600);
  evshield.init(SH_HardwareI2C);
  evshield.bank_a.motorReset();
  evshield.bank_b.motorReset();
  myLight.init(&evshield, SH_BAS2);
  myLight.setReflected();
}
void loop() {
  uint16_t light;
  light = myLight.readRaw();
  if (light <= 500){
    delay(4000);
    red2x4();
  }
  if (light >=800){
    delay(4000);
    blue2x4();
  }  
}

int blue2x4(void){
  claw_open();
  claw_close();
  delay(1000);
  
  arm_extent();
  
  //Moving base 
  encoder = evshield.bank_b.motorGetEncoderPosition(SH_Motor_1);
  Serial.print("Initial base position = ");
  Serial.println(encoder);
  evshield.bank_b.motorRunDegrees(SH_Motor_1, SH_Direction_Reverse , SH_Speed_Full, 60, SH_Completion_Wait_For, SH_Next_Action_BrakeHold);
  evshield.bank_b.motorStop(SH_Motor_1, SH_Next_Action_Brake);
  encoder = evshield.bank_b.motorGetEncoderPosition(SH_Motor_1);
  Serial.print("Final base position = ");
  Serial.println(encoder);
  
  claw_open();
  arm_rest();
  
  //Original base positin
  encoder = evshield.bank_b.motorGetEncoderPosition(SH_Motor_1);
  Serial.print("Initial base position = ");
  Serial.println(encoder);
  evshield.bank_b.motorRunDegrees(SH_Motor_1, SH_Direction_Forward , SH_Speed_Full, 60, SH_Completion_Wait_For, SH_Next_Action_BrakeHold);
  evshield.bank_b.motorStop(SH_Motor_1, SH_Next_Action_Brake);
  encoder = evshield.bank_b.motorGetEncoderPosition(SH_Motor_1);
  Serial.print("Final base position = ");
  Serial.println(encoder);    
}
int red2x4(void){
  claw_open();
  claw_close();
  delay(1000);
  
  arm_extent();

  encoder = evshield.bank_b.motorGetEncoderPosition(SH_Motor_1);
  Serial.print("Initial base position = ");
  Serial.println(encoder);
  evshield.bank_b.motorRunDegrees(SH_Motor_1, SH_Direction_Reverse , SH_Speed_Full, 30, SH_Completion_Wait_For, SH_Next_Action_BrakeHold);
  evshield.bank_b.motorStop(SH_Motor_1, SH_Next_Action_Brake);
  encoder = evshield.bank_b.motorGetEncoderPosition(SH_Motor_1);
  Serial.print("Final base position = ");
  Serial.println(encoder);   
  
  claw_open();
  arm_rest();

  encoder = evshield.bank_b.motorGetEncoderPosition(SH_Motor_1);
  Serial.print("Initial base position = ");
  Serial.println(encoder);
  evshield.bank_b.motorRunDegrees(SH_Motor_1, SH_Direction_Forward , SH_Speed_Full, 30, SH_Completion_Wait_For, SH_Next_Action_BrakeHold);
  evshield.bank_b.motorStop(SH_Motor_1, SH_Next_Action_Brake);
  encoder = evshield.bank_b.motorGetEncoderPosition(SH_Motor_1);
  Serial.print("Final base position = ");
  Serial.println(encoder);   
}
int red2x2(void){
  claw_open();
  claw_close();
  delay(1000);
  
  arm_extent();
  
  claw_open();
  arm_rest();
  
}
int grey1x4(void){
  claw_open();
  claw_close(); 
  delay(1000);

  arm_extent();

  encoder = evshield.bank_b.motorGetEncoderPosition(SH_Motor_1);
  Serial.print("Initial base position = ");
  Serial.println(encoder);
  evshield.bank_b.motorRunDegrees(SH_Motor_1, SH_Direction_Forward , SH_Speed_Full, 30, SH_Completion_Wait_For, SH_Next_Action_BrakeHold);
  evshield.bank_b.motorStop(SH_Motor_1, SH_Next_Action_Brake);
  encoder = evshield.bank_b.motorGetEncoderPosition(SH_Motor_1);
  Serial.print("Final base position = ");
  Serial.println(encoder);   
  
  claw_open();
  arm_rest();

  encoder = evshield.bank_b.motorGetEncoderPosition(SH_Motor_1);
  Serial.print("Initial base position = ");
  Serial.println(encoder);
  evshield.bank_b.motorRunDegrees(SH_Motor_1, SH_Direction_Reverse , SH_Speed_Full, 30, SH_Completion_Wait_For, SH_Next_Action_BrakeHold);
  evshield.bank_b.motorStop(SH_Motor_1, SH_Next_Action_Brake);
  encoder = evshield.bank_b.motorGetEncoderPosition(SH_Motor_1);
  Serial.print("Final base position = ");
  Serial.println(encoder);  
  
}
int claw_open(void){
  int encoder;
  encoder = evshield.bank_a.motorGetEncoderPosition(SH_Motor_2);
  Serial.print("Initial claw position = ");
  Serial.println(encoder);
  evshield.bank_a.motorRunDegrees(SH_Motor_2, SH_Direction_Forward , SH_Speed_Full, 30, SH_Completion_Wait_For, SH_Next_Action_Brake);
  evshield.bank_a.motorStop(SH_Motor_2, SH_Next_Action_Brake);
  encoder = evshield.bank_a.motorGetEncoderPosition(SH_Motor_2);
  Serial.print("Final claw position = ");
  Serial.println(encoder);
}
int claw_close(void){
  int encoder;
  encoder = evshield.bank_a.motorGetEncoderPosition(SH_Motor_2);
  Serial.print("Initial claw position = ");
  Serial.println(encoder);
  evshield.bank_a.motorRunDegrees(SH_Motor_2, SH_Direction_Reverse , SH_Speed_Full, 30, SH_Completion_Wait_For, SH_Next_Action_Brake);
  evshield.bank_a.motorStop(SH_Motor_2, SH_Next_Action_Brake);
  encoder = evshield.bank_a.motorGetEncoderPosition(SH_Motor_2);
  Serial.print("Final claw position = ");
  Serial.println(encoder);
}
int arm_extend(void){
   encoder = evshield.bank_a.motorGetEncoderPosition(SH_Motor_1);
   Serial.print("Initial arm position = ");
   Serial.println(encoder);
   evshield.bank_a.motorRunDegrees(SH_Motor_1, SH_Direction_Forward , SH_Speed_Full, 120, SH_Completion_Wait_For, SH_Next_Action_BrakeHold);
   evshield.bank_a.motorStop(SH_Motor_1, SH_Next_Action_Brake);
   encoder = evshield.bank_a.motorGetEncoderPosition(SH_Motor_1);
   Serial.print("Final arm position = ");
   Serial.println(encoder);
}
int arm_rest(void){
  encoder = evshield.bank_a.motorGetEncoderPosition(SH_Motor_1);
  Serial.print("Initial arm position = ");
  Serial.println(encoder);
  evshield.bank_a.motorRunDegrees(SH_Motor_1, SH_Direction_Reverse , SH_Speed_Full, 120, SH_Completion_Wait_For, SH_Next_Action_BrakeHold);
  evshield.bank_a.motorStop(SH_Motor_1, SH_Next_Action_Brake);
  encoder = evshield.bank_a.motorGetEncoderPosition(SH_Motor_1);
  Serial.print("Final arm position = ");
  Serial.println(encoder);
}

