String code = "";
String tempostr = "";
int tempo = 0;
float tempof = 0;
float beat = 0;
int beatint = 0;
int pulse_width = 300;
int togglePin = 8;
int togglePin2 = 13;
int count;
int repeats = 10;
void setup() {
  pinMode(togglePin,OUTPUT);
  pinMode(togglePin2, OUTPUT);
  digitalWrite(togglePin2,LOW);
  digitalWrite(togglePin,LOW);
	Serial.begin(115200);
  listen();
  int count = 0;
}
void loop() {
if(count<repeats){
  digitalWrite(togglePin,HIGH);
  digitalWrite(togglePin2,LOW);
   delay(pulse_width);
   digitalWrite(togglePin,LOW);
   digitalWrite(togglePin2,HIGH);
   delay(beatint-pulse_width);
   count += 1;
   if(count==repeats){
     digitalWrite(togglePin2,LOW);
   }
}
}
void listen(){
  while (!Serial.available());
    code = Serial.readString();
    if(code.substring(0,1) == "1"){
      digitalWrite(togglePin,HIGH);
      Serial.print("recieved:");
       Serial.print(code.substring(0,1));
    }
    else
    if(code.substring(0,1) == "0"){
      digitalWrite(togglePin,LOW);
      Serial.print("recieved:");
       Serial.print(code.substring(0,1));
    }
    else if(code.substring(0,3) == "123")
    {
      digitalWrite(togglePin,HIGH);
      Serial.print("recieved:");
       Serial.print(code.substring(0,3));
      
    }
    tempostr = code.substring(0,3);
    tempo = tempostr.toInt();
    tempof = float(tempo);
    beat = (60/tempof)*1000;
    beatint = int(beat);
}