#include <stdio.h>
#include <stdlib.h>
#include "lista.h"


typedef struct no {
    Produto* produto;
    struct no* ant;
    struct no* prox;
} No;

typedef struct lista {
    No* inicio;
    No* fim;
} Lista;

Lista* criarLista() {
    Lista* lista = (Lista*)malloc(sizeof(Lista));
    if (lista) {
        lista->inicio = NULL;
        lista->fim = NULL;
    }
    return lista;
}

int listaVazia(Lista *lista)
{
    return lista->inicio == NULL;
}

int inserirProduto(Lista* lista, Produto* p) {
    No* no = (No*)malloc(sizeof(No));
    
    if (!no) 
        return ERROR;

    no->produto = p;
    no->ant = NULL;
    no->prox = NULL;

    if (listaVazia(lista)) {
        lista->inicio = no;
        lista->fim = no;
        return SUCCESS;
    }

    No* aux = lista->inicio;
    while (aux && obterPreco(aux->produto) < obterPreco(p)) 
        aux = aux->prox;
    

    if (!aux) { // inserir no final
        no->ant = lista->fim;
        lista->fim->prox = no;
        lista->fim = no;
    } else if (!aux->ant) { // inserir no início
        no->prox = aux;
        aux->ant = no;
        lista->inicio = no;
    } else { // inserir no meio
        no->ant = aux->ant;
        no->prox = aux;
        aux->ant->prox = no;
        aux->ant = no;
    }
    return SUCCESS;
}

int removerProduto(Lista* lista, int codigo, Produto **p) {
    if (listaVazia(lista))
       return ERROR;

    No* aux = lista->inicio;
    while (aux && obterCodigo(aux->produto) != codigo) 
        aux = aux->prox;
    
    if (!aux) 
        return ERROR; 

    if (aux->ant!=NULL) 
       aux->ant->prox = aux->prox;
    else 
       lista->inicio = aux->prox;

    if (aux->prox!=NULL) 
        aux->prox->ant = aux->ant;
    else 
        lista->fim = aux->ant;

    *p=aux->produto;
    free(aux);
    return SUCCESS;
}

float calcularPrecoMedio(Lista* lista) {
    No* aux = lista->inicio;
    float soma = 0.0;
    int count = 0;

    while (aux) {
        soma += obterPreco(aux->produto);
        count++;
        aux = aux->prox;
    }
    return (count == 0) ? 0.0 : soma / count;
}

void mostrarProdutos(Lista* lista) {
    if (listaVazia(lista))
        printf("\nLista vazia");
    else{
       No* aux = lista->inicio;
       while (aux) {
         printf("Código: %d | Nome: %s | Preço: %.2f\n",
               obterCodigo(aux->produto),
               obterNome(aux->produto),
               obterPreco(aux->produto));
         aux = aux->prox;
        }
    }
}

void liberarLista(Lista* lista) {
    No* aux = lista->inicio;
    while (aux) {
        No* prox = aux->prox;
        liberarProduto(aux->produto);
        free(aux);
        aux = prox;
    }
    free(lista);
}

