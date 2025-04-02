#include<stdio.h>
#include<stdlib.h>
#include "pilha.h"

#define MAXTAM 5

struct pilha{
    Livro* item[MAXTAM];
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
int empilhar(Pilha *p, Livro *livro) 
{
    if (pilhaCheia(p))
       return ERROR;
       else{
        p->topo++;
        p->item[p->topo]=livro;
        return SUCCESS;
       }
}

//POP - Complexidade constante O(1)
int desempilhar(Pilha *p, Livro *livro)   
{
    if (pilhaVazia(p))
       return ERROR;
      else
      {
        livro = p->item[p->topo];
        p->topo--;
        return SUCCESS;
      } 
}

//PEEK - Complexidade constante O(1)
int topo(Pilha *p, Livro *livro)   
{
    if (pilhaVazia(p))
      return ERROR;
    else{
        livro = p->item[p->topo];
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
        for (int i=p->topo;i>=0;i--){
          printf("\nTítulo: %s ", getTitulo(p->item[i]));
          printf("\nAutor: %s", getAutor(p->item[i]));
          printf("\nEditora: %s", getEditora(p->item[i]));
          printf("\nAutor: %d", getAnoPublicacao(p->item[i]));
          printf("\n");

        }
}

void liberarPilha(Pilha *p)
{
    if (p != NULL) { 
        for (int i = 0; i <= p->topo; i++) {
            if (p->item[i] != NULL) { 
                free(p->item[i]);
                p->item[i] = NULL; 
            }
        }
        free(p);
        p = NULL; 
    }
}