#include <stdio.h>
#include <stdlib.h>
#include <cstdio>

typedef struct queue {
  int item;
  struct queue *next;
} QUEUE;

QUEUE* dequeue (QUEUE **first, QUEUE **last) {
  QUEUE *aux = *first;
  *first = aux->next;

  if (*first == NULL) {
    *last = NULL;
  }

  return aux;
}

void log (QUEUE *first) {
  if (first == NULL) {
    printf("Empty queue\n");
    return;
  }

  QUEUE *aux = first;
  while (aux != NULL) {
    printf("%i\t", aux->item);
    aux = aux->next;
  }

  printf("\n");
}

void clear (QUEUE **first, QUEUE **last) {
  QUEUE *aux = *first;
  while (aux != NULL) {
    aux = aux->next;
    free(*first);
    *first = aux;
  }

  *last = NULL;
}

int main (void) {
  QUEUE *first = NULL, *last = NULL, *aux;

  int option, item;

  do {
    system("clear");

    printf("Options Menu\n");
    printf("1 add a item\n");
    printf("2 log the queue\n");
    printf("3 remove a item\n");
    printf("4 clear the queue\n");
    printf("5 exit\n");
    printf("Option: ");
    scanf("%i", &option);

    if (option == 1) {
      printf("Type in a number: ");
      scanf("%i", &item);

      QUEUE *new_queue = (QUEUE *) malloc(sizeof(QUEUE));
      new_queue->item = item;
      new_queue->next = NULL;

      if (first == NULL) {
        first = new_queue;
      } else {
        (last)->next = new_queue;
      }

      last = new_queue;
      continue;
    } else if (option == 2) {
      if (first == NULL) {
        printf("Empty queue\n");
      }

      aux = first;
      while (aux != NULL) {
        printf("%i\t", aux->item);
        aux = aux->next;
      }

      printf("\n");
    } else if (option == 3) {
      aux = first;
      first = aux->next;

      if (first == NULL) {
        last = NULL;
      }

      printf("Removed: %i\n", aux->item);
      free(aux);
    } else if (option == 4) {
      aux = first;
      while (aux != NULL) {
        aux = aux->next;
        free(first);
        first = aux;
      }

      last = NULL;

      printf("Queue cleared\n");
    } else if (option == 5) {
      printf("Bye!!!\n");
      break;
    } else {
      printf("Invalid option\n");
      continue;
    }


    printf("Press enter to continue...");
    getchar();
    getchar();
  } while (option != 5);
}
