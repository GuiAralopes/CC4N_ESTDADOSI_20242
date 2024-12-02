#include <stdio.h>
#include <stdlib.h>

// Estrutura de um nó da Árvore AVL
typedef struct No {
    int chave;
    int altura;
    struct No* esquerda;
    struct No* direita;
} No;

// Função para obter a altura de um nó
int altura(No* no) {
    return no ? no->altura : 0;
}

// Função para atualizar a altura de um nó
void atualizarAltura(No* no) {
    if (no) {
        no->altura = 1 + (altura(no->esquerda) > altura(no->direita) ? altura(no->esquerda) : altura(no->direita));
    }
}

// Função para calcular o fator de balanceamento
int fatorBalanceamento(No* no) {
    return no ? altura(no->esquerda) - altura(no->direita) : 0;
}

// Rotação simples à direita (LL)
No* rotacaoDireita(No* y) {
    No* x = y->esquerda;
    No* T2 = x->direita;

    // Rotação
    x->direita = y;
    y->esquerda = T2;

    // Atualizar alturas
    atualizarAltura(y);
    atualizarAltura(x);

    return x;
}

// Rotação simples à esquerda (RR)
No* rotacaoEsquerda(No* x) {
    No* y = x->direita;
    No* T2 = y->esquerda;

    // Rotação
    y->esquerda = x;
    x->direita = T2;

    // Atualizar alturas
    atualizarAltura(x);
    atualizarAltura(y);

    return y;
}

// Balanceamento do nó
No* balancear(No* no) {
    atualizarAltura(no);
    int fb = fatorBalanceamento(no);

    // LL
    if (fb > 1 && fatorBalanceamento(no->esquerda) >= 0) {
        return rotacaoDireita(no);
    }

    // RR
    if (fb < -1 && fatorBalanceamento(no->direita) <= 0) {
        return rotacaoEsquerda(no);
    }

    // LR
    if (fb > 1 && fatorBalanceamento(no->esquerda) < 0) {
        no->esquerda = rotacaoEsquerda(no->esquerda);
        return rotacaoDireita(no);
    }

    // RL
    if (fb < -1 && fatorBalanceamento(no->direita) > 0) {
        no->direita = rotacaoDireita(no->direita);
        return rotacaoEsquerda(no);
    }

    return no;
}

// Função para encontrar o menor valor em uma subárvore
No* encontrarMinimo(No* no) {
    while (no->esquerda) {
        no = no->esquerda;
    }
    return no;
}

// Remoção na Árvore AVL
No* remover(No* no, int chave) {
    if (!no) {
        return NULL;
    }

    if (chave < no->chave) {
        no->esquerda = remover(no->esquerda, chave);
    } else if (chave > no->chave) {
        no->direita = remover(no->direita, chave);
    } else {
        // Nó encontrado
        if (!no->esquerda || !no->direita) {
            No* temp = no->esquerda ? no->esquerda : no->direita;
            free(no);
            return temp;
        }

        // Nó com dois filhos
        No* temp = encontrarMinimo(no->direita);
        no->chave = temp->chave;
        no->direita = remover(no->direita, temp->chave);
    }

    return balancear(no);
}

// Inserção na Árvore AVL
No* inserir(No* no, int chave) {
    if (!no) {
        No* novoNo = (No*)malloc(sizeof(No));
        novoNo->chave = chave;
        novoNo->altura = 1;
        novoNo->esquerda = novoNo->direita = NULL;
        return novoNo;
    }

    if (chave < no->chave) {
        no->esquerda = inserir(no->esquerda, chave);
    } else if (chave > no->chave) {
        no->direita = inserir(no->direita, chave);
    }

    return balancear(no);
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

int main() {
    No* raiz = NULL;

    // Inserir 8 elementos predefinidos
    int elementos[] = {50, 30, 70, 20, 40, 60, 80, 10};
    for (int i = 0; i < 8; i++) {
        raiz = inserir(raiz, elementos[i]);
    }

    int opcao, valor;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Inserir\n");
        printf("2. Remover\n");
        printf("3. Exibir Árvore\n");
        printf("4. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite um valor para inserir: ");
                scanf("%d", &valor);
                raiz = inserir(raiz, valor);
                break;
            case 2:
                printf("Digite um valor para remover: ");
                scanf("%d", &valor);
                raiz = remover(raiz, valor);
                break;
            case 3:
                printf("\nÁrvore AVL:\n");
                exibirArvore(raiz, 0);
                break;
            case 4:
                return 0;
            default:
                printf("Opção inválida.\n");
        }
    }
}
