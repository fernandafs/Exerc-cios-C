#include <stdio.h>

int main(void)
{
    int num;
    int horas;
    float salario;

    scanf("%d",&num);
    scanf("%d",&horas);
    scanf("%f",&salario);


    float total = horas*salario;

    printf("NUMBER = %d\n",num);
    printf("SALARY = U$ %1.2f\n", total);
}