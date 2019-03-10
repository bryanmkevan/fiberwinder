#include <AccelStepper.h>
#include <MultiStepper.h>

// Define two steppers and the pins they will use
AccelStepper car(AccelStepper::DRIVER, 9, 8);
AccelStepper mand(AccelStepper::DRIVER, 7, 6);

// 90 degrees
//int length = 30000;
//int car_speed = 300;
//int mand_speed = 3200;
//int end_wait_time = 0;

// 45 degrees
//int length = 32000; 
//int car_speed = 8000; 
//int mand_speed = 1600; 
//int end_wait_time = 3160;

// shorter
int length = 32000; 
int car_speed = 8000; 
int mand_speed = 3200; 
int end_wait_time = 1650;

// longer
//int length = 32000; 
//int car_speed = 16000; 
//int mand_speed = 1600; 
//int end_wait_time = 6500;

//int mand_speed = 300;  


unsigned long t_1 = 0;

void setup() {
  car.setMaxSpeed(50000);
  mand.setMaxSpeed(50000);
  car.moveTo(length);
}

unsigned long run_end_time = 0;

void loop() {
  
  mand.setSpeed(-1*mand_speed);
  mand.runSpeed();
  
  car.setSpeed(car_speed);
  
  if (car.distanceToGo() != 0) {
    run_end_time = millis();
  } else if ((car.distanceToGo() == 0) && (millis() - run_end_time > end_wait_time)) {
    car.moveTo(-car.currentPosition());
  } else if(millis() - run_end_time <= end_wait_time) {
    car.setSpeed(0);
  }
  
  car.runSpeedToPosition();
  
}

