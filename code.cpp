

const int temp_trans_pin = A0, Heater_pin = 13, FAN_pin = 8;
int MinTemp = 0, MaxTemp = 0;

void setup(){
 

 pinMode(Heater_pin, OUTPUT);//LED in our case
    pinMode(FAN_pin, OUTPUT);
  Serial.begin(9600);
  Serial.println("Enter the Max Temperature");
  while (Serial.available() == 0)   
  { }  
    MaxTemp = Serial.parseInt();
    Serial.println("Enter the Min Temperature");
    while (Serial.available() == 0)   
    { }    
    MinTemp = Serial.parseInt();
  

}

void loop(){
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
  int celsius=0;
  
  
 
 // Read voltage and convert to temperature (Celsius)
   
   celsius = map(((analogRead(A0) - 20) * 3.04), 0, 1023, -40, 125);
  if(celsius > MaxTemp){
    digitalWrite(Heater_pin, LOW);
  Serial.print("temp is HIGHER");
    Serial.print("\n");
  delay(500);
  Serial.print("Turn on FAN!");
    Serial.print("\n");
  digitalWrite(FAN_pin, HIGH);
  delay(2000);
  }
else if(celsius < MinTemp){
  digitalWrite(FAN_pin, LOW);
  Serial.print("temp is LOWER");
  Serial.print("\n");
  delay(500);
  Serial.print("Turn on HEATER!");
  Serial.print("\n");
  digitalWrite(Heater_pin, HIGH);
  delay(2000);
}
   else if(celsius > MinTemp && celsius < MaxTemp){
     digitalWrite(Heater_pin, LOW);
     digitalWrite(FAN_pin,LOW);
  delay(500);
  Serial.print("Temp is NORMAL!");
  Serial.print("\n");
  delay(500);

  Serial.print("Turn off all!");
  Serial.print("\n");
     delay(2000);
   }
  } 
  
