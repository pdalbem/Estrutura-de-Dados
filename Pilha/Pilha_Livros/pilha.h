#include "livro.h"
#define ERROR 1
#define SUCCESS 0

typedef struct pilha Pilha;

Pilha* criarPilha();
int empilhar(Pilha *p, Livro *livro); //push
int desempilhar(Pilha *p, Livro *livro);         //pop
int  topo(Pilha *p, Livro *livro);                //peek
void mostrarPilha(Pilha *p); //fins educativos
void liberarPilha(Pilha *p);