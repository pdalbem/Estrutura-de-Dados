#include<stdio.h>
#include<stdlib.h>

typedef struct{
    int num, den;
}Fracao;

Fracao criarFracaoEstatica(int num,int den)
{
    Fracao f; //criada no stack, endereço é liberado automaticamente quando
    f.num=num; //função termina
    f.den=den;
    return f;
}

Fracao* criarFracaoDinamica(int num, int den)
{
    Fracao *f= (Fracao*)malloc(sizeof(Fracao)); //alocada no heap, permanece até ser liberada por free
    f->num=num;
    f->den=den;
    return f;
}

int main()
{
    Fracao f1;
    f1.num=12;
    f1.den=6;

    Fracao *f2=&f1;
    (*f2).num=14;   //f2->num=14;
    (*f2).den=7;   //f2->den=7;

    Fracao *f3 = (Fracao*)malloc(sizeof(Fracao));
    f3->num=16;
    f3->den=8;

    Fracao f4 = criarFracaoEstatica(3,4);

    Fracao *f5=criarFracaoDinamica(3,4);

    return 0;
}