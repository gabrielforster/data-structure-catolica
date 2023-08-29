#include <iostream>

int rec_fibonacci(int n) {
  if (n == 0 || n == 1) {
    return 1;
  }

  return rec_fibonacci(n - 1) + rec_fibonacci(n - 2);
}


int main (void) {

  int n;

  std::cout << "Enter the position of Fibonacci sequence u wanna see: ";
  std::cin >> n;

  int result = rec_fibonacci(n);

  std::cout << result << std::endl;

  return 0;
}
