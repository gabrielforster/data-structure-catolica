#include <iostream>

int *factorial (int n) {
  int *result = &n;

  for (int i = n - 1; i >= 1; i--) {
    *result *= i;
  }

  return result;
}

int main () {
  int n;
  std::cout << "Enter a number: ";
  std::cin >> n;


  int *result = factorial(n);
  std::cout << *result << std::endl;

  return 0;
}
