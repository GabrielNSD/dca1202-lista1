#include <stdio.h>

int main(void)
{
    float vet[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
    float *f;
    int i;
    f = vet;
    printf("contador/valor/valor/endereco/endereco");
    for (i = 0; i <= 4; i++)
    {
        printf("\ni = %d\n", i);
        printf("vet[%d] = %.1f\n", i, vet[i]);
        printf("*(f + %d) = %.1f\n", i, *(f + i));
        printf("&vet[%d] = %X\n", i, &vet[i]);
        printf("(f + %d) = %X\n", i, f + i);
    }
}

/*
Esperado:
i = 0
vet[0] = 1.1
*(f+0) = 1.1
vet[0] = endereço...0
(f+0) = endereço...0

i = 1
vet[1] = 2.2
*(f+1) = 2.2
vet[1] = endereço...0+4
(f+1) = endereço...0+4

i = 2
vet[2] = 3.3
*(f+2) = 3.3
vet[2] = endereço...0+8
(f+2) = endereço...0+8

i = 3
vet[3] = 4.4
*(f+3) = 4.4
vet[3] = endereço...0+12
(f+3) = endereço...0+12

i = 4
vet[4] = 5.5
*(f+4) = 5.5
vet[4] = endereço...0+16
(f+4) = endereço...0+16
*/