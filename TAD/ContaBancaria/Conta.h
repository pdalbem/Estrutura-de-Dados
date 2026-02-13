#define ERROR 0
#define SUCCESS 1

typedef struct conta Conta;

Conta* criarConta(int num, double saldo);
int depositar(Conta *conta, double valor);
int sacar(Conta *conta, double valor);
int transferir(Conta *origem, Conta* destino, double valor);
int obterNum(Conta *conta);
double obterSaldo(Conta * conta);
void liberarConta(Conta *conta);
