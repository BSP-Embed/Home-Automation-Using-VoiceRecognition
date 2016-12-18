/*******************************************************************
Home Automation by Voice Recognition using andriod bluetooth
Check our YouTube channel BSPEmbed for project building & Demo
******************************************************************/
/* Port Pins */
int LightPin = 7;
int FanPin = 6;

const char *ControlStrings[] = {"*light on#", "*light off#", "*fan on#", "*fan off#"};

void setup() {
  Serial.begin(9600);
  pinMode(LightPin, OUTPUT);
  pinMode(FanPin, OUTPUT);
  digitalWrite(LightPin, 0);
  digitalWrite(FanPin, 0);
}

void loop() {
  String SerialString; 
  int i;
  while (Serial.available() > 0) {
    SerialString = Serial.readString();
    for (i = 0; i < 4; i++)
      if (SerialString == ControlStrings[i])
        break;
    switch (i) {
      case 0: digitalWrite(LightPin, 1); break;
      case 1: digitalWrite(LightPin, 0); break;
      case 2: digitalWrite(FanPin, 1); break;
      case 3: digitalWrite(FanPin, 0); break;
      default: break;
    }
  }
}
