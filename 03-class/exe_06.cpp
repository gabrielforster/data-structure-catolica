#include <iostream>

// implement pitagoras series 1, 3, 6, 10, 15, 21...
int pitagores_series (int n) {
  if (n == 1) {
    return 1;
  }

  return n + pitagores_series(n - 1);
}

int main (void) {
  int n;

  std::cout << "Enter a number: ";
  std::cin >> n;

  int result = pitagores_series(n);

  std::cout << result << std::endl;

  return 0;
}

