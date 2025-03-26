#define SUCCESS 0
#define ERROR 1

typedef struct lista Lista;
Lista* criarListaEncadeada();
int inserirInicio(Lista *lista, int valor);
int inserirFinal(Lista *lista, int valor);
int inserirApos(Lista *lista, int valor, int itemProcurado);
int remover(Lista *lista, int valor);
void mostrar(Lista *lista);
void liberarLista(Lista *lista);