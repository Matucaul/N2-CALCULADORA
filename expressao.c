#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "expressao.h"

typedef struct {
    float data[512];
    int top;
} Pilha;

void inicializaPilha(Pilha *p) {
    p->top = -1;
}

int empilha(Pilha *p, float valor) {
    if (p->top < 511) {
        p->data[++p->top] = valor;
        return 1;
    }
    return 0;
}

float desempilha(Pilha *p) {
    if (p->top >= 0) {
        return p->data[p->top--];
    }
    return 0;
}

void imprimePilha(Pilha *p) {
    printf("Pilha: ");
    for (int i = 0; i <= p->top; i++) {
        printf("%.2f ", p->data[i]);
    }
    printf("\n");
}

float getValor(char *Str) {
    Pilha p;
    inicializaPilha(&p);
    char *token = strtok(Str, " ");
    const double PI = 3.14;
    
    while (token != NULL) {
        if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1]))) {
            empilha(&p, atof(token));
        } else {
            double b = desempilha(&p);
            double a = desempilha(&p);
            double c = b * (PI/180);
            float resultado = 0;
            if (strcmp(token, "+") == 0) resultado = a + b;
            else if (strcmp(token, "-") == 0) resultado = a - b;
            else if (strcmp(token, "*") == 0) resultado = a * b;
            else if (strcmp(token, "/") == 0) resultado = a / b;
            else if (strcmp(token, "^") == 0) resultado = pow(a, b);
            else if (strcmp(token, "raiz") == 0) resultado = sqrt(b);
            else if (strcmp(token, "sen") == 0) resultado = sin(c);
            else if (strcmp(token, "cos") == 0) resultado = cos(c);
            else if (strcmp(token, "tg") == 0) resultado = tan(c);
            else if (strcmp(token, "log") == 0) resultado = log10(b);
            else {
                printf("Operacao nao identificada");
            }

            empilha(&p, resultado);
        }

        imprimePilha(&p);

        token = strtok(NULL, " ");
    }
    return desempilha(&p);
}

char *getFormaInFixa(char *Str) {
    static char resultado[512];

    snprintf(resultado, sizeof(resultado), "%s", Str);
    
    return resultado;
}