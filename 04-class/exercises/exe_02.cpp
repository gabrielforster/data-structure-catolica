#include <stdio.h>
#include <stdlib.h>
#include <cstdio>

#define QUEUE_SIZE 100

void enqueue (int *queue, int *tail, int value) {
  if (*tail < QUEUE_SIZE) {
    queue[*tail] = value;
    *tail = *tail + 1;
  } else {
    printf("Queue is full\n");
  }
}

int dequeue (int *queue, int *head) {
  if (*head < QUEUE_SIZE) {
    int value = queue[*head];
    *head = *head + 1;
    return value;
  } else {
    printf("Queue is empty\n");
    return -1;
  }
}

int main (void) {
  int queue[QUEUE_SIZE];

  int head = 0, tail = 0, search;

  for (int i = 0; i < QUEUE_SIZE; i++) {
    int random = rand() % QUEUE_SIZE;
    enqueue(queue, &tail, random);
  }

  printf("Enter a number to search: ");
  scanf("%i", &search);

  int found = 0;
  while (!found) {
    int value = dequeue(queue, &head);
    if (value == -1)
      break;

    if (value == search) {
      found = 1;
      break;
    }
  }

  if (found) {
    printf("Found at position %i!\n", head + 1);
  } else {
    printf("Not found!\n");
  }
}
