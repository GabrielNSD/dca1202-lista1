#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, k;
    float *x;

    printf("informe o numero de elementos (n): ");
    scanf("%d", &n);
    x = malloc(n * sizeof(float));

    for (i = 0; i < n; i++)
    {
        printf("informe o %d° valor: ", i + 1);
        scanf("%f", &x[i]);
    }

    //Bubble sorting

    float temp;

    for (i = 0; i < n - 1; i++)
    {
        for (k = 0; k < n - 1 - i; k++)
        {
            if (x[k] > x[k + 1])
            {
                temp = x[k];
                x[k] = x[k + 1];
                x[k + 1] = temp;
            }
        }
    }

    printf("Os valores ordenados: \n");

    for (i = 0; i < n; i++)
    {
        printf("%f ", x[i]);
    }

    free(x);
}