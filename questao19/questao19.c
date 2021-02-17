//libGC
// coletor de lixo em C

#include <gc.h>
#include <assert.h>
#include <stdio.h>

int main()
{
  int i;

  GC_INIT();	//chamada inicial para rotina do GC, necessário em apenas algumas plataformas

  int **matriz = (int**) GC_MALLOC(sizeof(int*)); //aloca um vetor bidimensional de inteiros, indicação de tamanho de elemento similar ao malloc
  int *variavel = (int * ) GC_MALLOC_ATOMIC(sizeof(int *)); // este objeto nunca deve conter ponteiros e a memória não é esvaziada após o uso
  void GC_FREE(variavel); //desaloca um objeto da memória, seu uso não é obrigatório
  
  return 0;
}