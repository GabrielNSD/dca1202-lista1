#include "ordena.h"

int ordena(int n, float *vetor, int (*f)(float, float))
{

    int i, k;
    float temp;

    for (i = 0; i < n - 1; i++)
    {
        for (k = 0; k < n - 1; k++)
        {
            if (f(vetor[k], vetor[k + 1]) > 0)
            {
                temp = vetor[k];
                vetor[k] = vetor[k + 1];
                vetor[k + 1] = temp;
            }
        }
    }
    return (0);
}