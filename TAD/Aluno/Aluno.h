#include "Curso.h"

typedef struct aluno Aluno;

Aluno* criarAluno(const char* nome, int prontuario, Curso* curso);
void matricular(Aluno* aluno, Curso* curso);
void exibirAluno(Aluno* aluno);

