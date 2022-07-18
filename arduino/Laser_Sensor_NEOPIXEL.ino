#include <Adafruit_NeoPixel.h>
#define PIN 6
#define BUZ_PIN 9
#include <LiquidCrystal_I2C.h>
#include <Wire.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
int buzzer = 9;
int laser_din=5;
int melody[] = {659,622,659,622,659,622,659,622};


void setup()
{  
  lcd.init();
  lcd.backlight();
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
  delay(50000)
  if(digitalRead(laser_din)==HIGH)
  {
    lcd.setCursor(0,0);
    lcd.print("This is a ");
    lcd.setCursor(0,1);
    lcd.print("NO-PARKING ZONE");
    colorWipe(strip.Color(5, 0, 0), 0); //빨간색 출력
    Serial.println("상태 : 미인식 !");
        delay(50000);
  
  }
  else
  {
    delay(50000)
    colorWipe(strip.Color(50, 0, 0), 0); //빨간색 출력
    delay(50000);
    colorWipe(strip.Color(0, 50, 0), 0); //빨간색 출력
    delay(50000);
    colorWipe(strip.Color(0, 0, 50), 0); //빨간색 출력
    delay(50000);
    Serial.println("상태 : 차량 접근 중!");

    for (int i =0; i<8;i++){
      delay(50000)
      tone(buzzer,melody[i],1000);
      Serial.println("소리나오는중!");
    }
  }
 delay(50000)
}
