#include <stdio.h>

int bubble_sort_with_temp(int *arr, int n) {
  int temp, iter = 0;
  bool swapped = true;

  for (int i = 0; i < n - 1; i++) {
    swapped = false;
    for (int j = 1; j < n - i; j++) {
      if (arr[j - 1] > arr[j]) {
        temp = arr[j - 1];
        arr[j - 1] = arr[j];
        arr[j] = temp;
        swapped = true;
      }
    }

    if (!swapped) {
      break;
    } else {
      iter++;
    }
  }

  return iter;
}

int bubble_sort_without_temp(int *arr, int n) {
  int iter = 0;
  bool swapped = true;

  for (int i = 0; i < n - 1; i++) {
    swapped = false;
    for (int j = 1; j < n - i; j++) {
      if (arr[j - 1] > arr[j]) {
        arr[j - 1] = arr[j - 1] + arr[j];
        arr[j] = arr[j - 1] - arr[j];
        arr[j - 1] = arr[j - 1] - arr[j];
        swapped = true;
      }
    }

    if (!swapped) {
      break;
    } else {
      iter++;
    }
  }

  return iter;
}

int reverse_check_buuble_sort(int *arr, int n) {
  int temp, iter = 0;
  bool swapped = true;

  for (int i = n - 1; i > 0; i--) {
    swapped = false;
    for (int j = n - 1; j > n - i - 1; j--) {
      if (arr[j - 1] > arr[j]) {
        temp = arr[j - 1];
        arr[j - 1] = arr[j];
        arr[j] = temp;
        swapped = true;
      }
    }

    if (!swapped) {
      break;
    } else {
      iter++;
    }
  }

  return iter;
}

int reverse_buuble_sort(int *arr, int n) {
  int temp, iter = 0;
  bool swapped = true;

  for (int i = 0; i < n - 1; i++) {
    swapped = false;
    for (int j = 1; j < n - i; j++) {
      if (arr[j - 1] < arr[j]) {
        temp = arr[j - 1];
        arr[j - 1] = arr[j];
        arr[j] = temp;
        swapped = true;
      }
    }

    if (!swapped) {
      break;
    } else {
      iter++;
    }
  }

  return iter;
}

int main() {
  int arr[] = {2, 7, 4, 15, 9, 10};
  int arr2[] = {2, 7, 4, 15, 9, 10};
  int arr3[] = {2, 7, 4, 15, 9, 10};
  int arr4[] = {2, 7, 4, 15, 9, 10};
  int size = sizeof(arr) / sizeof(arr[0]);

  int swap = bubble_sort_with_temp(arr, size);

  for (int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }

  printf("swapped %i times \n", swap);

  swap = bubble_sort_without_temp(arr2, size);

  for (int i = 0; i < size; i++) {
    printf("%d ", arr2[i]);
  }

  printf("swapped %i times\n", swap);

  swap = reverse_check_buuble_sort(arr3, size);

  for (int i = 0; i < size; i++) {
    printf("%d ", arr3[i]);
  }

  printf("swapped %i times\n", swap);

  swap = reverse_buuble_sort(arr4, size);

  for (int i = 0; i < size; i++) {
    printf("%d ", arr4[i]);
  }

  printf("swapped %i times\n", swap);
}
