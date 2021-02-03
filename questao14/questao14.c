#include <stdio.h>
#include <stdlib.h>

//função de comparaçao para o qsort:
int compara(const void * a, const void * b) //argumentos são ponteiros, do tipo genérico, que apontam para objetos que não podem ser modificados
{
    return (*(int *)a - *(int *)b); // retorna um valor positivo caso a seja maior que b e um valor negativo caso b seja maior que a
}

int main()
{
    int n, i; //declaração de variaáveis
    float *x;    //declarar ponteiro para alocação de memória


    printf("informe o numero de elementos (n): ");
    scanf("%d", &n);               //entrada do tamanho do vetor
    x = malloc(n * sizeof(float)); //alocação de memória necessária para armazenar os elementos do vetor

    for (i = 0; i < n; i++)
    {
        printf("informe o %d° valor: ", i + 1);
        scanf("%f", &x[i]);
    } //entrada dos valores do vetor

    qsort(x, n, sizeof(float), compara);

    printf("Os valores ordenados: \n");

    for (i = 0; i < n; i++)
    {
        printf("%f ", x[i]);
    } //imprime na tela o vetor com os elementos ordenados

    free(x); //liberação de memória
}