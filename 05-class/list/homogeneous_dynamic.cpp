#include <cstdlib>
#include <cstring>
#include <stdio.h>

typedef struct list {
  char name[20];
  int age;
  struct list *next;
} List;

int main(void) {
  int option;
  List *head = NULL, *tail = NULL, *aux;

  char name[20];
  int age;

  do {

    system("clear");

    printf("1. Add\n");
    printf("2. List\n");
    printf("3. Exit\n");
    printf("Option: ");
    scanf("%i", &option);

    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }

    if (option == 1) {
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
    } else if (option == 2) {
      aux = head;

      while (aux != NULL) {
        printf("Name: %s\n", aux->name);
        printf("Age: %i\n\n", aux->age);

        aux = aux->next;
      }

      getchar();
    }

  } while (option != 3);

  return 0;
}
