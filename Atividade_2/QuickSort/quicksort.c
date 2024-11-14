#include <stdio.h>

#include <time.h>


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

// Função para imprimir o array
void imprimirArray(int arr[], int tamanho) {
    for (int i = 0; i < tamanho; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

double medirTempoExecucao(void (*sortFunc)(int*, int, int), int *arr, int inicio, int fim) {
    clock_t inicio_tempo = clock();
    sortFunc(arr, inicio, fim);
    clock_t fim_tempo = clock();
    return (double)(fim_tempo - inicio_tempo) / CLOCKS_PER_SEC;
}

// Função principal para executar o código
int main() {
    // Exemplo de array para teste
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    // Cópia do array para o Quicksort
    int arr_quick[n];
    for (int i = 0; i < n; i++) arr_quick[i] = arr[i];

    printf("Array original: ");
    imprimirArray(arr, n);

    // Medição do tempo de execução do Quicksort
    clock_t inicio_quick = clock();
    quicksort(arr_quick, 0, n - 1);
    clock_t fim_quick = clock();
    double tempo_quick = (double)(fim_quick - inicio_quick) / CLOCKS_PER_SEC;

    printf("Array ordenado por Quicksort: ");
    imprimirArray(arr_quick, n);
    printf("Tempo de execução do Quicksort: %.6f segundos\n", tempo_quick);

    // Casos de teste:
    //  Array já ordenado: int arr[] = {1, 2, 3, 4, 5, 6};
    //  Ordem decrescente: int arr[] = {6, 5, 4, 3, 2, 1};
    //  Array com elementos repetidos: int arr[] = {5, 3, 8, 3, 5, 2, 8};

    return 0;
}

