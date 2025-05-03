#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

#define MAX 100  

typedef struct {
    int dados[MAX];
    int tamanho;
} Heap;

// Funções auxiliares para índices
int pai(int i) { return (i - 1) / 2; }
int filho_esq(int i) { return 2 * i + 1; }
int filho_dir(int i) { return 2 * i + 2; }


Heap* criar_heap() {
    Heap* h = malloc(sizeof(Heap));
    if (!h) {
        fprintf(stderr, "Erro ao alocar heap\n");
        exit(1);
    }
    h->tamanho = 0;
    return h;
}

// Troca dois elementos
void trocar(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// "Sobe" o elemento até restaurar propriedade de max-heap
void subir(Heap* h, int i) {
    while (i > 0 && h->dados[pai(i)] < h->dados[i]) {
        trocar(&h->dados[i], &h->dados[pai(i)]);
        i = pai(i);
    }
}


void inserir(Heap* h, int valor) {
    if (h->tamanho == MAX) {
        printf("Heap cheia!\n");
        return;
    }
    h->dados[h->tamanho] = valor;
    subir(h, h->tamanho);
    h->tamanho++;
}

// "Desce" o elemento para restaurar propriedade de max-heap
void descer(Heap* h, int i) {
    int maior = i;
    int esq = filho_esq(i);
    int dir = filho_dir(i);

    if (esq < h->tamanho && h->dados[esq] > h->dados[maior])
        maior = esq;
    if (dir < h->tamanho && h->dados[dir] > h->dados[maior])
        maior = dir;

    if (maior != i) {
        trocar(&h->dados[i], &h->dados[maior]);
        descer(h, maior);
    }
}

// Remove e retorna o maior elemento (raiz)
int remover_max(Heap* h) {
    if (h->tamanho == 0) {
        printf("Heap vazia!\n");
        return -1;
    }

    int max = h->dados[0];
    h->dados[0] = h->dados[h->tamanho - 1];
    h->tamanho--;
    descer(h, 0);
    return max;
}


void imprimir_heap(Heap* h) {
    printf("Heap: ");
    for (int i = 0; i < h->tamanho; i++) 
        printf("%d ", h->dados[i]);
    
    printf("\n");
}

void destruir_heap(Heap* h) {
    free(h);
}
