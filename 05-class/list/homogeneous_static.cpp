#include <iostream>

int main(void) {
  int list[10];

  for (int i = 0; i < 10; i++) {
    list[i] = i * 101;
  }

  for (int i = 0; i < 10; i++) {
    std::cout << list[i] << std::endl;
  }

  return 0;
}
