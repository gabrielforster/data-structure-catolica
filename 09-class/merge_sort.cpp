#include <stdio.h>

int merge_sort (int vec[], int length) {
  int swap = 0;

  if (length > 1) {
    int mid = length / 2;
    int left[mid];
    int right[length - mid];

    for (int i = 0; i < mid; i++) left[i] = vec[i];
    for (int i = mid; i < length; i++) right[i - mid] = vec[i];

    swap += merge_sort(left, mid);
    swap += merge_sort(right, length - mid);

    int i = 0, j = 0, k = 0;

    while (i < mid && j < length - mid) {
      if (left[i] < right[j]) {
        vec[k] = left[i];
        i++;
      } else {
        vec[k] = right[j];
        j++;
      }

      k++;
    }

    while (i < mid) {
      vec[k] = left[i];
      i++;
      k++;
    }

    while (j < length - mid) {
      vec[k] = right[j];
      j++;
      k++;
    }

    swap += i + j;
  }

  return swap;
}

int main (void) {
  int arr[] = {2, 7, 4, 15, 9};
  int size = sizeof(arr) / sizeof(arr[0]);

  int swap = merge_sort(arr, size);

  for (int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }

  printf("swapped %i times\n", swap);

  return 0;
}
