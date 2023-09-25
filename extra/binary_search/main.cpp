#include <stdio.h>


int binarySearch (int vector[], int size, int target) {
    int left = 0;
    int right = size - 1;
  
    while (left <= right) {
      int middle = (left + right) / 2;
  
      if (vector[middle] == target) {
        return middle;
      } else if (vector[middle] < target) {
        left = middle + 1;
      } else {
        right = middle - 1;
      }
    }
  
    return -1;
}

int main () {

  // int arr with sorted random numbers 
  int arr[] = {1, 3, 5, 9, 12, 11, 13, 24, 26, 27, 29, 30, 32};
  int size = sizeof(arr) / sizeof(arr[0]);
  int target = 12;

  int result = binarySearch(arr, size, target);

  if (result == -1) {
    printf("Did not find the element\n");
  } else {
    printf("Element present at index %d\n", result);
  }

}
