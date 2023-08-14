#include <iostream>

using namespace std;

int main () {

  int x, result = 1;

  cout << "Type a interger number: ";
  cin >> x;

  for (int i = 1; i <= x; i++) {
    result*= i;
  }

  cout << "The factorial of " << x << " is: " << result << endl;

  return 0;
}
