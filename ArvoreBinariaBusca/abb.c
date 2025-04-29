#include <stdio.h>
#include <stdlib.h>
#include "abb.h"

struct arvore
{
  int valor;
  struct arvore *esq;
  struct arvore *dir;
};

Arvore *inserir(int x, Arvore *p)
{
  if (p == NULL)
  {
    p = (Arvore *)malloc(sizeof(Arvore));
    if (p == NULL) {
      printf("Erro ao alocar memória");
      exit(1); 
    }
    p->valor = x;
    p->dir = NULL;
    p->esq = NULL;
  }
  else
  {
    if (x < p->valor)
      p->esq = inserir(x, p->esq);
    if (x > p->valor)
      p->dir = inserir(x, p->dir);
    if (x == p->valor)
      printf("Valor já existe");
  }
  return p;
}

Arvore *remover(Arvore *r, int elemento) {
  Arvore *p;
  if (r == NULL) 
      return NULL;
  

  if (elemento < r->valor) 
      r->esq = remover(r->esq, elemento);
  else if (elemento > r->valor) 
      r->dir = remover(r->dir, elemento);
 else {
      // Encontrou o nó a ser removido
      if (r->esq == NULL && r->dir == NULL) {
          free(r);
          return NULL;
      } else if (r->esq == NULL) {
          p = r->dir;
          free(r);
          return p;
      } else if (r->dir == NULL) {
          p = r->esq;
          free(r);
          return p;
      } else {
          // Dois filhos: substitui pelo menor da subárvore direita
          p = r->dir;
          while (p->esq != NULL) {
              p = p->esq;
          }
          r->valor = p->valor;
          r->dir = remover(r->dir, p->valor);
      }
  }

  return r;
}


void emordem(Arvore *p)
{
  if (p != NULL)
  {
    emordem(p->esq);
    printf("%d ", p->valor);
    emordem(p->dir);
  }
}

void preordem(Arvore *p)
{

  if (p != NULL)
  {
    printf("%d ", p->valor);
    preordem(p->esq);
    preordem(p->dir);
  }
}

void posordem(Arvore *p)
{
  if (p != NULL)
  {
    posordem(p->esq);
    posordem(p->dir);
    printf("%d ", p->valor);
  }
}

void liberarArvore(Arvore *p) {
  if (p != NULL) {
    liberarArvore(p->esq);
    liberarArvore(p->dir);
       free(p);
  }
}
