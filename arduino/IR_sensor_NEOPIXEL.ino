#include <Adafruit_NeoPixel.h>
#define PIN 6

int IR_sensor = A0; // IR센서
Adafruit_NeoPixel strip = Adafruit_NeoPixel(4, PIN, NEO_GRB + NEO_KHZ800);

void setup ()
{
  Serial.begin (9600);  // 시리얼 모니터를 사용하기 위해 보드레이트를 9600으로 설정합니다.
  pinMode (IR_sensor, INPUT);
  strip.begin(); //네오픽셀을 초기화하기 위해 모든LED를 off시킨다
  strip.show(); 
}

long gp2y0a21yk (long IR_value)
{
  if (IR_value < 10) IR_value = 10;
  
  return ((67870.0 / (IR_value - 3.0)) - 40.0)/10;
} 

//NeoPixel에 달린 LED를 각각 주어진 인자값 색으로 채워나가는 함수
void colorWipe(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, c);
      strip.show();
      delay(wait);
  }
}


void loop ()
{
  long IR_value = analogRead(IR_sensor);
  long IR_range = gp2y0a21yk(IR_value);
  
if (IR_range >= 60) {
  colorWipe(strip.Color(5, 0, 0), 0); //빨간색 출력
  delay(300);
}

else if (IR_range >= 45 && IR_range < 60) {
  colorWipe(strip.Color(50, 0, 0), 0); //빨간색 출력
delay(700);
  colorWipe(strip.Color(0, 0, 0), 0); //빨간색 출력
delay(700);
}

else if (IR_range >= 30 && IR_range < 45) {
  colorWipe(strip.Color(125, 0, 0), 0); //빨간색 출력
delay(400);
  colorWipe(strip.Color(0, 0, 0), 0); //빨간색 출력
delay(400);
}  

else if (IR_range >= 5 && IR_range < 30) {
  colorWipe(strip.Color(255, 0, 0), 0); //빨간색 출력
delay(120);
  colorWipe(strip.Color(0, 0, 0), 0); //빨간색 출력
delay(120);
}  

else {
  colorWipe(strip.Color(0, 0, 0), 0); //빨간색 출력

}

  
  Serial.print (IR_range);
  Serial.println (" cm");
  Serial.println ();
  delay (100);



  
}


 
