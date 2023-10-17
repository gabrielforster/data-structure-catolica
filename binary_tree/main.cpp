#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>

struct tree {
  int value;
  struct tree *left;
  struct tree *right;
};

typedef struct tree *Tree;

void insert(Tree *root, int value);
void inorder(Tree root);

int main (void) {
  Tree root = (Tree) malloc(sizeof(Tree));

  insert(&root, 10);
  insert(&root, 2);
  insert(&root, 3);
  insert(&root, 5);
  insert(&root, 9);
  insert(&root, 8);

  inorder(root);

  return 0;
}

void insert (Tree *root, int value) {
  if (*root == NULL) {
    *root = (Tree) malloc(sizeof(Tree));
    (*root)->value = value;
    (*root)->left = NULL;
    (*root)->right = NULL;
  } else {
    if (value < (*root)->value) {
      insert(&(*root)->left, value);
    } else {
      insert(&(*root)->right, value);
    }
  }
}


void inorder (Tree root) {
  if (root == NULL) return;

  inorder(root->left);
  printf("%i\n", root->value);
  inorder(root->right);
}
