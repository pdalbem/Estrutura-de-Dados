#define ERROR -1
#define SUCCESS 0

typedef struct fila Fila;

Fila* criarFila();
int enfileirar(Fila *f, int valor);  //enqueue
int desenfileirar(Fila *f);          //dequeue
int obterPrimeiro(Fila *f);
void mostrarFila(Fila *f);
void liberarFila(Fila *f);