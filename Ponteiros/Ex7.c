#include <stdio.h>
#include <string.h>

void contida(char *str1, char *str2){
    char *p1 = str1;
    char *p2 = str2;
    int achou = 0;

    while (*p1 != '\0'){
        char *inicio = p1;
        char *q = p2;

        while (*p1 != '\0' && *q != '\0' && *p1 == *q){
            p1++;
            q++;
        }

        if (*q == '\0'){
            achou = 1;
            break;
        }

        p1 = inicio + 1;
    }

    if (achou){
        printf("'%s' esta contida em '%s'\n", str2, str1);
    }
    else{
        printf("'%s' NAO esta contida em '%s'\n", str2, str1);
    }
}

void removerQuebraLinha(char *str){
    while (*str != '\0'){
        if (*str == '\n'){
            *str = '\0';
            break;
        }
        str++;
    }
}

int main(){
    char str1[50], str2[50];

    puts("Digite uma string:");
    fgets(str1, 50, stdin);
    removerQuebraLinha(str1);

    puts("Digite outra string:");
    fgets(str2, 50, stdin);
    removerQuebraLinha(str2);

    contida(str1, str2);
    return 0;
}