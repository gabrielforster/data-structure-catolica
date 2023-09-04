#include <cstdlib>
#include <cstring>
#include <stdio.h>

typedef struct data {
  char name[20];
  int age;

  struct data *next;
} List;

int main (void){
  List *head = NULL, *tail = NULL, *aux;

  char name[20];
  int age;

  int option = 1;

  while (option != 0) {
    printf("Type 1 to add an item to the list and 0 to exit and print the list\n\n");
    scanf("%i", &option);

    if (option == 0) {
      break;
    } else if (option < 0 && option > 1) {
      printf("Invalid option\n\n");
      continue;
    }

    printf("Enter name: ");
    scanf("%s", name);
    fflush(stdin);

    printf("Enter age: ");
    scanf("%i", &age);
    fflush(stdin);

    aux = (List *) malloc(sizeof(List));

    if (aux == NULL) {
      printf("Memory allocation error!\n");
      exit(1);
    }

    strcpy(aux->name, name);
    aux->age = age;
    aux->next = NULL;

    if (head == NULL) {
      head = aux;
    } else {
      tail->next = aux;
    }

    tail = aux;
  }

  aux = head;

  while (aux != NULL) {
    printf("Name: %s\n", aux->name);
    printf("Age: %i\n\n", aux->age);

    aux = aux->next;
  }

  return 0;
}
