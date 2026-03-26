#define ERROR 0
#define SUCCESS 1

typedef struct lista Lista;

Lista* criarLista();
int inserir(Lista *lista, int valor, int pos); 
int remover(Lista *lista, int pos, int *valorRemovido);   
int buscar(Lista *lista, int valorProcurado, int *pos);       
void mostrarLista(Lista *lista);
void liberarLista(Lista *lista);