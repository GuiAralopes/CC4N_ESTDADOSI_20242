# Implementação do Algoritmo MergeSort em C

Este projeto implementa o algoritmo de ordenação MergeSort em C. O código inclui uma função `mergeSort` recursiva e uma função `merge` para mesclar os subarrays. 

## Casos de Teste

Aqui estão alguns arrays de teste para teste a observar o comportamento do algoritmo

1. **Array já ordenado**: `{1, 2, 3, 4, 5, 6}`

2. **Array em ordem decrescente**: `{6, 5, 4, 3, 2, 1}`

3. **Array com elementos repetidos**: `{5, 3, 8, 3, 5, 2, 8}`

## Análise de Complexidade

- **Complexidade de Tempo**: \(O(n \log n)\) em todos os casos
- **Complexidade de Espaço**: \(O(n)\) devido ao array temporário usado para mesclar os subarrays.

