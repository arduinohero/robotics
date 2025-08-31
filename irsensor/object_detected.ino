int count = 0; // global counter

void setup() {
  pinMode(5,OUTPUT);
  pinMode(8, INPUT);       // set pin 7 as input
  Serial.begin(9600);      // initialize serial monitor
}

void loop() {
  int ir = digitalRead(8); // read IR sensor input
  if (ir == LOW) {         // IR sensor detects object when LOW
    count++;               // increment count
    Serial.println(count); // print count
    if(count==20){
      digitalWrite(5,HIGH);
      delay(1000);
      count=0;
    }
    delay(100);           // delay to avoid multiple increments
    digitalWrite(5,LOW);
  }
}
