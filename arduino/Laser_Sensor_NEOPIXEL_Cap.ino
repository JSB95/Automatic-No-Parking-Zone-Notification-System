#include <Adafruit_NeoPixel.h>
#define PIN 6

int laser_din=2;
Adafruit_NeoPixel strip = Adafruit_NeoPixel(4, PIN, NEO_GRB + NEO_KHZ800);

void setup()
{  
  Serial.begin(9600);
  pinMode(laser_din,INPUT);
  strip.begin(); //네오픽셀을 초기화하기 위해 모든LED를 off시킨다
  strip.show(); 
}

void colorWipe(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, c);
      strip.show();
      delay(wait);
  }
}

void loop()
{
  if(digitalRead(laser_din)==HIGH)
  {
    colorWipe(strip.Color(25, 0, 0), 0); //빨간색 출력
    Serial.println("상태 : 150m구간 내 차량 미인식 !");
  }
  else
  {
      colorWipe(strip.Color(150, 0, 0), 0); //빨간색 출력
    delay(500);
    colorWipe(strip.Color(0, 0, 0), 0); //빨간색 출력
    delay(500);
    Serial.println("상태 : 차량 150m 구간 접근!");
  }

}
