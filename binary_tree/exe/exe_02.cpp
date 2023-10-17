#include "stdio.h"
#include "stdlib.h"
#include <cstdlib>

struct tree {
  int value;
  struct tree *left;
  struct tree *right;
};

typedef struct tree Tree;

void insert(Tree **root, int value);
void preorder(Tree *root);
void postorder(Tree *root);

int main (void) {
  Tree *root = NULL;

  insert(&root, 10);
  insert(&root, 5);
  insert(&root, 8);
  insert(&root, 3);
  insert(&root, 15);
  insert(&root, 13);
  insert(&root, 1);
  insert(&root, 18);
  insert(&root, 21);

  printf("Preorder\n");
  preorder(root);

  printf("Postorder\n");
  postorder(root);

  return 0;
}

void insert (Tree **root, int value) {
  if (*root == NULL) {
    *root = (Tree *) malloc(sizeof(Tree));

    (*root)->value = value;
    (*root)->left = NULL;
    (*root)->right = NULL;
  } else if ((**root).value > value) insert(&(*root)->left, value);
  else insert(&(*root)->right, value);
}

void preorder(Tree *root) {
  if (root == NULL) return;

  printf("%i\n", root->value);
  preorder(root->left);
  preorder(root->right);
}

void postorder(Tree *root) {
  if (root == NULL) return;

  postorder(root->left);
  postorder(root->right);
  printf("%i\n", root->value);
}

