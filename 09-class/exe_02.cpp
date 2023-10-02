#include <cstdlib>
#include <stdio.h>

void insertion_sort (int vec[], int length) {
  int temp;

  for (int i = 1; i < length; i++) {
    temp = vec[i];
    int j = i - 1;

    while (j >= 0 && vec[j] > temp) {
      vec[j + 1] = vec[j];
      j--;
    }

    vec[j + 1] = temp;
  }
}

int main (void) {
 int vec[15];
  
 // populate vec with random values
 for (int i = 0; i < 15; i++) vec[i] = rand() % 100;

 insertion_sort(vec, 15);

 int minor = vec[0], count = 0;

 for (int i = 0; i < 15; i++)
   if (vec[i] == minor) count++;

 printf("The minor value is %d\n", minor);
 printf("It appears %d times in the list\n", count);
}
