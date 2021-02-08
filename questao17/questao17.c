#include <stdio.h>
#include <stdlib.h>

int soma(float *vetor_a, float *vetor_b, int n_a, int n_b)
{
    int n_resultado, menor, maior, i;
    float *vetor_resultado;

    if (n_a > n_b)
    {
        n_resultado = n_a;
        menor = n_b;
        maior = n_a;
    }
    else if (n_b > n_a)
    {
        n_resultado = n_b;
        menor = n_a;
        maior = n_b;
    }
    else
    {
        n_resultado = n_a;
        menor = maior = n_a;
    }

    //printf("resultado: %d", n_resultado);

    //criar um vetor resultado do tamanho do vetor maior

    vetor_resultado = malloc(n_resultado * sizeof(int));

    //criar um laço de repetição para somar os vetores, esse laço deve ser executado um numero de vezes igual ao tamanho do vetor menor

    for (i = 0; i < menor; i++)
    {
        vetor_resultado[i] = vetor_a[i] + vetor_b[i];
    }
    if (menor != maior)
    {
        //adicionar os elementos restantes do vetor maior no vetor resultado
        for (i = menor; i < maior; i++)
        {
            if (maior == n_a)
            {
                vetor_resultado[i] = vetor_a[i];
            }
            else
            {
                vetor_resultado[i] = vetor_b[i];
            }
        }
    }
    printf("Vetor A: \n");
    for(i=0; i<n_a; i++){
        printf("%.2f ", vetor_a[i]);
    }
    printf("\n");
    printf("Vetor B: \n");
    for(i=0; i<n_b; i++){
        printf("%.2f ", vetor_b[i]);
    }
    printf("\n");

    printf("Vetor resultado: \n");
    for (i = 0; i < maior; i++)
    {
        printf("%.2f ", vetor_resultado[i]);
    }

    free(vetor_resultado);

    return 0;
}

int main()
{
    int n_a, n_b, n_resultado, menor, maior, i, escolha;
    float *vetor_a, *vetor_b, *vetor_resultado;

    printf("informe o numero de elementos (n_a): ");
    scanf("%d", &n_a);
    printf("\n");
    printf("informe o numero de elementos (n_b): ");
    scanf("%d", &n_b);
    printf("\n");
ESCOLHATAG:
    printf("Se quiser informar os valores manualmente, digite 1.\nSe quiser que o programa gere valores aleatórios, digite 2\n");
    scanf("%d", &escolha);

    vetor_a = malloc(n_a * sizeof(int));
    vetor_b = malloc(n_b * sizeof(int));

    if (escolha == 1)
    {
        printf("informe os valores do vetor A: \n");
        for (i = 0; i < n_a; i++)
        {
            printf("%d° valor: ", i + 1);
            scanf("%f", &vetor_a[i]);
        }
        printf("\n");
        printf("informe os valores do vetor B: \n");
        for (i = 0; i < n_b; i++)
        {
            printf("%d° valor: ", i + 1);
            scanf("%f", &vetor_b[i]);
        }
        printf("\n");
    }
    else if (escolha == 2)
    {
        for (i = 0; i < n_a; i++)
        {
            vetor_a[i] = ((float)rand() / 1000000);
        }
        for (i = 0; i < n_b; i++)
        {
            vetor_b[i] = ((float)rand() / 1000000);
        }
    } else {
        printf("valor inválido \n");
        goto ESCOLHATAG;
    }

    soma(vetor_a, vetor_b, n_a, n_b);

    free(vetor_a);
    free(vetor_b);
}