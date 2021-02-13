#include <stdio.h>
#include <stdlib.h>

int multiplica_matriz(int **A, int **B, int **C, int col_A, int lin_A, int col_B)
{
    //col_A = lin_B

    int i, j; //i = linhas; j= colunas
    int k;

    for (i = 0; i < lin_A; i++)
    {
        for (j = 0; j < col_B; j++)
        {
            int temp = 0;
            for (k = 0; k < lin_A; k++)
            {
                temp = temp + (A[i][k] * B[k][j]);
            }
            C[i][j] = temp;
        }
    }

    return 0;
}

int main()
{

    int **a, **b, **c, nl_A, nc_A, nl_B, nc_B, i, j;

    //declarando dimenões das matrizes A e B
    nc_A = nl_B = 4;
    nl_A = 3;
    nc_B = 3;

    //alocar memoria
    a = malloc(nl_A * sizeof(int *));
    a[0] = malloc(nc_A * nl_A * sizeof(int));

    b = malloc(nl_B * sizeof(int *));
    b[0] = malloc(nc_B * nl_B * sizeof(int));

    c = malloc(nl_A * sizeof(int *));
    c[0] = malloc(nc_B * nl_A * sizeof(int));

    //fixar linhas
    for (i = 1; i < nl_A; i++)
    {
        a[i] = a[i - 1] + nc_A;
    }
    for (i = 1; i < nl_B; i++)
    {
        b[i] = b[i - 1] + nc_B;
    }
    for (i = 1; i < nl_A; i++)
    {
        c[i] = c[i - 1] + nc_B;
    }

    //printf("ok 4");

    //atribuindo valores as matrizes A e B
    for (i = 0; i < nl_A; i++)
    {
        for (j = 0; j < nc_A; j++)
        {
            a[i][j] = i + j;
        }
    }

    for (i = 0; i < nl_B; i++)
    {
        for (j = 0; j < nc_B; j++)
        {
            b[i][j] = i + j;
        }
    }

    multiplica_matriz(a, b, c, nc_A, nl_A, nc_B);

    //mostrar Matriz C na tela
    for (i = 0; i < nl_A; i++)
    {
        for (j = 0; j < nc_A; j++)
        {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }

    //liberar memoria
    free(a[0]);
    free(a);
    free(b[0]);
    free(b);
    free(c[0]);
    free(c);
    return 0;
}