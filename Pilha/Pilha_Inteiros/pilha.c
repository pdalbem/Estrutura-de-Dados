#include<stdio.h>
#include<stdlib.h>
#include "pilha.h"

#define MAXTAM 5

struct pilha{
    int item[MAXTAM];
    int topo;
};

Pilha* criarPilha()
{
    Pilha *p=(Pilha*)malloc(sizeof(Pilha));
    if (p==NULL)
        return NULL;
    
    p->topo=-1;
    return p;
}

int pilhaCheia(Pilha *p)
{
    return p->topo==MAXTAM-1;
}

int pilhaVazia(Pilha *p)
{
    return p->topo==-1;
}

//PUSH - Complexidade constante O(1)
int empilhar(Pilha *p, int valor) 
{
    if (pilhaCheia(p))
       return ERROR;
       else{
        p->topo++;
        p->item[p->topo]=valor;
        return SUCCESS;
       }
}

//POP - Complexidade constante O(1)
int desempilhar(Pilha *p, int *valor)   
{
    if (pilhaVazia(p))
       return ERROR;
      else
      {
        *valor = p->item[p->topo];
        p->topo--;
        return SUCCESS;
      } 
}

//PEEK - Complexidade constante O(1)
int topo(Pilha *p, int *valor)   
{
    if (pilhaVazia(p))
      return ERROR;
    else{
      *valor=p->item[p->topo];
      return SUCCESS;
    }
}

// para efeitos didáticos
// Complexidade linear O(N)
void mostrarPilha(Pilha *p)
{
    if (pilhaVazia(p))
       printf("Pilha vazia, nada para mostrar");
      else
        for (int i=p->topo;i>=0;i--)
          printf("%d ", p->item[i]);
}

void liberarPilha(Pilha *p)
{
    free(p);
}