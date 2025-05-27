#include <stdio.h>

int main()
{
    char str[4][30];
    char temp[30];
    char alf[26] = "abcdefghijklmnopqrstuvwxyz";
    char alfm[26] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    for (int i = 0; i < 4; i++){
        printf("Digite a palavra %d: ", i + 1);
        fgets(str[i], 30, stdin);

        for (int j = 0; j < 30; j++){
            if (str[i][j] == '\n'){
                str[i][j] = '\0';
                break;
            }
        }
    }

    for (int i = 0; i < 3; i++){
        for (int j = i + 1; j < 4; j++){
            int k = 0;
            int troca = 0;

            while (str[i][k] != '\0' && str[j][k] != '\0'){
                int pos1 = -1, pos2 = -1;

                for (int p = 0; p < 26; p++){
                    if (str[i][k] == alf[p] || str[i][k] == alfm[p]){
                        pos1 = p;
                    }
                    if (str[j][k] == alf[p] || str[j][k] == alfm[p]){
                        pos2 = p;
                    }
                }

                if (pos1 < pos2){
                    troca = 0;
                    break;
                }
                else if (pos1 > pos2)
                {
                    troca = 1;
                    break;
                }

                k++;
            }

            if (troca == 0 && str[i][k] == '\0' && str[j][k] != '\0'){
                troca = 0;
            }
            else if (troca == 0 && str[i][k] != '\0' && str[j][k] == '\0'){
                troca = 1;
            }

            if (troca == 1){
                for (int t = 0; t < 30; t++){
                    temp[t] = str[i][t];
                    str[i][t] = str[j][t];
                    str[j][t] = temp[t];
                }
            }
        }
    }

    for (int i = 0; i < 4; i++){
        printf("%s\n", str[i]);
    }

    return 0;
}