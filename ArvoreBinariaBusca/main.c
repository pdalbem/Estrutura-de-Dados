#include <stdio.h>
#include <stdlib.h>
#include "abb.h"

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
  Arvore *arvore = criar_arvore();
  if (arvore==NULL){
    printf("Não foi possível alocar memória");
    exit(1);
  }
     

  int op;
  int valor;
  do
  {
    limparTela();
    printf("\n1 - Inserir");
    printf("\n2 - Remover");
    printf("\n3 - Em Ordem");
    printf("\n4 - Pre Ordem");
    printf("\n5 - Pos Ordem");
    printf("\n6 - Liberar Árvore");
    printf("\n7 - Sair");
    printf("\n\nEscolha sua opção: ");
    scanf("%d", &op);
    switch (op)
    {
    case 1:

      printf("\nDigite o valor a ser inserido: ");
      scanf("%d", &valor);
      inserir(arvore, valor);
      break;

    case 2:
      printf("\nDigite o valor a ser removido: ");
      scanf("%d", &valor);
      remover(arvore, valor);
      break;

    case 3:
      percurso_em_ordem(arvore);
      break;

    case 4:
      percurso_pre_ordem(arvore);
      break;

    case 5:
      percurso_pos_ordem(arvore);
      break;

    case 6:
      destruir_arvore(arvore);
      arvore=criar_arvore();
      break;

    case 7:
    printf("\nSaindo...");
    destruir_arvore(arvore);
    break;

    default:
    printf("\nOpção inválida");
 
    }
    getchar();
  } while (op != 7);
  
  return 0;
}