# Implementação do Algoritmo RadixSort em C

Este projeto implementa o algoritmo de ordenação RadixSort em C, que ordena números inteiros, um dígito por vez, utilizando o método de ordenação por contagem (Counting Sort) como sub-rotina. O código inclui funções para obter o maior valor no array, realizar a contagem e ordenação dos dígitos, e medir o tempo de execução do RadixSort em diferentes cenários.

## Estrutura do Código

1. **Função `obterMaximo`**: Encontra o maior valor do array, usado para determinar o número de dígitos do maior elemento.
2. **Função `countingSort`**: Ordena os elementos de acordo com o dígito atual (unidade, dezena, centena, etc.) usando o método de ordenação por contagem.
3. **Função `radixSort`**: A função principal do RadixSort. Para cada dígito do maior elemento, chama a função `countingSort` para ordenar os números de acordo com aquele dígito específico.
4. **Função `preencherArray`**: Popula o array para três cenários distintos:
   - Caso Médio: Elementos aleatórios entre 0 e 99.
   - Caso Pior: Elementos em ordem crescente.
   - Caso Melhor: Elementos em ordem decrescente.


## Casos de Teste

Três tipos de configurações de dados foram utilizados para avaliar o desempenho do RadixSort em um array de 200 elementos:

1. **Caso Médio**: Array com valores aleatórios (representa o caso comum).
2. **Caso Pior**: Array em ordem crescente (caso que pode aumentar a complexidade dependendo dos valores).
3. **Caso Melhor**: Array em ordem decrescente (também pode apresentar variações de tempo de acordo com o dataset).

## Análise de Complexidade

### Complexidade de Tempo

- **Complexidade de Tempo**: \(O(d \times (n + k))\), onde:
  - \(n\) é o número de elementos no array,
  - \(d\) é o número de dígitos do maior número no array, e
  - \(k\) é o intervalo de valores dos dígitos (0 a 9, portanto \(k = 10\)).
  
  O RadixSort é eficiente para números inteiros e funciona bem para entradas grandes, especialmente se o número de dígitos for pequeno em comparação ao número de elementos.

### Complexidade de Espaço

- **Complexidade de Espaço**: \(O(n + k)\), onde \(n\) é o número de elementos e \(k\) é o intervalo de valores dos dígitos. O uso do array de saída e do array de contagem contribui para essa complexidade.

## Resultados de Execução

Os tempos de execução observados para o RadixSort em um array de 200 elementos são os seguintes:

- **Caso Médio**: `0.000007 segundos`
- **Caso Pior**: `0.000009 segundos`
- **Caso Melhor**: `0.000008 segundos`
