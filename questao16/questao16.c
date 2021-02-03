#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../questao15/ordena.h"

/* Passos:
1 - gerar vetor com numeros aleatórios para q sort
2 - gerar vetor com numeros aleatórios para função da questão 15
3 - marcar tempo qsort
4 - marcar tempo função personalizada
 */

/* Dúvidas:
- Por que a função personalizada não funciona com float menor que 1?
 */

int xf(float a, float b)
{
    return ((int)a - (int)b);
}

int compara(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int main()
{
    int n, i;                          //declaração de variaáveis
    float *vetor_qsort, *vetor_ordena; //declarar ponteiro para alocação de memória

    printf("informe o numero de elementos (n): ");
    scanf("%d", &n);                         //entrada do tamanho do vetor
    vetor_qsort = malloc(n * sizeof(float)); //alocação de memória necessária para armazenar os elementos do vetor
    vetor_ordena = malloc(n * sizeof(float));

    for (i = 0; i < n; i++)
    {
        vetor_qsort[i] = ((float)rand()/10000);
        vetor_ordena[i] = vetor_qsort[i];

    } //entrada dos valores do vetor


    printf("\n");

    // Medir tempo de execução da função implementada por mim
    double time_spent = 0.0;
    clock_t begin = clock();
    ordena(n, vetor_ordena, xf);
    clock_t end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    // fim da medição

    // Medir tempo de execução da função qsort
    double time_spent_qsort = 0.0;
    clock_t begin_qsort = clock();
    qsort(vetor_qsort, n, sizeof(float), compara);
    clock_t end_qsort = clock();
    time_spent_qsort += (double)(end_qsort - begin_qsort) / CLOCKS_PER_SEC;
    //fim da medição

    printf("Tempo gasto na função personalizada: %f segundos \n", time_spent);
    printf("Tempo gasto na função qsort: %f segundos", time_spent_qsort);

    free(vetor_qsort); //liberação de memória
    free(vetor_ordena);
}