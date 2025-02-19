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

void exibirCurso(Curso* curso) {
    printf("\nCurso: %s (%s)\n", curso->nome, curso->sigla);
}
