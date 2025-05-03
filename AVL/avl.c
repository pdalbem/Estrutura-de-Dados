#include <stdio.h>
#include <stdlib.h>
#include "avl.h"

typedef struct no {
    int valor;
    int altura;
    struct no *esq;
    struct no *dir;
}No;

struct arvore {
    No *raiz;
};

int max(int a, int b) {
    return (a > b) ? a : b;
}

int altura(No* n) {
    return n ? n->altura : 0;
}

int fator_balanceamento(No* n) {
    return n ? altura(n->esq) - altura(n->dir) : 0;
}

No* rotacao_direita(No* y) {
    No* x = y->esq;
    No* T2 = x->dir;

    x->dir = y;
    y->esq = T2;

    y->altura = 1 + max(altura(y->esq), altura(y->dir));
    x->altura = 1 + max(altura(x->esq), altura(x->dir));

    return x;
}

No* rotacao_esquerda(No* x) {
    No* y = x->dir;
    No* T2 = y->esq;

    y->esq = x;
    x->dir = T2;

    x->altura = 1 + max(altura(x->esq), altura(x->dir));
    y->altura = 1 + max(altura(y->esq), altura(y->dir));

    return y;
}

No* criar_no(int valor) {
    No* novo = malloc(sizeof(No));
    if (novo) {
        novo->valor = valor;
        novo->esq = novo->dir = NULL;
        novo->altura = 1;
    }
    return novo;
}

No* inserir_no(No* raiz, int valor) {
    if (raiz == NULL) return criar_no(valor);

    if (valor < raiz->valor)
        raiz->esq = inserir_no(raiz->esq, valor);
    else if (valor > raiz->valor)
        raiz->dir = inserir_no(raiz->dir, valor);
    else
        return raiz; // valor duplicado

    raiz->altura = 1 + max(altura(raiz->esq), altura(raiz->dir));
    int fb = fator_balanceamento(raiz);

    // Casos de rotação
    if (fb > 1 && valor < raiz->esq->valor)
        return rotacao_direita(raiz);
    if (fb < -1 && valor > raiz->dir->valor)
        return rotacao_esquerda(raiz);
    if (fb > 1 && valor > raiz->esq->valor) {
        raiz->esq = rotacao_esquerda(raiz->esq);
        return rotacao_direita(raiz);
    }
    if (fb < -1 && valor < raiz->dir->valor) {
        raiz->dir = rotacao_direita(raiz->dir);
        return rotacao_esquerda(raiz);
    }

    return raiz;
}

void inserir(Arvore* arvore, int valor) {
    arvore->raiz = inserir_no(arvore->raiz, valor);
}

No* encontrar_minimo(No* raiz) {
    while (raiz->esq) raiz = raiz->esq;
    return raiz;
}

No* remover_no(No* raiz, int valor) {
    if (!raiz) return NULL;

    if (valor < raiz->valor)
        raiz->esq = remover_no(raiz->esq, valor);
    else if (valor > raiz->valor)
        raiz->dir = remover_no(raiz->dir, valor);
    else {
        if (!raiz->esq || !raiz->dir) {
            No* temp = raiz->esq ? raiz->esq : raiz->dir;
            free(raiz);
            return temp;
        } else {
            No* temp = encontrar_minimo(raiz->dir);
            raiz->valor = temp->valor;
            raiz->dir = remover_no(raiz->dir, temp->valor);
        }
    }

    raiz->altura = 1 + max(altura(raiz->esq), altura(raiz->dir));
    int fb = fator_balanceamento(raiz);

    // Rebalanceamento
    if (fb > 1 && fator_balanceamento(raiz->esq) >= 0)
        return rotacao_direita(raiz);
    if (fb > 1 && fator_balanceamento(raiz->esq) < 0) {
        raiz->esq = rotacao_esquerda(raiz->esq);
        return rotacao_direita(raiz);
    }
    if (fb < -1 && fator_balanceamento(raiz->dir) <= 0)
        return rotacao_esquerda(raiz);
    if (fb < -1 && fator_balanceamento(raiz->dir) > 0) {
        raiz->dir = rotacao_direita(raiz->dir);
        return rotacao_esquerda(raiz);
    }

    return raiz;
}

void remover(Arvore* arvore, int valor) {
    arvore->raiz = remover_no(arvore->raiz, valor);
}

void em_ordem(No* raiz) {
    if (raiz) {
        em_ordem(raiz->esq);
        printf("%d ", raiz->valor);
        em_ordem(raiz->dir);
    }
}

void pre_ordem(No* raiz) {
    if (raiz) {
        printf("%d ", raiz->valor);
        pre_ordem(raiz->esq);
        pre_ordem(raiz->dir);
    }
}

void pos_ordem(No* raiz) {
    if (raiz) {
        pos_ordem(raiz->esq);
        pos_ordem(raiz->dir);
        printf("%d ", raiz->valor);
    }
}

void percurso_em_ordem(Arvore *arvore) {
    if (!arvore || !arvore->raiz) {
        printf("Árvore vazia\n");
        return;
    }
    em_ordem(arvore->raiz);
}

void percurso_pre_ordem(Arvore *arvore) {
    if (!arvore || !arvore->raiz) {
        printf("Árvore vazia\n");
        return;
    }
    pre_ordem(arvore->raiz);
}

void percurso_pos_ordem(Arvore *arvore) {
    if (!arvore || !arvore->raiz) {
        printf("Árvore vazia\n");
        return;
    }
    pos_ordem(arvore->raiz);
}

void destruir_nos(No* raiz) {
    if (raiz) {
        destruir_nos(raiz->esq);
        destruir_nos(raiz->dir);
        free(raiz);
    }
}

void destruir_arvore(Arvore* arvore) {
    if (arvore) {
        destruir_nos(arvore->raiz);
        free(arvore);
    }
}

Arvore* criar_arvore() {
    Arvore *arvore = malloc(sizeof(Arvore));
    if (arvore)
        arvore->raiz = NULL;
    return arvore;
}
