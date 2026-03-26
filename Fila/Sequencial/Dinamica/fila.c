#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

#define CAPACIDADE_INICIAL 2

struct fila {
    int *dados;
    int inicio;
    int fim;
    int tamanho;
    int capacidade;
};

// Criação
Fila* criarFila() {
    Fila *f = (Fila*) malloc(sizeof(Fila));
    if (!f) return NULL;

    f->dados = (int*) malloc(CAPACIDADE_INICIAL * sizeof(int));
    if (!f->dados) {
        free(f);
        return NULL;
    }

    f->inicio = 0;
    f->fim = 0;
    f->tamanho = 0;
    f->capacidade = CAPACIDADE_INICIAL;

    return f;
}

// Verifica vazia (interna)
int filaVazia(Fila *f) {
    return f->tamanho == 0;
}

// Redimensionar (mantendo ordem)
int redimensionar(Fila *f) {
    int novaCapacidade = f->capacidade * 2;
    int *novo = (int*) malloc(novaCapacidade * sizeof(int));

    if (!novo)
        return ERROR;

    // Copia respeitando a circularidade
    for (int i = 0; i < f->tamanho; i++) {
        novo[i] = f->dados[(f->inicio + i) % f->capacidade];
    }

    free(f->dados);
    f->dados = novo; //ptr dados aponta para novo endereço de memória maior
    f->inicio = 0;
    f->fim = f->tamanho;
    f->capacidade = novaCapacidade;

    return SUCCESS;
}

// Enfileirar (O(1) amortizado)
int enfileirar(Fila *f, int valor) {
    if (f->tamanho == f->capacidade) {
        if (redimensionar(f) == ERROR)
            return ERROR;
    }

    f->dados[f->fim] = valor;
    f->fim = (f->fim + 1) % f->capacidade;
    f->tamanho++;

    return SUCCESS;
}

// Desenfileirar (O(1))
int desenfileirar(Fila *f, int *valorRemovido) {
    if (filaVazia(f))
        return ERROR;

    *valorRemovido = f->dados[f->inicio];
    f->inicio = (f->inicio + 1) % f->capacidade;
    f->tamanho--;

    return SUCCESS;
}

// Consultar frente (O(1))
int frente(Fila *f, int *valor) {
    if (filaVazia(f))
        return ERROR;

    *valor = f->dados[f->inicio];
    return SUCCESS;
}

// Mostrar fila
void mostrarFila(Fila *f) {
    if (filaVazia(f)) {
        printf("Fila vazia.\n");
        return;
    }

    printf("Inicio -> ");
    for (int i = 0; i < f->tamanho; i++) {
        printf("%d -> ", f->dados[(f->inicio + i) % f->capacidade]);
    }
    printf("NULL <- Fim\n");
}

// Liberar memória
void liberarFila(Fila *f) {
    free(f->dados);
    free(f);
}