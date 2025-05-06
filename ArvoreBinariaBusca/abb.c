#include <stdio.h>
#include <stdlib.h>
#include "abb.h"

typedef struct no {
  int valor;
  struct no *esq;
  struct no *dir;
} No;

struct arvore {
  No *raiz;
};

Arvore* criar_arvore() {
  Arvore *arvore = (Arvore*) malloc(sizeof(Arvore));
  if (arvore)
     arvore->raiz = NULL;
  return arvore;
}

No* criar_no(int valor) {
  No *no = (No*) malloc(sizeof(No));
  if (no){
     no->valor = valor;
     no->esq = NULL;
     no->dir = NULL;
  }
  return no;
}

No* inserir_no(No* raiz, int valor) {
  if (raiz == NULL) 
      return criar_no(valor);
  

  if (valor < raiz->valor) 
      raiz->esq = inserir_no(raiz->esq, valor);
   else if (valor > raiz->valor) 
      raiz->dir = inserir_no(raiz->dir, valor);

  return raiz;
}

void inserir(Arvore* arvore, int valor) {
  arvore->raiz = inserir_no(arvore->raiz, valor);
}

No* encontrar_minimo(No* raiz) {
  while (raiz->esq != NULL)
      raiz = raiz->esq;
  return raiz;
}

No* remover_no(No* raiz, int valor) {
  if (raiz == NULL)
      return NULL;

  if (valor < raiz->valor) {
      raiz->esq = remover_no(raiz->esq, valor);
  } else if (valor > raiz->valor) {
      raiz->dir = remover_no(raiz->dir, valor);
  } else {
      // Caso 1: sem filhos
      if (raiz->esq == NULL && raiz->dir == NULL) {
          free(raiz);
          return NULL;
      }
      // Caso 2: um filho
      else if (raiz->esq == NULL) {
          No* temp = raiz->dir;
          free(raiz);
          return temp;
      }
      else if (raiz->dir == NULL) {
          No* temp = raiz->esq;
          free(raiz);
          return temp;
      }
      // Caso 3: dois filhos
      else {
          //menor valor da subarvore direita 
          No* sucessor = raiz->dir;
          while (sucessor->esq != NULL)
                 sucessor = sucessor->esq;
         
          raiz->valor = sucessor->valor;
          raiz->dir = remover_no(raiz->dir, sucessor->valor);
      }
  }

  return raiz;
}

void remover(Arvore* arvore, int valor) {
  arvore->raiz = remover_no(arvore->raiz, valor);
}


void pre_ordem(No* raiz) {
  if (raiz) {
      printf("%d ", raiz->valor);
      pre_ordem(raiz->esq);
      pre_ordem(raiz->dir);
  }
}

void percurso_pre_ordem(Arvore *arvore){
  if (arvore == NULL || arvore->raiz == NULL) {
    printf("Árvore vazia");
    return;
  }
  pre_ordem(arvore->raiz);
}

void em_ordem(No* raiz) {
  if (raiz) {
      em_ordem(raiz->esq);
      printf("%d ", raiz->valor);
      em_ordem(raiz->dir);
  }
}

void percurso_em_ordem(Arvore *arvore){
  if (arvore == NULL || arvore->raiz == NULL) {
    printf("Árvore vazia");
    return;
  }
  em_ordem(arvore->raiz);
}

void pos_ordem(No* raiz) {
  if (raiz) {
      pos_ordem(raiz->esq);
      pos_ordem(raiz->dir);
      printf("%d ", raiz->valor);
  }
}

void percurso_pos_ordem(Arvore *arvore){
  if (arvore == NULL || arvore->raiz == NULL) {
    printf("Árvore vazia");
    return;
  }
  pos_ordem(arvore->raiz);
}

void destruir_nos(No* raiz) {
  if (raiz) {
      destruir_nos(raiz->esq);
      destruir_nos(raiz->dir);
      free(raiz);
  }
}

void destruir_arvore(Arvore* arvore) {
  if (arvore) {
      destruir_nos(arvore->raiz);
      free(arvore);
  }
}