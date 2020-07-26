#include <LiquidCrystal_I2C.h>
#include <SoftwareSerial.h>
#include <Wire.h>
SoftwareSerial serial (2,3);
LiquidCrystal_I2C lcd(0x3F,16,2);
long number1; // first number of the calculation, sent through the Serial monitor. If you take a look, it's a long varible, so we're able to use big numbers
long number2; // second number sent through the SM
char operation; // create a char variable to store the calcuation signal.
long result; // result of the calculation
String teks = "";
char cekmenu;
void setup() {
  

  serial.begin(9600);
  
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("menu a : text");
  lcd.setCursor(0,1);
  lcd.print("menu B : calculator");
  

  
}

void loop() {
  {
  
 
        
    
    menu();
    
       
    
  }
  }


void menu(){
  
  cekmenu = serial.read();
  if(cekmenu == 'a'){
    
   kata();
  }
  else if (cekmenu == 'b'){
    calculate();
  }
}

void kata(){
  
  teks = serial.readString();
  lcd.clear();  
      lcd.setCursor(0,1);
      lcd.print("Teks");
      lcd.setCursor(0,0);
      lcd.print(teks);
      
}
void calculate() { // Custom function that performs the calculations 
    
   
    number1 = serial.parseInt();    
    operation = serial.read(); // calSignal will be the first char after the first number    
    number2 = serial.parseInt(); // stores the second number in number2 
     
  if (operation == '+') {
    result = number1 + number2;
    lcd.clear();  
      lcd.setCursor(0,1);
      lcd.print("kalkulator");
      lcd.setCursor(0,0);
      lcd.print(result);
      
  }
  else if (operation == '-')  {
    result = number1 - number2; 
    lcd.clear();  
      lcd.setCursor(0,1);
      lcd.print("kalkulator");
      
      lcd.setCursor(0,0);
      lcd.print(result);
      
  }
  else if (operation == '*')  {
    result = number1 * number2; 
    lcd.clear();  
      lcd.setCursor(0,1);
      lcd.print("kalkulator");
      
      lcd.setCursor(0,0);
      lcd.print(result);
      
      
  }
  else if (operation == '/')  {
    result = number1 / number2; 
    lcd.clear();  
      lcd.setCursor(0,1);
      lcd.print("kalkulator");
      
      lcd.setCursor(0,0);
      lcd.print(result);
      
  }
  
  else  {
    
    lcd.clear();  
      lcd.setCursor(0,1);
      lcd.print("kalkulator");
      
      lcd.setCursor(0,0);
      lcd.print(result);
     
      
      
  }
}
