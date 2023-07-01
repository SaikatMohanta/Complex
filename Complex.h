#ifndef Complex_h
#define Complex_h

#include <Arduino.h>
#include <math.h>

class Complex {
  private:
    float real;
    float imaginary;

  public:
    Complex(float r, float i);
    
    // Getters and setters
    float getReal();
    void setReal(float r);
    float getImaginary();
    void setImaginary(float i);
    
    // Operations
    Complex add(Complex c);
    Complex subtract(Complex c);
    Complex multiply(Complex c);
    Complex divide(Complex c);

    // Magnitude (absolute value)
    float magnitude();
    
    // Argument (phase)
    float phase();

    // Conversion from polar to Cartesian
    static Complex fromPolar(float magnitude, float phase);
};

#endif
