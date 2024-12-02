#include <stdio.h>
#include <stdlib.h>

// Estrutura de um nó da Árvore BST
typedef struct No {
    int chave;
    struct No* esquerda;
    struct No* direita;
} No;

// Função para criar um novo nó
No* criarNo(int chave) {
    No* novoNo = (No*)malloc(sizeof(No));
    if (!novoNo) {
        printf("Erro ao alocar memória.\n");
        exit(1);
    }
    novoNo->chave = chave;
    novoNo->esquerda = NULL;
    novoNo->direita = NULL;
    return novoNo;
}

// Inserção na Árvore BST
No* inserir(No* raiz, int chave) {
    if (raiz == NULL) {
        return criarNo(chave);
    }

    if (chave < raiz->chave) {
        raiz->esquerda = inserir(raiz->esquerda, chave);
    } else if (chave > raiz->chave) {
        raiz->direita = inserir(raiz->direita, chave);
    }

    return raiz;
}

// Busca na Árvore BST
No* buscar(No* raiz, int chave) {
    if (raiz == NULL || raiz->chave == chave) {
        return raiz;
    }

    if (chave < raiz->chave) {
        return buscar(raiz->esquerda, chave);
    } else {
        return buscar(raiz->direita, chave);
    }
}

// Encontrar o menor valor na subárvore
No* encontrarMinimo(No* raiz) {
    while (raiz->esquerda != NULL) {
        raiz = raiz->esquerda;
    }
    return raiz;
}

// Remoção na Árvore BST
No* remover(No* raiz, int chave) {
    if (raiz == NULL) {
        return NULL;
    }

    if (chave < raiz->chave) {
        raiz->esquerda = remover(raiz->esquerda, chave);
    } else if (chave > raiz->chave) {
        raiz->direita = remover(raiz->direita, chave);
    } else {
        // Nó encontrado
        if (raiz->esquerda == NULL) {
            No* temp = raiz->direita;
            free(raiz);
            return temp;
        } else if (raiz->direita == NULL) {
            No* temp = raiz->esquerda;
            free(raiz);
            return temp;
        }

        // Nó com dois filhos
        No* temp = encontrarMinimo(raiz->direita);
        raiz->chave = temp->chave;
        raiz->direita = remover(raiz->direita, temp->chave);
    }

    return raiz;
}

// Percorrendo em ordem (in-order)
void percorrerEmOrdem(No* raiz) {
    if (raiz != NULL) {
        percorrerEmOrdem(raiz->esquerda);
        printf("%d ", raiz->chave);
        percorrerEmOrdem(raiz->direita);
    }
}

// Função para exibir a árvore hierarquicamente no terminal
void exibirArvore(No* raiz, int espacos) {
    if (raiz == NULL) {
        return;
    }

    espacos += 5;

    // Exibir a subárvore direita
    exibirArvore(raiz->direita, espacos);

    // Exibir o nó atual
    printf("\n");
    for (int i = 5; i < espacos; i++) {
        printf(" ");
    }
    printf("%d\n", raiz->chave);

    // Exibir a subárvore esquerda
    exibirArvore(raiz->esquerda, espacos);
}

// Função para liberar memória da árvore
void liberarArvore(No* raiz) {
    if (raiz != NULL) {
        liberarArvore(raiz->esquerda);
        liberarArvore(raiz->direita);
        free(raiz);
    }
}

// Função principal para testar a BST
int main() {
    No* raiz = NULL;
    int opcao, valor;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Inserir\n");
        printf("2. Buscar\n");
        printf("3. Remover\n");
        printf("4. Exibir em ordem\n");
        printf("5. Exibir árvore\n");
        printf("6. Sair\n");
        printf("Escolha uma opção: ");
        
        // Tratamento de erro para entrada inválida
        if (scanf("%d", &opcao) != 1) {
            printf("Entrada inválida. Por favor, insira um número entre 1 e 6.\n");
            while (getchar() != '\n'); // Limpar buffer
            continue;
        }

        switch (opcao) {
            case 1:
                printf("Digite um valor para inserir: ");
                if (scanf("%d", &valor) != 1) {
                    printf("Entrada inválida. Insira um número válido.\n");
                    while (getchar() != '\n'); // Limpar buffer
                    break;
                }
                raiz = inserir(raiz, valor);
                break;
            case 2:
                printf("Digite um valor para buscar: ");
                if (scanf("%d", &valor) != 1) {
                    printf("Entrada inválida. Insira um número válido.\n");
                    while (getchar() != '\n'); // Limpar buffer
                    break;
                }
                No* encontrado = buscar(raiz, valor);
                if (encontrado) {
                    printf("Valor %d encontrado.\n", valor);
                } else {
                    printf("Valor %d não encontrado.\n", valor);
                }
                break;
            case 3:
                printf("Digite um valor para remover: ");
                if (scanf("%d", &valor) != 1) {
                    printf("Entrada inválida. Insira um número válido.\n");
                    while (getchar() != '\n'); // Limpar buffer
                    break;
                }
                raiz = remover(raiz, valor);
                break;
            case 4:
                printf("Elementos em ordem: ");
                percorrerEmOrdem(raiz);
                printf("\n");
                break;
            case 5:
                printf("\nÁrvore BST:\n");
                exibirArvore(raiz, 0);
                break;
            case 6:
                liberarArvore(raiz);
                printf("Saindo...\n");
                return 0;
            default:
                printf("Opção inválida. Por favor, insira um número entre 1 e 6.\n");
        }
    }
}
