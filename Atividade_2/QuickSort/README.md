# Implementação do Algoritmo Quicksort 

Este projeto apresenta uma implementação do algoritmo de ordenação Quicksort em C. O código inclui a função `quicksort` para ordenar arrays de inteiros e uma função `imprimirArray` para mostrar o estado do array antes e depois da ordenação.

## Casos de Teste

Para entender melhor o comportamento do Quicksort, recomendam-se os seguintes casos de teste. Eles foram incluídos como comentários no código e podem ser ativados ao substituir o array de entrada original.

1. **Array já ordenado**: `{1, 2, 3, 4, 5, 6}`
   - Demonstra o pior caso do algoritmo.

2. **Array em ordem decrescente**: `{6, 5, 4, 3, 2, 1}`
   - Outro caso que representa o pior cenário, exigindo o máximo de comparações.

3. **Array com elementos repetidos**: `{5, 3, 8, 3, 5, 2, 8}`
   - Testa a capacidade do algoritmo de lidar com elementos duplicados.


## Análise de Complexidade

- **Complexidade de Tempo**:
  - **Melhor caso**: \(O(n \log n)\)
  - **Caso médio**: \(O(n \log n)\)
  - **Pior caso**: \(O(n^2)\)

- **Complexidade de Espaço**:
  - \(O(\log n)\) no caso médio e \(O(n)\) no pior caso devido ao uso da pilha de chamadas recursivas.

