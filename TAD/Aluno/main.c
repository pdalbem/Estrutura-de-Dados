#include <stdio.h>
#include <stdlib.h>
#include "Curso.h"
#include "Aluno.h"

int main() {
    Curso* curso1 = criarCurso("ADS", "Análise e Desenvolvimento de Sistemas");
    Curso* curso2 = criarCurso("BES", "Bach. Engenharia de Software");

    printf("Informações do Curso 1:");
    exibirCurso(curso1);
    printf("\n");

    printf("Informações do Curso 2:");
    exibirCurso(curso2);
    printf("\n");


    Aluno* aluno1 = criarAluno("João", 12345, curso1); 
    Aluno* aluno2 = criarAluno("Maria", 67890, curso2); 


    printf("Informações do Aluno 1:\n");
    exibirAluno(aluno1);
    printf("\n");

    printf("Informações do Aluno 2:\n");
    exibirAluno(aluno2);
    printf("\n");


    free(curso1);
    free(curso2);
    free(aluno1);
    free(aluno2);

    return 0;
}
