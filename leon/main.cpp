#include <Arduino.h>
#include <Adafruit_SSD1306.h>
#include<Adafruit_GFX.h>
#include <WebServer.h>

#define LED_PIN 33
#define BTN_PIN 32



#define JOY_X 34
#define JOY_Y 35


#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1


const char *ssid="Praktyki";
const char *password="Praktyki";


Adafruit_SSD1306 display(SCREEN_WIDTH,SCREEN_HEIGHT, &Wire, OLED_RESET);

WebServer server(80);
void handleGet(){
server.send(200,"text/plain");

display.clearDisplay();
display.setCursor(0,0);
display.println(server.arg("text"));
display.display();

}
void setup() 
{
  Serial.begin(115200);
  Wire.begin(23, 19);
  
   
  
  

  Serial.println("hello world");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)
  {
   delay(50);
   Serial.print(".");

  }
  Serial.println(WiFi.localIP());
  

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)){
  Serial.println(F("error"));
    
      for (;;); 
      
  }
  Serial.println("display");
  display.clearDisplay();
  display.setTextSize(6);
  display.setCursor(0, 0);
  display.setTextColor(WHITE,BLACK);

  display.println(F("SUS"));
  display.display();

server.on("/test",HTTP_GET,handleGet);
server.begin();

display.setTextSize(2);
display.setCursor(0,0);
display.println(WiFi.localIP());
display.display();

}
// int x_1 = -1;
// int y_1 = -1;
// int show_point = true;
void loop() {
  server.handleClient();
  // delay(50);
  // int x = map(analogRead(JOY_X), 0, 4095, 0 , 127);
  // int y = map(analogRead(JOY_Y),0 , 4095, 0, 63);
  // if (analogRead(BTN_PIN) == 0){
    // display.clearDisplay();
    // Serial.println("display");
    
  //   if (x_1 != -1 && y_1 != -1)
  //   {
  //     int x_1 = -1;
  //     int y_1 = -1;
  //   }
  //   else {
      
  //     int x_1 = x;
  //     int y_1 = y;
  //   }
    

  // }
  // display.clearDisplay();
  // if (x_1 == -1 && y_1 == -1 )
  // {
  //  display.writePixel(x, y, WHITE);
  //  Serial.println("pixel");
  // }
  // else{
    
  //   display.drawLine(x_1, y_1, x, y, WHITE);
  //   Serial.println("linia");
  //   }
  
  
  
  //display.writePixel(map(analogRead(JOY_X), 0 , 4095, 0, 127), map(analogRead(JOY_Y),0 , 4095, 0 , 63),WHITE);
  //display.display();
  // display.clearDisplay();
  // display.setTextSize(3);
  // display.setCursor(0,0);
  // display.println("przycisk" + String(analogRead(BTN_PIN) == 0));
  // display.display();
  // display.drawLine();
}
// Serial.println("loop");
  // Serial.println(analogRead(JOY_X));

  // int JOYState = analogRead(JOY_X);


  // if (JOYState > 1800)
  //   digitalWrite(LED_PIN, HIGH);
  // else
  //   digitalWrite(LED_PIN, LOW);

  
  

  // digitalWrite(LED_PIN, HIGH);

  // delay(1000);

  // digitalWrite(LED_PIN, LOW);

  // delay(2000);
  //int buttonstate = digitalRead(BTN_PIN);
  //Serial.println(buttonstate == 0);
