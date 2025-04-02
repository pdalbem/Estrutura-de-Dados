#define ERROR -1
#define SUCCESS 0

typedef struct lista Lista;

Lista* criarLista();
int inserir(Lista *lista, int valor, int pos); 
int remover(Lista *lista, int pos, int *retorno);   
int buscar(Lista *lista, int valor, int *pos);       
void mostrarLista(Lista *lista);
void liberarLista(Lista *lista);