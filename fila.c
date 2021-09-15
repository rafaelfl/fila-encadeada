#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

Fila * criar_fila() {
  Fila *f = malloc(sizeof(Fila));

  f->ini = f->fim = NULL;
  f->tam = 0;

  return f;
}

void liberar_fila(Fila *f) {
  while (f->ini != NULL) {
    No *primeiro = f->ini;
    No *segundo = primeiro->prox;

    free(primeiro);
    f->ini = segundo;
  }

  free(f);
}

int enfileirar(Fila *f, char valor) {
  No *temp = malloc(sizeof(No));

  if (temp == NULL) {
    return -1;
  }

  // criado o novo nó
  temp->val = valor;
  temp->prox = NULL;

  if (fila_vazia(f)) {
    f->ini = f->fim = temp;
  } else {
    No *ultimo = f->fim;

    // temp é o novo "último da fila"
    ultimo->prox = temp;

    // o novo "último elemento" da fila é temp
    f->fim = temp;
  }

  f->tam++;

  return 0;
}

char desenfileirar (Fila *f) {
  char c;

  if (fila_vazia(f)) {
    return '\0';
  }

  No *primeiro = f->ini;
  No *segundo = primeiro->prox;

  c = primeiro->val;
  free(primeiro);

  f->ini = segundo;

  // se eu tirei o único elemento que tinha...
  if (f->ini == NULL) {
    f->fim = NULL;
  }

  f->tam--;

  return c;
}

int fila_vazia(Fila *f) {
  if (f->ini == NULL) {
    return TRUE;
  } else {
    return FALSE;
  }
}

int tamanho_fila(Fila *f) {
  return f->tam;
}

void imprimir_fila(Fila *f) {
  printf("ini [ ");

  No *atual = f->ini;

  while (atual != NULL) {
    printf(" %c ", atual->val);

    atual = atual->prox;
  }

  printf(" ] fim\n");
}