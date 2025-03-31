#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listaduplamenteencadeada.h"

typedef struct no {
   int item;
   struct no *prox;
   struct no *ant;
} No;

struct lista {
   No *inicio;
   No *fim;
};

Lista *criarListaDuplamenteEncadeada() {
   Lista *lista = (Lista *)malloc(sizeof(Lista));
   if (lista) {
       lista->inicio = NULL;
       lista->fim = NULL;
   }
   return lista;
}

int inserirInicio(Lista *lista, int valor) {
   No *no = (No *)malloc(sizeof(No));
   if (!no) return ERROR;

   no->item = valor;
   no->prox = lista->inicio;
   no->ant = NULL;

   if (lista->inicio) {
       lista->inicio->ant = no;
   } else {
       lista->fim = no;
   }
   lista->inicio = no;
   return SUCCESS;
}

int inserirFinal(Lista *lista, int valor) {
   No *no = (No *)malloc(sizeof(No));
   if (!no) return ERROR;

   no->item = valor;
   no->prox = NULL;
   no->ant = lista->fim;

   if (lista->fim) {
       lista->fim->prox = no;
   } else {
       lista->inicio = no;
   }
   lista->fim = no;
   return SUCCESS;
}

int inserirApos(Lista *lista, int valor, int itemExistente) {
   No *aux = lista->inicio;
   while (aux && aux->item != itemExistente) {
       aux = aux->prox;
   }
   if (!aux) return ERROR;

   No *no = (No *)malloc(sizeof(No));
   if (!no) return ERROR;
   
   no->item = valor;
   no->prox = aux->prox;
   no->ant = aux;
   
   if (aux->prox) {
       aux->prox->ant = no;
   } else {
       lista->fim = no;
   }
   aux->prox = no;
   return SUCCESS;
}

int remover(Lista *lista, int valor) {
   No *aux = lista->inicio;
   while (aux && aux->item != valor) {
       aux = aux->prox;
   }
   if (!aux) return ERROR;

   if (aux->ant) {
       aux->ant->prox = aux->prox;
   } else {
       lista->inicio = aux->prox;
   }
   if (aux->prox) {
       aux->prox->ant = aux->ant;
   } else {
       lista->fim = aux->ant;
   }

   free(aux);
   return SUCCESS;
}

void mostrar(Lista *lista) {
   No *aux = lista->inicio;
   if (!aux) {
       printf("Lista vazia!\n");
       return;
   }
   while (aux) {
       printf("%d ", aux->item);
       aux = aux->prox;
   }
   printf("\n");
}

void liberarLista(Lista *lista) {
   No *aux = lista->inicio;
   while (aux) {
       No *proximo = aux->prox;
       free(aux);
       aux = proximo;
   }
   free(lista);
}
