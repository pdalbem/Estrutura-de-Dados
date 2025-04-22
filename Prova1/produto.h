typedef struct produto Produto;

Produto* criarProduto(int codigo, const char* nome, float preco);
int obterCodigo(Produto* p);
const char* obterNome(Produto* p);
float obterPreco(Produto* p);
void liberarProduto(Produto* p);
