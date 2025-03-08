#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

#define N 100000000 // Size of the array
#define NUM_THREADS 8

int main() {
    double *array = (double *)malloc(N * sizeof(double));
    double sum = 0.0;
    clock_t start, end;

    // Initialize the array with random values
    srand(time(NULL)); // Seed the random number generator
    for (int i = 0; i < N; i++) {
        array[i] = (double)rand() / RAND_MAX; // Random value between 0 and 1
    }

    // Parallel Execution with OpenMP
    sum = 0.0; // Reset sum
    start = clock();

    # pragma omp parallel for reduction(+:sum) schedule(dynamic)
    for (int i = 0; i < N; i++) {
        sum += array[i]; 
    }
    end = clock();

    double par_time = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Parallel Sum: %f\n", sum);
    printf("Parallel Execution Time: %f seconds\n", par_time);

    free(array);
    return 0;
}