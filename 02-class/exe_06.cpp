#include <iostream>

void change_value(int *value) {
  *value = 20;
}

int main(){

  int num = 10;

  std::cout << "The value of num is: " << num << std::endl;
  change_value(&num);
  std::cout << "The value of num now is: " << num << std::endl;

  return 0;
}
