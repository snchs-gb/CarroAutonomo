/*
Conexões
Display: SCL = A5 e SDA = A4
DHT11: A1
IR: A0
Ultra: TRIG = 8 e ECHO = 7
*/

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "DHT.h"
#include <Ultrasonic.h>

#define DHTPIN A1
#define DHTTYPE DHT11
#define IR A0

Ultrasonic ultrassom(8,7);
DHT dht(DHTPIN, DHTTYPE);

Adafruit_SSD1306 display = Adafruit_SSD1306();

float temperatura;
float umidade;
float distancia;
float cor;

void setup(){
  pinMode(IR, INPUT);
  dht.begin();
  Wire.begin();
  
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.setTextColor(WHITE);
  display.setTextSize(1);
  display.clearDisplay();
  Serial.begin(9600);
}

void loop(){
  temperatura = dht.readTemperature();
  umidade = dht.readHumidity(); 
  distancia = ultrassom.Ranging(CM);
  cor = analogRead(IR);
  
  display.setCursor(1,0);
  display.print("Temperatura: ");
  display.print(temperatura);
  display.print("*C");

  display.setCursor(1,7);
  display.print("Umidade: ");
  display.print(umidade);
  display.print("%");
  
  display.setCursor(1,14);
  display.print("Distancia: ");
  display.print(distancia);
  display.print("cm");
  
  display.setCursor(1,21);
  display.print("Cor:");
  display.print(cor);
  
  display.display(); //send text
  
  delay(100); //01 seg
  
  display.clearDisplay(); //clean display
}
