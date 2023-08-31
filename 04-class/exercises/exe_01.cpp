#include <stdio.h>
#include <stdlib.h>
#include <cstdio>

#define STACK_MAX 100

// create an algo that finds a term in a stack

void push(int stack[], int *top, int value) {
  if (*top < STACK_MAX) {
    stack[*top] = value;
    *top = *top + 1;
  } else {
    printf("Stack is full.\n");
  }
}

int pop(int stack[], int *top) {
  if (*top > 0) {
    *top = *top - 1;
    return stack[*top];
  } else {
    printf("Stack is empty.\n");
    return -1;
  }
}

int main (void) {
  int stack[STACK_MAX];
  int top = 0;

  for (int i = 0; i < STACK_MAX; i++) {
    int random = rand() % STACK_MAX;
    push(stack, &top, random);
  }
  
  int input;
  printf("Enter a number to search: ");
  scanf("%i", &input);

  printf("Searching for %i...\n", input);

  int found = 0;
  while (!found) {
    int value = pop(stack, &top);

    if (value == -1)
      break;

    if (value == input) {
      found = 1;
      break;
    }
  }

  if (found) {
    printf("Found at position %i!\n", top + 1);
  } else {
    printf("Not found!\n");
  }
}

