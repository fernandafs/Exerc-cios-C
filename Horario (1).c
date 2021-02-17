#include <stdio.h>
#include <math.h>

int main(void)
{
    int num;

    scanf("%d",&num);

    int hora;
    int minutos;

    hora = num/3600;
    num = num - hora*3600;
    minutos = num/60;
    num = num - minutos*60;


    printf("%d:%d:%d\n", hora,minutos,num);

}