# Implementação do Algoritmo Quicksort 

Este projeto apresenta uma implementação do algoritmo de ordenação Quicksort em C. O código inclui a função `quicksort` para ordenar arrays de inteiros e uma função `imprimirArray` para mostrar o estado do array antes e depois da ordenação.

## Estrutura do Código

1. **Função `merge`**: Mescla duas metades ordenadas do array principal em um array temporário.
2. **Função `mergeSort`**: Divide o array recursivamente e utiliza a função `merge` para combinar os subarrays ordenados.
3. **Função `measureTime`**: Mede o tempo de execução do MergeSort para diferentes casos de teste.
4. **Função `preencherArray`**: Popula o array com valores para simular três cenários:
   - Caso Médio: Elementos aleatórios.
   - Caso Melhor: Elementos em ordem crescente.
   - Caso Pior: Elementos em ordem decrescente.


## Casos de Teste

1. **Caso Médio**: Array preenchido com valores aleatórios entre 0 e 99.
2. **Caso Melhor**: Array já ordenado em ordem crescente.
3. **Caso Pior**: Array em ordem decrescente.

## Análise de Complexidade

### Complexidade de Tempo

- **Caso Médio**: \( O(n \log n) \) — O MergeSort divide o array e mescla os elementos independentemente da configuração inicial dos dados, mantendo a complexidade \( O(n \log n) \).
  
- **Caso Melhor**: \( O(n \log n) \) — Mesmo com o array já ordenado, o algoritmo ainda precisa dividir e mesclar o array.
  
- **Caso Pior**: \( O(n \log n) \) — Em um array ordenado de forma inversa, o MergeSort mantém a complexidade \( O(n \log n) \), dividindo e mesclando os elementos.

### Complexidade de Espaço

- **Complexidade de Espaço**: \( O(n) \) — Devido ao array temporário necessário para armazenar os elementos durante o processo de mesclagem.

## Resultados de Execução

Os tempos de execução foram medidos para um array de 200 elementos em cada caso:

- **Caso Médio**: `0.000029 segundos`
- **Caso Pior**: `0.000013 segundos`
- **Caso Melhor**: `0.000012 segundos`

