#include <LiquidCrystal_I2C.h>
#include <SoftwareSerial.h>
#include <Wire.h>
SoftwareSerial serial (2,3);

long number1; // first number of the calculation, sent through the Serial monitor. If you take a look, it's a long varible, so we're able to use big numbers
long number2; // second number sent through the SM
char operation; // create a char variable to store the calcuation signal.
long result; // result of the calculation
char teks = "";
char cekmenu;

void setup() {
  Serial.begin(9600); // begins serial communications
  
  
  serial.begin(9600);
  Serial.println("Pilih menu");
  Serial.println("'a' untuk mode transfer TEKS. Contoh: 'a AKU KP DI RAINBOARD' ");
  Serial.println("'b' untuk mode CALCULATOR. Contoh : 'b 2+3'");
  

  Serial.println();
}

void loop() {
  while((Serial.available() > 0)){
  
  if (Serial.available())
    serial.write(Serial.read()); {    // while there is result being sent to arduino,
        
    
    menu();
    
       
    
    
  }
}
}

void menu(){
  cekmenu = Serial.read();
  serial.write(cekmenu);
   if(cekmenu == 'a'){
    
   kata();
  }
  else if (cekmenu == 'b'){
    calculate();
  }
}

void kata(){
  teks = Serial.read();
  serial.write(teks);
    Serial.println("teks anda telah terkirm");
    Serial.println("Done..."); // prints
    Serial.println(); // jumps a line
    
}
void calculate() { // Custom function that performs the calculations 
    
    number1 = Serial.parseInt();
    serial.write(number1);    
    operation = Serial.read(); // calSignal will be the first char after the first number
    serial.write(operation);    
    number2 = Serial.parseInt(); // stores the second number in number2 
    serial.write(number2);
     
  if (operation == '+') {
    result = number1 + number2;
    
      Serial.println("Perhitungan Selesai");
      Serial.println("Done..."); // prints
    Serial.println(); // jumps a line
  }
  else if (operation == '-')  {
    result = number1 - number2; 
    
      Serial.print("hasil dari perhitungan");
      Serial.println();
      Serial.print(number1);
      Serial.print(operation);
      Serial.print(number2);
      Serial.print("=");
    Serial.println(result); // Prints the result of the calculation
    Serial.println("Done..."); // prints
    Serial.println(); // jumps a line
  }
  else if (operation == '*')  {
    result = number1 * number2; 
    
      Serial.print("hasil dari perhitungan");
      Serial.println();
      Serial.print(number1);
      Serial.print(operation);
      Serial.print(number2);
      Serial.print("=");
    Serial.println(result); // Prints the result of the calculation
    Serial.println("Done..."); // prints
    Serial.println(); // jumps a line
      
  }
  else if (operation == '/')  {
    result = number1 / number2; 
   
      
     
      Serial.print("hasil dari perhitungan");
      Serial.println();
      Serial.print(number1);
      Serial.print(operation);
      Serial.print(number2);
      Serial.print("=");
    Serial.println(result); // Prints the result of the calculation
    Serial.println("Done..."); // prints
    Serial.println(); // jumps a line
  }
  
  else  {
    Serial.println("Error, Wrong input!!"); 
    Serial.println();
    result = 0;
   
      
      Serial.print("result = ");
    Serial.println(result); // Prints the result of the calculation
    Serial.println("Done..."); // prints
    
    Serial.println(); // jumps a line
  }
 

}
