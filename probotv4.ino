String voice="";

int led1 = 5;
int fan1 = 6;

void lon() {
  digitalWrite (led1, HIGH);
 
}

void loff() {
  digitalWrite (led1, LOW);
 }

void fon(){
    digitalWrite (fan1, HIGH);
}

void foff() {
  digitalWrite (fan1, LOW);
 }

void setup() {
  Serial.begin(38400);
  pinMode(led1, OUTPUT);
  digitalWrite (led1, HIGH);
   pinMode(fan1, OUTPUT);
  digitalWrite (fan1, HIGH);
 
}

void loop() {
  while(Serial.available()) {
    delay(10);
    char c=Serial.read();
    Serial.println(c);
    if(c=='#')
    {break; }
    voice += c;
}

if (voice.length() > 0) {
  Serial.println(voice);
  if (voice == "*LED on"||voice == "*lights on" )
  {lon() ; }
  else if (voice == "*LED of" || voice == "*LED off" || voice == "*lights of" || voice == "*lights off")
  {loff() ; }
  else if (voice == "*fan on")
  {fon() ; }
   else if (voice == "*fan of" || voice == "*fan off")
  {foff() ; }
  
voice="";
}
}


