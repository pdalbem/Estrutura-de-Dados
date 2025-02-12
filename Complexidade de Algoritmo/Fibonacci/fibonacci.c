#include <stdio.h>

// Complexidade:
// Melhor caso: O(1) (casos quando n = 0 ou n = 1).
// Caso médio: O(n).
// Pior caso: O(n).

int fibonacci(int n) {

    if (n == 0) 
        return 0;
    
    if (n == 1) 
        return 1;
    

    int a = 0, b = 1, temp;

    for (int i = 2; i <= n; i++) {
        temp = a + b;
        a = b;
        b = temp;
    }

    return b;
}

int main() {
    int n;
    printf("Digite o valor de n: ");
    scanf("%d", &n);

    int result = fibonacci(n);
    printf("O %d-ésimo termo da sequência de Fibonacci é: %d\n", n, result);

    return 0;
}
