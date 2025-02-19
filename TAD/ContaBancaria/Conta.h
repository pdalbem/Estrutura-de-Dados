typedef struct conta Conta;

Conta* criarConta(int num, double saldo);
void depositar(Conta *conta, double valor);
void sacar(Conta *conta, double valor);
void transferir(Conta *origem, Conta* destino, double valor);
void exibirConta(Conta *conta);
