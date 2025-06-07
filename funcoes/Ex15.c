#include <stdio.h>

int fibonacci(int n){
    if (n == 0)return 0;
    if (n == 1)return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main(){
    int termo;
    int resultado;

    puts("Digite um valor para a sequencia de fibonacci");
    scanf("%d", &termo);
    resultado = fibonacci(termo);
    printf("%d\n", resultado);

    return 0;
}