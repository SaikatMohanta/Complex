#include "Complex.h"

void setup() {
  Serial.begin(9600);
  
  // Create two complex numbers
  Complex c1(3.0, 4.0);
  Complex c2(1.0, -2.0);
  
  // Perform operations
  Complex sum = c1.add(c2);
  Complex difference = c1.subtract(c2);
  Complex product = c1.multiply(c2);
  Complex quotient = c1.divide(c2);
  
  // Print results
  Serial.print("Sum: ");
  Serial.print(sum.getReal());
  Serial.print(" + ");
  Serial.print(sum.getImaginary());
  Serial.println("i");
  
  Serial.print("Difference: ");
  Serial.print(difference.getReal());
  Serial.print(" + ");
  Serial.print(difference.getImaginary());
  Serial.println("i");
  
  Serial.print("Product: ");
  Serial.print(product.getReal());
  Serial.print(" + ");
  Serial.print(product.getImaginary());
  Serial.println("i");
  
  Serial.print("Quotient: ");
  Serial.print(quotient.getReal());
  Serial.print(" + ");
  Serial.print(quotient.getImaginary());
  Serial.println("i");
  
  // Magnitude and phase
  float magnitude = c1.magnitude();
  float phase = c1.phase();
  
  Serial.print("Magnitude: ");
  Serial.println(magnitude);
  
  Serial.print("Phase: ");
  Serial.println(phase);
}

void loop() {
  // Code in the loop if needed
}
