#include <iostream>

double calc_average(int *vector) {
  int length = sizeof(&vector) / sizeof(vector[0]);
  double total = 0;
  for (int i = 0; i < length; i++) {
    total += vector[i];
  }

  return total / length;
}

int main (void) {
  int size = 7;
  int vector[size];
  double average;

  for (int i = 0; i < size; i++) {
    std::cout << "Enter the grade: ";
    std::cin >> vector[i];
  }

  average = calc_average(vector);

  std::cout << "The average is: " << average << std::endl;
}
