typedef struct no No;

typedef struct fila Fila;

Fila *criar();
void enfileirar(Fila *fila, int x);
int desenfileirar(Fila *f);
int quantidadeElementos(Fila *f);