#include <stdio.h>
#include <stdlib.h>
#include <cstdio>

typedef struct person {
  char name[50];
  int age;
} PERSON;

typedef struct queue {
  person *p;
  struct queue *next;
} QUEUE;

void enqueue (PERSON *PERSON, QUEUE **first, QUEUE **last);
QUEUE* dequeue (QUEUE **first, QUEUE **last);

int is_priority (int age) {
  return age >= 60;
}

void bubble_sort_by_priority (QUEUE **first, QUEUE **last) {
  while (1) {
    int swapped = 0;
    QUEUE *aux = *first;

    while (aux->next != NULL) {
      if (is_priority(aux->p->age) && !is_priority(aux->next->p->age)) {
        PERSON *temp = aux->p;
        aux->p = aux->next->p;
        aux->next->p = temp;
        swapped = 1;
      }
      aux = aux->next;
    }

    if (!swapped) break;
  }
}

QUEUE* dequeue (QUEUE **first, QUEUE **last) {
  if (*first != NULL) {
    QUEUE *aux = *first;
    *first = (*first)->next;
    if (*first == NULL)
      *last = NULL;
    return aux;
  } else {
    printf("Queue is empty\n");
    return NULL;
  }
}

void enqueue (PERSON *new_person, QUEUE **first, QUEUE **last) {
  QUEUE *newQueue = (QUEUE*) malloc(sizeof(QUEUE));
  newQueue->p = new_person;
  newQueue->next = NULL;

  if (*first == NULL) {
    *first = newQueue;
  } else {
    (*last)->next = newQueue;
  }

  *last = newQueue;
}

void clear(QUEUE **first, QUEUE **last) {
  QUEUE *aux = *first;

  while (aux != NULL) {
    QUEUE *next = aux->next;
    free(aux);
    aux = next;
  }

  *first = NULL;
  *last = NULL;
}

void log(QUEUE **first, QUEUE **last) {
  QUEUE *aux = *first;

  while (aux != NULL) {
    printf("Name: %s\n", aux->p->name);
    printf("Age: %i\n", aux->p->age);
    aux = aux->next;
  }
}

int main (void) {
  QUEUE *first = NULL, *last = NULL, *aux;
  int option;

  do {
    system("clear");

    printf("Options Menu\n");
    printf("1 add a item\n");
    printf("2 log the QUEUE\n");
    printf("3 remove a item\n");
    printf("4 clear the QUEUE\n");
    printf("5 exit\n");
    printf("Option: ");
    scanf("%i", &option);

    // Clear buffer (fflush(stdin) is not portable)
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
  
    switch (option) {
      case 1: {
        PERSON *newPerson = (PERSON*) malloc(sizeof(PERSON));
        printf("Name: ");
        scanf("%[^\n]s", newPerson->name);

        printf("Age: ");
        scanf("%i", &newPerson->age);

        enqueue(newPerson, &first, &last);
        bubble_sort_by_priority(&first, &last);

        break;
      }
      case 2: {
        log(&first, &last);
        getchar();
        break;
      }
      case 3: {
        aux = dequeue(&first, &last);
        if (aux != NULL) {
          printf("Name: %s\n", aux->p->name);
          printf("Age: %i\n", aux->p->age);
          free(aux);
        }
        getchar();
        break;
      }
      case 4: {
        clear(&first, &last);
        break;
      }
      case 5: {
        clear(&first, &last);
        break;
      }
      default: {
        printf("Invalid option\n");
        getchar();
        break;
      }
    }

  } while (option != 5);
}
