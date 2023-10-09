#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#define VECTOR_SIZE 1000

int binary_search(int *vector, int size, int target);
void bubble_sort(int *vector, int size);
void gen_random_values(int *vector);

int main () {

  // int vector with sorted random numbers 
  int vector[VECTOR_SIZE];
  int size = sizeof(vector) / sizeof(vector[0]);
  int target = 1173211456;

  gen_random_values(vector);

  // for (int i = 0; i < VECTOR_SIZE; i++) printf("%i ", vector[i]);

  printf("\nTARGET -> %i\n", target);

  bubble_sort(vector, size);

  int result = binary_search(vector, size, target);

  if (result == -1) {
    printf("Did not find the element\n");
  } else {
    printf("Element present at index %d, size -> %i\n", result, size);
  }

}

void gen_random_values(int *vector) {
  for(int i = 0; i < VECTOR_SIZE; i++) {
    vector[i] = rand() * VECTOR_SIZE;
  }
}

void bubble_sort(int *vector, int size) {
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < (size - 1); j++) {
      if (vector[j] > vector[j + 1]) {
        vector[j] = vector[j] + vector[j + 1];
        vector[j + 1] = vector[j] - vector[j + 1];
        vector[j] = vector[j] - vector[j + 1];
      }
    }
  }
}

int binary_search (int *vector, int size, int target) {
  int middle;
  int left = 0;
  int right = size - 1;

  while (left <= right) {
    middle = (left + right) / 2;
    if (vector[middle] == target)
      return middle;
    else if (vector[middle] < target)
      left = middle + 1;
    else
     right = middle - 1;
  }

  return -1;
}
