#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"



int main()
{
    Grafo *grafo = inicializa();
    grafo = insere_vertice(grafo, 6);
    grafo = insere_vertice(grafo, 5);
    grafo = insere_vertice(grafo, 4);
    grafo = insere_vertice(grafo, 3);
    grafo = insere_vertice(grafo, 2);
    grafo = insere_vertice(grafo, 1);
    insere_aresta(grafo, 1, 2);
    insere_aresta(grafo, 1, 3);
    insere_aresta(grafo, 2, 4);
    insere_aresta(grafo, 3, 5);
    insere_aresta(grafo, 3, 6);
    insere_aresta(grafo, 4, 5);
    insere_aresta(grafo, 4, 6);
    imprime(grafo);
    busca_largura(grafo,3);

    return 0;
}