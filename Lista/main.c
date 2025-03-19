#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

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
    Lista *lista= criarLista();
    if (lista==NULL)
      printf("Não foi possível alocar memória");
    
    int opcao, valor, resultado, pos;  
    do{
        limparTela();
        printf("\n1 - Inserir");
        printf("\n2 - Remover");
        printf("\n3 = Buscar");
        printf("\n4 - Mostrar lista");
        printf("\n5 - Liberar lista");
        printf("\n6 - Sair");
        printf("\nEscolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("\nDigite o valor a ser inserido: ");
            scanf("%d", &valor);
            printf("\nDigite a posição (índice do vetor) para inserir: ");
            scanf("%d", &pos);
            resultado = inserir(lista, valor,pos);
            if (resultado==ERROR)
              printf("\nLista cheia ou posição inválida, não foi possível inserir");
             else
              printf("\n%d inserido com sucesso na posição %d", valor, pos); 
            break;
        
        case 2:
            printf("\nDigite a posição (índice do vetor) para remover: ");
            scanf("%d", &pos);    
            resultado=remover(lista,pos);
            if (resultado==ERROR)
              printf("\nLista vazia ou posição inválida");
            else
              printf("\nItem %d removido da posição %d", resultado, pos);
            
            break;
          
        case 3:
            printf("\nDigite o valor a ser procurado: ");
        scanf("%d", &valor);    
        resultado=buscar(lista,valor);
        if (resultado==ERROR)
          printf("\nLista vazia ou elemento não encontrado");
        else
          printf("\nItem %d encontrado na posição %d", valor, resultado);  


        case 4:
            mostrarLista(lista);
            break;
        
        case 5:
             liberarLista(lista);
             printf("Lista liberada e recriada");
             lista=criarLista();
             break;   
        case 6:
           printf("\nSaindo...");
           liberarLista(lista);
           break;    
        default:
            printf("\nOpção inválida");
            break;
        }

        getchar();
        getchar();
    }while (opcao!=6);  


    return 0;
}