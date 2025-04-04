#include <Adafruit_GFX.h>
#include <Adafruit_TFTLCD.h>

#define LCD_CS A3
#define LCD_CD A2
#define LCD_WR A1
#define LCD_RD A0
#define LCD_RESET A4

Adafruit_TFTLCD tft(LCD_CS, LCD_CD, LCD_WR, LCD_RD, LCD_RESET);

void setup() {
  tft.begin();
  tft.setRotation(1);
  tft.fillScreen(0xFFFF);
  tft.setTextColor(0x0000);
  tft.setTextSize(2);
  tft.setCursor(20, 40);
  tft.print("Touch Screen!");
}

void loop() {
}