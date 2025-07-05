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
    if(p->topo==NULL){
        return 1;
    }

    return 0;
}

int push(Pilha *p, char carac){
    elemento *caracter=(elemento *)malloc(sizeof(elemento));
    if(caracter==NULL){
        return 1;
    }
    caracter->letra=carac;
    caracter->prox=p->topo;
    p->topo=caracter;

    return 0;
}

char pop(Pilha *p){
    char chave;
    if(p->topo==NULL)exit(1);

    chave=p->topo->letra;
    elemento *apagar=p->topo;
    p->topo=p->topo->prox;
    free(apagar);
    return chave;
}

void mostrarPilha(Pilha *p){
    puts("Pilha:");
    elemento *atual=p->topo;
    while (atual != NULL){
        printf("%c", atual->letra);
        atual=atual->prox;
    }
}

void palind(Pilha *p, char *string){
    char carac;
    int i=0;
    int tamanho=strlen(string);

    while(i<tamanho){
        carac=pop(p);
        if(string[i]!=carac){
            puts("Nao eh um palindromo");
            exit(1);
        }

        i++;
    }

    puts("Eh um palindromo");
    exit(0);
}

void reinicializarPilha(Pilha *p){
    elemento *atual=p->topo;
    while(atual!=NULL){
        elemento *apagar=atual;
        atual=atual->prox;
        free(apagar);
    }

    p->topo=NULL;
}

int main(){
    Pilha *p=malloc(sizeof(Pilha));
    char palavra[50];
    puts("Digite uma palvra:");
    fgets(palavra,50,stdin);
    palavra[strcspn(palavra,"\n")]='\0';


    int tamanho=strlen(palavra);

    for(int i=0;i<tamanho;i++){
        push(p,palavra[i]);
    }

    palind(p,palavra);
    reinicializarPilha(p);

    return 0;
}