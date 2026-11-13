//Dans ce croquis se tient un test pour la manette et le buzzer passif.

#define VRY A2
#define bzzbzz A0

const int BAS = 0;
const int OPT = 450;
const int HAUT = 900;
int x;
void setup() {
  // put your setup code here, to run once:
  pinMode(bzzbzz, OUTPUT);
  pinMode(VRY, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  x = analogRead(VRY);
  Serial.println(x);
  delay(250);
  if (x < 450) {
    tone(bzzbzz, 296, 500);
  }
  else if (x < 900) {
    noTone(bzzbzz);
  }
  else{
    tone(bzzbzz, 405, 500);
  }
  delay(500);
}
