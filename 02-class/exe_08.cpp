#include <iostream>

using namespace std;

struct numbers {
  int num1;
  int num2;
  int num3;
};

numbers change_numbers(numbers num) {
  num.num1 = 20;
  num.num2 = 30;
  num.num3 = 40;

  return num;
}

int main(){
  numbers num;

  cout << "Type a interger number: ";
  cin >> num.num1;

  cout << "Type another interger number: ";
  cin >> num.num2;

  cout << "Type another interger number: ";
  cin >> num.num3;

  cout << "The values are: " << num.num1 << ", " << num.num2 << ", " << num.num3 << endl;

  numbers changed = change_numbers(num);

  cout << "The values now are: " << changed.num1 << ", " << changed.num2 << ", " << changed.num3 << endl;

  return 0;
}
