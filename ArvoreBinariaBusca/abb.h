typedef struct arvore Arvore;

Arvore* criar_arvore();
void inserir(Arvore* arvore, int valor); 
void remover(Arvore* arvore, int valor); 
void percurso_pre_ordem(Arvore *arvore);
void percurso_em_ordem(Arvore *arvore);
void percurso_pos_ordem(Arvore *arvore);
void destruir_arvore(Arvore* arvore);