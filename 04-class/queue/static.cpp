#include <cmath>
#include <cstdio>
#include <deque>
#include <iostream>

#define QUEUE_SIZE 10

using namespace std;

int queue[QUEUE_SIZE];

void log() {
  for (int i = 0; i < QUEUE_SIZE; i++) {
    cout << queue[i] << "\t";
  }

  cout << endl;
}

void enqueue(int item) {
  for (int i = 0; i < QUEUE_SIZE; i++) {
    if (queue[i] == 0) {
      queue[i] = item;
      break;
    }
  }
}

void dequeue() {
  for (int i = 0; i < QUEUE_SIZE; i++) {
    if (queue[i] == 0) continue;
    queue[i] = 0;
    break;
  }

  for (int i = 0; i < QUEUE_SIZE - 1; i++) {
    if (queue[i] == 0) {
      queue[i] = queue[i + 1];
      queue[i + 1] = 0;
    }
  }
}

int main (void) {
  int item;


  do {
    system("clear");

    printf("Type in a number (-1 to exit, -2 to dequeue, -3 to log the queue): ");
    scanf("%i", &item);

    // Clear buffer (fflush(stdin) is not portable)
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}

    if (item == -2) {
      dequeue();
    } else if (item == -3) {
      log();

      printf("Type any key to continue...");
      getchar();
    } else {
      enqueue(item);
    }
  } while (item != -1);
}
