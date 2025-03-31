#define ERROR -1
#define SUCCESS 0

typedef struct lista Lista;

Lista* criarListaDuplamenteEncadeada();
int inserirInicio(Lista *lista, int valor);
int inserirFinal(Lista *lista, int valor);
int inserirApos(Lista *lista, int valor, int itemExistente);
int remover (Lista *lista, int valor);
void mostrar (Lista *lista);
void liberarLista(Lista *lista); 