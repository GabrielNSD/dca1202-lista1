#include <stdio.h>
#include <stdlib.h>


int main()
{
    printf("tamanho char: %lu byte\n", sizeof(char));
    printf("tamanho int: %lu bytes\n", sizeof(int));
    printf("tamanho float: %lu bytes\n", sizeof(float));
    printf("tamanho double: %lu bytes\n", sizeof(double));

    char a[4];
    printf("Para x do tipo char: \n");
    int i;
    for (i = 0; i < 4; i++)
    {
        printf("x + %d : %p \n", i, a + i);
    }
    printf("\n");

    int b[4];
    printf("Para x do tipo int: \n");
    int j;
    for (j = 0; j < 4; j++)
    {
        printf("x + %d : %p \n", j, b + j);
    }
    printf("\n");

    float c[4];
    printf("Para x do tipo float: \n");
    int k;
    for (k = 0; k < 4; k++)
    {
        printf("x + %d : %p \n", k, c + k);
    }
    printf("\n");

    double d[4];
    printf("Para x do tipo double: \n");
    int l;
    for (l = 0; l < 4; l++)
    {
        printf("x + %d : %p \n", l, d + l);
    }
    printf("\n");
}


/*
Resultado de uma execução:

tamanho char: 1 byte
tamanho int: 4 bytes
tamanho float: 4 bytes
tamanho double: 8 bytes
Para x do tipo char: 
x + 0 : 0x7ffe15603614 
x + 1 : 0x7ffe15603615 
x + 2 : 0x7ffe15603616 
x + 3 : 0x7ffe15603617 

Para x do tipo int: 
x + 0 : 0x7ffe156035d0 
x + 1 : 0x7ffe156035d4 
x + 2 : 0x7ffe156035d8 
x + 3 : 0x7ffe156035dc 

Para x do tipo float: 
x + 0 : 0x7ffe156035e0 
x + 1 : 0x7ffe156035e4 
x + 2 : 0x7ffe156035e8 
x + 3 : 0x7ffe156035ec 

Para x do tipo double: 
x + 0 : 0x7ffe156035f0 
x + 1 : 0x7ffe156035f8 
x + 2 : 0x7ffe15603600 
x + 3 : 0x7ffe15603608 

*/