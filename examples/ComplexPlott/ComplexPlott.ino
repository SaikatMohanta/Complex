#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "Complex.h"

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "Complex.h"

#define OLED_RESET -1
Adafruit_SSD1306 display(OLED_RESET);

const int potentiometerRealPin = A0;
const int potentiometerImaginaryPin = A1;

const float maxPotValue = 1023.0; // Max value of the analog read (10-bit resolution)

void setup() {
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.display();
  delay(2000); // Initial delay to see the OLED splash screen
  display.clearDisplay();
}

void loop() {
  float realValue = analogRead(potentiometerRealPin) / maxPotValue;
  float imaginaryValue = analogRead(potentiometerImaginaryPin) / maxPotValue;

  Complex complexNumber(realValue, imaginaryValue);

  // Clear the display and set text size
  display.clearDisplay();
  display.setTextSize(1);
  
  // Print the complex number in the Argand plane
  display.setCursor(0, 0);
  display.print("Real: ");
  display.println(complexNumber.getReal());
  display.print("Imaginary: ");
  display.println(complexNumber.getImaginary());
  display.print("Magnitude: ");
  display.println(complexNumber.magnitude());
  display.print("Phase: ");
  display.println(complexNumber.phase());

  // Draw the complex number on the OLED display (scaled for visualization)
  int centerX = 64; // Half the display width
  int centerY = 32; // Half the display height
  int scaledReal = complexNumber.getReal() * 30;
  int scaledImaginary = complexNumber.getImaginary() * 30;
  display.drawLine(centerX, centerY, centerX + scaledReal, centerY - scaledImaginary, WHITE);

  display.display();
  delay(100); // Adjust the delay as needed
}

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
