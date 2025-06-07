#include <stdio.h>

int contarCaracteres(char *p){
    int cont = 0;

    while (*p != '\0' && *p != '\n'){ 
        if(*p==' '){
            cont--;
        }
        cont++;
        p++; 
    }

    return cont;
}

int main(){
    char frase[51]; 

    printf("Digite uma frase (ate 50 caracteres):\n");
    fgets(frase, 51, stdin);

    int total = contarCaracteres(frase);

    printf("A frase possui %d caracteres.\n", total);

    return 0;
}