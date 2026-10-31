const int ledKirmizi = 2;
const int ledSari    = 3;
const int ledYesil   = 4;
const int butonPin   = 7;

int mod = 0; 

void setup() {
  pinMode(ledKirmizi, OUTPUT);
  pinMode(ledSari, OUTPUT);
  pinMode(ledYesil, OUTPUT);
  
  pinMode(butonPin, INPUT_PULLUP);
}

void loop() {
  switch (mod) {

    case 0:

      digitalWrite(ledYesil, HIGH);
      digitalWrite(ledSari, LOW);
      digitalWrite(ledKirmizi, LOW);
      for (int t = 0; t < 20; t++) {
        if (digitalRead(butonPin) == LOW) {
          delay(50); 
          while (digitalRead(butonPin) == LOW); 
          mod = 1;
          return;
        }
        delay(100); 
      }

      digitalWrite(ledYesil, LOW);
      digitalWrite(ledSari, HIGH);
      digitalWrite(ledKirmizi, LOW);
      for (int t = 0; t < 10; t++) {
        if (digitalRead(butonPin) == LOW) {
          delay(50);
          while (digitalRead(butonPin) == LOW);
          mod = 1;
          return;
        }
        delay(100); 
      }

      digitalWrite(ledYesil, LOW);
      digitalWrite(ledSari, LOW);
      digitalWrite(ledKirmizi, HIGH);
      for (int t = 0; t < 20; t++) {
        if (digitalRead(butonPin) == LOW) {
          delay(50);
          while (digitalRead(butonPin) == LOW);
          mod = 1;
          return;
        }
        delay(100); 
      }
      break;

    case 1:
      digitalWrite(ledYesil, LOW);
      digitalWrite(ledKirmizi, LOW);

      for (int i = 0; i < 5; i++) {
        digitalWrite(ledSari, HIGH);
        delay(300);
        digitalWrite(ledSari, LOW);
        delay(300);

        if (digitalRead(butonPin) == LOW) {
          delay(50);
          while (digitalRead(butonPin) == LOW);
          mod = 2;
          return;
        }
      }

      while (mod == 1) {
        if (digitalRead(butonPin) == LOW) {
          delay(50);
          while (digitalRead(butonPin) == LOW);
          mod = 2;
        }
      }
      break;

    case 2:
      digitalWrite(ledYesil, LOW);
      digitalWrite(ledSari, LOW);
      digitalWrite(ledKirmizi, LOW);

      while (mod == 2) {
        if (digitalRead(butonPin) == LOW) {
          delay(50);
          while (digitalRead(butonPin) == LOW);
          mod = 0;
        }
      }
      break;
  }
}