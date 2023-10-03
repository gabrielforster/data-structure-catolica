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
  int valor;
  struct node *esquerda;
  struct node *direita;
} Node;

// Prototipacao das funcoes
void gera_valores_arvore(int *vetor, int op);
void heap_sort(int *vetor);
void imprimir_arvore(int *vetor);

void heap_sort (int *vetor) {
  int i, aux;
  Node *raiz = NULL;
  Node *novo = NULL;

  // Criando uma balenced tree (arvore binaria balanceada).
  // Em uma arvore binaria balanceada, a estrutura se auto-balanceia a cada insercao
  // ou remocao de um elemento.

  for (i = 0; i < TAMANHO_VETOR; i++) {
    novo = (Node *) malloc(sizeof(Node));
    novo->valor = vetor[i];
    novo->esquerda = NULL;
    novo->direita = NULL;

    // Valida se a raiz e nula
    if (raiz == NULL) {
      // se raiz for nula, recebe o valor do elemento da iteracao
      raiz = novo;
    } else {
      // se raiz nao for nula, percorre a arvore ate encontrar o local correto
      Node *atual = raiz;
      Node *anterior = NULL;

      // Enquanto o elemento atual nao for nulo, percorre a arvore fazendo as devidas validacoes
      while (atual != NULL) {
        anterior = atual;

        // Valida se o valor do elemento da iteracao e menor que o valor do elemento atual
        if (novo->valor < atual->valor) {
          // se for menor, o elemento da iteracao vai para a esquerda
          atual = atual->esquerda;
        } else {
          // se for maior, o elemento da iteracao vai para a direita
          atual = atual->direita;
        }
      }

      // Valida se o valor do elemento da iteracao e menor que o valor do elemento anterior
      if (novo->valor < anterior->valor) {
        // se sim, o elemento atual vira o elemento da esquerda do anterior
        anterior->esquerda = novo;
      } else {
        // se nao, o elemento atual vira o elemento da direita do anterior
        anterior->direita = novo;
      }
    }
  }
}

void gera_valores_arvore(int *vetor, int op) {
  int i, j;
  switch (op) {
    case 1: // Gera valores ordenados para o vetor (melhor caso)
      for (i = 0; i < TAMANHO_VETOR; i++) {
        vetor[i] = i;
      }
      break;
    case 2: // gera valores ordenados de forma invertida (pior caso)
      for (i = TAMANHO_VETOR; i > 0; i--) {
        vetor[i] = i;
      }
      break;
    case 3: // gera valores de forma aleatoria para o vetor (caso medio)
      for (i = 0; i < TAMANHO_VETOR; i++) {
        vetor[i] = rand() % RANDOM;
      }
      break;
  }
}

void imprimir_arvore(int *vetor) {
  int i;
  for (i = 0; i < TAMANHO_VETOR; i++) {
    printf("%d ", vetor[i]);
  }
  printf("\n");
}

int main (void) {
  int vetor[TAMANHO_VETOR];
  int opcao, i;
  clock_t tempo_inicio, tempo_fim;
  double tempo_gasto;


  printf("Escolha uma opcao:\n");
  printf("1 - Melhor caso\n");
  printf("2 - Pior caso\n");
  printf("3 - Caso medio\n");
  printf("Opcao: ");
  scanf("%d", &opcao);

  gera_valores_arvore(vetor, opcao);

  printf("Vetor gerado:\n");
  imprimir_arvore(vetor);

  tempo_inicio = clock();
  heap_sort(vetor);
  tempo_fim = clock();

  printf("Vetor ordenado:\n");
  imprimir_arvore(vetor);

  tempo_gasto = ((double) (tempo_fim - tempo_inicio)) / CLOCKS_PER_SEC;
  printf("Tempo gasto: %lf\n", tempo_gasto);

  return 0;
}
