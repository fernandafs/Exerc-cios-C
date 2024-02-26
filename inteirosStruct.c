#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 101

typedef struct {
    char num[MAX_SIZE];
} tInteiro;

void strrev(char *str) {
    int length = strlen(str);
    int i;
    for (i = 0; i < length / 2; i++) {
        char temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }
}

tInteiro inteiro(char *str) {
    tInteiro resultado;
    strcpy(resultado.num, str);
    return resultado;
}

tInteiro soma(tInteiro a, tInteiro b) {
    tInteiro resultado;
    int carry = 0;
    int i, j, k;
    for (i = strlen(a.num) - 1, j = strlen(b.num) - 1, k = 0; i >= 0 || j >= 0 || carry; i--, j--, k++) {
        int num_a = (i >= 0) ? (a.num[i] - '0') : 0;
        int num_b = (j >= 0) ? (b.num[j] - '0') : 0;
        int sum = num_a + num_b + carry;
        resultado.num[k] = (sum % 10) + '0';
        carry = sum / 10;
    }
    resultado.num[k] = '\0';
    strrev(resultado.num);
    return resultado;
}

tInteiro subtrai(tInteiro a, tInteiro b) {
    tInteiro resultado;
    int borrow = 0;
    int i, j, k;
    for (i = strlen(a.num) - 1, j = strlen(b.num) - 1, k = 0; i >= 0 || j >= 0; i--, j--, k++) {
        int num_a = (i >= 0) ? (a.num[i] - '0') : 0;
        int num_b = (j >= 0) ? (b.num[j] - '0') : 0;
        int sub = num_a - num_b - borrow;
        if (sub < 0) {
            sub += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }
        resultado.num[k] = sub + '0';
    }
    resultado.num[k] = '\0';
    strrev(resultado.num);
    return resultado;
}

tInteiro multiplica(tInteiro a, tInteiro b) {
    tInteiro resultado = inteiro("0");
    tInteiro temp;
    int i, j, k, l;
    for (i = strlen(b.num) - 1, k = 0; i >= 0; i--, k++) {
        int carry = 0;
        temp.num[0] = '0';
        for (l = 0; l < k; l++) {
            temp.num[l+1] = '0';
        }
        for (j = strlen(a.num) - 1; j >= 0; j--) {
            int num_a = a.num[j] - '0';
            int num_b = b.num[i] - '0';
            int product = num_a * num_b + carry;
            temp.num[l++] = (product % 10) + '0';
            carry = product / 10;
        }
        if (carry > 0) {
            temp.num[l++] = carry + '0';
        }
        temp.num[l] = '\0';
        strrev(temp.num);
        resultado = soma(resultado, temp);
    }
    return resultado;
}

int main() {
    char op;
    tInteiro num1, num2, resultado;
    while (scanf("%s %c %s", num1.num, &op, num2.num) != EOF) {
        switch (op) {
            case '+':
                resultado = soma(num1, num2);
                break;
            case '-':
                resultado = subtrai(num1, num2);
                break;
            case '*':
                resultado = multiplica(num1, num2);
                break;
        }
        printf("%s\n", resultado.num);
    }
}