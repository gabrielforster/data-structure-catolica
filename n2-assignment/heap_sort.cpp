/*
  Processo avaliativo N2 - Estrutura de Dados

  Equipe 03 - Heap sort
  Nomes: Gabriel Forster Rocha, Pablo Arman Schuller, Endric Mateus Fruhauf

  Conseguiu chegar no resultado?

  Se nao, por que nao conseguiu chegar no resultado?

*/
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define TAMANHO_VETOR 10000
#define RANDOM 100000

// Criando typedef de Node que sera usado na arvore binaria
typedef struct node {
  int data;
  struct node *esquerda;
  struct node *direita;
} Node;

// Prototipacao das funcoes
void gera_valores_arvore(Node *raiz, int op);
void heap_sort(Node *raiz);
void imprimir_arvore(Node *raiz);

void heap_sort (Node *raiz) {
}

void gera_valores_arvore(Node *vetor, int op) {
  int i, j;
  switch (op) {
    case 1: // Gera valores ordenados para o vetor (melhor caso)
      for (i = 0; i < TAMANHO_VETOR; i++) {
      }
      break;
    case 2: // gera valores ordenados de forma invertida (pior caso)
      for (i = 0; i < TAMANHO_VETOR; i++) {
      }
      break;
    case 3: // gera valores de forma aleatoria para o vetor (caso medio)
      for (i = 0; i < TAMANHO_VETOR; i++) {
      }
      break;
  }
}

void imprimir_arvore(Node *raiz) {
  if (raiz != NULL) {
    printf("%d\n", raiz->data);
    imprimir_arvore(raiz->esquerda);
    imprimir_arvore(raiz->direita);
  }
}

int main (void) {
}
