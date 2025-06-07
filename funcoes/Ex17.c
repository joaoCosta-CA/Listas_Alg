#include <stdio.h>

double serie(int n){
    if (n == 1)
        return 2.0 + (1.0 + 1.0) / 1.0;
    return (1.0 + n * n) / n + serie(n - 1);
}

int main(){
    int n;
    double resultado;

    puts("Digite um valor maior que zero");
    scanf("%d", &n);
    resultado = serie(n);
    printf("%.2lf\n", resultado);

    return 0;
}