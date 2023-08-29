#include <stdlib.h>
#include <stdio.h>
#include <cstdio>

typedef struct stack {
  int item;
  struct stack *next;
} STACK;

void push (STACK **top, int item) {
  STACK *new_stack = (STACK *) malloc(sizeof(STACK));
  new_stack->item = item;
  new_stack->next = *top;
  *top = new_stack;
}

STACK* pop (STACK **top) {
  STACK *aux = *top;
  *top = aux->next;
  return aux;
}

void log (STACK *top) {
  if (top == NULL) {
    printf("Empty stack\n");
    return;
  }

  STACK *aux = top;
  while (aux != NULL) {
    printf("%i\n", aux->item);
    aux = aux->next;
  }
}

void clear (STACK **top) {
  STACK *aux = *top;
  while (aux != NULL) {
    aux = aux->next;
    free(*top);
    *top = aux;
  }
}

int main (void) {
  int option, item;
  STACK *top = NULL, *aux;

  do {
    system("clear");

    printf("Options Menu\n");
    printf("1 add a item\n");
    printf("2 log the stack\n");
    printf("3 remove a item\n");
    printf("4 clear the stack\n");
    printf("5 exit\n");
    printf("Option: ");
    scanf("%i", &option);

    // Clear buffer (fflush(stdin) is not portable)
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}

    if (option < 1 || option > 5) {
      printf("Invalid option(Type any key to continue)");
      getchar();
    }

    if (option == 1) {
      printf("Type a number: ");
      scanf("%i", &item);
      fflush(stdin);
      push(&top, item);
    }

    if (option == 2) {
      log(top);

      printf("Type any key to continue");
      getchar();
    }

    if (option == 3) {
      aux = pop(&top);
      if (aux != NULL) {
        printf("Item removed: %i\n", aux->item);
      }

      printf("Type any key to continue");
      getchar();
    }

    if (option == 4) {
      clear(&top);
      printf("Stack cleared\n");

      printf("Type any key to continue");
      getchar();
    }
  } while (option != 5);
}
