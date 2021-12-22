 
#include "BluetoothSerial.h" 


#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run
`make menuconfig` to and enable it
#endif

BluetoothSerial SerialBT;


// define the GPIO connected with Relays and switches
#define RelayPin1 26  
#define RelayPin2 27
#define RelayPin3 14 
#define RelayPin4 12 
#define RelayPin5 13  
#define RelayPin6 21
#define RelayPin7 4 
#define RelayPin8 18
#define RelayPin9 19 
#define RelayPin10 2

char bt_data; // variable for storing bluetooth data 


void all_Switch_ON(){
  digitalWrite(RelayPin1, LOW);  delay(100);
  digitalWrite(RelayPin2, LOW);  delay(100);
  digitalWrite(RelayPin3, LOW);  delay(100);
  digitalWrite(RelayPin4, LOW);  delay(100);
  digitalWrite(RelayPin5, LOW);  delay(100);
  digitalWrite(RelayPin6, LOW);  delay(100);
  digitalWrite(RelayPin7, LOW);  delay(100);
  digitalWrite(RelayPin8, LOW);  delay(100);
  digitalWrite(RelayPin9, LOW);  delay(100);
  digitalWrite(RelayPin10, LOW);  delay(100);

}

void all_Switch_OFF(){
  digitalWrite(RelayPin1, HIGH); delay(100);
  digitalWrite(RelayPin2, HIGH); delay(100);
  digitalWrite(RelayPin3, HIGH); delay(100);
  digitalWrite(RelayPin4, HIGH); delay(100);
  digitalWrite(RelayPin5, HIGH); delay(100);
  digitalWrite(RelayPin6, HIGH); delay(100);
  digitalWrite(RelayPin7, HIGH); delay(100);
  digitalWrite(RelayPin8, HIGH); delay(100);
  digitalWrite(RelayPin9, HIGH); delay(100);
  digitalWrite(RelayPin10, HIGH); delay(100);

}

void Bluetooth_handle()
{
  bt_data = SerialBT.read();
  Serial.println(bt_data);
  delay(20);

  switch(bt_data)
      {
        case 'A': digitalWrite(RelayPin1, LOW);   break; // if 'A' received Turn off Relay1
        case 'a': digitalWrite(RelayPin1, HIGH);  break; // if 'a' received Turn on Relay1
        case 'B': digitalWrite(RelayPin2, LOW);   break; // if 'B' received Turn off Relay2
        case 'b': digitalWrite(RelayPin2, HIGH);  break; // if 'b' received Turn on Relay2
        case 'C': digitalWrite(RelayPin3, LOW);   break; // if 'C' received Turn off Relay3
        case 'c': digitalWrite(RelayPin3, HIGH);  break; // if 'c' received Turn on Relay3
        case 'D': digitalWrite(RelayPin4, LOW);   break; // if 'D' received Turn off Relay4
        case 'd': digitalWrite(RelayPin4, HIGH);  break; // if 'd' received Turn on Relay4
        case 'E': digitalWrite(RelayPin5, LOW);   break; // if 'E' received Turn off Relay5
        case 'e': digitalWrite(RelayPin5, HIGH);  break; // if 'e' received Turn on Relay5
        case 'F': digitalWrite(RelayPin6, LOW);   break; // if 'F' received Turn off Relay6
        case 'f': digitalWrite(RelayPin6, HIGH);  break; // if 'f' received Turn on Relay6
        case 'G': digitalWrite(RelayPin7, LOW);   break; // if 'G' received Turn off Relay7
        case 'g': digitalWrite(RelayPin7, HIGH);  break; // if 'g' received Turn on Relay7
        case 'H': digitalWrite(RelayPin8, LOW);   break; // if 'H' received Turn off Relay8
        case 'h': digitalWrite(RelayPin8, HIGH);  break; // if 'h' received Turn on Rela8
        case 'I': digitalWrite(RelayPin9, LOW);   break; // if 'I' received Turn off Relay9
        case 'i': digitalWrite(RelayPin9, HIGH);  break; // if 'i' received Turn on Relay9
        case 'J': digitalWrite(RelayPin10, LOW);   break; // if 'J' received Turn off Relay10
        case 'j': digitalWrite(RelayPin10, HIGH);  break; // if 'j' received Turn on Relay10
        case 'K': all_Switch_ON(); break;  // if 'K' received Turn on all Relays
        case 'k': all_Switch_OFF(); break; // if 'k' received Turn off all Relays
        default : break;
      }
}

void setup()
{
  Serial.begin(9600);

  btStart();  //Serial.println("Bluetooth On");
  
  SerialBT.begin("HA_BT_ESP32"); //Bluetooth device name
  Serial.println("The device started, now you can pair it with bluetooth!");
  delay(5000);

  pinMode(RelayPin1, OUTPUT);
  pinMode(RelayPin2, OUTPUT);
  pinMode(RelayPin3, OUTPUT);
  pinMode(RelayPin4, OUTPUT);
  pinMode(RelayPin5, OUTPUT);
  pinMode(RelayPin6, OUTPUT);
  pinMode(RelayPin7, OUTPUT);
  pinMode(RelayPin8, OUTPUT);
  pinMode(RelayPin9, OUTPUT);
  pinMode(RelayPin10, OUTPUT);



  //During Starting all Relays should TURN OFF
  digitalWrite(RelayPin1, LOW);
  digitalWrite(RelayPin2, LOW);
  digitalWrite(RelayPin3, LOW);
  digitalWrite(RelayPin4, LOW);
  digitalWrite(RelayPin5, LOW);
  digitalWrite(RelayPin6, LOW);
  digitalWrite(RelayPin7, LOW);
  digitalWrite(RelayPin8, LOW);
  digitalWrite(RelayPin9, LOW);
  digitalWrite(RelayPin10, LOW);
   
   delay(200);
}

void loop()
{  
  if (SerialBT.available()){
   Bluetooth_handle();
 }

}
