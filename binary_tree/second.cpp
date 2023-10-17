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
void inorder(Tree *root);

int main (void) {
  Tree *root = (Tree*) malloc(sizeof(Tree));

  insert(&root, 10);
  insert(&root, 7);
  insert(&root, 4);
  insert(&root, 2);
  insert(&root, 9);

  inorder(root);

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

void inorder(Tree *root) {
  if (root == NULL) return;

  inorder(root->left);
  printf("%i\n", root->value);
  inorder(root->right);
}
