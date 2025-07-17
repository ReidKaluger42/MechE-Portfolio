#include <Servo.h>
#include <LiquidCrystal.h>

// Initialize LCD pins: (RS, EN, DB4, DB5, DB6, DB7)
LiquidCrystal lcd(12, 11, 5, 6, 7, 8);  // Map to Arduino pins

// Initalize Servos
Servo panServo;
Servo tiltServo;

// Inital Angles
int panAngle = 100;
int tiltAngle = 0;

void setup() {

// Set up the LCD's columns and rows:
lcd.begin(16, 2);  // For 16x2 LCD

// Attach Servos to Pins
panServo.attach(9);
tiltServo.attach(10);

// Move Servos to Angles
panServo.write(panAngle);
tiltServo.write(tiltAngle);

Serial.begin(9600);


// 'PREPARING CAT LASER' Blinking Sequence
lcd.setCursor(0, 0);
lcd.print(" PREPARING CAT");
lcd.setCursor(0, 1);
lcd.print("      LASER");
delay(2000);
lcd.clear();
delay(500);
lcd.setCursor(0, 0);
lcd.print(" PREPARING CAT");
lcd.setCursor(0, 1);
lcd.print("     LASER");
delay(2000);
lcd.clear();
delay(500);
lcd.setCursor(0, 0);
lcd.print(" PREPARING CAT");
lcd.setCursor(0, 1);
lcd.print("     LASER");
delay(2000);
lcd.clear();

// 'CAT LASER READY!'
lcd.setCursor(0, 0);
lcd.print("   CAT LASER");
lcd.setCursor(0, 1);
lcd.print("    READY!");
delay(2000);
lcd.clear();
delay(500);
}

void loop() {
// 'W' 'A' 'S' 'D' Manual Input Commands for Debugging and Constraining


//  if (Serial.available() > 0) {
//      char command = Serial.read();

//    switch (command){
//    case 'w': tiltAngle += 5; break;
//    case 's': tiltAngle -= 5; break;
//    case 'a': panAngle += 5; break;
//    case 'd': panAngle -= 5; break; 
//    }

// Update servo positions
//     panServo.write(panAngle);
//     tiltServo.write(tiltAngle);

// Update LCD and Serial Monitor
// updateLCD();
// printAngles();

// Constrain angles to valid range (0-180 degrees) based on surroundings
     panAngle = constrain(panAngle, 50, 155);
     tiltAngle = constrain(tiltAngle, 0, 40);
 

// First Tilt Sequence w/random Tilt Angle Angling Up
int randtiltAngle = random(0, 41);
while (tiltAngle < randtiltAngle){
tiltServo.write(tiltAngle);
tiltAngle+=3;
updateLCD();
printAngles();
delay(80);
}

// Optional Random Delay 
//int randdelay1 = random(100, 500);
//delay(randdelay1);

// Second Tilt Sequence w/random Tilt Angle Angling Down
int randtiltAngle2 = random(0, 41);
while (tiltAngle > randtiltAngle2){
tiltServo.write(tiltAngle);
tiltAngle-=3;
updateLCD();
printAngles();
delay(80);
}

// Optional Random Delay 
//int randdelay2 = random(100, 500);
//delay(randdelay2);

// First Pan Sequence w/random Pan Angle Angling CW
int randpanAngle = random(50, 156); 
while (panAngle < randpanAngle){
panServo.write(panAngle);
panAngle+=3;
updateLCD();
printAngles();
delay(60);
}

// Optional Random Delay 
//int randdelay3 = random(100, 500);
//delay(randdelay3);

// Second Pan Sequence w/random Pan Angle Angling CCW
int randpanAngle2 = random(50, 156); 
while (panAngle > randpanAngle2){
panServo.write(panAngle);
panAngle-=3;
updateLCD();
printAngles();
delay(60);
}
// Optional Random Delay 
//int randdelay4 = random(100, 500);
//delay(randdelay4);
}


/////////////////// FUNCTIONS //////////////////////
// Helper function to print angles on Serial Reader
void printAngles() {
  Serial.print("Pan: ");
  Serial.print(panAngle);
  Serial.print("°\tTilt: ");
  Serial.print(tiltAngle);
  Serial.println("°");
}
// Update LCD display
void updateLCD() {
  lcd.clear();
  lcd.setCursor(0, 0);          // Row 1
  lcd.print("Tilt: ");
  lcd.print(tiltAngle);         // Tilt Value
  lcd.setCursor(0, 1);          // Row 2
  lcd.print("Pan: ");
  lcd.print(panAngle);          // Pan Value 
}

