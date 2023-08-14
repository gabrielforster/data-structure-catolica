#include <iostream>

int main () {
  for (int i = 0; i < 10; i++)
    if (!(i&1)) std::cout << i << std::endl;

  return 0;
}
