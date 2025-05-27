#include <stdio.h>

#define tam 5

struct produto{
    int cod; 
    int preco, qnt;
    char nome[15];

};

int main(){
    struct produto p[5] = {
        {12345, 2500, 10, "Tv"},
        {54321, 1234, 11, "micro-wave"},
        {16789, 666, 13, "xebiu"},
        {12367, 999, 19, "dedo de gorila"},
        {98765, 1, 20, "Pimenta"}
    };
    int usercod,userqnt, soma=0,prec=0;

    for(int i=0;i<tam;){
        printf("Produto:%d\n", i+1);

        printf("Codigo do produto:");
        scanf("%d", &usercod);

        if(usercod==0){
            break;
        }else{
            printf("Quantidade do produto:");
            scanf("%d", &userqnt);

            for (int i = 0; i < tam; i++){
                if (usercod == p[i].cod){
                    printf("Codigo encontrado!\n");

                    if (userqnt <= p[i].qnt){
                        printf("Quantidade suficiente!\n");
                        p[i].qnt=p[i].qnt-userqnt;
                        printf("Quantidade atual:%d\n", p[i].qnt);
                        prec=userqnt*p[i].preco;
                        soma+=prec;
                    }else{
                        printf("A quantidade de item no estoque eh insuficiente!\n");

                    }
                }
            }
            printf("====================================\n");
        }

    }

    printf("Preco final=%d", soma);
}