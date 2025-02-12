#include <stdio.h>

// Complexidade:
// Melhor caso: O(1) (quando n = 0 ou n = 1).
// Caso médio: O(2^n).
// Pior caso: O(2^n).

int fibonacci(int n) {
    if (n == 0) 
        return 0;
     else if (n == 1) 
        return 1;
    
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n;
    printf("Digite o valor de n: ");
    scanf("%d", &n);

    int result = fibonacci(n);
    printf("O %d-ésimo termo da sequência de Fibonacci é: %d\n", n, result);

    return 0;
}
