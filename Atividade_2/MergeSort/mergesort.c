#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANHO 200

void merge(int *V, int inicio, int meio, int fim) {
    int *temp;           // Array temporário para armazenar o merge
    int p1 = inicio;     // Ponteiro para o início do primeiro subarray
    int p2 = meio + 1;   // Ponteiro para o início do segundo subarray
    int tamanho = fim - inicio + 1;
    int i, j, k;
    int fim1 = 0, fim2 = 0;

    temp = (int *)malloc(tamanho * sizeof(int)); 
    if (temp != NULL) {
        for (i = 0; i < tamanho; i++) {
            if (!fim1 && !fim2) {
                // Compara os elementos dos subarrays e armazena o menor na temp
                if (V[p1] < V[p2])
                    temp[i] = V[p1++];
                else
                    temp[i] = V[p2++];

                if (p1 > meio) fim1 = 1;  
                if (p2 > fim) fim2 = 1;  
            } else {
                // Se um dos subarrays terminou, copia o restante do outro
                if (!fim1)
                    temp[i] = V[p1++];
                else
                    temp[i] = V[p2++];
            }
        }
        // Copia os elementos do array temporário de volta para o array original
        for (j = 0, k = inicio; j < tamanho; j++, k++)
            V[k] = temp[j];
    }
    free(temp);  
}

// Função principal do MergeSort (recursiva)
void mergeSort(int *V, int inicio, int fim) {
    int meio;
    if (inicio < fim) {
        meio = (inicio + fim) / 2;      // Encontra o meio do array
        mergeSort(V, inicio, meio);     // Ordena a primeira metade
        mergeSort(V, meio + 1, fim);    // Ordena a segunda metade
        merge(V, inicio, meio, fim);    // Mescla as duas metades ordenadas
    }
}

// Função para medir o tempo de execução
void measureTime(void (*sortFunc)(int[], int, int), int arr[], int n, const char *label) {
    clock_t start = clock();
    sortFunc(arr, 0, n - 1);
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
    measureTime(mergeSort, arr, TAMANHO, "MergeSort - Caso Médio");

    // Caso Pior
    preencherArray(arr, TAMANHO, 2);
    measureTime(mergeSort, arr, TAMANHO, "MergeSort - Caso Pior");

    // Caso Melhor
    preencherArray(arr, TAMANHO, 3);
    measureTime(mergeSort, arr, TAMANHO, "MergeSort - Caso Melhor");
  
    return 0;
}
