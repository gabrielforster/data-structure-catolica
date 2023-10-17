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
void print(Tree *root, int depth = 0);

int main (void) {
  Tree *root = NULL;

  insert(&root, 10);
  insert(&root, 7);
  insert(&root, 4);
  insert(&root, 2);
  insert(&root, 9);

  print(root);

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

void print(Tree *root, int depth) {
  if (root == NULL) return;

  const int indent = 4;

  for (int i = 0; i < depth * indent; i++) printf(" ");

  printf("%i\n", root->value);

  print(root->left, depth + 1);
  print(root->right, depth + 1);
}
