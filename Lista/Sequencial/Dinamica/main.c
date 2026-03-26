#include <stdio.h>
#include "lista.h"

int main() {
    Lista *lista = criarLista();

    int opcao;
    int valor, pos;
    int retorno;

    do {
        printf("\n--- LISTA SEQUENCIAL DINAMICA ---\n");
        printf("1 - Inserir\n");
        printf("2 - Remover\n");
        printf("3 - Buscar\n");
        printf("4 - Mostrar lista\n");
        printf("0 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Valor: ");
                scanf("%d", &valor);
                printf("Posicao: ");
                scanf("%d", &pos);

                retorno = inserir(lista, valor, pos);
                if (retorno == SUCCESS)
                    printf("Inserido com sucesso.\n");
                else
                    printf("Erro ao inserir.\n");
                break;

            case 2:
                printf("Posicao: ");
                scanf("%d", &pos);

                retorno = remover(lista, pos, &valor);
                if (retorno == SUCCESS)
                    printf("Removido: %d\n", valor);
                else
                    printf("Erro ao remover.\n");
                break;

            case 3:
                printf("Valor a buscar: ");
                scanf("%d", &valor);

                retorno = buscar(lista, valor, &pos);
                if (retorno == SUCCESS)
                    printf("Valor encontrado na posicao: %d\n", pos);
                else
                    printf("Valor nao encontrado.\n");
                break;

            case 4:
                mostrarLista(lista);
                break;

            case 0:
                printf("Encerrando...\n");
                break;

            default:
                printf("Opcao invalida!\n");
        }

    } while (opcao != 0);

    liberarLista(lista);
    return 0;
}