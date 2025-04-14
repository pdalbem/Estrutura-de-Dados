typedef struct polinomio Polinomio;

Polinomio* criarPolinomio();
void inserirTermo(Polinomio *p, int coef, int exp);
double avaliarPolinomio(Polinomio *p, double x);  
void mostrarPolinomio(Polinomio *p); 
void liberarPolinomio(Polinomio *p);