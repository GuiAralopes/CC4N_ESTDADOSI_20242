#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANHO 200
// Função para trocar dois elementos
void trocar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Função para dividir o array e retornar a posição do pivô
int particionar(int arr[], int inicio, int fim) {
    int pivo = arr[fim]; // Escolhendo o último elemento como pivô
    int i = (inicio - 1);

    for (int j = inicio; j < fim; j++) {
        if (arr[j] < pivo) {
            i++;
            trocar(&arr[i], &arr[j]);
        }
    }
    trocar(&arr[i + 1], &arr[fim]);
    return (i + 1);
}

// Função recursiva do Quicksort
void quicksort(int arr[], int inicio, int fim) {
    if (inicio < fim) {
        int pi = particionar(arr, inicio, fim); // índice do pivô
        quicksort(arr, inicio, pi - 1);
        quicksort(arr, pi + 1, fim);
    }
}

void preencherArray(int arr[], int tamanho, int tipo) {
    for (int i = 0; i < tamanho; i++) {
        if (tipo == 1) {
            arr[i] = rand() % 100; // Caso aleatório (médio caso)
        } else if (tipo == 2) {
            arr[i] = i; // Caso crescente (pior caso)
        } else if (tipo == 3) {
            arr[i] = tamanho - i; // Caso decrescente (melhor caso)
        }
    }
}

double medirTempoExecucao(void (*sortFunc)(int*, int, int), int *arr, int inicio, int fim) {
    clock_t inicio_tempo = clock();
    sortFunc(arr, inicio, fim);
    clock_t fim_tempo = clock();
    return (double)(fim_tempo - inicio_tempo) / CLOCKS_PER_SEC;
}

// Função principal para executar o código
int main() {
 
 int arr[TAMANHO];
    clock_t inicio, fim;
    double tempo;

    // Caso Médio (array aleatório)
    preencherArray(arr, TAMANHO, 1);
    inicio = clock();
    quicksort(arr, 0, TAMANHO - 1);
    fim = clock();
    tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("Quicksort - Caso Médio: %.6f segundos\n", tempo);

    // Caso Pior (array crescente)
    preencherArray(arr, TAMANHO, 2);
    inicio = clock();
    quicksort(arr, 0, TAMANHO - 1);
    fim = clock();
    tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("Quicksort - Caso Pior: %.6f segundos\n", tempo);

    // Caso Melhor (array decrescente)
    preencherArray(arr, TAMANHO, 3);
    inicio = clock();
    quicksort(arr, 0, TAMANHO - 1);
    fim = clock();
    tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("Quicksort - Caso Melhor: %.6f segundos\n", tempo);

    return 0;
}

