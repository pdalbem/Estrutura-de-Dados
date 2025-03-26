#include <stdio.h>
#include <stdlib.h>
#include "listaencadeada.h"

void limparTela()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif    
}

int main()
{ 
    Lista *lista = criarListaEncadeada();
    if (lista == NULL)
    {
        printf("Não foi possível alocar memória");
        exit(1);
    }
    
    int opcao, valor, itemProcurado, resultado;
    do {
        limparTela();
        printf("\n1 - Inserir no início");
        printf("\n2 - Inserir no final");
        printf("\n3 - Inserir após um elemento");
        printf("\n4 - Remover");
        printf("\n5 - Mostrar lista");
        printf("\n6 - Liberar lista");
        printf("\n7 - Sair");
        printf("\nEscolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("\nDigite o valor a ser inserido no início: ");
            scanf("%d", &valor);
            resultado = inserirInicio(lista, valor);
            if (resultado == ERROR)
                printf("\nErro ao inserir");
            else
                printf("\n%d inserido com sucesso no início", valor);
            break;
        
        case 2:
            printf("\nDigite o valor a ser inserido no final: ");
            scanf("%d", &valor);
            resultado = inserirFinal(lista, valor);
            if (resultado == ERROR)
                printf("\nErro ao inserir");
            else
                printf("\n%d inserido com sucesso no final", valor);
            break;
        
        case 3:
            printf("\nDigite o valor a ser inserido: ");
            scanf("%d", &valor);
            printf("\nDigite o valor existente na lista: ");
            scanf("%d", &itemProcurado);
            resultado = inserirApos(lista, valor, itemProcurado);
            if (resultado == ERROR)
                printf("\nErro ao inserir. Elemento não encontrado.");
            else
                printf("\n%d inserido com sucesso após %d", valor, itemProcurado);
            break;
        
        case 4:
            printf("\nDigite o valor a ser removido: ");
            scanf("%d", &valor);
            resultado = remover(lista, valor);
            if (resultado == ERROR)
                printf("\nErro ao remover. Elemento não encontrado.");
            else
                printf("\n%d removido com sucesso", valor);
            break;
        
        case 5:
            mostrar(lista);
            break;
        
        case 6:
            liberarLista(lista);
            printf("\nLista liberada e recriada");
            lista = criarListaEncadeada();
            break;
        
        case 7:
            printf("\nSaindo...");
            liberarLista(lista);
            break;
        
        default:
            printf("\nOpção inválida");
            break;
        }
        getchar();
        getchar();
    } while (opcao != 7);

    return 0;
}
