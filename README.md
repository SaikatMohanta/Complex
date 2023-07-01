# Complex
A  ARDUINO IDE library to manupulate with Complex Numbers

Here's an explanation of the Complex Number library:

The Complex class represents a complex number with both real and imaginary components. It provides methods for performing common operations on complex numbers, such as addition, subtraction, multiplication, and division. Additionally, it includes functions to calculate the magnitude (absolute value) and phase (argument) of a complex number.

The library consists of two files: Complex.h and Complex.cpp.

Complex.h:
- The `Complex` class is defined with private member variables `real` and `imaginary`, representing the real and imaginary parts of a complex number, respectively.
- Public member functions are defined for the class, including a constructor to initialize a complex number with real and imaginary values, getters and setters for the real and imaginary components, and functions for arithmetic operations (addition, subtraction, multiplication, and division).
- The class also provides functions to calculate the magnitude (absolute value) and phase (argument) of a complex number, as well as a static function `fromPolar` to convert from polar form (magnitude and phase) to Cartesian form (real and imaginary).

Complex.cpp:
- The definitions of the member functions declared in Complex.h are implemented in this file.
- The arithmetic operations (addition, subtraction, multiplication, and division) are performed based on the formulas for complex number operations.
- The magnitude is calculated using the Pythagorean theorem, which takes the square root of the sum of the squares of the real and imaginary components.
- The phase is calculated using the `atan2` function, which returns the arctangent of the ratio of the imaginary and real components, taking into account the signs of the components.
- The `fromPolar` function uses the given magnitude and phase to calculate the real and imaginary components of the complex number in Cartesian form, using trigonometric functions `cos` and `sin`.

In the Arduino sketch, the Complex library is included using `#include "Complex.h"`. Then, an example sketch demonstrates the usage of the library by creating complex numbers, performing operations, and printing the results.

Overall, this library provides a convenient way to manipulate complex numbers in both Cartesian and polar forms, enabling complex number arithmetic and conversions between the two representations.
--------------------------------------------------------------------------------------------------------------------------------------------------------------------

Here's an explanation of the different functions provided by the Complex Number library:

1. `Complex(float r, float i)`: The constructor function that creates a Complex object with a given real part `r` and imaginary part `i`.

2. Getters and Setters:
   - `float getReal()`: Returns the real part of the complex number.
   - `void setReal(float r)`: Sets the value of the real part of the complex number.
   - `float getImaginary()`: Returns the imaginary part of the complex number.
   - `void setImaginary(float i)`: Sets the value of the imaginary part of the complex number.

3. Basic Operations:
   - `Complex add(Complex c)`: Performs addition of the current complex number with another complex number `c` and returns the result.
   - `Complex subtract(Complex c)`: Performs subtraction of the current complex number by another complex number `c` and returns the result.
   - `Complex multiply(Complex c)`: Performs multiplication of the current complex number with another complex number `c` and returns the result.
   - `Complex divide(Complex c)`: Performs division of the current complex number by another complex number `c` and returns the result.

4. Magnitude and Phase:
   - `float magnitude()`: Calculates and returns the magnitude (absolute value) of the complex number.
   - `float phase()`: Calculates and returns the argument (phase) of the complex number.

5. Conversion:
   - `static Complex fromPolar(float magnitude, float phase)`: Static function that creates a Complex object from polar coordinates, given the magnitude and phase. It converts the polar representation to Cartesian form and returns the result.

These functions allow you to perform arithmetic operations, access and modify the real and imaginary parts of a complex number, calculate its magnitude and phase, and convert between polar and Cartesian representations.

By using this custom Complex Number library, you can easily manipulate complex numbers in your Arduino projects, whether in Cartesian or polar form.
-----------------------------------------------------------------------------------------------------------------------------------------------------------------
