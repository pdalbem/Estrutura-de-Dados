#include <stdio.h>
#include "heap.h"

int main() {
    Heap* heap = criar_heap();

    inserir(heap, 30);
    inserir(heap, 20);
    inserir(heap, 40);
    inserir(heap, 10);
    inserir(heap, 50);

    imprimir_heap(heap);

    printf("Removendo max: %d\n", remover_max(heap));
    imprimir_heap(heap);

    destruir_heap(heap);
    return 0;
}
