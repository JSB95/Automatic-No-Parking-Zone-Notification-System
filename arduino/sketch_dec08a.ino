#include <SoftwareSerial.h>
#include <DFPlayer_Mini_Mp3.h>
//초음파 센서 핀설정
int trigPin = 9;
int echoPin = 8;
 
void setup () {
    Serial.begin (9600);
    mp3_set_serial (Serial);     // DFPlayer-mini mp3 module 시리얼 세팅
    delay(1);                     // 볼륨을 Setup 하기 위한 delay
    mp3_set_volume (30);          // 볼륨 0~30
 
    //초음파 센서 핀설정
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
}
void loop () {
  float duration, distance;
  digitalWrite(trigPin, HIGH);
  delay(10);
  digitalWrite(trigPin, LOW);
 
  // 장애물과의 거리계산
  duration = pulseIn(echoPin, HIGH);
  distance = ((float)(340 * duration) / 10000) / 2;
  delay(100);
  if(distance < 50) //장애물이 50cm 이내일때
  {
    mp3_play(99); //안녕하세요... mp3 (0099.mp3) 파일 플레이
    delay(7000);
  }
}

