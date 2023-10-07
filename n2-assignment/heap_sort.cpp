/*
 * Processo avaliativo N2 - Estrutura de Dados
 *
 * Equipe 03 - Heap sort 
 * Nomes: Gabriel Forster Rocha, Pablo Arman Schuller, Endric Mateus Fruhauf
 *
 * Conseguiu chegar no resultado? 
 * - Sim
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
  // Inicializamos o "maior" como raiz (pegamos o indice que recebemos e usamos como nossa raiz)
  // e entao calculamos os indices para os filhos da nossa raiz.
  // Por isso nao o lop de criacao da arvore dentro da funcao heap_sort pega ate a metade do vetor.
  // 
  // Ex: Em um vetor de 10 posicoes -> 
  // raiz = vetor[4], filho_esquerda = vetor[9], filho_direita = vetor[10]
  // raiz = vetor[3], filho_esquerda = vetor[7], filho_direita = vetor[8]
  // raiz = vetor[2], filho_esquerda = vetor[5], filho_direita = vetor[6]
  // raiz = vetor[1], filho_esquerda = vetor[3], filho_direita = vetor[4]
  // raiz = vetor[0], filho_esquerda = vetor[1], filho_direita = vetor[2]
  //
  // Importante citar, maior/filho_esquerda/filho_direita nao possuem os valores ainda, mas sim os indices
  int maior = n;
  int filho_esquerda = 2 * n + 1;
  int filho_direita = 2 * n + 2;

  (*qtd_comparacoes)++;
  // Se o filho esquerdo for maior que a raiz, entao o maior se torna o filho esquerdo
  if (filho_esquerda < tamanho && vetor[filho_esquerda] > vetor[maior]) {
    maior = filho_esquerda;
  }

  (*qtd_comparacoes)++;
  // Se o filho direito for maior que a raiz, entao o maior se torna o filho direito
  if (filho_direita < tamanho && vetor[filho_direita] > vetor[maior]) {
    maior = filho_direita;
  }

  (*qtd_comparacoes)++;
  // Se o maior nao for a raiz, entao trocamos a raiz com o maior elemento
  if (maior != n) {
    // Realizando a troca a raiz com o maior elemento
    int temp = vetor[n];
    vetor[n] = vetor[maior];
    vetor[maior] = temp;
    (*qtd_trocas)++;

    // Chama o heapify recursivamente, na subarvore afetada, para ordenar as subarvores
    heapify(vetor, tamanho, maior, qtd_comparacoes, qtd_trocas);
  }
}


void heap_sort (int *vetor, int tamanho) {
  int i, aux, qtd_comparacoes = 0, qtd_trocas = 0;
  clock_t tempo_inicio = clock();

  // Constrio uma heap tree com os elementos do vetor do primeiro indice ate o a metade do vetor 
  // Nao e necessario constriur uma heap com os elementos que estao depois da metade do vetor 
  // pois eles sao inseridos quando a heap e construida
  for (i = tamanho / 2 - 1; i >= 0; i--) {
    heapify(vetor, tamanho, i, &qtd_comparacoes, &qtd_trocas);
  }

  // Extrai, um por um, todos os elementos do heap 
  for (i = tamanho - 1; i > 0; i--) {
    // Move a raiz atual para o final do vetor, fazendo com que o maior elemento fique no final do vetor.
    // Realiza a troca da raiz com o ultimo elemento do vetor.
    aux = vetor[0];
    vetor[0] = vetor[i];
    vetor[i] = aux;
    qtd_trocas++;

    // Chama o heapify para que o tamanho do heap seja reduzido e o vetor seja reordenado
    heapify(vetor, i, 0, &qtd_comparacoes, &qtd_trocas);
  }

  // Calculando o tempo de execucao do algoritimo
  float tempo_final = clock() - tempo_inicio;

  // Imprimindo dados sobre a execucao do algoritimo
  printf("\nQuantidade de comparacoes: %i\n", qtd_comparacoes);
  printf("Quantidade de trocas: %i\n", qtd_trocas);
  printf("Tempo de execucao do algoritmo: %.3f \n\n",tempo_final/1000);
}
