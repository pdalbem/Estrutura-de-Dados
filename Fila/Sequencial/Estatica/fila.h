#define ERROR 0
#define SUCCESS 1

typedef struct fila Fila;

Fila* criarFila();
int enfileirar(Fila *f, int valor);       //enqueue
int desenfileirar(Fila *f, int *valor);   //dequeue
int obterPrimeiro(Fila *f, int *valor);
void mostrarFila(Fila *f);
void liberarFila(Fila *f);