#include <stdio.h>

int selection_sort (int vector[], int length) {
  int swapped, selected;

  for (int i = 0; i < length; i++) {
    selected = vector[i];
    for (int j = i + 1; j < length; j++) {
      if (vector[j] < selected) {
        selected = vector[j];
        vector[j] = vector[i];
        vector[i] = selected;
        swapped++;
      }
    }
  }

  return swapped;
}

int main (void) {
  int arr[] = {2, 7, 4, 15, 9};
  int size = sizeof(arr) / sizeof(arr[0]);

  int swap = selection_sort(arr, size);

  for (int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }

  printf("swapped %i times\n", swap);

  return 0;
}
