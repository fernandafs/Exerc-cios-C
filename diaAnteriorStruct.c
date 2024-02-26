#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    int dia, mes, ano;
} Data;

int isBissexto(int ano) {
    return (ano % 4 == 0 && ano % 100 != 0) || ano % 400 == 0;
}

int isValida(Data dt) {
    
    if (dt.mes < 1 || dt.mes > 12 || dt.dia < 1)
        return 0;

    // fevereiro
    if (dt.mes == 2) {
        if (isBissexto(dt.ano)) {
            return (dt.dia <= 29);
        } else {
            return (dt.dia <= 28);
        }
    }

    // mes de 30 dias
    if ((dt.mes == 4 || dt.mes == 6 || dt.mes == 9 || dt.mes == 11)) {
        return (dt.dia <= 30);
    }

    // mes de 31 dias
    return (dt.dia <= 31);
}

Data diaAnterior(Data dt) {
    if (dt.dia == 1) {
        if (dt.mes == 1) {
            dt.dia = 31;
            dt.mes = 12;
            dt.ano--;
        } else if (dt.mes == 3 && isBissexto(dt.ano)) {
            dt.dia = 29;
            dt.mes--;
        } else if (dt.mes == 3) {
            dt.dia = 28;
            dt.mes--;
        } else if ((dt.mes == 5 || dt.mes == 7 || dt.mes == 8 || dt.mes == 10 || dt.mes == 12)) {
            dt.dia = 30;
            dt.mes--;
        } else {
            dt.dia = 31;
            dt.mes--;
        }
    } else {
        dt.dia--;
    }

    return dt;
}

int main() {
    Data dt;

    scanf("%d", &dt.dia);
    scanf("%d", &dt.mes);
    scanf("%d", &dt.ano);

    if (isValida(dt)) {
        dt = diaAnterior(dt);
        printf("%d %d %d\n", dt.dia, dt.mes, dt.ano);
    } else {
        printf("Data inválida.\n");
    }
}