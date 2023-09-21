 #include <Arduino.h>
 #include <Adafruit_GFX.h>
 #include <Adafruit_SSD1306.h>
 #include <WiFi.h>
 #include <WebServer.h>


 #define LED_PIN 33
 #define BTN_PIN 32

 #define JOY_X 34
 #define JOY_Y 35

 #define SCREEN_WIDTH 128
 #define SCREEN_HEIGHT 64
 #define OLED_RESET -1

  const char *ssid = "Praktyki";
  const char *password = "Praktyki";


  Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
  WebServer server(80);

  void handleGet(){
    Serial.println("dziala");
    display.setCursor(0,0);
    display.println(server.arg("text"));
    display.display();
    server.send(200,"text/plain");
  }

 void setup()
 {
   Serial.begin(115200);
   Wire.begin(23,19);

   Serial.println("hello world");

   WiFi.begin(ssid, password);
   while(WiFi.status() != WL_CONNECTED){
    delay(50);
    Serial.println(".");
   }
   Serial.println(WiFi.localIP());

   if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)){
     Serial.println(F("error"));
       for(;;);
   }
   display.clearDisplay();

  //  display.setTextSize(5);
  // display.setCursor(0, 0);
  //  display.setTextColor(WHITE, BLACK);

  // display.println(F("siemano kolano"));
  //  display.display();

  server.on("/test",HTTP_GET,handleGet);
  server.begin();

  display.setTextSize(1);
  display.setCursor(0,0);
  display.println(WiFi.localIP());
  display.display();

 }

 void loop(){

server.handleClient();

 }





  // int x_1 = -1;
  // int y_1 = -1;
  // bool show_point = true;


//  void loop()
//  {
//   delay(50);
//   int x = map(analogRead(JOY_X), 0, 4095, 0, 127);
//   int y = map(analogRead(JOY_Y), 0, 4095, 0, 63);
//   Serial.println("x" + x);
//   Serial.println("y" + y);

//   if(analogRead(BTN_PIN) == 0){


//     // display.clearDisplay();
//     // Serial.println("display");
//       if(x_1 != -1 && y_1 != -1){
//         x_1 = -1;
//         y_1 = -1;
//       }
//       else{
//       x_1 = x;
//       y_1 = y;
//       }
       
//       if(show_point){
//         show_point = false;
//       }

//   }
//   if(show_point && x_1 != -1 && y_1 != -1){
//     show_point = true;
//     x_1 = -1;
//     y_1 = -1;
//   }

//   display.clearDisplay();
//   if(x_1==-1 && y_1==-1){
//     display.writePixel(x,y, WHITE);
//     Serial.println("pixel");
//   }
//   else{
    
//     display.drawLine(x_1, y_1,x,y,WHITE);
//     Serial.println("linia");
    
//   }
//   display.display();


//  display.writePixel(map(analogRead(JOY_X), 0, 4095, 0, 127),map(analogRead(JOY_Y), 0, 4095, 0, 63),WHITE);
//  display.display();
  // display.clearDisplay();
  // display.setTextSize(3);
  // display.setCursor(0, 0);
  // display.println("przycisk:" + String(analogRead(BTN_PIN)== 0));
  // display.display();

 //}
// pinMode(LED_PIN,OUTPUT);

//    pinMode(BTN_PIN, INPUT_PULLUP);
//    pinMode(BTN_PIN, INPUT);
//   Serial.println("petla");

//    digitalWrite(LED_PIN,HIGH);

//    delay(1000);

//    digitalWrite(LED_PIN,LOW);

//    delay(2000);
//    int buttonState = analogRead(BTN_PIN);
//    Serial.println(buttonState == 0);
//    Serial.println(analogRead(JOY_X));
//    int joystate = analogRead(JOY_X);

//    if(joystate > 1800)
//      digitalWrite(LED_PIN, HIGH);
//    else
//      digitalWrite(LED_PIN, LOW);