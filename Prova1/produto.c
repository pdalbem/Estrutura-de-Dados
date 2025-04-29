#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "produto.h"

struct produto{
    int codigo;
    char nome[100];
    float preco;
};

Produto* criarProduto(int codigo, const char* nome, float preco) {
    Produto* p = (Produto*)malloc(sizeof(Produto));
    if (p!=NULL) {
        p->codigo = codigo;
        strcpy(p->nome, nome);
        p->preco = preco;
    }
    return p;
}

int obterCodigo(Produto* p) {
    return p->codigo;
}

const char* obterNome(Produto* p) {
    return p->nome;
}

float obterPreco(Produto* p) {
    return p->preco;
}

void liberarProduto(Produto* p) {
    free(p);
}