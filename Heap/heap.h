typedef struct heap Heap;

Heap* criar_heap();
void inserir(Heap* h, int valor);
int remover(Heap* h); 
void imprimir_heap(Heap* h);
void destruir_heap(Heap* h); 