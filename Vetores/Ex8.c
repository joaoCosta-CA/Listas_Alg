#include <stdio.h>

int main(){
    char text[20];
    int carc=0;
    setbuf(stdin, NULL);

    printf("Digite um nome:\n");
    fgets(text, sizeof(text), stdin);

    for(int i=0;text[i]!='\0'; i++){
        if(text[i]=='\0' || text[i]=='\n'){
            break;
        }
        carc++;
    }

    printf("%stem:\n%d caracteres", text, carc);

}