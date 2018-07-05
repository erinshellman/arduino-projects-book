int switchState = 0;
int greenLight = 3;
int yellowLight = 4;
int redLight = 5;

int flashSpeed = 150;
int resetSpeed = 250;

void setup() {
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(2, INPUT);

}

void loop() {
  switchState = digitalRead(2);

  if (switchState == LOW) {
    
    digitalWrite(greenLight, HIGH);
    digitalWrite(yellowLight, LOW);
    digitalWrite(redLight, LOW);
    
    }

  else {
    
    int i;
    digitalWrite(greenLight, LOW);

    for (i = 0; i < 10; i = i + 1) {
      digitalWrite(yellowLight, LOW);
      digitalWrite(redLight, HIGH);
      delay(flashSpeed);

      digitalWrite(yellowLight, HIGH);
      digitalWrite(redLight, LOW);
      delay(flashSpeed);

    }
        
    }
}
