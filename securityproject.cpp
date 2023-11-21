#define trigPin 2
#define echoPin 3
#define LEDlampRed 4 
#define LEDlampYellow 5 
#define LEDlampGreen 6 
#define soundbuzzer 7 



const int trigPin = 2; 
const int echoPin = 3;
const int LEDlampRed = 4; 
const int LEDlampYellow = 5; 
const int LEDlampGreen = 6; 
const int buzzer = 7; 
int sound = 500; 

long durationInDigit, distanceInCm;  


void setup()
  {
    Serial.begin(9600);
    pinMode (trigPin, OUTPUT);
    pinMode (trigPin, INPUT);
    pinMode (LEDlampRed, OUTPUT);
    pinMode(LEDlampYellow, OUTPUT);
    pinMode(LEDlampGreen, OUTPUT);
    pinMode (buzzer, OUTPUT);

  }

void loop()
{

  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2); 
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10); 
  digitalWrite(trigPin, LOW); 
  durationInDigit = pulseIn(echoPin, HIGH); 
  distanceInCM = (durationInDigit * 0.034) / 2; 

if (distanceInCm > 50)
  {
      // when the object is very far away from the sensor by more than 50 cms
    digitalWrite(LEDlampGreen, LOW); 
    digitalWrite(LEDlampYellow, LOW); 
    digitalWrite(LEDlampRed, LOW);
    noTone(buzzer);

  }


else if (distanceInCm <= 50 && distanceInCm > 20 )
  {
    // code for when the code is a medium distance from the sensor and it detects it
    digitalWrite(LEDlampGreen, HIGH); 
    digitalWrite(LEDlampYellow, LOW); 
    digitalWrite(LEDlampRed, LOW); 
    noTone(buzzer);

  }

else if (distanceInCm <= 20 && distanceInCm > 5)
  {
      // code for if the object is very close to the sensor
    digitalWrite(LEDlampYellow, HIGH); 
    digitalWrite(LEDlampGreen, HIGH); 
    digitalWrite(LEDlampRed, LOW); 
    tone(buzzer, 500);

  }

else 
  {
    digitalWrite(LEDlampGreen, HIGH); 
    digitalWrite(LEDlampYellow, HIGH); 
    tone(buzzer, 1000); 
    digitalWrite(LEDlampRed, HIGH);
    delay(300); 
    digitalWrite(LEDlampRed, LOW); 
    delay(300);

  }

//the print on the breadboard 

Serial.print (distanceInCm);
Serial.println(" cm"));
}