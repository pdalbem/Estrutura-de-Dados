#include <stdio.h>
#include "fila.h"

int main() {
    Fila *f = criarFila();

    int opcao;
    int valor;
    int retorno;

    do {
        printf("\n--- FILA SEQUENCIAL DINAMICA ---\n");
        printf("1 - Enfileirar\n");
        printf("2 - Desenfileirar\n");
        printf("3 - Frente\n");
        printf("4 - Mostrar fila\n");
        printf("0 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Valor: ");
                scanf("%d", &valor);

                retorno = enfileirar(f, valor);
                if (retorno == SUCCESS)
                    printf("Inserido com sucesso.\n");
                else
                    printf("Erro ao inserir.\n");
                break;

            case 2:
                retorno = desenfileirar(f, &valor);
                if (retorno == SUCCESS)
                    printf("Removido: %d\n", valor);
                else
                    printf("Erro: fila vazia.\n");
                break;

            case 3:
                retorno = frente(f, &valor);
                if (retorno == SUCCESS)
                    printf("Frente: %d\n", valor);
                else
                    printf("Erro: fila vazia.\n");
                break;

            case 4:
                mostrarFila(f);
                break;

            case 0:
                printf("Encerrando...\n");
                break;

            default:
                printf("Opcao invalida!\n");
        }

    } while (opcao != 0);

    liberarFila(f);
    return 0;
}