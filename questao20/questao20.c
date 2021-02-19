#include <sys/resource.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <gc.h>


int malloc_tradicional()
{
  
  int i;

  for(i=0;i<100000; i++) {
    int *p_t = malloc(10000*sizeof(int*));
    free(p_t);
  }

}

int malloc_libgc()
{

  int i;

  for(i=0;i<100000; i++) {
    int *p = GC_MALLOC(10000*sizeof(int*));
  }

}

double calcula_malloc()
{
  // Medir tempo de execução malloc
  double time_spent_malloc = 0.0;
  clock_t begin_malloc = clock();

  malloc_libgc();

  clock_t end_malloc = clock();
  time_spent_malloc += (double)(end_malloc - begin_malloc) / CLOCKS_PER_SEC;
  //fim da medição
  return time_spent_malloc;
}

double calcula_libgc()
{
  double time_spent_libgc = 0.0;
  clock_t begin_libgc = clock();

  malloc_tradicional();

  clock_t end_libgc = clock();
  time_spent_libgc += (double)(end_libgc - begin_libgc) / CLOCKS_PER_SEC;
  return time_spent_libgc;
}

int main()
{

  //rodar cada método por X vezes
  //retornar tempo médio de cada

  int numero_de_testes = 5;
  double resultados_malloc[numero_de_testes], resultados_libgc[numero_de_testes];

  int i;


  //Repete o teste de acordo com o número de testes definido
  for (i = 0; i < numero_de_testes; i++)
  {
    resultados_malloc[i] = calcula_malloc();
  }
  double media_malloc = 0;
  for (i = 0; i < numero_de_testes; i++)
  {
    media_malloc = resultados_malloc[i] + media_malloc;
  }
  media_malloc = media_malloc / numero_de_testes;


  //Repete o teste de acordo com o número de testes definido
  for (i = 0; i < numero_de_testes; i++)
  {
    resultados_libgc[i] = calcula_libgc();
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