#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listaduplamenteencadeada.h"

typedef struct no
{
    int item;
    struct no *prox;
    struct no *ant;
} No;

struct lista
{
    No *inicio;
    No *fim;
};

Lista *criarListaDuplamenteEncadeada()
{
    Lista *lista = (Lista *)malloc(sizeof(Lista));
    if (lista!=NULL)
    {
        lista->inicio = NULL;
        lista->fim = NULL;
    }
    return lista;
}

int inserirInicio(Lista *lista, int valor)
{
    No *no = (No *)malloc(sizeof(No));
    if (no == NULL)
        return ERROR;

    no->item = valor;
    no->prox = lista->inicio;
    no->ant = NULL;

    if (lista->inicio!=NULL)
        lista->inicio->ant = no;
    else
        lista->fim = no;
    
    lista->inicio = no;
    return SUCCESS;
}

int inserirFinal(Lista *lista, int valor)
{
    No *no = (No *)malloc(sizeof(No));
    if (no == NULL)
        return ERROR;

    no->item = valor;
    no->prox = NULL;
    no->ant = lista->fim;

    if (lista->fim!=NULL)
        lista->fim->prox = no;
    else
        lista->inicio = no;

    lista->fim = no;
    return SUCCESS;
}

int inserirApos(Lista *lista, int valor, int itemExistente)
{
    No *aux = lista->inicio;
    while (aux!=NULL && aux->item != itemExistente)
        aux = aux->prox;
    
    if (aux==NULL)
        return ERROR;

    No *no = (No *)malloc(sizeof(No));
    if (no == NULL)
        return ERROR;

    no->item = valor;
    no->prox = aux->prox;
    no->ant = aux;

    if (aux->prox!=NULL)
        aux->prox->ant = no;
    else
        lista->fim = no;
    
    aux->prox = no;
    return SUCCESS;
}

int listaVazia(Lista *lista)
{
    return lista->inicio == NULL;
}

int remover(Lista *lista, int valor)
{
    if (listaVazia(lista))
        return ERROR;

    No *aux = lista->inicio;
    while (aux!=NULL && aux->item != valor)
        aux = aux->prox;
    
    if (aux == NULL)
        return ERROR;

    if (aux->ant)
        aux->ant->prox = aux->prox;
    else
        lista->inicio = aux->prox;
    
    if (aux->prox)
        aux->prox->ant = aux->ant;
    else
        lista->fim = aux->ant;
    

    free(aux);
    return SUCCESS;
}

void mostrar(Lista *lista)
{
    if (listaVazia(lista))
        printf("Lista vazia!\n");
    else
    {

        No *aux = lista->inicio;
        while (aux)
        {
            printf("\n%d ", aux->item);
            aux = aux->prox;
        }
        printf("\n");
    }
}

void liberarLista(Lista *lista){
    if (lista==NULL)
      return;

    No *aux = lista->inicio;
    while(aux!=NULL){
        No *proximo = aux->prox;
        free(aux);
        aux=proximo;
    }
    free(lista);
}
