#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct{
    char nome[50];
    char telefone[15];
    int dia, mes, ano; 
} Contato;

void inserirContato(Contato **agenda, int *tamanho){
    *agenda = realloc(*agenda, (*tamanho + 1) * sizeof(Contato));
    if (*agenda == NULL){
        printf("Erro de alocação!\n");
        exit(1);
    }

    printf("Nome: ");
    scanf(" %[^\n]", (*agenda)[*tamanho].nome);

    printf("Telefone: ");
    scanf(" %[^\n]", (*agenda)[*tamanho].telefone);

    printf("Data de nascimento (dd mm aaaa): ");
    scanf("%d %d %d", &(*agenda)[*tamanho].dia, &(*agenda)[*tamanho].mes, &(*agenda)[*tamanho].ano);

    (*tamanho)++;
    printf("Contato adicionado com sucesso!\n");
}

void removerContato(Contato *agenda, int *tamanho){
    char nome[50];
    printf("Nome do contato a remover: ");
    scanf(" %[^\n]", nome);

    int i;
    for (i = 0; i < *tamanho; i++){
        if (strcmp(agenda[i].nome, nome) == 0){
            for (int j = i; j < *tamanho - 1; j++){
                agenda[j] = agenda[j + 1];
            }
            (*tamanho)--;
            printf("Contato removido com sucesso!\n");
            return;
        }
    }
    printf("Contato não encontrado.\n");
}

void pesquisarContato(Contato *agenda, int tamanho){
    char nome[50];
    printf("Nome a pesquisar: ");
    scanf(" %[^\n]", nome);

    for (int i = 0; i < tamanho; i++){
        if (strcmp(agenda[i].nome, nome) == 0){
            printf("\nNome: %s\nTelefone: %s\nData de nascimento: %02d/%02d/%04d\n",
                   agenda[i].nome, agenda[i].telefone,
                   agenda[i].dia, agenda[i].mes, agenda[i].ano);
            return;
        }
    }
    printf("Contato não encontrado.\n");
}

void listarContatos(Contato *agenda, int tamanho){
    if (tamanho == 0){
        printf("Agenda vazia.\n");
        return;
    }

    for (int i = 0; i < tamanho; i++){
        printf("\n[%d]\nNome: %s\nTelefone: %s\nData de nascimento: %02d/%02d/%04d\n",
               i + 1, agenda[i].nome, agenda[i].telefone,
               agenda[i].dia, agenda[i].mes, agenda[i].ano);
    }
}

void listarPorLetra(Contato *agenda, int tamanho){
    char letra;
    printf("Letra inicial: ");
    scanf(" %c", &letra);
    letra = tolower(letra);

    int achou = 0;
    for (int i = 0; i < tamanho; i++){
        if (tolower(agenda[i].nome[0]) == letra){
            printf("\nNome: %s\nTelefone: %s\nData de nascimento: %02d/%02d/%04d\n",
                   agenda[i].nome, agenda[i].telefone,
                   agenda[i].dia, agenda[i].mes, agenda[i].ano);
            achou = 1;
        }
    }
    if (!achou)
        printf("Nenhum contato encontrado com essa letra.\n");
}

void listarAniversariantes(Contato *agenda, int tamanho){
    int mes;
    printf("Digite o mês (1-12): ");
    scanf("%d", &mes);

    int achou = 0;
    for (int i = 0; i < tamanho; i++){
        if (agenda[i].mes == mes){
            printf("\nNome: %s\nTelefone: %s\nData de nascimento: %02d/%02d/%04d\n",
                   agenda[i].nome, agenda[i].telefone,
                   agenda[i].dia, agenda[i].mes, agenda[i].ano);
            achou = 1;
        }
    }
    if (!achou)
        printf("Nenhum aniversariante neste mês.\n");
}

void salvarEmTxt(Contato *agenda, int tamanho, FILE *arq){
    for(int i=0;i<tamanho;i++){
        size_t escrever=fwrite(&agenda[i],sizeof(agenda),1,arq);
        if(!escrever){
            printf("Erro ao escrever o arquivo");
        }
    }
    puts("Arquivo salvo com sucesso");

    fclose(arq);

}

void menu(){
    printf("\n--- MENU ---\n");
    printf("a) Inserir contato\n");
    printf("b) Remover contato\n");
    printf("c) Pesquisar por nome\n");
    printf("d) Listar todos os contatos\n");
    printf("e) Listar por letra inicial\n");
    printf("f) Aniversariantes do mes\n");
    printf("s) Sair\n");
    printf("Escolha: ");
}

int main(){
    Contato *agenda = NULL;
    int tamanho = 0;
    char opcao;
    FILE *arq = fopen("Agenda.txt", "w+b");
    if (arq == NULL){
        printf("Erro ao abir o arquivo");
        exit(1);
    }

    do{
        menu();
        scanf(" %c", &opcao);
        switch (tolower(opcao))
        {
        case 'a':
            inserirContato(&agenda, &tamanho);
            break;
        case 'b':
            removerContato(agenda, &tamanho);
            break;
        case 'c':
            pesquisarContato(agenda, tamanho);
            break;
        case 'd':
            listarContatos(agenda, tamanho);
            break;
        case 'e':
            listarPorLetra(agenda, tamanho);
            break;
        case 'f':
            listarAniversariantes(agenda, tamanho);
            break;
        case 's':
            printf("Encerrando...\n");
            salvarEmTxt(agenda,tamanho,arq);
            break;
        default:
            printf("Opção inválida!\n");
        }
    } while (opcao != 's');

    free(agenda);
    return 0;
}