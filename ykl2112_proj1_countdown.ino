/* 
 This sketch used font 2, 4, 7
 
 Make sure all the display driver and pin connections are correct by
 editing the User_Setup.h file in the TFT_eSPI library folder.

 Note that yield() or delay(0) must be called in long duration for/while
 loops to stop the ESP8266 watchdog triggering.
 *
 *
 */
#include <TFT_eSPI.h> // Graphics and font library for ST7735 driver chip
#include <SPI.h>
#include <cstring>
#include <stdio.h>

TFT_eSPI tft = TFT_eSPI();  // Invoke library, pins defined in User_Setup.h

void setup() {
  // put your setup code here, to run once:
  tft.init();
  tft.fillScreen(TFT_WHITE); // white background 
  tft.setRotation(1); // horizontal view 
  tft.setTextColor(TFT_RED, TFT_WHITE);
}

 void reset(){
  tft.fillScreen(TFT_WHITE);
 }

void textAcross(char *message){
  int y = 20;
  int cursor = 5;
  int len = strlen(message);
   tft.setTextFont(2);
   tft.setTextColor(TFT_RED, TFT_WHITE);

   
  for(int i = 0; i < len; i++){
    // print many times 
    if(len < 19){
      tft.setCursor(5 + (i*12), 20);
      tft.println(message[i]);
      tft.setCursor( 5 + (i*12), 40);
      tft.println(message[i]);
      tft.setCursor( 5 + (i*12), 60);
      tft.println(message[i]);
    }
    else{
      // print once 
      tft.setCursor(cursor, y);
      if(message[i] == '\n'){
        cursor = 5;
        y += 20;
        tft.setCursor(cursor, y);
        i++;
      }
      else{
        tft.println(message[i]);
        cursor += 12;
      }
    }
    delay(50);
  }
  delay(200);
  tft.println("");
}

uint16_t COLOR(){
  // maroon magenta red pink 
  uint16_t colorOptions[] = {0x7800, 0xF800, 0xF81F, 0xFE19};
  // generate a random number 
//  int r = random(sizeof(colorOptions));
   int r = random(4);
//   return colorOptions[r];
// for now we are only returning one color 
   return 0x7800;
}
void colorNumber(char *num){
  tft.setCursor( 40, 60);
  // change screen color and text color 
  uint16_t thisColor = COLOR();
  tft.fillScreen(thisColor);
  tft.setTextColor(TFT_WHITE,thisColor);
  // print number 
  tft.setTextFont(4); 
  tft.println(num);
  delay(900);
  
}


void printFast(char *message){
  tft.setTextFont(2); 
  tft.println(message);
  delay(500);
}

void loop() {
  // put your main code here, to run repeatedly:
  char *shortLyrics[] = {"my baby is a", "ten", "We dressing to the", "nine",
  "He pick me up we", "eight", 
  "make me \n feel so \n lucky", "seven",
  "He kiss me in his", "six", "We be making \n love in", "five", "Still the one \n I do this", "four", 
  "I'm trying to \n make us", "three", "From that", "two", "He still the", "one"};
  
  char *endLyrics[] = {"There's ups \n and downs in \n this love", "Got a lot \n to learn in\n this love"};

  int parts = sizeof(shortLyrics);
  for(int i=0; i< parts; i++){
    if(i % 2){
      colorNumber(shortLyrics[i]);
      reset();
    }
    else{
      textAcross(shortLyrics[i]);
    }
  }
  // fill screen and wait 
  tft.fillScreen(0x7800);
  delay(1000);
  // print the last two lyrics 
  printFast(endLyrics[0]);
  delay(1000);
   tft.fillScreen(0x7800);
   printFast(endLyrics[1]);
  delay(1000);
  tft.fillScreen(0x7800);
}
