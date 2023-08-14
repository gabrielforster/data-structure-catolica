#include <iostream>

using namespace std;

int rest (int num1, int num2) {
  return num1 % num2;
}

int main () {
  int num1, num2, result = 0;

  cout << "Type a interger number: ";
  cin >> num1;

  cout << "Type another interger number: ";
  cin >> num2;

  cout << "The rest of " << num1 << " divided by " << num2 << " is: " << rest(num1, num2) << endl;

  return 0;
}
