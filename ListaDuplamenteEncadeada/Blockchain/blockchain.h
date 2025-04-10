typedef struct blockchain Blockchain;

Blockchain* criarBlockchain() ;
void adicionarBloco(Blockchain *bc, const char *data);
void removerBloco(Blockchain *bc);
void mostrarBlockchain(Blockchain *bc);
void liberarBlockchain(Blockchain *bc);