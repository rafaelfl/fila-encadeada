
#define TRUE 1
#define FALSE 0

typedef struct _no {
  char val;
  struct _no *prox;
} No;

typedef struct _fila {
  No *ini;
  No *fim;
  int tam;
} Fila;

Fila * criar_fila();

void liberar_fila(Fila *f);

int enfileirar(Fila *f, char valor);

char desenfileirar (Fila *f);

int fila_vazia(Fila *f);

int tamanho_fila(Fila *f);

void imprimir_fila(Fila *f);