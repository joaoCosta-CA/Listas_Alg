#include <stdio.h>

int main(){
    char text[20], x;
    char vogal[6]= {'a', 'e', 'i', 'o', 'u', '\0'};
    int v=0;
    setbuf(stdin, NULL);


    printf("Digite a palavra:\n");
    fgets(text, sizeof(text), stdin);

    printf("Digite uma vogal para substituicao:\n");
    scanf("%c", &x);
    

    for(int i=0;text[i]!='\0';i++){
        for(int j=0;j<6;j++){
            if(text[i]==vogal[j]){
                v++;
                text[i]=x;
            }
        }
    }

    printf("\n");

    printf("A palavra original tinha %d vogais\n", v);

    printf("E a palvra com substituicao fica: %s", text);
}