#include <stdio.h>

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

// Função principal para executar o código
int main() {
    // Array original para teste de ordenação
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Array original: ");
    imprimirArray(arr, n);

    // Chamada da função Quicksort
    quicksort(arr, 0, n - 1);
    printf("Array ordenado: ");
    imprimirArray(arr, n);

    // Casos de teste:
    //  Array já ordenado: int arr[] = {1, 2, 3, 4, 5, 6};
    //  Ordem decrescente: int arr[] = {6, 5, 4, 3, 2, 1};
    //  Array com elementos repetidos: int arr[] = {5, 3, 8, 3, 5, 2, 8};


    return 0;
}
