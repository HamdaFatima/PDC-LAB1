#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100000000 // Size of the array

int main() {
    double *array = (double *)malloc(N * sizeof(double));
    double sum = 0.0;
    clock_t start, end;

    // Initialize the array with random values
    srand(time(NULL)); // Seed the random number generator
    for (int i = 0; i < N; i++) {
        array[i] = (double)rand() / RAND_MAX; // Random value between 0 and 1
    }

    // Measure execution time
    start = clock();
    for (int i = 0; i < N; i++) {
        sum += array[i]; // Accumulate the sum
    }
    end = clock();

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Sequential Sum: %f\n", sum);
    printf("Sequential Execution Time: %f seconds\n", time_taken);

    free(array);
    return 0;
}