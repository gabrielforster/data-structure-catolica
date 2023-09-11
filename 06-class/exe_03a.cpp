#include <iostream>

using namespace std;

typedef struct stack {
  int data;
  struct stack *next;
} Stack;

typedef struct queue {
  int data;
  struct queue *next;
} Queue;

void push(Stack **stack, int data) {
  Stack *new_stack = (Stack *) malloc(sizeof(Stack));
  new_stack->data = data;
  new_stack->next = *stack;
  *stack = new_stack;
}

int pop(Stack **stack) {
  if (*stack == NULL) {
    return -1;
  }

  Stack *aux = *stack;
  int data = aux->data;
  *stack = aux->next;
  free(aux);
  return data;
}

void enqueue(Queue **queue, int data) {
  Queue *new_queue = (Queue *) malloc(sizeof(Queue));
  new_queue->data = data;
  new_queue->next = NULL;

  if (*queue == NULL) {
    *queue = new_queue;
    return;
  }

  Queue *aux = *queue;
  while (aux->next != NULL) {
    aux = aux->next;
  }

  aux->next = new_queue;
}

int dequeue(Queue **queue) {
  if (*queue == NULL) {
    return -1;
  }

  Queue *aux = *queue;
  int data = aux->data;
  *queue = aux->next;
  free(aux);
  return data;
}

int main(void) {
  Stack *stack = NULL;
  Queue *queue = NULL;

  bool converted = false;
  int option;

  do {  
    system("clear");
      
    cout << "1. Push" << endl;
    cout << "2. Pop" << endl;
    cout << "3. Display Stack" << endl;
    cout << "4. Convert Stack to Queue" << endl;
    cout << "Option: ";
    cin >> option;

    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }

    switch (option) {
      case 1:
        int data;
        cout << "Type the data: ";
        cin >> data;
        push(&stack, data);
        break;
      case 2:
        cout << "Popped: " << pop(&stack) << endl;
        break;
      case 3: {

        if (stack == NULL) {
          printf("Empty stack\n");
          break;
        }

        Stack *aux = stack;
        while (aux != NULL) {
          printf("%i\n", aux->data);
          aux = aux->next;
        }

        cout << "Press any key to continue...";
        getchar();

        break;
      }
      case 4:
        while (stack != NULL) {
          enqueue(&queue, pop(&stack));
        }
        converted = true;
        break;
      default:
        cout << "Invalid option" << endl;
        break;
    }
  } while (!converted);

  cout << "Converted stack to queue" << endl;

  bool exit = false;

  do {
    system("clear");

    cout << "1. Enqueue" << endl;
    cout << "2. Dequeue" << endl;
    cout << "3. Display Queue" << endl;
    cout << "4. Exit" << endl;
    cout << "Option: ";
    cin >> option;

    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }

    switch (option) {
      case 1:
        int data;
        cout << "Type the data: ";
        cin >> data;
        enqueue(&queue, data);
        break;
      case 2:
        cout << "Dequeued: " << dequeue(&queue) << endl;
        break;
      case 3: {

        if (queue == NULL) {
          printf("Empty queue\n");
          break;
        }

        Queue *aux = queue;
        while (aux != NULL) {
          printf("%i\n", aux->data);
          aux = aux->next;
        }

        cout << "Press any key to continue...";
        getchar();

        break;
      }
      case 4:
        exit = true;
        break;
      default:
        cout << "Invalid option" << endl;
        break;
    }
  } while (!exit);

  return 0;
}
