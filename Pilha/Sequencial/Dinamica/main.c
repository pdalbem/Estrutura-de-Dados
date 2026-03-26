#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int main()
{
    Pilha *pilha = criarPilha(3);

    if (pilha == NULL)
    {
        printf("Erro de alocação\n");
        exit(1);
    }

    push(pilha, 10);
    push(pilha, 20);
    push(pilha, 30);
    push(pilha, 40); // aqui ocorre realloc

    mostrarPilha(pilha);

    int removido;

    pop(pilha, &removido);
    printf("\nRemovido: %d\n", removido);

    mostrarPilha(pilha);

    liberarPilha(pilha);

    return 0;
}