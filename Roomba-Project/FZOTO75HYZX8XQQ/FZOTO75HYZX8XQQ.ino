char data=0;

void setup() {
  Serial.begin(9600);
  Serial.println("asdasdas");
}

void loop() {
  if(Serial.available()) {
    data=Serial.read();
    Serial.println(data);
    data = 0;
  }
}

