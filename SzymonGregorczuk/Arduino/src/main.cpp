#include <Arduino.h>

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <WiFi.h>
#include <WebServer.h>


#define JOY_X 34
#define JOY_Y 35
#define LED_PIN 33
#define BIN_PIN 32

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1


const char *ssid = "Praktyki";
const char *password = "Praktyki";

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

WebServer server(80);

void handleGet(){
	Serial.println("dziala");

	display.clearDisplay();
	display.setCursor(0, 0);
	display.println(server.arg("text"));
	display.display();

	server.send(200, "text/plain");

}

void setup() {
	Wire.begin(23, 19);
	Serial.begin(115200);

	WiFi.begin(ssid,password);
	while(WiFi.status() != WL_CONNECTED){
		delay(50);
		Serial.print(".");
	}
	Serial.println(WiFi.localIP());

	Serial.println("hello world!");
	pinMode(LED_PIN, OUTPUT);
	if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3c)){
		Serial.println(F("error"));
		for(;;);
	}

	display.clearDisplay();

	display.setTextSize(1);
	display.setCursor(0,0);
	display.setTextColor(WHITE, BLACK);

	display.println(F("HELLO WORLD!"));
	display.display();

	server.on("/test", HTTP_GET, handleGet);
	server.begin();

	display.setTextSize(1);
	display.setCursor(0, 0);
	display.setTextColor(WHITE, BLACK);
	display.println(WiFi.localIP());
	display.display();
}

int x_1 = -1;
int y_1 = -1;



void loop() {	
	server.handleClient();
}




	// delay(50);
	// int x = map(analogRead(JOY_X), 4095, 0, 127, 0);
	// int y = map(analogRead(JOY_Y), 4095, 0, 127, 0);

	// Serial.println("x: " + x);
	// Serial.println("y: " + y);
	// if(analogRead(BIN_PIN)== 0){

	// 	// display.clearDisplay();
	// 	// display.println("display")
	// 	if(x_1 != -1 && y_1 != -1){
	// 		x_1 = -1;
	// 		y_1 = -1;
	// 	}
	// 	else{
	// 		x_1 = x;
	// 		y_1 = y;
	// 	}


	// }display.clearDisplay();

	// if(x_1 == -1 && y_1 == -1){
	// 	display.writePixel(y, x, WHITE);
	// 	Serial.println("pixel");
	// }
	// else{
	// 	display.drawLine(y_1, x_1, y, x, WHITE);
	// }
	// display.display();
	// display.clearDisplay();
	// display.setTextSize(1);
	// display.setCursor(0,0);
	// display.println("Przycisk" + String(analogRead(BIN_PIN) == 0));
	// display.display();
	// display.drawLine();

