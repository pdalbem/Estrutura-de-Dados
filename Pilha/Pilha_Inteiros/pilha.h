#define ERROR 1
#define SUCCESS 0

typedef struct pilha Pilha;

Pilha* criarPilha();
int empilhar(Pilha *p, int valor); //push
int desempilhar(Pilha *p);         //pop
int topo(Pilha *p);                //peek
void mostrarPilha(Pilha *p); //fins educativos
void liberarPilha(Pilha *p);