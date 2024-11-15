#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANHO 200

// Função para obter o maior valor no array
int obterMaximo(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

// Função para fazer a contagem e ordenar os dígitos
void countingSort(int arr[], int n, int exp) {
    int output[n];  // Array de saída
    int count[10] = {0};

    // Conta o número de ocorrências de cada dígito
    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    // Atualiza count[i] para conter a posição de cada dígito no output[]
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Constrói o array de saída
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // Copia o array de saída para arr[]
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

// Função RadixSort
void radixSort(int arr[], int n) {
    int max = obterMaximo(arr, n);

    // Aplica counting sort para cada dígito
    for (int exp = 1; max / exp > 0; exp *= 10)
        countingSort(arr, n, exp);
}

// Função para medir o tempo de execução
void measureTime(void (*sortFunc)(int[], int), int arr[], int n, const char *label) {
    clock_t start = clock();
    sortFunc(arr, n);
    clock_t end = clock();
    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("%s: Tempo de execução: %f segundos\n", label, time_taken);
}

// Função para preencher o array com diferentes casos
void preencherArray(int arr[], int tamanho, int tipo) {
    for (int i = 0; i < tamanho; i++) {
        if (tipo == 1) {
            arr[i] = rand() % 100;  // Caso médio
        } else if (tipo == 2) {
            arr[i] = i;  // Caso crescente
        } else if (tipo == 3) {
            arr[i] = tamanho - i;  // Caso decrescente
        }
    }
}

int main() {
    int arr[TAMANHO];

    // Caso Médio
    preencherArray(arr, TAMANHO, 1);
    measureTime(radixSort, arr, TAMANHO, "RadixSort - Caso Médio");

    // Caso Pior
    preencherArray(arr, TAMANHO, 2);
    measureTime(radixSort, arr, TAMANHO, "RadixSort - Caso Pior");

    // Caso Melhor
    preencherArray(arr, TAMANHO, 3);
    measureTime(radixSort, arr, TAMANHO, "RadixSort - Caso Melhor");

    return 0;
}
