#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listaduplamenteencadeada.h"

typedef struct no
{
    Veiculo *v;
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

int inserirInicio(Lista *lista, Veiculo *veiculo)
{
    No *no = (No *)malloc(sizeof(No));
    if (no == NULL)
        return ERROR;

    no->v = veiculo;
    no->prox = lista->inicio;
    no->ant = NULL;

    if (lista->inicio!=NULL)
        lista->inicio->ant = no;
    else
        lista->fim = no;
    
    lista->inicio = no;
    return SUCCESS;
}

int inserirFinal(Lista *lista, Veiculo *veiculo)
{
    No *no = (No *)malloc(sizeof(No));
    if (no == NULL)
        return ERROR;

    no->v = veiculo;
    no->prox = NULL;
    no->ant = lista->fim;

    if (lista->fim!=NULL)
        lista->fim->prox = no;
    else
        lista->inicio = no;

    lista->fim = no;
    return SUCCESS;
}

int inserirApos(Lista *lista, Veiculo *veiculo, char* placaExistente)
{
    No *aux = lista->inicio;
    while (aux!=NULL &&  strcmp(getPlaca(aux->v), placaExistente) !=0)
        aux = aux->prox;
    
    if (aux==NULL) //percorreu toda lista e não encontrou
        return ERROR;

    No *no = (No *)malloc(sizeof(No));
    if (no == NULL)
        return ERROR;

    no->v = veiculo;
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

int remover (Lista *lista, char *placaRemover)
{
    if (listaVazia(lista))
        return ERROR;

    No *aux = lista->inicio;
    while (aux!=NULL &&  strcmp(getPlaca(aux->v), placaRemover) !=0)
        aux = aux->prox;
    
    if (aux == NULL) //percorreu toda lista e não encontrou
        return ERROR;

    if (aux->ant!=NULL) //se itemExistente é primeiro elemento
        aux->ant->prox = aux->prox;
    else
        lista->inicio = aux->prox;
    
    if (aux->prox!=NULL)
        aux->prox->ant = aux->ant;
    else
        lista->fim = aux->ant;
    
    free(aux->v);
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
        while (aux!=NULL)
        {
            printf("\nPlaca: %s", getPlaca(aux->v));
            printf("\nMarca: %s", getMarca(aux->v));
            printf("\nAno: %d", getAno(aux->v));
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
        free(aux->v);
        free(aux);
        aux=proximo;
    }
    free(lista);
}
