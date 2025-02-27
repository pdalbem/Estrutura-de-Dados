#include "livro.h"
#define ERROR 1
#define SUCCESS 0

typedef struct pilha Pilha;

Pilha* criarPilha();
Livro*  empilhar(Pilha *p, Livro *livro); //push
Livro* desempilhar(Pilha *p);         //pop
Livro*  topo(Pilha *p);                //peek
void mostrarPilha(Pilha *p); //fins educativos
void liberarPilha(Pilha *p);