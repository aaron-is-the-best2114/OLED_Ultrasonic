#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <SR04.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define OLED_RESET     4 // Reset pin # (or -1 if sharing Arduino reset pin  
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#define TRIG_PIN 12
#define ECHO_PIN 11
SR04 sr04 = SR04(ECHO_PIN,TRIG_PIN);
long a;

void show() { // Often used sequence - Function to simplify code
  display.display(); delay(2000); display.fillScreen(SSD1306_BLACK);
}

void setup() {
   Serial.begin(9600);
   if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Old Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
   }
   // Title screen
   display.clearDisplay();
   display.setTextSize(2);                
   display.setTextColor(SSD1306_WHITE);   // Draw white text
   display.setCursor(20,10);
   display.setTextSize(2);                // Medium
   display.println("Welcome");
   show();
   display.setTextSize(1);
   delay(1000);
}

void loop() {
   a=sr04.Distance();
   String dis= String(a) + " cm";
   int dist=a/2.54;
   String dis2= String(dist) + " in";

   Serial.begin(9600);
   display.clearDisplay();
   display.setTextSize(2);                
   display.setTextColor(SSD1306_WHITE);   // Draw white text
   display.setCursor(20,10);
   display.setTextSize(2);                // Medium
   display.println(dis);
   display.setCursor(20,35);
   display.setTextSize(2);
   display.println(dis2);
   show();
   Serial.print(a);
   Serial.println("cm");
   delay(500);

}
