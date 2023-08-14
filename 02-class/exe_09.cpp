#include <iostream>

using namespace std;

int main () {

  int num1, num2, menu_answer = 1;

  while (menu_answer != 0) {
    cout << endl;
    cout << "Type 1 to check the sum of two numbers." << endl;
    cout << "Type 2 to check the diff between two numbers" << endl;
    cout << "Type 3 to check the the first times two plus the second times three" << endl;
    cout << "Type 4 to check the first times the second" << endl;
    cout << "Type 0 to close the app!" << endl;

    cin >> menu_answer;

    if (menu_answer == 0) {
      cout << "Closing the app!" << endl;
      break;
    }

    cout << "Type a interger number: ";
    cin >> num1;

    cout << "Type another interger number: ";
    cin >> num2;

    switch (menu_answer) {
      case 1:
        cout << "The sum of " << num1 << " and " << num2 << " is: " << num1 + num2 << endl;
        break;
      case 2:
        cout << "The diff between " << num1 << " and " << num2 << " is: " << num1 - num2 << endl;
        break;
      case 3:
        cout << "The first times two plus the second times three of " << num1 << " and " << num2 << " is: " << (num1 * 2) + (num2 * 3) << endl;
        break;
      case 4:
        cout << "The first times the second of " << num1 << " and " << num2 << " is: " << num1 * num2 << endl;
        break;
      default:
        cout << "Invalid answer!" << endl;
        break;
    }
  }

  return 0;
}
