#include <stdio.h>
#include <stdlib.h>
#include <time.h>


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

// Função para imprimir o array
void imprimirArray(int V[], int tamanho) {
    for (int i = 0; i < tamanho; i++)
        printf("%d ", V[i]);
    printf("\n");
}


int main() {
    // Exemplo de array para teste
    int V[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(V) / sizeof(V[0]);
    
    // Cópia do array para o MergeSort
    int arr_merge[n];
    for (int i = 0; i < n; i++) arr_merge[i] = V[i];

    printf("Array original: ");
    imprimirArray(V, n);

    // Medição do tempo de execução do MergeSort
    clock_t inicio_merge = clock();
    mergeSort(arr_merge, 0, n - 1);
    clock_t fim_merge = clock();
    double tempo_merge = (double)(fim_merge - inicio_merge) / CLOCKS_PER_SEC;

    printf("Array ordenado por MergeSort: ");
    imprimirArray(arr_merge, n);
    printf("Tempo de execução do MergeSort: %.6f segundos\n", tempo_merge);

    // Casos de teste:
    // 1. Array já ordenado: int V[] = {1, 2, 3, 4, 5, 6};
    // 2. Array em ordem decrescente: int V[] = {6, 5, 4, 3, 2, 1};
    // 3. Array com elementos repetidos: int V[] = {5, 3, 8, 3, 5, 2, 8};
   
    return 0;
}
