#include <stdlib.h>
#include <stdio.h>

void main(){
  int int_vector[10] = {1,2,3,4,5,6,7,8,9,10};

  printf("%zu", sizeof(int_vector) / sizeof(int));

  return 0;
}
