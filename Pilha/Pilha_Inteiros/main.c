#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

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
    Pilha *p= criarPilha();
    if (p==NULL)
      printf("Não foi possível alocar memória");
    
    int opcao, valor, resultado;  
    do{
        limparTela();
        printf("\n1 - Empilhar");
        printf("\n2 - Desempilhar");
        printf("\n3 - Mostrar topo");
        printf("\n4 - Mostrar pilha");
        printf("\n5 - Liberar pilha");
        printf("\n6 - Sair");
        printf("\nEscolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("\nDigite o valor a ser empilhado: ");
            scanf("%d", &valor);
            resultado = empilhar(p, valor);
            if (resultado==ERROR)
              printf("\nPilha cheia, não foi possível inserir");
             else
              printf("\n%d inserido com sucesso", valor); 
            break;
        
        case 2:
            resultado=desempilhar(p, &valor);
            if (resultado==ERROR)
              printf("\nPilha vazia");
            else
              printf("\nItem %d removido", valor);
            
            break;
          
        case 3:
            resultado=topo(p,&valor);
            if (resultado==ERROR)
                printf("\nPilha vazia");
            else
                printf("\nItem no topo:  %d", valor);
        
            break;   
        
        case 4:
            mostrarPilha(p);
            break;
        
        case 5:
             liberarPilha(p);
             printf("Pilha liberada e recriada");
             p=criarPilha();
             break;   
        case 6:
           printf("\nSaindo...");
           liberarPilha(p);
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