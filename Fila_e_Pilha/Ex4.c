#include <stdio.h>
#include <stdlib.h>

typedef struct elemento{
    int valor;
    struct elemento *prox;
}elemento;

typedef struct{
    elemento *topo;
}Pilha;

void iniciar(Pilha *p){
    p->topo=NULL;
}

int vazia(Pilha *p){
   return p->topo==NULL;
}

void inserir(Pilha *p, int valor){
    elemento *novo=malloc(sizeof(elemento));
    novo->valor=valor;
    novo->prox=p->topo;
    p->topo=novo;
}

int retirar(Pilha *p, int *valor){
    if(vazia(p)){
        return 0;
    }

    elemento *guard= p->topo;
    *valor=guard->valor;
    p->topo=guard->prox;
    free(guard);

    return 1;
}

void mostrarPilha(Pilha *p){
    elemento *atual=p->topo;
    printf("Pilha:\n");

    while(atual!=NULL){
        printf("%d ", atual->valor);
        atual=atual->prox;
    }
}

void verNeg(Pilha *p){
    elemento *atual=p->topo;
    elemento *anterior=NULL;

    while(atual!=NULL){

        if(atual->valor<0){
            if(anterior==NULL){
                p->topo=atual->prox;
                free(atual);
                atual=p->topo;
            }else{
                anterior->prox=atual->prox;
                free(atual);
                atual = anterior->prox;
            }
        }else{
            anterior=atual;
            atual= atual->prox;
        }
    }
}

int topo(Pilha *p){
    return p->topo->valor;
}

int main(){
    Pilha p;
    int valor;
    int tamanho=0;
    iniciar(&p);

    puts("Digite um valor:");
    for(int i=0;i<10;i++){
        scanf("%d", &valor);
        inserir(&p,valor);
        tamanho++;
    }

    mostrarPilha(&p);
    verNeg(&p);
    printf("\n");
    mostrarPilha(&p);

    return 0;
}