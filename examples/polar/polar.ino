#include "Complex.h"

void setup() {
  Serial.begin(9600);
  
  // Create a complex number in polar form
  float magnitude = 5.0;
  float phase = PI / 4.0; // 45 degrees in radians
  
  // Convert polar to Cartesian form
  Complex c = Complex::fromPolar(magnitude, phase);
  
  // Print Cartesian coordinates
  Serial.print("Cartesian form: ");
  Serial.print(c.getReal());
  Serial.print(" + ");
  Serial.print(c.getImaginary());
  Serial.println("i");
  
  // Print polar coordinates
  Serial.print("Polar form: ");
  Serial.print("Magnitude: ");
  Serial.print(c.magnitude());
  Serial.print(", Phase: ");
  Serial.print(c.phase());
  Serial.println(" radians");
}

void loop() {
  // Code in the loop if needed
}
