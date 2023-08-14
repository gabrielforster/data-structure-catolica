#include <iostream>

using namespace std;

#define discount 0.08

int main() {
  char employee_name[45];
  float employee_salary;

  cout << "Type the employee name: ";
  cin >> employee_name;

  cout << "Type the employee salary: ";
  cin >> employee_salary;

  float final_salary = employee_salary - (employee_salary * discount);

  cout << "The employee " << employee_name << " has a final salary of " << final_salary << endl;

  return 0;
}
