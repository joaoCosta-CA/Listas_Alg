#include <stdio.h>

struct cadastro{
    char nome[50];
    char end[50];
    int idade;
};

int main(){
    struct cadastro p1;

    printf("Digite o seu nome:\n");
    setbuf(stdin, NULL);
    fgets(p1.nome, sizeof(p1.nome), stdin);

    printf("Digite seu enderco:\n");
    setbuf(stdin, NULL);
    fgets(p1.end, sizeof(p1.end), stdin);

    printf("Digite sua idade:\n");
    setbuf(stdin, NULL);
    scanf("%d", &p1.idade);

    printf("\n");

    printf("Ola %s!\nVoce mora na %se tem %d ano(s) de idade", p1.nome, p1.end, p1.idade);
}