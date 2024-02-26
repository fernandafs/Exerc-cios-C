#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct tComplex {
    int real;
    int imag;
};

struct tComplex complexo(int real, int imag) {
    struct tComplex resultado;
    resultado.real = real;
    resultado.imag = imag;
    return resultado;
}

struct tComplex soma(struct tComplex c1, struct tComplex c2) {
    struct tComplex resultado;
    resultado.real = c1.real + c2.real;
    resultado.imag = c1.imag + c2.imag;
    return resultado;
}

struct tComplex subtrai(struct tComplex c1, struct tComplex c2) {
    struct tComplex resultado;
    resultado.real = c1.real - c2.real;
    resultado.imag = c1.imag - c2.imag;
    return resultado;
}


struct tComplex multiplica(struct tComplex c1, struct tComplex c2) {
    struct tComplex resultado;
    resultado.real = c1.real * c2.real - c1.imag * c2.imag;
    resultado.imag = c1.real * c2.imag + c1.imag * c2.real;
    return resultado;
}


struct tComplex divide(struct tComplex c1, struct tComplex c2) {
    struct tComplex resultado;
    int divisor = c2.real * c2.real + c2.imag * c2.imag;
    resultado.real = (c1.real * c2.real + c1.imag * c2.imag) / divisor;
    resultado.imag = (c1.imag * c2.real - c1.real * c2.imag) / divisor;
    return resultado;
}

int main() {
    int A, C;
    char imag1, imag2;
    double B, D;
    char operador;

    while (scanf("%d %lf %c %c %d %lf %c", &A, &B, &imag1, &operador, &C, &D, &imag2) != EOF) {
        
        struct tComplex c1 = complexo(A, B);
        struct tComplex c2 = complexo(C, D);
        struct tComplex resultado;

        switch (operador) {
            case '+':
                resultado = soma(c1, c2);
                break;
            case '-':
                resultado = subtrai(c1, c2);
                break;
            case '*':
                resultado = multiplica(c1, c2);
                break;
            case '/':
                resultado = divide(c1, c2);
                break;
        }

        printf("%d %di\n", resultado.real, resultado.imag);
    }
}