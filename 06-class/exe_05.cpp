#include <iostream>

using namespace std;

typedef struct Node {
  int data;
  struct Node *next;
  struct Node *last;
} ListNode;

Node* create_node(int data) {
  Node *new_node = (Node *) malloc(sizeof(Node));
  new_node->data = data;
  new_node->next = NULL;
  new_node->last = NULL;
  return new_node;
}

void insert_node(ListNode **head, int data) {
  Node* new_node = create_node(data);

  if (*head == NULL) {
    *head = new_node;
    return;
  }

  Node *aux = *head;

  while (aux->next != NULL) {
    aux = aux->next;
  }

  aux->next = new_node;
  new_node->last = aux;
}

void delete_node(ListNode **head, int data) {
  if (*head == NULL) {
    return;
  }

  Node *aux = *head;

  while (aux != NULL) {
    if (aux->data == data) {
      if (aux->last == NULL) {
        *head = aux->next;
        free(aux);
        return;
      }

      aux->last->next = aux->next;
      free(aux);
      return;
    }

    aux = aux->next;
  }
}

void print_list(ListNode *head, int how_many, bool reverse) {
  if (head == NULL) {
    return;
  }

  if (how_many == 0) {
    return;
  }

  if (reverse) {
    Node *aux = head;

    while (aux->next != NULL) {
      aux = aux->next;
    }

    while (aux != NULL && how_many-- > 0) {
      cout << aux->data << " ";
      aux = aux->last;
    }

    return;
  }

  Node *aux = head;

  while (aux != NULL && how_many-- > 0) {
    cout << aux->data << " ";
    aux = aux->next;
  }
}

int main (void) {
  ListNode *head = NULL;
  bool exit = false;

  do {
    system("clear");

    int option;

    cout << "1. Insert node" << endl;
    cout << "2. Delete node" << endl;
    cout << "3. Print list from start" << endl;
    cout << "4. Print list from end" << endl;
    cout << "5. Exit" << endl;
    cout << "Option: ";
    cin >> option;

    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }

    switch (option) {
      case 1: {
        int data;
        cout << "Data: ";
        cin >> data;

        insert_node(&head, data);
        break;
      }

      case 2: {
        int data;
        cout << "Data: ";
        cin >> data;

        delete_node(&head, data);
        break;
      }

      case 3: {
        int how_many;
        cout << "How many: ";
        cin >> how_many;

        print_list(head, how_many, false);

        printf("Press enter to continue...");
        getchar();
        break;
      }

      case 4: {
        int how_many;
        cout << "How many: ";
        cin >> how_many;

        print_list(head, how_many, true);

        printf("Press enter to continue...");
        getchar();
        break;
      }

      case 5: {
        exit = true;
        break;
      }

      default: {
        cout << "Invalid option" << endl;
        break;
      }
    }

  } while (!exit);

  return 0;
}

