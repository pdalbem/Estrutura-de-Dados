#define ERROR 0
#define SUCCESS 1

typedef struct pilha Pilha;

Pilha* criarPilha();
int empilhar(Pilha *p, int valor);           //push
int desempilhar(Pilha *p, int *valor);       //pop
int topo(Pilha *p, int *valor);              //peek
void mostrarPilha(Pilha *p);                 //fins educativos
void liberarPilha(Pilha *p);