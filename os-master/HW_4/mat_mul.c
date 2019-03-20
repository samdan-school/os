#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int mat_r[100][100];

void *find_prime(void *arg) {
}

int main(int argc, char *argv[]) {
    int N_OF_THREAD = 0;

    int mat1[2][3] = {
        {1, 2, 3},
        {4, 5, 6}};

    int mat2[3][2] = {
        {7, 8},
        {9, 10},
        {11, 12}};

    int total1 = sizeof(mat1);
    int column1 = sizeof(mat1[0]);
    int row1 = total1 / column1;

    int total2 = sizeof(mat2);
    int column2 = sizeof(mat2[0]);
    int row2 = total2 / column2;

    if (!(column1 == row2)) {
        printf("matrix buruu baina!");
        exit(EXIT_FAILURE);
    }
    N_OF_THREAD = row1 * column2;

    pthread_t tid[N_OF_THREAD];

    for (size_t i = 0; i < N_OF_THREAD; i++) {
        int num = i;
        pthread_create(&tid[i], NULL, find_prime, (void *)num);
    }

    for (size_t i = 0; i < N_OF_THREAD; i++) {
        pthread_join(tid[i], NULL);
    }

    return 0;
}