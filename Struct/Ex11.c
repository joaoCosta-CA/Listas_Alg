#include <stdio.h>
#include <string.h>
//teste

struct livro{
    char receita[25];
    int qnt_ing;;
    char nome_ing[20][10];

};

int main(){
    struct livro receitas[5] = {
        {"Bolo de cenoura", 3, {"cenoura", "acucar", "farinha"}},
        {"Macarronada", 4, {"macarrao", "molho", "queijo", "carne"}},
        {"Feijoada", 5, {"feijao", "carne", "linguica", "alho", "cebola"}},
        {"Panqueca", 4, {"farinha", "leite", "ovo", "sal"}},
        {"Salada verde", 3, {"alface", "rucula", "tomate"}}
    };

    char nome_receita[30];
    int encontrada=0;

    for(int i=0;i<1;){

        puts("Por qual receita procura?");
        setbuf(stdin,NULL);
        fgets(nome_receita,30,stdin);
        nome_receita[strcspn(nome_receita, "\n")] = '\0';

        if(nome_receita[i]=='\0'){
            break;
        }else{
            for(int i=0;i<5;i++){
                if (strcmp(nome_receita, receitas[i].receita) == 0){
                    encontrada=1;
                    printf("Nome da receita:%s\n", receitas[i].receita);
                    printf("Quantidade de ingredientes:%d\n", receitas[i].qnt_ing);
                    printf("Ingredientes:");
                    for(int j=0;j<receitas[i].qnt_ing;j++){
                        printf("%s, ", receitas[i].nome_ing[j]);
                    }
                }
            }
            if (!encontrada){
                printf("Receita nao encontrada!");
            }
        }
        printf("\n");
    }
}
