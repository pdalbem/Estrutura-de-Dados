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
Livro*  empilhar(Pilha *p, Livro *livro) 
{
    if (pilhaCheia(p))
       return NULL;
       else{
        p->topo++;
        p->item[p->topo]=livro;
        return livro;
       }
}

//POP - Complexidade constante O(1)
Livro* desempilhar(Pilha *p)   
{
    if (pilhaVazia(p))
       return NULL;
      else
      {
        Livro* livro = p->item[p->topo];
        p->topo--;
        return livro;
      } 
}

//PEEK - Complexidade constante O(1)
Livro* topo(Pilha *p)   
{
    if (pilhaVazia(p))
      return NULL;
    else
      return p->item[p->topo];
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