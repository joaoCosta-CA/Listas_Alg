#include <stdio.h>

struct data
{
    int dia, mes, ano;
};

int main()
{
    struct data d[2];
    int dias = 0;

    printf("Digite a data mais recente (dd/mm/aaaa): ");
    scanf("%d %d %d", &d[0].dia, &d[0].mes, &d[0].ano);

    printf("Digite a data mais antiga (dd/mm/aaaa): ");
    scanf("%d %d %d", &d[1].dia, &d[1].mes, &d[1].ano);

    for (int i = 0; i < 2; i++)
    {
        int bissexto = (d[i].ano % 4 == 0 && (d[i].ano % 100 != 0 || d[i].ano % 400 == 0));
        int dias_mes;
        if (d[i].mes == 2)
            dias_mes = bissexto ? 29 : 28;
        else if (d[i].mes == 4 || d[i].mes == 6 || d[i].mes == 9 || d[i].mes == 11)
            dias_mes = 30;
        else if (d[i].mes >= 1 && d[i].mes <= 12)
            dias_mes = 31;
        else
        {
            printf("Mes invalido\n");
            return 1;
        }

        if (d[i].dia < 1 || d[i].dia > dias_mes)
        {
            printf("Dia invalido para o mes informado\n");
            return 1;
        }
    }

    if (d[0].ano < d[1].ano ||
        (d[0].ano == d[1].ano && d[0].mes < d[1].mes) ||
        (d[0].ano == d[1].ano && d[0].mes == d[1].mes && d[0].dia < d[1].dia))
    {
        printf("As datas estao invertidas.\n");
        return 1;
    }

    if (d[0].dia == d[1].dia && d[0].mes == d[1].mes && d[0].ano == d[1].ano)
    {
        printf("As datas sao iguais\n");
        return 0;
    }

    struct data atual = d[1];

    while (atual.ano < d[0].ano || atual.mes < d[0].mes || atual.dia < d[0].dia)
    {
        int bissexto = (atual.ano % 4 == 0 && (atual.ano % 100 != 0 || atual.ano % 400 == 0));
        int dias_mes;
        if (atual.mes == 2)
            dias_mes = bissexto ? 29 : 28;
        else if (atual.mes == 4 || atual.mes == 6 || atual.mes == 9 || atual.mes == 11)
            dias_mes = 30;
        else
            dias_mes = 31;

        atual.dia++;
        if (atual.dia > dias_mes)
        {
            atual.dia = 1;
            atual.mes++;
            if (atual.mes > 12)
            {
                atual.mes = 1;
                atual.ano++;
            }
        }
        dias++;
    }

    printf("Se passaram %d dias\n", dias);
    return 0;
}
