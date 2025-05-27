#include  <stdio.h>

int main(){
  float vet[10], quad[10];

  printf("Digite 10 valroes do conjunto dos Reais:\n");
  for(int i=0;i<10;i++){
    scanf("%f", &vet[i]);
  }

  for(int j=0;j<10;j++){
    quad[j]=vet[j]*vet[j];
  }
  
  printf("Vetor inicial:\n");
  for(int k=0;k<10;k++){
    printf("[%.2f]\n", vet[k]);
  }

  printf("Vetor dos quadrados:\n");
  for(int l=0;l<10;l++){
    printf("[%.2f]\n", quad[l]);
  }
}