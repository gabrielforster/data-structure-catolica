#include <iostream>

int rec_factorial(int n) {
  if (n == 1) {
    return 1;
  }

  return n * rec_factorial(n - 1);
}

int main () {
  int n;
  std::cout << "Enter a number: ";
  std::cin >> n;

  int result = rec_factorial(n);

  std::cout << result << std::endl;

  return 0;
}
