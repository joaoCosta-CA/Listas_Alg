#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void stringInv(char v[], int tamanho){
    char temp;
    int inicio = 0;
    int fim = tamanho - 1;

    while (inicio < fim)
    {
        temp = v[inicio];
        v[inicio] = v[fim];
        v[fim] = temp;

        inicio++;
        fim--;
    }
}

int main(){
    char v[50];

    printf("Digite uma string:");
    fgets(v,50,stdin);
    v[strcspn(v, "\n")] = '\0';

    int tamanho = strlen(v);

    stringInv(v, tamanho);

    printf("String invertida: %s", v);

    return 0;
}