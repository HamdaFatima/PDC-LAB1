#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

#define N 100000000 // Size of the array

int main() {
    double *array = (double *)malloc(N * sizeof(double));
    double sum = 0.0;
    clock_t start, end;

    // Initialize the array with random values
    srand(time(NULL));
    for (int i = 0; i < N; i++) {
        array[i] = (double)rand() / RAND_MAX;
    }

    // Measure execution time
    start = clock();

    // Parallelize the summation using OpenMP
    #pragma omp parallel
    {
        double local_sum = 0.0; // Local sum for each thread

        #pragma omp for
        for (int i = 0; i < N; i++) {
            local_sum += array[i];
        }

        // Use a critical section to safely update the global sum
        #pragma omp critical
        {
            sum += local_sum;
        }
    }

    end = clock();

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Parallel Sum (using critical): %f\n", sum);
    printf("Parallel Execution Time: %f seconds\n", time_taken);

    free(array);
    return 0;
}
