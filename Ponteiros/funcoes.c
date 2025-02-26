#include <stdio.h>
#include <stdlib.h>

//passagem de parâmetros por referência
void troca(int *x, int *y)
{
    int aux=*x;
    *x=*y;
    *y=aux;
}

//função retorna um ponteiro para int
// int* soma(int x,int y)
// {
//    int z=x+y;
//    return &z; CUIDADO, variável z foi declarada no stack. QUando a função terminar,
// }             o endereço de memória de z é liberado automaticamente


//função retorna um ponteiro para int
int* soma(int x,int y)
{
   int *z=(int*)malloc(sizeof(int));
   *z=x+y;
   return z; 

}

int main()
{
    int a=50;
    int b=70;
    troca(&a,&b);
    printf("a: %d\n", a);
    printf("b: %d\n", b);

    int *ptr=soma(a,b);
    return 0;
}