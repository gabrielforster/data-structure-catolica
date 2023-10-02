#include <stdio.h>

typedef struct employee {
  char name[50];
  float salary;
} Employee;

void buuble_sort_by_salary(Employee *arr, int n) {
  Employee temp;
  bool swapped = true;

  for (int i = 0; i < n - 1; i++) {
    swapped = false;
    for (int j = 1; j < n - i; j++) {
      if (arr[j - 1].salary > arr[j].salary) {
        temp = arr[j - 1];
        arr[j - 1] = arr[j];
        arr[j] = temp;
        swapped = true;
      }
    }

    if (!swapped) {
      break;
    }
  }
}

void reverse_buuble_sort_by_salary(Employee *arr, int n) {
  Employee temp;
  bool swapped = true;

  for (int i = n - 1; i > 0; i--) {
    swapped = false;
    for (int j = n - 1; j > n - i - 1; j--) {
      if (arr[j - 1].salary < arr[j].salary) {
        temp = arr[j - 1];
        arr[j - 1] = arr[j];
        arr[j] = temp;
        swapped = true;
      }
    }

    if (!swapped) {
      break;
    }
  }
}

void buuble_sort_by_name (Employee *arr, int n) {
  Employee temp;
  bool swapped = true;

  for (int i = 0; i < n - 1; i++) {
    swapped = false;
    for (int j = 1; j < n - i; j++) {
      if (arr[j - 1].name[0] > arr[j].name[0]) {
        temp = arr[j - 1];
        arr[j - 1] = arr[j];
        arr[j] = temp;
        swapped = true;
      }
    }

    if (!swapped) {
      break;
    }
  }
}

void print_employees(Employee *arr, int n) {
  for (int i = 0; i < n; i++) {
    printf("%s: %.2f\n", arr[i].name, arr[i].salary);
  }
}

int main () {
  Employee arr[10];
  int i;

  for (i = 0; i < 10; i++) {
    printf("Enter name: ");
    scanf("%s", arr[i].name);
    printf("Enter salary: ");
    scanf("%f", &arr[i].salary);
  }

  buuble_sort_by_salary(arr, 10);
  printf("\nSorted by salary:\n");
  print_employees(arr, 10);

  reverse_buuble_sort_by_salary(arr, 10);
  printf("\nReverse sorted by salary:\n");
  print_employees(arr, 10);
  
  buuble_sort_by_name(arr, 10);
  printf("\nSorted by name:\n");
  print_employees(arr, 10);

  return 0;
}
