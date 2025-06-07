#include <stdio.h>

void imprimirPalavras(char *frase){
    char *p = frase;

    while (*p != '\0'){
        while (*p == ' ')
            p++;

        while (*p != ' ' && *p != '\0'){
            putchar(*p);
            p++;
        }

        if (*p == ' ' || *p == '\0'){
            putchar('\n');
        }
    }
}

int main(){
    char frase[61];

    printf("Digite uma frase (ate 60 caracteres):\n");
    fgets(frase, 61, stdin);

    imprimirPalavras(frase);

    return 0;
}