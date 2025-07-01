#include <stdio.h>
#include <string.h>

struct endereco{
    char rua[20];
    int cep;
    char complemento[10];
    char bairro[20];
    char estado[20];
    char cidade[20];
    char pais[20];
};

struct telefone{
    int ddd;
    int number;
};

struct aniversario{
    int dia;
    int mes;
    int ano;
};

struct pessoa{
    char nome[30];
    char email[30];
    char obs[30];
    struct endereco ender;
    struct telefone tel;
    struct aniversario niver;
};

int main()
{
    struct pessoa ag[10] = {
        {"Alice", "alice@email.com", "amiga da faculdade", {"Rua A", 12345, "apt 1", "Bairro A", "SP", "Sao Paulo", "Brasil"}, {11, 999999001}, {1, 11, 1990}},
        {"Bruno", "bruno@email.com", "colega de trabalho", {"Rua B", 23456, "casa", "Bairro B", "RJ", "Rio", "Brasil"}, {21, 999999002}, {2, 3, 1991}},
        {"Carla", "carla@email.com", "vizinha", {"Rua C", 34567, "apt 2", "Bairro C", "MG", "Belo Horizonte", "Brasil"}, {31, 999999003}, {3, 3, 1992}},
        {"Daniel", "daniel@email.com", "amigo do curso", {"Rua D", 45678, "casa", "Bairro D", "RS", "Porto Alegre", "Brasil"}, {51, 999999004}, {4, 12, 1993}},
        {"Eva", "eva@email.com", "conhecida", {"Rua E", 56789, "apt 3", "Bairro E", "BA", "Salvador", "Brasil"}, {71, 999999005}, {5, 9, 1994}},
        {"Felipe", "felipe@email.com", "cliente", {"Rua F", 67890, "casa", "Bairro F", "PE", "Recife", "Brasil"}, {81, 999999006}, {6, 5, 1995}},
        {"Giovana", "giovana@email.com", "professora", {"Rua G", 78901, "apt 4", "Bairro G", "SC", "Florianopolis", "Brasil"}, {48, 999999007}, {7, 1, 1996}},
        {"Hugo", "hugo@email.com", "mentor", {"Rua H", 89012, "casa", "Bairro H", "PR", "Curitiba", "Brasil"}, {41, 999999008}, {8, 8, 1997}},
        {"Isabela", "isabela@email.com", "contato do evento", {"Rua I", 90123, "apt 5", "Bairro I", "CE", "Fortaleza", "Brasil"}, {85, 999999009}, {9, 10, 1998}},
        {"Joao", "joao@email.com", "parente", {"Rua J", 10234, "casa", "Bairro J", "AM", "Manaus", "Brasil"}, {92, 999999010}, {1, 11, 1999}}};

    int op, imp;
    char nome[30];
    int dia, mes;

    while (1)
    {
        puts("\nComo deseja buscar na agenda?");
        puts("1 - Pelo nome");
        puts("2 - Pelo dia e mes de nascimento");
        puts("3 - Nao buscar (sair)");
        scanf("%d", &op);

        if (op == 3)
        {
            break;
        }

        puts("Escolha em que formato quer que imprima as informacoes:");
        puts("1 - Nome, telefone e e-mail");
        puts("2 - Imprimir tudo");
        scanf("%d", &imp);
        getchar(); 

        if (op == 1)
        {
            printf("Digite o nome:\n");
            fgets(nome, sizeof(nome), stdin);
            nome[strcspn(nome, "\n")] = '\0';

            int encontrado = 0;
            for (int i = 0; i < 10; i++){
                if (strcmp(nome, ag[i].nome) == 0){
                    encontrado = 1;
                    if (imp == 1){
                        printf("\nNome: %s\nTelefone: (%d) %d\nEmail: %s\n", ag[i].nome, ag[i].tel.ddd, ag[i].tel.number, ag[i].email);
                    }
                    else if (imp == 2){
                        printf("\nNome: %s\nTelefone: (%d) %d\nData de nascimento: %d/%d/%d\nEmail: %s\nRua: %s\nComplemento: %s\nBairro: %s\nCidade: %s\nEstado: %s\nPais: %s\n",ag[i].nome, ag[i].tel.ddd, ag[i].tel.number,ag[i].niver.dia, ag[i].niver.mes, ag[i].niver.ano,ag[i].email, ag[i].ender.rua, ag[i].ender.complemento, ag[i].ender.bairro,ag[i].ender.cidade, ag[i].ender.estado, ag[i].ender.pais);
                    }
                    break; 
                }
            }if (!encontrado){
                printf("Pessoa nao encontrada.\n");
            }
        }
        else if (op == 2){
            printf("Digite o dia e o mes de nascimento:\n");
            scanf("%d %d", &dia, &mes);

            int encontrados = 0;
            for (int i = 0; i < 10; i++){
                if (ag[i].niver.dia == dia && ag[i].niver.mes == mes){
                    encontrados++;
                    if (imp == 1){
                        printf("\nNome: %s\nTelefone: (%d) %d\nEmail: %s\n", ag[i].nome, ag[i].tel.ddd, ag[i].tel.number, ag[i].email);
                    }
                    else if (imp == 2){
                        printf("\nNome: %s\nTelefone: (%d) %d\nData de nascimento: %d/%d/%d\nEmail: %s\nRua: %s\nComplemento: %s\nBairro: %s\nCidade: %s\nEstado: %s\nPais: %s\n",
                               ag[i].nome, ag[i].tel.ddd, ag[i].tel.number,
                               ag[i].niver.dia, ag[i].niver.mes, ag[i].niver.ano,
                               ag[i].email, ag[i].ender.rua, ag[i].ender.complemento, ag[i].ender.bairro,
                               ag[i].ender.cidade, ag[i].ender.estado, ag[i].ender.pais);
                    }
                }
            }if (encontrados == 0){
                printf("Nenhuma pessoa encontrada com essa data.\n");
            }
        }else{
            printf("Opcao invalida. Tente novamente.\n");
        }
    }

    return 0;
}
