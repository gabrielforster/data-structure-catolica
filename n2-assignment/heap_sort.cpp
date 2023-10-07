/*
   Processo avaliativo N2 - Estrutura de Dados

   Equipe 03 - Heap sort
Nomes: Gabriel Forster Rocha, Pablo Arman Schuller, Endric Mateus Fruhauf

Conseguiu chegar no resultado?
- Sim

*/
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define TAMANHO_VETOR 10000
#define RANDOM 100000

// Prototipando as funcoes
void gera_valores_vetor(int *vetor, int op);
void imprimir_vetor(int *vetor, int tamanho);
void heap_sort(int *vetor, int tamanho);
void heapify(int *vetor, int tamanho, int n, int *qtd_comparacoes, int *qtd_trocas);

int main (void) {
  int vetor[TAMANHO_VETOR];
  int opcao, i;

  printf("Escolha uma opcao:\n");
  printf("1 - Melhor caso\n");
  printf("2 - Pior caso\n");
  printf("3 - Caso medio\n");
  printf("Opcao: ");
  scanf("%i", &opcao);

  printf("opcao escolhida: %i\n", opcao);

  gera_valores_vetor(vetor, opcao);

  printf("Vetor gerado: ");
  imprimir_vetor(vetor, TAMANHO_VETOR);

  heap_sort(vetor, TAMANHO_VETOR);

  printf("Vetor ordenado: ");
  imprimir_vetor(vetor, TAMANHO_VETOR);

  return 0;
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
        vetor[i] = rand() % RANDOM;
      }
      break;
  }
}

void imprimir_vetor(int *vetor, int tamanho) {
  int i;
  for (i = 0; i < tamanho; i++) {
    printf("%d ", vetor[i]);
  }
  printf("\n");
}

void heapify(int *vetor, int tamanho, int n, int *qtd_comparacoes, int *qtd_trocas) {
  int maior = n; // Inicializa o maior como raiz
  int filho_esquerda = 2 * n + 1;
  int filho_direita = 2 * n + 2;

  (*qtd_comparacoes)++;
  // Se o filho esquerdo for maior que a raiz
  if (filho_esquerda < tamanho && vetor[filho_esquerda] > vetor[maior]) {
    maior = filho_esquerda;
  }

  (*qtd_comparacoes)++;
  // Se o filho direito for maior que a raiz
  if (filho_direita < tamanho && vetor[filho_direita] > vetor[maior]) {
    maior = filho_direita;
  }

  (*qtd_comparacoes)++;
  // Se o maior não for a raiz
  if (maior != n) {
    // Troca a raiz com o maior elemento
    int temp = vetor[n];
    vetor[n] = vetor[maior];
    vetor[maior] = temp;
    (*qtd_trocas)++;

    // Chama o heapify recursivamente no subárvore afetada
    heapify(vetor, tamanho, maior, qtd_comparacoes, qtd_trocas);
  }
}


void heap_sort (int *vetor, int tamanho) {
  int i, aux, qtd_comparacoes = 0, qtd_trocas = 0;
  clock_t tempo_inicio = clock();

  // Constroi o heap apartir de cada elemento do vetor (rearranja o vetor)
  for (i = tamanho / 2 - 1; i >= 0; i--) {
    heapify(vetor, tamanho, i, &qtd_comparacoes, &qtd_trocas);
  }

  // Extrai, um por um, todos os elementos do heap 
  for (i = tamanho - 1; i > 0; i--) {
    // Move a raiz atual para o final do vetor
    aux = vetor[0];
    vetor[0] = vetor[i];
    vetor[i] = aux;
    qtd_trocas++;

    // Chama o heapify na subarvore reduzida
    heapify(vetor, i, 0, &qtd_comparacoes, &qtd_trocas);
  }

  // Calculando o tempo de execucao do algoritimo
  float tempo_final = clock() - tempo_inicio;

  // Imprimindo dados sobre a execucao do algoritimo
  printf("\nQuantidade de comparacoes: %i\n", qtd_comparacoes);
  printf("Quantidade de trocas: %i\n", qtd_trocas);
  printf("Tempo de execucao do algoritmo: %.3f \n\n",tempo_final/1000);
}
