#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

//Crivo de Eratóstenes - Mostra todos os números primos menores que N
//Complexidade: O(N log log N).


void crivo(int n) {
    // Usando um array de booleanos para economizar memória
    bool array[n+1];

    // Inicializa todos os números como primos (true)
    for (int i = 2; i <= n; i++) {
        array[i] = true;
    }

    // Aplicando o Crivo de Eratóstenes
    for (int i = 2; i <= sqrt(n); i++) 
        if (array[i])  // Se i for primo
            for (int j = i * i; j <= n; j += i)  // Começa em i * i
                array[j] = false; // Marca os múltiplos como não primos
            
        
    

    // Exibindo os números primos
    printf("Números primos:\n\n");
    for (int i = 2; i <= n; i++) 
        if (array[i]) 
            printf("%d  ", i);
        
    

    printf("\n\n");


}

int main() {
    int n;
    printf("Digite um valor para 'n': ");
    scanf("%d", &n);

    crivo(n);

    return 0;
}

