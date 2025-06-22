#include <stdio.h>

struct Aluno{
    int matricula;
    char nome[50];
    int n1,n2,n3;
};

int main(){
  struct Aluno aluno;
  
  printf("Tamanho do struct: %lu bytes", sizeof(struct Aluno));

  return 0;
}