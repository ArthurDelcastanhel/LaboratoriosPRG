#ifndef LIBPRG_LIBPRG_H
#define LIBPRG_LIBPRG_H

// Laboratorio 7

typedef struct No {
    int valor;
    struct No* proximo;
};

typedef struct {
    No* inicio;
    No tamanho;
} Lista;

Lista* cria_lista();
void inserir(Lista* lista, int valor);
void remover_numero(Lista* lista, int valor);
int obter_primeiro(Lista* lista);
void imprimir_lista(Lista* lista);
void destruir_lista(Lista* lista);

// Laboratorio 8

void bubble_sort(int arr[], int n);
void insertion_sort(int arr[], int n);
void selection_sort(int arr[], int n);

#endif // LIBPRG_LIBRARY_H