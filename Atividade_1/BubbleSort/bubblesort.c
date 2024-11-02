#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubbleSort(int arr[], int n) {
  int i, j, aux;
  for (i = 0; i < n - 1; i++) {
    for (j = 0; j < n - i - 1; j++) {
      
      if (arr[j] > arr[j + 1]) {
        aux = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = aux;
      }
    }
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

  bubbleSort(arr, n); 

  printf("\nArray ordenado:\n");
  for (i = 0; i < n; i++) {
    printf("%d ", arr[i]); 
  }

  return 0;
}
