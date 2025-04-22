#include "produto.h"

#define SUCCESS 0
#define ERROR 1

typedef struct lista Lista;

Lista* criarLista();
int inserirProduto(Lista* lista, Produto* p);
int removerProduto(Lista* lista, int codigo, Produto **p);
float calcularPrecoMedio(Lista* lista);
void mostrarProdutos(Lista* lista);
void liberarLista(Lista* lista);

