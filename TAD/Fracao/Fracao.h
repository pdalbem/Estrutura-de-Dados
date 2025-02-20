typedef struct fracao Fracao;

Fracao* criarFracao(int num, int den);
Fracao* somarFracao(Fracao *f1, Fracao *f2);
Fracao* subtrairFracao(Fracao *f1, Fracao *f2);
Fracao* multiplicarFracao(Fracao *f1, Fracao *f2);
Fracao* dividirFracao(Fracao *f1, Fracao *f2);
void simplificarFracao(Fracao *f);
int compararFracao(Fracao *f1, Fracao *f2);
float converterParaDecimal(Fracao *f);
void exibirFracao(Fracao *f);
