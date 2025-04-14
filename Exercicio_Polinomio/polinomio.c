#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "polinomio.h"

typedef struct termo
{
    int coef, exp;
    struct termo *prox;
} Termo;

struct polinomio
{
    Termo *inicio;   //Não vou precisar do Termo *fim, somente do Termo *inicio
};

Polinomio* criarPolinomio(){
    Polinomio *p = (Polinomio *)malloc(sizeof(Polinomio));
    if (p!=NULL)
        p->inicio = NULL;

    return p;
}

void inserirTermo(Polinomio *p, int coef, int exp) {
    if (p == NULL || coef == 0 || exp<0) return;

    Termo *aux1 = p->inicio;
    Termo *aux2 = NULL;

    // Procuro a posição para inserção - ordem decrescente de expoente
    while (aux1 != NULL && aux1->exp > exp) {
        aux2 = aux1;
        aux1 = aux1->prox;
    }

    if (aux1 != NULL && aux1->exp == exp) {
        // Termo com mesmo expoente encontrado: somo os coeficientes
        aux1->coef += coef;

        // Se coeficiente virar zero, removo o termo
        if (aux1->coef == 0) {
            if (aux2 == NULL) {
                p->inicio = aux1->prox;
            } else {
                aux2->prox = aux1->prox;
            }
            free(aux1);
        }
    } else {
        // Crio novo termo somente quando necessário
        Termo *termo = (Termo*) malloc(sizeof(Termo));
        if (termo == NULL) return;

        termo->coef = coef;
        termo->exp = exp;
        termo->prox = aux1;

        if (aux2 == NULL) {
            p->inicio = termo;
        } else {
            aux2->prox = termo;
        }
    }
}


void mostrarPolinomio(Polinomio *p){
    if (p->inicio == NULL) {
        printf("0\n");
        return;
    }

    Termo *aux = p->inicio;
    int primeiro = 1;

    while (aux != NULL) {
        int c = aux->coef;
        int e = aux->exp;

        if (c == 0) {
            aux = aux->prox;
            continue;
        }

        // Mostro o sinal
        if (!primeiro) {
            if (c > 0) printf(" + ");
            else printf(" - ");
        } else {
            if (c < 0) printf("-");
        }

        // Mostro o coeficiente, sem mostrar 1 ou -1 quando apropriado
        int absCoef = abs(c); 
        if (absCoef != 1 || e == 0)
            printf("%d", absCoef);

        // Mostro a parte da variável x
        if (e != 0) {
            printf("x");
            if (e != 1)
                printf("^%d", e);
        }

        primeiro = 0;
        aux = aux->prox;
    }

    printf("\n");
}

double calcularPotencia(int base, int exp){
    double resultado = 1.0;
    for (int i = 0; i < exp; i++) {
        resultado *= base;
    }
    return resultado;
}

double avaliarPolinomio(Polinomio *p, double x)   {
    double resultado = 0.0;
    Termo* aux = p->inicio;
    while (aux != NULL) {
        resultado += aux->coef * calcularPotencia(x, aux->exp); //poderia usar pow de math.h
        aux = aux->prox;
    }
    return resultado;
}

void liberarPolinomio(Polinomio *p) {
    if (p==NULL)
      return;

    Termo *aux = p->inicio;
    while(aux!=NULL){
        Termo *proximo = aux->prox;
        free(aux);
        aux=proximo;
    }
    free(p);
}
