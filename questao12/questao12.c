#include <stdio.h>

// declarar função que será referenciada
float divisao(float a, float b)
{
    printf("Resultado = %f: ", a / b);
}

int main(void)
{
    float (*ponteiro_funcao)(float, float) = divisao;
    float c, d;
    printf("informe o primeiro numero: ");
    scanf("%f", &c);
    printf("informe o segundo numero ");
    scanf("%f", &d);
    (*ponteiro_funcao)(c, d);
}