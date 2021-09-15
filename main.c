#include <stdio.h>
#include "fila.h"

int main(void) {
  Fila *f = criar_fila();
  char c;

  enfileirar(f, 'T');
  enfileirar(f, 'D');
  enfileirar(f, 'Y');
  enfileirar(f, 'R');
  enfileirar(f, 'Q');

  imprimir_fila(f);

  c = desenfileirar(f);
  printf("desenfileirei o elemento %c\n", c);
  c = desenfileirar(f);
  printf("desenfileirei o elemento %c\n", c);
  c = desenfileirar(f);
  printf("desenfileirei o elemento %c\n", c);

  imprimir_fila(f);

  liberar_fila(f);

  return 0;
}