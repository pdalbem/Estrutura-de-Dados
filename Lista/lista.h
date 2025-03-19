#define ERROR -1
#define SUCCESS 0

typedef struct lista Lista;

Lista* criarLista();
int inserir(Lista *l, int valor, int pos); 
int remover(Lista *l, int pos);          
void mostrarLista(Lista *l);
void liberarLista(Lista *l);