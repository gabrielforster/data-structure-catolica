#include <iostream>

using namespace std;

int main() {
  char employee_name[45];
  float employee_salary;

  cout << "Type the employee name: ";
  cin >> employee_name;

  cout << "Type the employee salary: ";
  cin >> employee_salary;

  float discount_value;

  if (employee_salary <= 1000)
    discount_value = 0.08;
  else if (employee_salary > 1000 && employee_salary <= 1500)
    discount_value = 0.085;
  else 
    discount_value = 0.09;

  cout << "The tax was " << discount_value << endl;

  float final_salary = employee_salary - (employee_salary * discount_value);
  discount_value = employee_salary * discount_value;

  cout << "The employee " << employee_name << " has a final salary of " << final_salary << endl;
  cout << "The discount value is: " << discount_value << endl;

  return 0;
}
