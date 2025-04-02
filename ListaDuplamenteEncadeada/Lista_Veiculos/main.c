#include <stdio.h>
#include <stdlib.h>
#include "listaduplamenteencadeada.h"

void limparTela()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif    
}

void mostrarResultado(Veiculo *resultado){
    printf("\nPlaca: %s ", getPlaca(resultado));
    printf("\nMarca: %s", getMarca(resultado));
    printf("\nAno: %d", getAno(resultado));
}

int main()
{ 
    Lista *lista = criarListaDuplamenteEncadeada();
    if (lista == NULL)
    {
        printf("Não foi possível alocar memória");
        exit(1);
    }
    
    int opcao, valor, resultado, ano;
    char placa[10], marca[100], placaProcurada[10];
    Veiculo *veiculo;
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
        printf("Digite a placa: ");
        scanf("%s", placa);
        printf("Digite a marca: ");
        scanf("%s", marca);
        printf("Digite o ano: ");
        scanf("%d", &ano);
        veiculo=criarVeiculo(placa, marca, ano);
        resultado = inserirInicio(lista, veiculo);
        if (resultado == ERROR)
              printf("\nErro ao inserir");
        else{
              printf("\nInserido com sucesso no início");
              mostrarResultado(veiculo);
            }

        break;
        
        case 2:
        printf("Digite a placa: ");
        scanf("%s", placa);
        printf("Digite a marca: ");
        scanf("%s", marca);
        printf("Digite o ano: ");
        scanf("%d", &ano);
        veiculo=criarVeiculo(placa, marca, ano);
        resultado = inserirFinal(lista, veiculo);
        if (resultado == ERROR)
              printf("\nErro ao inserir");
        else{
              printf("\nInserido com sucesso no fim");
              mostrarResultado(veiculo);
            }

        break;
        
        case 3:
            printf("\nDigite a placa existente na lista: ");
            scanf("%s", placaProcurada);
            printf("Digite a placa a ser inserida: ");
            scanf("%s", placa);
            printf("Digite a marca: ");
            scanf("%s", marca);
            printf("Digite o ano: ");
            scanf("%d", &ano);
            veiculo=criarVeiculo(placa, marca, ano);
            resultado = inserirApos(lista, veiculo, placaProcurada);
            if (resultado == ERROR)
                  printf("\nErro ao inserir");
            else{
                  printf("\nInserido com sucesso após placa %s", placaProcurada);
                  mostrarResultado(veiculo);
                }
    
            break;
        
        case 4:
            printf("\nDigite a placa do veículo a ser removido: ");
            scanf("%s", placaProcurada);
            resultado = remover(lista, placaProcurada);
            if (resultado == ERROR)
                printf("\nErro ao remover. Lista vazia ou elemento não encontrado.");
            else
                printf("\n%s removido com sucesso", placaProcurada);
            
            break;
        
        case 5:
            mostrar(lista);
            break;
        
        case 6:
            liberarLista(lista);
            printf("\nLista liberada e recriada");
            lista = criarListaDuplamenteEncadeada();
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