#include <iostream>

using namespace std;

int main() {
  int x;

  cout << "Type a interger number: ";
  cin >> x;

  for (int i = 0; i <= x; i++) {
    if (!(i&1) || i % 6 == 0)
      cout << i << endl;
  }

  return 0;
}
