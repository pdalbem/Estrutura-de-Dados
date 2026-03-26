typedef struct livro Livro;

Livro* criarLivro(const char* titulo, const char* autor, const char* editora, int ano);
char *getTitulo(Livro *livro);
char *getAutor(Livro *livro);
char *getEditora(Livro *livro);
int getAnoPublicacao(Livro *livro);