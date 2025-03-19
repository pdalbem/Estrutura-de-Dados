#include <stdio.h>
#include <stdlib.h>
#include "lista.h"


#define MAXTAM 5


struct lista {
    int item[MAXTAM];
    int tamanho;
};

// Função para criar uma nova lista
Lista* criarLista() {
    Lista* l = (Lista*)malloc(sizeof(Lista));  // Aloca a lista
    if (l) {
        l->tamanho = 0;  // Inicializa o tamanho da lista
    }
    return l;
}

int listaCheia(Lista *l){
    return l->tamanho == MAXTAM;
}

int listaVazia(Lista *l){
    return l->tamanho==0;
}


// Função para inserir um novo elemento na lista em uma posição específica
int inserir(Lista *l, int valor, int pos) {
    // Verifica se a posição é válida e se a lista não está cheia
     if (listaCheia(l)|| pos < 0 || pos > l->tamanho) {
        return ERROR;  // Falha: lista cheia ou posição inválida
    }

    // Move os elementos para a direita para abrir espaço para o novo valor
    for (int i = l->tamanho; i > pos; i--) {
        l->item[i] = l->item[i - 1];
    }

    // Insere o valor na posição desejada
    l->item[pos] = valor;
    l->tamanho++;
    return SUCCESS;  // Inserção bem-sucedida
}

// Função para remover o primeiro elemento da lista
int remover(Lista *l, int pos) {
    // Verifica se a lista está vazia
    if (listaVazia(l)|| pos < 0 || pos > l->tamanho) {
        return ERROR;  // Falha: lista vazia ou posição inválida
    }
       

    // Move os elementos para a esquerda para preencher a lacuna
    int valor = l->item[pos];
    for (int i = pos; i < l->tamanho - 1; i++) {
        l->item[i] = l->item[i + 1];
    }
       
    l->tamanho--;
    return valor;  // Remoção bem-sucedida
}

// Função para exibir todos os elementos da lista
void mostrarLista(Lista *l) {
    if (listaVazia(l)) {
        printf("Lista vazia.\n");
    } else {
        for (int i = 0; i < l->tamanho; i++) {
            printf("\n %d ", l->item[i]);
        }
      }
}

// Função para liberar a memória alocada para a lista
void liberarLista(Lista *l) {
    free(l);  // Libera a memória da estrutura da lista
}
