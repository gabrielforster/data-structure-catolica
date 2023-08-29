#include <iostream>
#include <math.h>

int *area(int radius) {
  int *result = &radius;

  *result = M_PI * (*result * *result);

  return result;
}

int main () {
  int radius;
  std::cout << "Enter a radius in milimetters: ";
  std::cin >> radius;

  int result = *area(radius);
  std::cout << "The area of the circle is: " << result << " mm²" << std::endl;

  return 0;
}

