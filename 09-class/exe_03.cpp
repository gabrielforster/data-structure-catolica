#include <cstdlib>
#include <stdio.h>

void selection_sort (int vec[], int length) {
  int selected;

  for (int i = 0; i < length; i++) {
    selected = vec[i];
    for (int j = i + 1; j < length; j++) {
      if (vec[j] < selected) {
        selected = vec[j];
        vec[j] = vec[i];
        vec[i] = selected;
      }
    }
  }
}

int main (void) {
 int vec[15];
  
 // populate vec with random values
 for (int i = 0; i < 15; i++) vec[i] = rand() % 100;

 selection_sort(vec, 15);

 int minor = vec[0], count = 0;

 for (int i = 0; i < 15; i++)
   if (vec[i] == minor) count++;

 printf("The minor value is %d\n", minor);
 printf("It appears %d times in the list\n", count);
}
