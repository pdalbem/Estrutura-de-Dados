#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Aluno.h"

struct aluno
{
    int prontuario;
    char nome[100];
    Curso *curso;
};

Aluno *criarAluno(const char *nome, int prontuario, Curso *curso)
{
    Aluno *novoAluno = (Aluno *)malloc(sizeof(Aluno));
    if (novoAluno != NULL)
    {
        strcpy(novoAluno->nome, nome);
        novoAluno->prontuario = prontuario;
        novoAluno->curso = curso;
    }
    return novoAluno;
}

void obterNomeAluno(Aluno *a, char *nome)
{
    if (a != NULL && nome != NULL)
    {
        strcpy(nome, a->nome);
    }
}

int obterProntuario(Aluno* a)
{
    if (a != NULL)
    {
        return a->prontuario;
    }
}

Curso* obterCurso(Aluno* a) {
    if (!a) return NULL;
    return a->curso; 
}


void liberarAluno(Aluno* a) 
{
        free(a);
}
