#include "Curso.h"

typedef struct aluno Aluno;

Aluno* criarAluno(const char* nome, int prontuario, Curso* curso);
void obterNomeAluno(Aluno* a, char* nome);
int obterProntuario(Aluno* a);
Curso* obterCurso(Aluno* a);
void liberarAluno(Aluno* a);    

