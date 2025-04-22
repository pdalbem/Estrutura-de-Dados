#include <stdio.h>
#include <stdlib.h>
#include "lista.h" 

void limparTela() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void mostrarProduto(Produto* p) {
    printf("Código: %d | Nome: %s | Preço: %.2f\n",
           obterCodigo(p),
           obterNome(p),
           obterPreco(p));
}

int main() {
    Lista* lista = criarLista();
    if (lista == NULL) {
        printf("Erro ao criar a lista.\n");
        return 1;
    }

    int opcao;
    int codigo;
    float preco;
    char nome[100];
    Produto* produto = NULL;

    do {
        limparTela();
        printf("\n===== MENU =====");
        printf("\n1 - Inserir produto");
        printf("\n2 - Remover produto por código");
        printf("\n3 - Mostrar produtos");
        printf("\n4 - Mostrar preço médio");
        printf("\n5 - Liberar lista");
        printf("\n6 - Sair");
        printf("\nEscolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o código: ");
                scanf("%d", &codigo);
                getchar();

                printf("Digite o nome: ");
                scanf("%s", nome);

                printf("Digite o preço: ");
                scanf("%f", &preco);

                produto = criarProduto(codigo, nome, preco);
                if (inserirProduto(lista, produto) == SUCCESS) 
                    printf("Produto inserido com sucesso!\n");
                 else {
                    printf("Erro ao inserir produto.\n");
                    liberarProduto(produto);
                }
                break;

            case 2:
                printf("Digite o código do produto a ser removido: ");
                scanf("%d", &codigo);
                produto = NULL;
                if (removerProduto(lista, codigo, &produto) == SUCCESS) {
                    printf("Produto removido com sucesso!\n");
                    mostrarProduto(produto);
                    liberarProduto(produto);
                } else 
                    printf("Produto não encontrado ou lista vazia");
                
                break;

            case 3:
                printf("\nProdutos na lista:\n");
                mostrarProdutos(lista);
                break;

            case 4:
                printf("Preço médio: %.2f\n", calcularPrecoMedio(lista));
                break;

            case 5:
                liberarLista(lista);
                printf("Lista liberada e recriada.\n");
                lista = criarLista(); // recria a lista após liberar
                break;

            case 6:
                printf("Saindo...\n");
                liberarLista(lista);
                break;

            default:
                printf("Opção inválida.\n");
                break;
        }

        printf("\nPressione Enter para continuar...");
        getchar();
        getchar();

    } while (opcao != 6);

    return 0;
}
