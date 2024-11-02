#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selecao(int arr[], int n) {
  int i, j, menor;

  for (i = 0; i < n - 1; i++) {
    menor = i;
    for (j = i + 1; j < n; j++) {
      if (arr[j] < arr[menor]) {
        menor = j;
      }
    }
    
    int temp = arr[menor];
    arr[menor] = arr[i];
    arr[i] = temp;
  }
}

int main() {
  int arr[50], n = 50, i;

  
  srand(time(NULL));

  
  for (i = 0; i < n; i++) {
    arr[i] = rand() % 100; 
  }

  printf("Array gerado:\n");
  for (i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }

  selecao(arr, n); 

  printf("\nArray ordenado:\n");
  for (i = 0; i < n; i++) {
    printf("%d ", arr[i]); 
  }

  return 0;
}
