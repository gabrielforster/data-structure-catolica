#include <stdio.h>

int insertion_sort (int *arr, int n) {
  int temp, iter = 0;

  for (int i = 1; i < n; i++) {
    temp = arr[i];
    int j = i - 1;

    while (j >= 0 && arr[j] > temp) {
      arr[j + 1] = arr[j];
      j--;
      iter++;
    }

    arr[j + 1] = temp;
  }

  return iter;
}

int main () {
  int arr[] = {2, 7, 4, 15, 9};
  int size = sizeof(arr) / sizeof(arr[0]);

  int swap = insertion_sort(arr, size);

  for (int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }

  printf("swapped %i times\n", swap);

  return 0;
}
