#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define N_OF_THREAD 100

void *find_prime(void *arg) {
    int number = (int)arg;
    // printf("%d: ", number);

    int c = 2;

    for (c = 2; c <= number - 1; c++) {
        if (number % c == 0)
            break;
    }
    if (c == number)
        printf("%d ", number);
}

int main(int argc, char *argv[]) {
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