#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "Complex.h"

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
#define SCREEN_ADDRESS 0x3C

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

const int potentiometerPinReal = A0;     // Analog pin for real part
const int potentiometerPinImaginary = A1;  // Analog pin for imaginary part

const float potentiometerScale = 5.0;  // Scale factor for potentiometer values

Complex complexNumber(0, 0);  // Initialize complex number with zero

void setup() {
  // Initialize I2C OLED screen
  Wire.begin();
  display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS);
  display.clearDisplay();
  display.display();

  // Set text size and color
  display.setTextSize(1);
  display.setTextColor(WHITE);
}

void loop() {
  // Read potentiometer values
  float realValue = analogRead(potentiometerPinReal) / potentiometerScale;
  float imaginaryValue = analogRead(potentiometerPinImaginary) / potentiometerScale;

  // Update the complex number
  complexNumber.setReal(realValue);
  complexNumber.setImaginary(imaginaryValue);

  // Clear display
  display.clearDisplay();

  // Plot complex number on the screen
  plotComplexNumber(complexNumber);

  // Display the updated screen
  display.display();
}

void plotComplexNumber(Complex number) {
  // Calculate screen coordinates based on complex number values
  int x = map(number.getReal(), -5, 5, 0, SCREEN_WIDTH);
  int y = map(number.getImaginary(), -5, 5, 0, SCREEN_HEIGHT);

  // Draw a point at the calculated coordinates
  display.drawPixel(x, y, WHITE);

  // Print the complex number values
  display.setCursor(0, 0);
  display.print("Real: ");
  display.println(number.getReal());
  display.print("Imaginary: ");
  display.println(number.getImaginary());
}
