#include <iostream>
#include <math.h>

int bhaskara(double *x1, double *x2, int a, int b, int c) {
  float delta = pow(b, 2) - (4 * a * c);

  if (delta < 0) {
    return 0;
  }

  *x1 = (-b + sqrt(delta)) / (2 * a);
  *x2 = (-b - sqrt(delta)) / (2 * a);

  return 1;
}

int main (void) {
  int a, b, c;
  double x1, x2;

  std::cout << "Enter the value of a: ";
  std::cin >> a;

  std::cout << "Enter the value of b: ";
  std::cin >> b;

  std::cout << "Enter the value of c: ";
  std::cin >> c;

  int result = bhaskara(&x1, &x2, a, b, c);

  if (result == 0) {
    std::cout << "The delta is negative, so the equation has no real roots." << std::endl;
  } else {
    std::cout << "The roots of the equation are: " << x1 << " and " << x2 << std::endl;
  }

  return 0;
}
