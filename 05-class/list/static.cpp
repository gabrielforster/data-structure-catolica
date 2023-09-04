#include <stdio.h>

typedef struct data {
  char name[20];
  int age;
} Data;

int main (void) {
  Data list[5];

  for (int i = 0; i < 5; i++) {
    printf("Enter name: ");
    scanf("%s", list[i].name);
    fflush(stdin);

    printf("Enter age: ");
    scanf("%i", &list[i].age);
    fflush(stdin);
  }

  for (int i = 0; i < 5; i++) {
    printf("Name: %s\n", list[i].name);
    printf("Age: %i\n\n", list[i].age);
  }

  return 0;
}
