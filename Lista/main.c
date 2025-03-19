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
    Lista *l= criarLista();
    if (l==NULL)
      printf("Não foi possível alocar memória");
    
    int opcao, valor, resultado, pos;  
    do{
        limparTela();
        printf("\n1 - Inserir");
        printf("\n2 - Remover");
        printf("\n3 - Mostrar lista");
        printf("\n4 - Liberar lista");
        printf("\n5 - Sair");
        printf("\nEscolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("\nDigite o valor a ser inserido: ");
            scanf("%d", &valor);
            printf("\nDigite a posição (índice do vetor) para inserir: ");
            scanf("%d", &pos);
            resultado = inserir(l, valor,pos);
            if (resultado==ERROR)
              printf("\nLista cheia ou posição inválida, não foi possível inserir");
             else
              printf("\n%d inserido com sucesso", valor); 
            break;
        
        case 2:
            printf("\nDigite a posição (índice do vetor) para remover: ");
            scanf("%d", &pos);    
            resultado=remover(l,pos);
            if (resultado==ERROR)
              printf("\nLista vazia ou posição inválida");
            else
              printf("\nItem %d removido", resultado);
            
            break;
          
      
        case 3:
            mostrarLista(l);
            break;
        
        case 4:
             liberarLista(l);
             printf("Lista liberada e recriada");
             l=criarLista();
             break;   
        case 5:
           printf("\nSaindo...");
           liberarLista(l);
           break;    
        default:
            printf("\nOpção inválida");
            break;
        }

        getchar();
        getchar();
    }while (opcao!=5);  


    return 0;
}