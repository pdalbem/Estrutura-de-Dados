#define ERROR 0
#define SUCCESS 1

typedef struct pilha Pilha;

Pilha* criarPilha(int capacidadeInicial);
int push(Pilha *pilha, int valor);
int pop(Pilha *pilha, int *valorRemovido);
int peek(Pilha *pilha, int *valorTopo);
void mostrarPilha(Pilha *pilha);
void liberarPilha(Pilha *pilha);