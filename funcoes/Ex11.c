#include <stdio.h>

void encaixa(int a[], int b[], int tamA, int tamB){
    int cont=0;

    if(tamB>tamA){
        cont=0;
    }
    
   for(int i=0;i<tamB;i++){
        if(a[tamA-tamB+i] !=b[i]){
            cont=0;
            break; 
        }else{
            cont=1;
        }
   }

   if (cont==1){
       printf("'b' encaixa em 'a'");
   }
   else{
       printf("'b' nao encaixa em 'a'");
   }
}

int main()
{
    int a[10],b[10],cont=0,cont2=0;

    puts("Digite um valor para:");
    for(int i=0;i<10;i++){
        scanf("%d", &a[i]);
        cont++;
        if (a[i] == 0){
            break;
        }
    }

    puts("Digite o segundo valor:");
    for(int i=0;i<10;i++){
        scanf("%d", &b[i]);
        cont2++;
        if (b[i] == 0){
            break;
        }
    }

    encaixa(a,b,cont,cont2);

    return 0;
}