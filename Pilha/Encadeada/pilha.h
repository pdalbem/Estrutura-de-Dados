#ifndef PILHA_H
#define PILHA_H

#define ERROR 0
#define SUCCESS 1

typedef struct pilha Pilha;

// Criação e destruição
Pilha* criarPilha();
void liberarPilha(Pilha *p);

// Operações
int push(Pilha *p, int valor);
int pop(Pilha *p, int *valorRemovido);
int topo(Pilha *p, int *valor);

// Utilidade
void mostrarPilha(Pilha *p);

#endif