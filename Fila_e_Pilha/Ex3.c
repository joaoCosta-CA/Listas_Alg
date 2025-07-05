#include <stdio.h>
#include <stdlib.h>

typedef struct elemento{
    int valor;
    struct elemento *prox;
}elemento;

typedef struct{
    elemento *inicio;
    elemento *fim;
}Fila;

void inicializar(Fila *f){
    f->inicio=NULL;
    f->fim=NULL;
}

int push(Fila *f, int valor){
    elemento *novo=(elemento *)malloc(sizeof(elemento));
    if(novo==NULL)return 1;

    novo->valor=valor;
    novo->prox=NULL;

    if(f->inicio==NULL){
        f->inicio=novo;
    }else{
        f->fim->prox=novo;
    }

    f->fim=novo;

    return 0;
}

int pushRverso(Fila *f, int valor){
    elemento *novo = (elemento *)malloc(sizeof(elemento));
    if (novo == NULL)return 1;

    novo->valor = valor;
    novo->prox = f->inicio;
    f->inicio = novo;

    if(f->fim==NULL)f->fim=novo;
    
    return 0;
}

int pop(Fila *f){
    int chave;
    if (f->inicio == NULL)return 1;

    chave=f->inicio->valor;
    elemento *apagar=f->inicio;
    f->inicio=apagar->prox;

    if(f->inicio==NULL){
        f->fim=NULL;
    }
    free(apagar);

    return chave;
}

int exibirFila(Fila *f){
    if(f->inicio==NULL)return 1;

    elemento *p=f->inicio;
    while(p!=NULL){
        printf("%d ", p->valor);
        p=p->prox;
    }
    puts("\n");

    return 0;
}

void reverso(Fila *f, Fila *f2){
    while ((f->inicio!=NULL)){
        int valor=pop(f);
        pushRverso(f2,valor);
    }
}

int main(){
    Fila *f=malloc(sizeof(Fila));
    Fila *f2=malloc(sizeof(Fila));
    inicializar(f);
    inicializar(f2);
    int valor;

    puts("Digite os valores para entrar na fila:");
    for(int i=0;i<5;i++){
        scanf("%d", &valor);
        push(f,valor);
    }

    puts("Fila original:");
    exibirFila(f);
    reverso(f,f2);
    puts("Fila reversa:");
    exibirFila(f2);

    return 0;
}