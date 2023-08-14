#include <iostream>
#include <cmath>

using namespace std;

int main () {
  int num, result = 0;

  cout << "Type a interger number: ";
  cin >> num;

  for (int i = 1; i <= num; i++)
    result+= pow(i, 2);

  cout << "The result is: " << result << endl;

  return 0;
}

