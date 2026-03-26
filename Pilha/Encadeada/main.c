#include <stdio.h>
#include "pilha.h"

int main() {
    Pilha *p = criarPilha();

    int opcao;
    int valor;
    int retorno;

    do {
        printf("\n--- PILHA ENCADEADA ---\n");
        printf("1 - Push\n");
        printf("2 - Pop\n");
        printf("3 - Topo\n");
        printf("4 - Mostrar pilha\n");
        printf("0 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Valor: ");
                scanf("%d", &valor);

                retorno = push(p, valor);
                if (retorno == SUCCESS)
                    printf("Valor inserido com sucesso.\n");
                else
                    printf("Erro ao inserir.\n");
                break;

            case 2:
                retorno = pop(p, &valor);
                if (retorno == SUCCESS)
                    printf("Valor removido: %d\n", valor);
                else
                    printf("Erro: pilha vazia.\n");
                break;

            case 3:
                retorno = topo(p, &valor);
                if (retorno == SUCCESS)
                    printf("Topo da pilha: %d\n", valor);
                else
                    printf("Erro: pilha vazia.\n");
                break;

            case 4:
                mostrarPilha(p);
                break;

            case 0:
                printf("Encerrando...\n");
                break;

            default:
                printf("Opcao invalida!\n");
        }

    } while (opcao != 0);

    liberarPilha(p);
    return 0;
}