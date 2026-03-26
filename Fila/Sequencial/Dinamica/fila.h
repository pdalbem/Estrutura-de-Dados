#ifndef FILA_H
#define FILA_H

#define ERROR 0
#define SUCCESS 1

typedef struct fila Fila;

// Criação e destruição
Fila* criarFila();
void liberarFila(Fila *f);

// Operações
int enfileirar(Fila *f, int valor);
int desenfileirar(Fila *f, int *valorRemovido);
int frente(Fila *f, int *valor);

// Utilidade
void mostrarFila(Fila *f);

#endif