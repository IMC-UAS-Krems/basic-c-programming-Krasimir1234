#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


int is_positive_integer(const char *str) {
    if (!str || *str == '\0') return 0; 
    while (*str) {
        if (*str < '0' || *str > '9') {
            return 0;
        }
        str++;
    }
    return 1;
}

int main(int argc, char *argv[]) {
 
    if (argc != 3) {
        printf("Incorrect usage. You provided %d arguments. The correct number of arguments is 2\n", argc - 1);
        return 1;
    }

    if (!is_positive_integer(argv[1]) || !is_positive_integer(argv[2])) {
        printf("Incorrect usage. The parameters you provided are not positive integers\n");
        return 1;
    }

    int rows = atoi(argv[1]);
    int cols = atoi(argv[2]);

    if (rows <= 0 || cols <= 0) {
        printf("Incorrect usage. Dimensions must be positive integers\n");
        return 1;
    }


    int **matrix = malloc(rows * sizeof(int *));
    if (!matrix) {
        perror("Failed to allocate memory for rows");
        return 1;
    }
    for (int i = 0; i < rows; i++) {
        matrix[i] = malloc(cols * sizeof(int));
        if (!matrix[i]) {
            perror("Failed to allocate memory for columns");
            for (int j = 0; j < i; j++) free(matrix[j]);
            free(matrix);
            return 1;
        }
    }


    srand(time(NULL));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = rand() % 100 + 1; 
        }
    }

    FILE *file = fopen("matrix.txt", "w");
    if (!file) {
        perror("Failed to create matrix.txt");
        for (int i = 0; i < rows; i++) free(matrix[i]);
        free(matrix);
        return 1;
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            fprintf(file, "%d", matrix[i][j]);
            if (j < cols - 1) fprintf(file, " "); 
        }
        fprintf(file, "\n"); 
    }
    fclose(file);

    for (int i = 0; i < rows; i++) free(matrix[i]);
    free(matrix);

    printf("Matrix successfully written to matrix.txt\n");
    return 0;
}
