#include <stdio.h>

void imprimir(float *p, float a[3][3]){
    p=&a[0][0];

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            printf("Endereco da matriz[%d][%d]= %p\n", i,j,(p+i*3+j));
        }
    }
}

int main(){
    float v[3][3];
    float *p;

    imprimir(p,v);
}