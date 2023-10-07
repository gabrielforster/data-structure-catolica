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
void heapify(int *vetor, int n);
void heap_sort(int *vetor);
void gera_valores_vetor(int *vetor, int op);
void imprimir_vetor(int *vetor);

void heapify(int *vetor, int tamanho, int n) {
  int maior = n; // Inicializa o maior como raiz
  int filho_esquerda = 2 * n + 1;
  int filho_direita = 2 * n + 2;

  // Se o filho esquerdo for maior que a raiz
  if (filho_esquerda < tamanho && vetor[filho_esquerda] > vetor[maior]) {
    maior = filho_esquerda;
  }

  // Se o filho direito for maior que a raiz
  if (filho_direita < tamanho && vetor[filho_direita] > vetor[maior]) {
    maior = filho_direita;
  }

  // Se o maior não for a raiz
  if (maior != n) {
    // Troca a raiz com o maior elemento
    int temp = vetor[n];
    vetor[n] = vetor[maior];
    vetor[maior] = temp;

    // Chama o heapify recursivamente no subárvore afetada
    heapify(vetor, tamanho, maior);
  }
}


void heap_sort (int *vetor) {
  int i, aux, qtd_comparacoes = 0, qtd_trocas = 0;
  clock_t tempo_inicio = clock();

  // Constroi o heap (rearranja o array)
  for (i = TAMANHO_VETOR / 2 - 1; i >= 0; i--) {
    heapify(vetor, TAMANHO_VETOR, i);
  }

  // Extrai elementos do heap um por um
  for (i = TAMANHO_VETOR - 1; i > 0; i--) {
    // Move a raiz atual para o final
    int temp = vetor[0];
    vetor[0] = vetor[i];
    vetor[i] = temp;

    // Chama o heapify na subárvore reduzida
    heapify(vetor, i, 0);
  }

  // Calculando o tempo de execucao do algoritimo
  float tempo_final = clock() - tempo_inicio;

  // Imprimindo dados sobre a execucao do algoritimo
  printf("\nQuantidade de comparacoes: %i\n",qtd_comparacoes);
  printf("Quantidade de trocas: %i\n",qtd_trocas);
  printf("Tempo de execucao do algoritmo: %.3f \n\n",tempo_final/1000);
}

void gera_valores_vetor(int *vetor, int op) {
  int i, j;
  switch (op) {
    case 1: // Gera valores ordenados para o vetor (melhor caso)
      for (i = 0; i < TAMANHO_VETOR; i++) {
        vetor[i] = i;
      }
      break;
    case 2: // gera valores ordenados de forma invertida (pior caso)
      for (i = TAMANHO_VETOR, j = 0; i > 0; i--, j++) {
        vetor[j] = i;
      }
      break;
    case 3: // gera valores de forma aleatoria para o vetor (caso medio)
      for (i = 0; i < TAMANHO_VETOR; i++) {
        vetor[i] = rand() % TAMANHO_VETOR;
      }
      break;
  }
}

void imprimir_vetor(int *vetor) {
  int i;
  for (i = 0; i < TAMANHO_VETOR; i++) {
    printf("%d ", vetor[i]);
  }
  printf("\n");
}

int main (void) {
  int vetor[TAMANHO_VETOR];
  int opcao, i;
  double tempo_gasto;


  printf("Escolha uma opcao:\n");
  printf("1 - Melhor caso\n");
  printf("2 - Pior caso\n");
  printf("3 - Caso medio\n");
  printf("Opcao: ");
  scanf("%i", &opcao);

  printf("opcao escolhida: %i\n", opcao);

  gera_valores_vetor(vetor, opcao);

  printf("Vetor gerado:\n");
  imprimir_vetor(vetor);

  heap_sort(vetor);

  printf("Vetor ordenado:\n");
  imprimir_vetor(vetor);

  return 0;
}
