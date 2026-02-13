#include <stdio.h>
#include <stdlib.h>
#include "Curso.h"
#include "Aluno.h"

int main() {
    Curso* curso1 = criarCurso("ADS", "Análise e Desenvolvimento de Sistemas");
    Curso* curso2 = criarCurso("BES", "Bach. Engenharia de Software");

    Aluno* aluno1 = criarAluno("João", 12345, curso1); 
    Aluno* aluno2 = criarAluno("Maria", 67890, curso2); 


    char nomeAluno[100];
    obterNomeAluno(aluno1,nomeAluno);

    Curso* cursoAluno = obterCurso(aluno1);
    char nomeCurso[100];
    obterNomeCurso(cursoAluno, nomeCurso);

    printf("Pront: %d, Nome: %s, Curso: %s \n",obterProntuario(aluno1), nomeAluno, nomeCurso);

    liberarCurso(curso1);
    liberarCurso(curso2);
    liberarAluno(aluno1);
    liberarAluno(aluno2);

    return 0;
}
