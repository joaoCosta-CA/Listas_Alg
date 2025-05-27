#include <stdio.h>
#include <string.h>

#define tam 5

struct Livros{
    char titulo[30];
    char aut[15];
    int ano;
};

int main(){
 struct Livros livro[5]={
    {"pomba", "Eu", 2007},
    {"pombinha", "Voce", 1845},
    {"50 tons de azul", "Alguem", 5},
    {"bomba", "Seu pai", 100},
    {"bigode", "Nao", 2000}
 };
 char liv[20];

 printf("Qual livro procura?\n");
 setbuf(stdin,NULL);
 fgets(liv,20,stdin);
 liv[strcspn(liv,"\n")]='\0';


 for(int i=0;i<tam;i++){
    if(strcmp(liv, livro[i].titulo)==0){
        printf("Titulo:%s\nAutor:%s\nAno:%d", livro[i].titulo, livro[i].aut,livro[i].ano);
        return 0;
    }
 }

 puts("Livro nao encontrado!");

    
}