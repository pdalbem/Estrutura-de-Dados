#include <stdio.h>
#include <stdlib.h>
#include "listaencadeada.h"

typedef struct no{
    int item;
    struct no *prox;
}No;

struct lista{
    No *inicio;
    No *fim;
};

Lista* criarListaEncadeada(){
    Lista *lista = (Lista*)malloc(sizeof(Lista));
    if (lista){
        lista->inicio=NULL;
        lista->fim=NULL;
    }
    return lista;
}

int inserirInicio(Lista *lista, int valor){
    No *no = (No*)malloc(sizeof(No));
    if (no==NULL)
       return ERROR;
    
    no->item=valor;
    no->prox=lista->inicio;
    lista->inicio=no;
    if (lista->fim==NULL) //se lista estiver vazia
        lista->fim=no;
   
    return SUCCESS;       
}

int inserirFinal(Lista *lista, int valor){
    No *no=(No*)malloc(sizeof(No));
    if (no==NULL)
      return ERROR;
    
    no->item=valor;
    no->prox=NULL;
    
    if (lista->fim==NULL) //se lista estiver vazia
       lista->inicio=no;
      else
       lista->fim->prox=no;
   
       lista->fim=no;
    
    return SUCCESS;
}

int inserirApos(Lista *lista, int valor, int itemProcurado){
    No *no=(No*)malloc(sizeof(No));
    if (no==NULL)
       return ERROR;
    no->item=valor;

    No *aux = lista->inicio;
    while(aux!=NULL && aux->item!=itemProcurado){
        aux=aux->prox;
    }

    if (aux==NULL) //percorreu toda a lista e não encontrou o item desejado
        return ERROR;
    
    no->prox = aux->prox;
    aux->prox = no;
    
    if (aux==lista->fim) //item procurado era o último da lista
        lista->fim=no;  //precisa atualizar 'fim'
    
    return SUCCESS;    
}

int listaVazia(Lista *lista){
    return lista->inicio==NULL;
}

int remover(Lista *lista, int valor){
    if(listaVazia(lista))
       return ERROR;
    
    No *aux1 = lista->inicio;
    No *aux2 = NULL;
    
    while(aux1!=NULL && aux1->item!=valor){
        aux2=aux1;
        aux1=aux1->prox;
    }
    if (aux1==NULL) //percorreu toda a lista e não encontrou o item
        return ERROR;

    if (aux1==lista->inicio){ //item está no início da lista
        lista->inicio = lista->inicio->prox;
        if (lista->inicio==NULL) //item removido era o único
           lista->fim = NULL; 
    } else if (aux1==lista->fim){ //item está no final da lista
              aux2->prox = NULL;
              lista->fim=aux2;
          }
          else
            aux2->prox = aux1->prox; //item está no meio da lista
          
    free(aux1);
    return SUCCESS;      
}

void mostrar(Lista *lista){
    if (listaVazia(lista))
       printf("Lista vazia");
     else
     {
        No *aux = lista->inicio;
        while(aux!=NULL){
            printf("\n%d", aux->item);
            aux=aux->prox;
        }
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