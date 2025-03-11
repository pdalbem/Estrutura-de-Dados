#include <stdio.h>
#include<stdlib.h>
#include "fila.h"

#define MAXTAM 5

struct fila{
    int item[MAXTAM];
    int inicio, fim, qtd;
};

Fila* criarFila(){
    Fila *f=(Fila*)malloc(sizeof(Fila));
    if (f==NULL)
       return NULL;
    
    f->inicio=0;
    f->fim=-1;
    f->qtd=0;
    return f;   
}

int filaCheia(Fila *f){
    return f->qtd==MAXTAM;
}

int filaVazia(Fila *f){
    return f->qtd==0;
}

// enqueue - Complexidade constante O(1)
int enfileirar(Fila *f, int valor){   
    if (filaCheia(f))
      return ERROR;
     else{
        // f->fim++;
        // if (f->fim==MAXTAM)
        //    f->fim=0;
        f->fim = (f->fim+1) % MAXTAM;
        f->item[f->fim] = valor;
        f->qtd++;
        return SUCCESS;
     } 
}

// dequeue = Complexidade constante O(1)
int desenfileirar(Fila *f){  
    if (filaVazia(f))
         return ERROR;
       else{
        int valor = f->item[f->inicio];
        f->inicio = (f->inicio+1) % MAXTAM;
        f->qtd--;
        return valor;
       }
}

// Complexidade constante O(1)
int obterPrimeiro(Fila *f){
    if (filaVazia(f))
       return ERROR;
      else
        return f->item[f->inicio];  
}

// Complexidade linear O(n)
void mostrarFila(Fila *f){
    if (filaVazia(f))
       printf("Fila vazia");
     else{
        int i = f->inicio; 
        for (int cont=0;cont<f->qtd;cont++){
             printf("Item: %d\n", f->item[i]);
             i = (i+1) % MAXTAM; 
        }
     }  
}

void liberarFila(Fila *f){
    free(f);
}