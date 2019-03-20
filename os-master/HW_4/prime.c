#include <pthread.h>
#include <stdio.h>

#define N 100
#define MAX_THREADS 100

int prime_arr[N] = {0};

void *printprime(void *ptr) {
    int j, flag;
    int i = (int)(long long int)ptr;
    while (i < N) {
        flag = 0;
        for (j = 2; j <= i / 2; j++) {
            if (i % j == 0) {
                flag = 1;
                break;
            }
        }

        if (flag == 0 && (i > 1)) {
            prime_arr[i] = 1;
        }
        i += MAX_THREADS;
    }
}

int main() {
    pthread_t tid[MAX_THREADS] = {{0}};
    int count = 0;
    for (count = 0; count < MAX_THREADS; count++) {
        pthread_create(&tid[count], NULL, printprime, (void *)count);
    }
    for (count = 0; count < MAX_THREADS; count++) {
        pthread_join(tid[count], NULL);
    }

    int c = 0;
    for (count = 0; count < N; count++)
        if (prime_arr[count] == 1)
            printf("%d ", count);

    return 0;
}