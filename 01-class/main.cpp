#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

struct point_struct {
  float x;
  float y;
};

typedef point_struct point;

int bubble_sort(int *array) {
  int size = sizeof(&array) / sizeof(array[0]);

  int i, j, aux;

  for (i = 0; i < size; i++) {
    for (j = 0; j < size - 1; j++) {
      if (array[j] > array[j + 1]) {
        aux = array[j];
        array[j] = array[j + 1];
        array[j + 1] = aux;
      }
    }
  }

  return 0;
}

int main () {
  point test;

  cout << "Type the X value: ";
  cin >> test.x;

  cout << "Type the Y value: ";
  cin >> test.y;

  printf("\nThe point is (%.2f, %.2f)\n", test.x, test.y);

  return 0;
}
