#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct elemento{
    char letra;
    struct elemento *prox;
}elemento;

typedef struct{
    elemento *topo;
}Pilha;

void iniciar(Pilha *p){
    p->topo=NULL;
}

int vazio(Pilha *p){
    if(p->topo==NULL)return 1;

    return 0;
}

int push(Pilha *p, char chave){
    elemento *caracter=(elemento *)malloc(sizeof(elemento));
    if(caracter==NULL)return 1;

    caracter->letra=chave;
    caracter->prox=p->topo;
    p->topo=caracter;

    return 0;
}

char  pop(Pilha *p){
    char chave;
    if(p->topo==NULL)exit(1);

    chave=p->topo->letra;
    elemento *apagar=p->topo;
    p->topo=p->topo->prox;
    free(apagar);
    return chave;
}

void inverso(Pilha *p, char *string){
    char letra;
    int i=0;

    while(string[i]!='\0'){
        if(string[i] !=' ' && string[i]!='.'){
            push(p, string[i]);
        }else{
            while(p->topo!=NULL){
                letra=pop(p);
                printf("%c", letra);
            }
            if (string[i] == ' ' || string[i] == '.'){
                printf("%c", string[i]);
            }
        }
        i++;
    }
}

void reinicializar(Pilha *p){
    if(p->topo==NULL)exit(1);

    while(p->topo!=NULL){
        elemento *apagar=p->topo;
        p->topo=p->topo->prox;
        free(apagar);
    }
}

int main(){
    Pilha *p=(Pilha *)malloc(sizeof(elemento));
    char palavra[50];
    iniciar(p);

    puts("Digite uma frase:");
    fgets(palavra,50,stdin);
    palavra[strcspn(palavra,"\n")]='\0';


    inverso(p,palavra);
    reinicializar(p);

    return 0;
}