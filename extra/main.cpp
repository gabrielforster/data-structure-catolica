#include <stdio.h>

typedef struct node {
  int data;

  struct node  *left;
  struct node  *right;
} Node;

Node* insert(Node *root, int data) {
  if (root == NULL) {
    root = new Node();
    root->data = data;
    root->left = NULL;
    root->right = NULL;
  } else if (data <= root->data) {
    root->left = insert(root->left, data);
  } else {
    root->right = insert(root->right, data);
  }

  return root;
}

void inorder(Node *root) {
  if (root == NULL) return;

  inorder(root->left);
  printf("%d ", root->data);
  inorder(root->right);
}

Node* deleteNode(Node *root, int data) {
  if (root == NULL) return root;

  if (data < root->data) {
    root->left = deleteNode(root->left, data);
  } else if (data > root->data) {
    root->right = deleteNode(root->right, data);
  } else {
    // Case 1: No child
    if (root->left == NULL && root->right == NULL) {
      delete root;
      root = NULL;
    } else if (root->left == NULL) {
      // Case 2: One child
      Node *temp = root;
      root = root->right;
      delete temp;
    } else if (root->right == NULL) {
      // Case 2: One child
      Node *temp = root;
      root = root->left;
      delete temp;
    } else {
      // Case 3: 2 children
      Node *temp = root->right;

      while (temp->left != NULL) {
        temp = temp->left;
      }

      root->data = temp->data;
      root->right = deleteNode(root->right, temp->data);
    }
  }

  return root;
}

int main () {
  int data[] ={30, 20, 40, 10, 25, 35, 50, 5, 15, 28, 41, 55};

  Node *root = NULL;

  for (int i = 0; i < 12; i++) {
    root = insert(root, data[i]);
  }

  printf("Inorder traversal of the given tree \n");
  inorder(root);

  printf("\nDelete 20\n");
  root = deleteNode(root, 20);
  printf("Inorder traversal of the modified tree \n");
  inorder(root);
}
