#include "Complex.h"

Complex::Complex(float r, float i) {
  real = r;
  imaginary = i;
}

float Complex::getReal() {
  return real;
}

void Complex::setReal(float r) {
  real = r;
}

float Complex::getImaginary() {
  return imaginary;
}

void Complex::setImaginary(float i) {
  imaginary = i;
}

Complex Complex::add(Complex c) {
  float r = real + c.getReal();
  float i = imaginary + c.getImaginary();
  return Complex(r, i);
}

Complex Complex::subtract(Complex c) {
  float r = real - c.getReal();
  float i = imaginary - c.getImaginary();
  return Complex(r, i);
}

Complex Complex::multiply(Complex c) {
  float r = real * c.getReal() - imaginary * c.getImaginary();
  float i = real * c.getImaginary() + imaginary * c.getReal();
  return Complex(r, i);
}

Complex Complex::divide(Complex c) {
  float divisor = pow(c.getReal(), 2) + pow(c.getImaginary(), 2);
  float r = (real * c.getReal() + imaginary * c.getImaginary()) / divisor;
  float i = (imaginary * c.getReal() - real * c.getImaginary()) / divisor;
  return Complex(r, i);
}

float Complex::magnitude() {
  return sqrt(pow(real, 2) + pow(imaginary, 2));
}

float Complex::phase() {
  return atan2(imaginary, real);
}

Complex Complex::fromPolar(float magnitude, float phase) {
  float r = magnitude * cos(phase);
  float i = magnitude * sin(phase);
  return Complex(r, i);
}
