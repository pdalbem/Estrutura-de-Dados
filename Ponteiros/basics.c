#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a = 50;
    const int *pointerA = &a; // declara um ponteiro que é constante 
    // *pointerA=60;  ponteiro não pode alterar valor da variável a

    //ponteiro para array
    int array[] = {100, 200, 300};  
    int *pointer = array;
    printf("Elementos: %d %d %d\n", array[0], array[1], array[2]);
    printf("Elementos: %d %d %d\n", *pointer, *(pointer + 1), *(pointer + 2));


    int x = 50;
    int *p = &x;
    *p = 55;
    int **q = &p;
    **q = 60;

    printf("Conteúdo de x: %d\n", x);
    printf("Endereço de x: %p\n", &x);
    printf("Conteúdo de x via p: %d\n", *p);
    printf("Conteúdo de p: %p\n", p);
    printf("Endereço de p: %p\n", &p);
    printf("Conteúdo de x via q: %d\n", **q);
    printf("Endereço de q: %p\n", &q);
    printf("Conteúdo de q: %p\n", q);
    printf("Conteúdo de p via q: %p\n", *q);

    p++; // por isso pointers precisam de tipo
    printf("Novo endereço de p: %p\n", p);

    int *ptr;
    // *ptr=10; Cuidado, ptr não foi inicializado

    ptr = (int *)malloc(sizeof(int)); //alocação dinâmica de memória
    *ptr = 10;   
    printf("Conteúdo de ptr: %d\n", *ptr);
    free(ptr);

    return 0;
}
