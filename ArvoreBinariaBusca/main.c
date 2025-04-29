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
  Arvore *raiz = NULL;

  int op;
  int elem;
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
      scanf("%d", &elem);
      raiz = inserir(elem, raiz);
      break;

    case 2:
      printf("\nDigite o valor a ser removido: ");
      scanf("%d", &elem);
      raiz = remover(raiz, elem);
      break;

    case 3:
      (raiz == NULL) ? printf("Árvore vazia") : emordem(raiz);
      break;

    case 4:
      (raiz == NULL) ? printf("Árvore vazia") : preordem(raiz);
      break;

    case 5:
      (raiz == NULL) ? printf("Árvore vazia") : posordem(raiz);
      break;

    case 6:
      liberarArvore(raiz);
      raiz=NULL;
      break;

    case 7:
    printf("\nSaindo...");
    liberarArvore(raiz);
    break;

    default:
    printf("\nOpção inválida");
 
    }
    getchar();
  } while (op != 7);
  
  return 0;
}