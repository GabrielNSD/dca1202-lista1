/* Este algoritmo utiliza o método de multiplicação de matrizes implementado na questão 16
   - As Funções 'malloc_tradicional' e 'malloc_lib_gc' alocam mas matrizes na memória e invocam a função de multiplição de matrizes, duas vezes. Usando malloc tradicional e GC_MALLOC, respectivamente
   - a Função main executa essas funções em um número de vezes pre-determinada e imprime a média de tempo de execução de cada uma
 */


#include <sys/resource.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <gc.h>


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

int malloc_tradicional(int nl_A, int nc_A, int nl_B, int nc_B)
{

  int **a, **b, **c, **d, **e, **f;
  int i, j;
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

  printf("malloc: linhas fixadas 1\n");

  //atribuindo valores as matrizes A e B
  for (i = 0; i < nl_A; i++)
  {
    for (j = 0; j < nc_A; j++)
    {
      a[i][j] = (rand() % 100);
    }
  }

  for (i = 0; i < nl_B; i++)
  {
    for (j = 0; j < nc_B; j++)
    {
      b[i][j] = rand() % 100;
    }
  }

  printf("malloc: valores atribuidos 1\n");

  multiplica_matriz(a, b, c, nc_A, nl_A, nc_B);


  //liberar memoria
  free(a[0]);
  free(a);
  free(b[0]);
  free(b);
  free(c[0]);
  free(c);

  printf("malloc: memoria liberada 1\n");

  //alocar memoria
  d = malloc(nl_A * sizeof(int *));
  d[0] = malloc(nc_A * nl_A * sizeof(int));

  e = malloc(nl_B * sizeof(int *));
  e[0] = malloc(nc_B * nl_B * sizeof(int));

  f = malloc(nl_A * sizeof(int *));
  f[0] = malloc(nc_B * nl_A * sizeof(int));

  //fixar linhas
  for (i = 1; i < nl_A; i++)
  {
    d[i] = d[i - 1] + nc_A;
  }
  for (i = 1; i < nl_B; i++)
  {
    e[i] = e[i - 1] + nc_B;
  }
  for (i = 1; i < nl_A; i++)
  {
    f[i] = f[i - 1] + nc_B;
  }

  printf("malloc: linhas fixadas 2\n");

  //atribuindo valores as matrizes A e B
  for (i = 0; i < nl_A; i++)
  {
    for (j = 0; j < nc_A; j++)
    {
      d[i][j] = (rand() % 100);
    }
  }

  for (i = 0; i < nl_B; i++)
  {
    for (j = 0; j < nc_B; j++)
    {
      e[i][j] = (rand() % 100);
    }
  }

  printf("malloc: valores atribuidos 2\n");

  multiplica_matriz(d, e, f, nc_A, nl_A, nc_B);

  //liberar memoria
  free(d[0]);
  free(d);
  free(e[0]);
  free(e);
  free(f[0]);
  free(f);

  printf("malloc: memoria liberada 2\n");
}

int malloc_libgc(int nl_A, int nc_A, int nl_B, int nc_B)
{

  int **a, **b, **c, **d, **e, **f;
  int i, j;
  //alocar memoria
  a = (int **)GC_MALLOC(nl_A * sizeof(int *));
  a[0] = (int *)GC_MALLOC(nc_A * nl_A * sizeof(int *));

  b = (int **)GC_MALLOC(nl_B * sizeof(int *));
  b[0] = (int *)GC_MALLOC(nc_B * nl_B * sizeof(int));

  c = (int **)GC_MALLOC(nl_A * sizeof(int *));
  c[0] = (int *)GC_MALLOC(nc_B * nl_A * sizeof(int));

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

  printf("libgc: linhas fixadas 1\n");

  //atribuindo valores as matrizes A e B
  for (i = 0; i < nl_A; i++)
  {
    for (j = 0; j < nc_A; j++)
    {
      a[i][j] = (rand() % 100);
    }
  }

  for (i = 0; i < nl_B; i++)
  {
    for (j = 0; j < nc_B; j++)
    {
      b[i][j] = (rand() % 100);
    }
  }

  printf("libgc: valores atribuidos 1\n");

  multiplica_matriz(a, b, c, nc_A, nl_A, nc_B);

  d = (int **)GC_MALLOC(nl_A * sizeof(int *));
  d[0] = (int *)GC_MALLOC(nc_A * nl_A * sizeof(int *));

  e = (int **)GC_MALLOC(nl_B * sizeof(int *));
  e[0] = (int *)GC_MALLOC(nc_B * nl_B * sizeof(int));

  f = (int **)GC_MALLOC(nl_A * sizeof(int *));
  f[0] = (int *)GC_MALLOC(nc_B * nl_A * sizeof(int));

  printf("libgc: linhas fixadas 2\n");

  //fixar linhas
  for (i = 1; i < nl_A; i++)
  {
    d[i] = d[i - 1] + nc_A;
  }
  for (i = 1; i < nl_B; i++)
  {
    e[i] = e[i - 1] + nc_B;
  }
  for (i = 1; i < nl_A; i++)
  {
    f[i] = f[i - 1] + nc_B;
  }


  //atribuindo valores as matrizes A e B
  for (i = 0; i < nl_A; i++)
  {
    for (j = 0; j < nc_A; j++)
    {
      d[i][j] = (rand() % 100);
    }
  }

  for (i = 0; i < nl_B; i++)
  {
    for (j = 0; j < nc_B; j++)
    {
      e[i][j] = (rand() % 100);
    }
  }

  printf("libgc: valores atribuidos 2\n");

  multiplica_matriz(d, e, f, nc_A, nl_A, nc_B);

}

double calcula_malloc(int nl_A, int nc_A, int nl_B, int nc_B)
{
  // Medir tempo de execução malloc
  double time_spent_malloc = 0.0;
  clock_t begin_malloc = clock();

  malloc_tradicional(nl_A, nc_A, nl_B, nc_B);

  clock_t end_malloc = clock();
  time_spent_malloc += (double)(end_malloc - begin_malloc) / CLOCKS_PER_SEC;
  //fim da medição
  return time_spent_malloc;
}

double calcula_libgc(int nl_A, int nc_A, int nl_B, int nc_B)
{
  double time_spent_libgc = 0.0;
  clock_t begin_libgc = clock();

  malloc_tradicional(nl_A, nc_A, nl_B, nc_B);

  clock_t end_libgc = clock();
  time_spent_libgc += (double)(end_libgc - begin_libgc) / CLOCKS_PER_SEC;
  return time_spent_libgc;
}

int main()
{

  //rodar cada método por X vezes
  //retornar tempo médio de cada

  //metodo tradicional

  int numero_de_testes = 7;
  double resultados_malloc[numero_de_testes], resultados_libgc[numero_de_testes];

  int nl_A, nc_A, nl_B, nc_B, i, j;

  //declarando dimenões das matrizes A e B
  nc_A = nl_B = 10000;
  nl_A = 400;
  nc_B = 500;


  //Repete a multiplicação de matrizes e registra o tempo gasto para cada execução da função (usando malloc)
  for (i = 0; i < numero_de_testes; i++)
  {
    resultados_malloc[i] = calcula_malloc(nl_A, nc_A, nl_B, nc_B);
  }
  double media_malloc = 0;
  for (i = 0; i < numero_de_testes; i++)
  {
    media_malloc = resultados_malloc[i] + media_malloc;
  }
  media_malloc = media_malloc / numero_de_testes;


  //Repete a multiplicação de matrizes e registra o tempo gasto para cada execução da função (usando libgc)
  for (i = 0; i < numero_de_testes; i++)
  {
    resultados_libgc[i] = calcula_libgc(nl_A, nc_A, nl_B, nc_B);
  }
  double media_libgc = 0;
  for (i = 0; i < numero_de_testes; i++)
  {
    media_libgc = resultados_libgc[i] + media_libgc;
  }
  media_libgc = media_libgc / numero_de_testes;


  printf("\n");
  printf("\n");
  printf("\n");
  printf("\n");
  
  printf("Tempo gasto com malloc: %f segundos", media_malloc);
  printf("\n");
  printf("Tempo gasto com libgc: %f segundos", media_libgc);

  return 0;
}