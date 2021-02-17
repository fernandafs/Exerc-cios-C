#include <stdio.h>

int main()
{

    int numero;

    scanf("%d", &numero);

    int contador;

    for(contador = 1;contador <= 10000; contador++)
    {
        if(contador%numero == 2)
        {
            printf("%d\n", contador);
        }
    }
}