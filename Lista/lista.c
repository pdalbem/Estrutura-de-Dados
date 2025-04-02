#include <stdio.h>
#include <stdlib.h>
#include "lista.h"


#define MAXTAM 5


struct lista {
    int item[MAXTAM];
    int tamanho;
};


Lista* criarLista() {
    Lista* lista = (Lista*)malloc(sizeof(Lista));  
    if (lista) {
        lista->tamanho = 0;  
    }
    return lista;
}

int listaCheia(Lista *lista){
    return lista->tamanho == MAXTAM;
}

int listaVazia(Lista *lista){
    return lista->tamanho==0;
}


// Complexidade linear O(n)
int inserir(Lista *lista, int valor, int pos) {
     if (listaCheia(lista)|| pos < 0 || pos > lista->tamanho) {
        return ERROR;  
    }

    // Move os elementos para a direita para abrir espaço para o novo valor
    for (int i = lista->tamanho; i > pos; i--) 
        lista->item[i] = lista->item[i - 1];
    

    // Insere o valor na posição desejada
    lista->item[pos] = valor;
    lista->tamanho++;
    return SUCCESS;  
}

// Complexidade linear O(n)
int remover(Lista *lista, int pos, int *retorno) {
    if (listaVazia(lista)|| pos < 0 || pos > lista->tamanho) 
        return ERROR;  
    
       
    // Move os elementos para a esquerda para preencher a lacuna
    *retorno = lista->item[pos];
    for (int i = pos; i < lista->tamanho - 1; i++) 
         lista->item[i] = lista->item[i + 1];
    
       
    lista->tamanho--;
    return SUCCESS;  
}

// Complexidade linear O(n)
int buscar(Lista *lista, int valor, int *pos){
    if (listaVazia(lista))
       return ERROR;
    for (int i=0;i<lista->tamanho;i++)
         if (lista->item[i]==valor){
            *pos=i;
            return SUCCESS;
         }
          else
            return ERROR;     
}

// Complexidade linear O(n)
void mostrarLista(Lista *lista) {
    if (listaVazia(lista)) 
        printf("Lista vazia.\n");
    else 
        for (int i = 0; i < lista->tamanho; i++) 
            printf("\n %d ", lista->item[i]);
        
      
}


void liberarLista(Lista *lista) {
    free(lista);  
}
