#include <stdio.h>
#include <stdlib.h>

typedef struct elemento{
    int valor;
    struct elemento *prox;
}ELEMENTO;

typedef ELEMENTO *PONT;

typedef struct{
    PONT inicio;
}lista;

void iniciar(lista *l){
    l->inicio=NULL;
}

int tamanho(lista *l){
    int tamanho=0;
    PONT atual=l->inicio;
    while(atual!=NULL){
        tamanho++;
        atual=atual->prox;
    }

    return tamanho;
}

int push(lista *l, int valor){
    PONT novo=(PONT)malloc(sizeof(ELEMENTO));
    if(!novo)return 1;

    novo->valor=valor;
    novo->prox=l->inicio;
    l->inicio=novo;

    return 0;
}

void exibirLista(lista *l){
    if (l->inicio == NULL){
        puts("Lista vazia!");
        return ;
    }

    PONT atual=l->inicio;
    puts("Lista /");
    while(atual!=NULL){
        printf("%d-> ", atual->valor);
        atual=atual->prox;
    }
    printf("NULL\n");
}

void reiniciar(lista *l){
    PONT atual=l->inicio;
    while(atual!=NULL){
        PONT temp=atual;
        atual=atual->prox;
        free(temp);
    }

    l->inicio=NULL;
}

int endpush(lista *l, int valor){
    PONT novo=(PONT)malloc(sizeof(ELEMENTO  ));
    if(novo==NULL)return 1;

    novo->valor=valor;
    if(l->inicio==NULL){
        novo->prox=l->inicio;
        l->inicio=novo;
    }else{

        PONT atual=l->inicio;
        while(atual->prox!=NULL){
            atual=atual->prox;
        }
        novo->prox=atual->prox;
        atual->prox=novo;
    }

    return 0;
}

void buscarEl(lista *l, int chave){
    int tam=1;
    PONT atual=l->inicio;
    while (atual!=NULL && atual->valor!=chave){
        tam++;
        atual=atual->prox;
    }
    if(atual==NULL){
        puts("Esse elemento nao esta na lista");
        return;
    }else if(atual->valor==chave){
        printf("Valor %d esta na lista\n", atual->valor);
        printf("Posicao: %d", tam);
    }
    
}

int excluir(lista* l, int chave){
    PONT atual=l->inicio;
    PONT ant=NULL;

    while (atual!=NULL && atual->valor != chave){
        ant=atual;
        atual=atual->prox;
    }

    if(atual==NULL)return 0;

    if(ant==NULL){
        l->inicio=atual->prox;
    }else{
        ant->prox=atual->prox;
        free(atual);
    }

    return 0;
    
}

void buscaOrd(lista *l, int chave){
    PONT atual=l->inicio;

    while(atual!=NULL && atual->valor<chave){
        atual=atual->prox;
    }

    if (atual!=NULL && atual->valor==chave){
        puts("Valor encontrado");
        return;
    }
    else{
        puts("Numero nao encontrado");
        return;
    }
}

void ordenarLIst(lista *l){
    if(l->inicio==NULL)return;

    int trocou;
    do{
        trocou=0;

        PONT atual=l->inicio;
        while(atual->prox!=NULL){
            if(atual->valor>atual->prox->valor){
                int temp;
                temp=atual->valor;
                atual->valor=atual->prox->valor;
                atual->prox->valor=temp;
                trocou= 1;
            }
            atual=atual->prox;
        }
    }while(trocou);
}

void inserirPorPosicao(lista *l, int valor, int pol){
    if(l->inicio==NULL)return;

    PONT novo=(PONT)malloc(sizeof(ELEMENTO));
    novo->valor=valor;
    PONT atual=l->inicio;
    int tam=1;

    while(atual!=NULL && tam!=pol){
        atual=atual->prox;
        tam++;
    }
    if(atual==NULL){
        puts("Tamanho da lista incopativel");
    }else if(tam==pol){
        novo->prox=atual->prox;
        atual->prox=novo;
    }
}

void inverter(lista *l){
    PONT anterior = NULL;
    PONT atual = l->inicio;
    PONT proximo = NULL;

    while (atual != NULL){
        proximo = atual->prox;  
        atual->prox = anterior; 
        anterior = atual;       
        atual = proximo;        
    }

    l->inicio = anterior; 
}

int main(){
    int tam;
    lista *l = malloc(sizeof(lista));
    if (!l)return 1;
    iniciar(l);

    push(l,6);
    push(l,2);
    push(l,1);
    push(l,7);
    endpush(l,30);
    exibirLista(l);
    tam = tamanho(l);
    printf("Tamanho da lista: %d\n", tam);
    excluir(l,30);
    ordenarLIst(l);
    exibirLista(l);
    inserirPorPosicao(l,10,4);
    exibirLista(l);
    inverter(l);
    exibirLista(l);
    reiniciar(l);

    return 0;
}