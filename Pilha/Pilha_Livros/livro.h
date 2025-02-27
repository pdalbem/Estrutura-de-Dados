typedef struct livro Livro;

Livro* criarLivro();
char *getTitulo(Livro *livro);
char *getAutor(Livro *livro);
char *getEditora(Livro *livro);
int getAnoPublicacao(Livro *livro);