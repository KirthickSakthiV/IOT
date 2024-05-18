#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  Serial.begin(9600);
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  pinMode(13,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(6,OUTPUT);
}

void loop() {
  
  int gas_data;
  gas_data = analogRead(A0);
  lcd.setCursor(00,00);
  lcd.print("Gas :");
  lcd.setCursor(6,00);
  lcd.print(gas_data);
  
  if(gas_data > 800){
  	digitalWrite(13,HIGH);
    delay(100);
    digitalWrite(13,LOW);
    lcd.setCursor(00,1);
    lcd.print("DANGER");

  }else if(gas_data > 700){
    digitalWrite(6,HIGH);
  	delay(100);
    digitalWrite(6,LOW);
    lcd.setCursor(00,1);
    lcd.print("WARNING");
    
  }else {
    digitalWrite(7,HIGH);
    lcd.setCursor(00,1);
    lcd.print("SAFE");
  }
  
  Serial.println(gas_data);
  delay(100);
  lcd.clear();
 
}
 