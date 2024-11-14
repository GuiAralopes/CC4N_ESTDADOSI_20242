# Implementação do Algoritmo MergeSort em C

Este projeto implementa o algoritmo de ordenação MergeSort em C. O código inclui uma função `mergeSort` recursiva e uma função `merge` para mesclar os subarrays. 

## Casos de Teste

Aqui estão alguns arrays de teste para teste a observar o comportamento do algoritmo

1. **Array já ordenado**: `{1, 2, 3, 4, 5, 6}`

2. **Array em ordem decrescente**: `{6, 5, 4, 3, 2, 1}`

3. **Array com elementos repetidos**: `{5, 3, 8, 3, 5, 2, 8}`

## Análise de Complexidade

### Complexidade de Tempo

- **Melhor Caso**: \( O(n \log n) \) — O `MergeSort` precisa de tempo \( O(n \log n) \) mesmo que o array já esteja ordenado, pois ele ainda precisa dividir e mesclar os subarrays.
  
- **Caso Médio**: \( O(n \log n) \) — O algoritmo precisa dividir o array repetidamente e mesclar as partes, mantendo a complexidade de \( O(n \log n) \) em cenários típicos.

- **Pior Caso**: \( O(n \log n) \) — O `MergeSort` sempre realiza as mesmas operações independentemente da ordem inicial dos elementos, resultando em uma complexidade de tempo consistente de \( O(n \log n) \) mesmo quando o array está em ordem inversa.

### Complexidade de Espaço

- **Complexidade de Espaço**: \( O(n) \) — Devido ao uso de um array temporário para armazenar os elementos durante a mesclagem, o `MergeSort` requer espaço adicional proporcional ao tamanho do array original.

## Exemplo de Saída

Com um array de 200 elementos, temos os tempos de execução observados para cada caso:

- **Caso Médio**: `0.000029 segundos`
- **Caso Pior**: `0.000013 segundos`
- **Caso Melhor**: `0.000012 segundos`

