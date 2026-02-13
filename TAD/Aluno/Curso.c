#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Curso.h"

struct curso {
    char sigla[10];
    char nome[50];
};

Curso* criarCurso(const char* sigla, const char* nome) {
    Curso* novoCurso = (Curso*)malloc(sizeof(Curso));
    if (novoCurso != NULL) {
        strcpy(novoCurso->sigla, sigla);
        strcpy(novoCurso->nome, nome);
    }
    return novoCurso;
}

void obterSigla(Curso *c, char* sigla)
{
    if (c!= NULL && sigla !=NULL)
        strcpy(sigla, c->sigla);
}

void obterNomeCurso(Curso *c, char* nome)
{
    if (c!= NULL && nome !=NULL)
        strcpy(nome, c->nome);
}

void liberarCurso(Curso *c)
{
    free(c);
}
