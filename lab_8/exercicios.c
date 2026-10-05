#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>
#include <sys/time.h> // Necessário para gettimeofday (medir tempo de parede)
#include "/home/aluno/CLionProjects/Laboratorios/libprg/libprg.h"

// Função para medir o tempo de relógio de parede em segundos
double get_wall_time() {
    struct timeval time;
    if (gettimeofday(&time, NULL)) {
        return 0;
    }
    return (double)time.tv_sec + (double)time.tv_usec * 0.000001;
}

// Função para medir o tempo de CPU em segundos
double get_cpu_time() {
    return (double)clock() / CLOCKS_PER_SEC;
}

// Copia o vetor original para manter os dados desordenados iguais em todos os testes
void copiar_vetor(int origem[], int destino[], int n) {
    for (int i = 0; i < n; i++) {
        destino[i] = origem[i];
    }
}

int main() {
    int n;

    // Recebe o tamanho do vetor do usuário
    printf("Informe o tamanho n do vetor: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Tamanho invalido.\n");
        return 1;
    }

    // Alocações dinâmicas para o vetor principal e a cópia de testes
    int *vetor_original = (int *)malloc(n * sizeof(int));
    int *vetor_teste = (int *)malloc(n * sizeof(int));

    if (vetor_original == NULL || vetor_teste == NULL) {
        printf("Erro de alocação de memória.\n");
        return 1;
    }

    // Aplica a dica para fixar a semente e gerar sempre os mesmos números
    srand(1);

    for (int i = 0; i < n; i++) {
        // Usa shift em bits para sistemas onde RAND_MAX é pequeno,
        // garantindo cobertura em toda a faixa até INT_MAX.
        long r = ((long)rand() << 15) | rand();
        vetor_original[i] = (int)(r % ((long)INT_MAX + 1));
    }

    double wall0, wall1, cpu0, cpu1;

    // Teste do Bubble Sort
    copiar_vetor(vetor_original, vetor_teste, n);
    wall0 = get_wall_time();
    cpu0 = get_cpu_time();

    bubble_sort(vetor_teste, n);

    wall1 = get_wall_time();
    cpu1 = get_cpu_time();
    printf("Bubble Sort    - Tempo Parede: %f s, Tempo CPU: %f s\n", wall1 - wall0, cpu1 - cpu0);

    // Teste do Insertion Sort
    copiar_vetor(vetor_original, vetor_teste, n);
    wall0 = get_wall_time();
    cpu0 = get_cpu_time();

    insertion_sort(vetor_teste, n);

    wall1 = get_wall_time();
    cpu1 = get_cpu_time();
    printf("Insertion Sort - Tempo Parede: %f s, Tempo CPU: %f s\n", wall1 - wall0, cpu1 - cpu0);

    // Teste do Selection Sort
    copiar_vetor(vetor_original, vetor_teste, n);
    wall0 = get_wall_time();
    cpu0 = get_cpu_time();

    selection_sort(vetor_teste, n);

    wall1 = get_wall_time();
    cpu1 = get_cpu_time();
    printf("Selection Sort - Tempo Parede: %f s, Tempo CPU: %f s\n", wall1 - wall0, cpu1 - cpu0);

    // Libera a memória alocada
    free(vetor_original);
    free(vetor_teste);

    return 0;
}
