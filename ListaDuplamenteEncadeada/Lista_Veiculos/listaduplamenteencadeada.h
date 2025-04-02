#include "veiculo.h"
#define ERROR -1
#define SUCCESS 0

typedef struct lista Lista;

Lista* criarListaDuplamenteEncadeada();
int inserirInicio(Lista *lista, Veiculo *veiculo);
int inserirFinal(Lista *lista, Veiculo *veiculo);
int inserirApos(Lista *lista, Veiculo *veiculo, char* placaExistente);
int remover (Lista *lista, char* placaRemover);
void mostrar (Lista *lista);
void liberarLista(Lista *lista); 