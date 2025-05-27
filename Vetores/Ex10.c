#include <stdio.h>

int main(){
    char text[20], text2[20], cont[20];
    int x=0;
    setbuf(stdin, NULL);

    printf("Digite a priemeira palavra:\n");
    fgets(text, sizeof(text), stdin);

    printf("Digite a segunda:\n");
    fgets(text2, sizeof(text2), stdin);


    for(int i=0;text[i]!='\0';i++){
        for(int j=0;j<text2;j++){
            if (text2[j]==text[i]){
                x++;
                cont[i]=text2[j];
            }
        }
    }

    printf("%s esta contida na primeira", cont);
}