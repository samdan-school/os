#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int mat_res[100][100];
int n_row = 0;

/*
    Compile with
    gcc mat_mul.c -pthread -o mat && ./mat
*/

/*
     58  64
    139 154
*/
int mat1[2][3] = {
    {1, 2, 3},
    {4, 5, 6}};

int mat2[3][2] = {
    {7, 8},
    {9, 10},
    {11, 12}};

/* 
    [83 64 37 75] 
*/
// int mat1[1][3] = {
//     {3, 4, 2}};

// int mat2[3][4] = {
//     {13, 9, 7, 15},
//     {8, 7, 4, 6},
//     {6, 4, 0, 3}};

/*
     4 4
    10 8
*/
// int mat1[2][2] = {
//     {1, 2},
//     {3, 4}};

// int mat2[2][2] = {
//     {2, 0},
//     {1, 2}};

int total1 = sizeof(mat1) / sizeof(int);
int column1 = sizeof(mat1[0]) / sizeof(int);

int total2 = sizeof(mat2) / sizeof(int);
int column2 = sizeof(mat2[0]) / sizeof(int);

void *mat_mul(void *arg) {
    int num = (int)arg;
    int row = 0;
    int column = 0;
    if (n_row == 1) {
        row = num % n_row;
        column = num / n_row;
    } else {
        row = num / n_row;
        column = num % n_row;
    }

    int row1 = total1 / column1;
    int row2 = total2 / column2;

    int sum = 0;
    for (size_t i = 0; i < column1; i++) {
        sum += mat1[row][i] * mat2[i][column];
    }
    mat_res[row][column] = sum;
}

int main(int argc, char *argv[]) {
    int N_OF_THREAD = 0;
    int row1 = total1 / column1;
    int row2 = total2 / column2;

    if (!(column1 == row2)) {
        printf("matrix buruu baina!");
        exit(EXIT_FAILURE);
    }
    N_OF_THREAD = row1 * column2;
    n_row = row1;

    pthread_t tid[N_OF_THREAD];

    for (size_t i = 0; i < N_OF_THREAD; i++) {
        int num = i;
        pthread_create(&tid[i], NULL, mat_mul, (void *)num);
    }

    for (size_t i = 0; i < N_OF_THREAD; i++) {
        pthread_join(tid[i], NULL);
    }

    for (size_t i = 0; i < row1; i++) {
        for (size_t j = 0; j < column2; j++) {
            printf("%d ", mat_res[i][j]);
        }
        printf("\n");
    }

    return 0;
}