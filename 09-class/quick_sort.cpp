#include <stdio.h>

int quick_sort (int vec[], int length) {
  int swapped;

  if (length > 1) {
    int pivot = vec[length - 1];
    int left[length - 1];
    int right[length - 1];

    int left_size = 0, right_size = 0;

    for (int i = 0; i < length - 1; i++) {
      if (vec[i] < pivot) {
        left[left_size] = vec[i];
        left_size++;
      } else {
        right[right_size] = vec[i];
        right_size++;
      }
    }

    swapped = left_size + right_size;

    swapped += quick_sort(left, left_size);
    swapped += quick_sort(right, right_size);

    int i = 0;

    for (; i < left_size; i++) {
      vec[i] = left[i];
    }

    vec[i] = pivot;

    for (int j = 0; j < right_size; j++) {
      vec[i + j + 1] = right[j];
    }
  } else {
    swapped = 0;
  }

  return swapped;
}

int main (void) {
  int arr[] = {2, 7, 4, 15, 9};
  int size = sizeof(arr) / sizeof(arr[0]);

  int swap = quick_sort(arr, size);

  for (int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }

  printf("swapped %i times\n", swap);

  return 0;
}
