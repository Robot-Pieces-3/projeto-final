#include <Servo.h>
#include <Ultrasonic.h>

#define pinRele_1 2
#define pinRele_2 3
#define ledvd 4
#define ledvm 5
#define pino_echo 9
#define pino_trigger 10
 
Servo servo;

Ultrasonic ultrasonic(pino_trigger, pino_echo);

void setup (){
  pinMode(pinRele_1, OUTPUT);
  pinMode(pinRele_2, OUTPUT);
  Serial.begin(9600);
  Serial.print("Lendo dados do sensor...");
  servo.attach(12);
}

void loop() {
  float cm;
  long microsec = ultrasonic.timing();
  cm = ultrasonic.convert(microsec, Ultrasonic::CM);
  Serial.print("distancia em cm:");
  Serial.println(cm);
  delay(150);
 
  if (cm >= 30) {
    digitalWrite(pinRele_1, 0);
    JogaTudo();
    digitalWrite(ledvd, 1 );
    digitalWrite(ledvm, 0 );
 
  } else {
    digitalWrite(pinRele_1, 1);
    digitalWrite(ledvm, 1 );
    digitalWrite(ledvd, 0 );
    servo.write(90);
    digitalWrite(pinRele_2, 1);
  }
}
void JogaTudo()
{
  servo.write(70);
  digitalWrite(pinRele_2, 0);
    delay (260);
  servo.write(90);
  digitalWrite(pinRele_2, 1);
   delay(300);

}
