#include "BluetoothSerial.h"

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

BluetoothSerial SerialBT;
// int received;// received value will be stored in this variable
char receivedChar;// received value will be stored as CHAR in this variable

const char turnONPleasant ='a';
const char turnOFFPleasant ='b';
const char turnONUnpleasant ='c';
const char turnOFFUnpleasant ='d';
const char turnONNeutral ='e';
const char turnOFFNeutral ='f';

const int LEDpinPleasant = 25;
const int LEDpinUnpleasant = 26;
const int LEDpinNeutral = 27;
const int driver = 4;

void setup() {
  Serial.begin(115200);
  SerialBT.begin("ESP32_Robojax"); //Bluetooth device name
  Serial.println("The device started, now you can pair it with bluetooth!");
  // Serial.println("To turn ON send: 1");//print on serial monitor  
  // Serial.println("To turn OFF send: 0"); //print on serial monitor 
  pinMode(LEDpinPleasant, OUTPUT);
  pinMode(LEDpinUnpleasant, OUTPUT);
  pinMode(LEDpinNeutral, OUTPUT);

  digitalWrite(driver, HIGH);
  delay(20);
  digitalWrite(driver, LOW);
 
}

void loop() {

    // receivedChar =(char)Serial.read();
    receivedChar =(char)SerialBT.read();


  if (Serial.available()) {
    SerialBT.write(Serial.read());
  
  }
  if (SerialBT.available()) {
    
    SerialBT.print("Received:");// write on BT app
    SerialBT.println(receivedChar);// write on BT app      
    Serial.print ("Received:");//print on serial monitor
    Serial.println(receivedChar);//print on serial monitor   

    //control pleasant 
    if(receivedChar == turnONPleasant)
    {
     SerialBT.println("LED ON:");// write on BT app
     Serial.println("LED ON:");//write on serial monitor
     digitalWrite(LEDpinPleasant, HIGH);// turn the LED ON

    //  delay(5000);

    //  digitalWrite(LEDpinPleasant, LOW);
       
    }
    if(receivedChar == turnOFFPleasant)
    {
     SerialBT.println("LED OFF:");// write on BT app
     Serial.println("LED OFF:");//write on serial monitor
      digitalWrite(LEDpinPleasant, LOW);// turn the LED off 
    } 

    //control unpleasent
    if(receivedChar == turnONUnpleasant)
    {
     SerialBT.println("LED ON:");// write on BT app
     Serial.println("LED ON:");//write on serial monitor
     digitalWrite(LEDpinUnpleasant, HIGH);// turn the LED ON

    //  delay(5000);

    //  digitalWrite(LEDpinUnpleasant, LOW);
       
    }
    if(receivedChar == turnOFFUnpleasant)
    {
     SerialBT.println("LED OFF:");// write on BT app
     Serial.println("LED OFF:");//write on serial monitor
      digitalWrite(LEDpinUnpleasant, LOW);// turn the LED off 
      // delay(50000);
      // digitalWrite(LEDpinUnpleasant, HIGH);
      // delay(60000);
      // digitalWrite(LEDpinUnpleasant, LOW);
    }    

    //control neutral
    if(receivedChar == turnONNeutral)
    {
     SerialBT.println("LED ON:");// write on BT app
     Serial.println("LED ON:");//write on serial monitor
     digitalWrite(LEDpinNeutral, HIGH);// turn the LED ON

    //  delay(5000);

    //  digitalWrite(LEDpinNeutral, LOW);
       
    }
    if(receivedChar == turnOFFNeutral)
    {
     SerialBT.println("LED OFF:");// write on BT app
     Serial.println("LED OFF:");//write on serial monitor
      digitalWrite(LEDpinNeutral, LOW);// turn the LED off 
    }    
  

  }
  delay(20);
}