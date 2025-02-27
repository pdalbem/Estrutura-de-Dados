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

void mostrarResultado(Livro *resultado){
    printf("\nTítulo: %s ", getTitulo(resultado));
    printf("\nAutor: %s", getAutor(resultado));
    printf("\nEditora: %s", getEditora(resultado));
    printf("\nAutor: %d", getAnoPublicacao(resultado));
}

int main()
{
    Pilha *p= criarPilha();
    if (p==NULL){
      printf("Não foi possível alocar memória");
      exit(1);
    }
       
    int opcao, valor, anoPublicacao;  
    char titulo[100], autor[100], editora[100];

    Livro *livro, *resultado;

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
            printf("Digite o título do livro a ser empilhado: ");
            scanf("%s", titulo);
            printf("Digite o autor do livro a ser empilhado: ");
            scanf("%s", autor);
            printf("Digite a editora do livro a ser empilhado: ");
            scanf("%s", editora);
            printf("Digite o ano de publicação do livro a ser empilhado: ");
            scanf("%d", &anoPublicacao);
            livro=criarLivro(titulo,autor,editora,anoPublicacao);

            resultado = empilhar(p, livro);
            if (resultado==NULL)
              printf("\nPilha cheia, não foi possível inserir");
             else{
               printf("\nLivro inserido com sucesso");
               mostrarResultado(resultado);
            } 
            break;
        
        case 2:
            livro=desempilhar(p);
            if (livro==NULL)
              printf("\nPilha vazia");
              else{
                printf("\nLivro removido com sucesso");
                mostrarResultado(resultado);
             } 
            break;
          
        case 3:
            livro=topo(p);
            if (livro==NULL)
                printf("\nPilha vazia");
                else{
                    printf("\nLivro no topo:");
                    mostrarResultado(resultado);
                 } 
            break;   
        
        case 4:
            mostrarPilha(p);
            break;
        
        case 5:
             liberarPilha(p);
             printf("\nPilha liberada e recriada");
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