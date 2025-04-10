#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>
#include <time.h>
#include "blockchain.h"

// Função principal
int main() {
    Blockchain *bc = criarBlockchain();
    
    adicionarBloco(bc, "Pablo paga 10 BTC para Maria");
    adicionarBloco(bc, "Maria paga 5 BTC para Carlos");
    adicionarBloco(bc, "Joaquim paga 2 BTC para José");
    
    printf("\n=== Blockchain ===\n");
    mostrarBlockchain(bc);
    
    removerBloco(bc);
    printf("\nApós remoção do último bloco:\n");
    mostrarBlockchain(bc);
    
    liberarBlockchain(bc);
    return 0;
}
