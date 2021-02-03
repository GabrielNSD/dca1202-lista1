#include <stdio.h>
#include <stdlib.h>
#include "ordena.h"


int xf(float a, float b)
{
    return (a - b);
}

/* int ordena(int n, float *vetor, int (*f)(float, float))
{

    int i, k, j;
    float temp;

    for (i = 0; i < n - 1; i++)
    {
        for (k = 0; k < n - 1; k++)
        {
            //printf("i: %d, k: %d \n", i,k);
            //printf("compara: %f e %f \n", vetor[k], vetor[k + 1]);
            if (f(vetor[k], vetor[k + 1]) > 0)
            {
                //printf("true \n");
                temp = vetor[k];
                vetor[k] = vetor[k + 1];
                vetor[k + 1] = temp;
            }
        }
    }
} */

int main()
{
    int n, i; //declaração de variaáveis
    float *x; //declarar ponteiro para alocação de memória

    printf("informe o numero de elementos (n): ");
    scanf("%d", &n);               //entrada do tamanho do vetor
    x = malloc(n * sizeof(float)); //alocação de memória necessária para armazenar os elementos do vetor

    for (i = 0; i < n; i++)
    {
        printf("informe o %d° valor: ", i + 1);
        scanf("%f", &x[i]);
    } //entrada dos valores do vetor


    ordena(n, x, xf);

    printf("Resultado: \n");

    for (i = 0; i < n; i++)
    {
        printf("%f ", x[i]);
    }

    free(x); //liberação de memória
}