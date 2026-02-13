typedef struct curso Curso;

Curso* criarCurso(const char* sigla, const char* nome) ;
void obterSigla(Curso *c, char* sigla);
void obterNomeCurso(Curso *c, char* nome);
void liberarCurso(Curso *c);


