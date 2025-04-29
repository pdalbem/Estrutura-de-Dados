typedef struct arvore Arvore;

Arvore *inserir(int x, Arvore *p);
Arvore *remover(Arvore *r, int elemento);
void emordem(Arvore *p);
void preordem(Arvore *p);
void posordem(Arvore *p);
void liberarArvore(Arvore *p);