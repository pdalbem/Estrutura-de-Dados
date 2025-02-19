#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Aluno.h"

struct aluno {
    int prontuario;
    char nome[100];
    Curso* curso; 
};


Aluno* criarAluno(const char* nome, int prontuario, Curso* curso) {
    Aluno* novoAluno = (Aluno*)malloc(sizeof(Aluno));
    if (novoAluno != NULL) {
        strcpy(novoAluno->nome, nome);
        novoAluno->prontuario = prontuario;
        novoAluno->curso = curso; 
    }
    return novoAluno;
}

void matricular(Aluno* aluno, Curso* curso){
    aluno->curso=curso;
}

void exibirAluno(Aluno* aluno) {
    printf("Aluno: %s\n", aluno->nome);
    printf("Prontuário: %d", aluno->prontuario);
    if (aluno->curso != NULL) {
        exibirCurso(aluno->curso);
    } else {
        printf("\nNão matriculado em nenhum curso.\n");
    }
}
