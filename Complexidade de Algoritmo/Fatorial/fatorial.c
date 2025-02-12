#include <stdio.h>

// Complexidade:
// Melhor caso: O(1) (quando n = 0).
// Caso médio: O(n).
// Pior caso: O(n).

int factorial(int n) {
    int result = 1;


    for (int i = 1; i <= n; i++) {
        result *= i;
    }

    return result;
}

int main() {
    int n;
    printf("Digite o valor de n: ");
    scanf("%d", &n);

    if (n < 0) 
        printf("Fatorial não é definido para números negativos.\n");
     else {
        int result = factorial(n);
        printf("O fatorial de %d é: %d\n", n, result);
    }

    return 0;
}
