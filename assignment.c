#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

int is_positive_integer(const char *str) {
    int len = strlen(str);
    int i = 0;
    while (i < len) {
        if (!isdigit(str[i])) return 0;
        i++;
    }
    return atoi(str) > 0;
}

void allocate_matrix(int ***matrix, int rows, int cols) {
    *matrix = (int **)calloc(rows, sizeof(int *));
    int i = 0;
    while (i < rows) {
        (*matrix)[i] = (int *)calloc(cols, sizeof(int));
        i++;
    }
}

void initialize_matrix(int **matrix, int rows, int cols) {
    srand(time(NULL));
    int i = 0;
    while (i < rows) {
        int j = 0;
        while (j < cols) {
            matrix[i][j] = rand() % 100 + 1;
            j++;
        }
        i++;
    }
}

void write_matrix_to_file(const char *filename, int **matrix, int rows, int cols) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        perror("Failed to create file");
        exit(EXIT_FAILURE);
    }
    int i = 0;
    while (i < rows) {
        int j = 0;
        while (j < cols) {
            fprintf(file, "%d", matrix[i][j]);
            if (j < cols - 1) fprintf(file, " ");
            j++;
        }
        fprintf(file, "\n");
        i++;
    }
    fclose(file);
}

void free_matrix(int **matrix, int rows) {
    int i = 0;
    do {
        free(matrix[i]);
        i++;
    } while (i < rows);
    free(matrix);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Incorrect usage. You provided %d arguments. The correct number of arguments is 2\n", argc - 1);
        return EXIT_FAILURE;
    }

    if (!is_positive_integer(argv[1]) || !is_positive_integer(argv[2])) {
        printf("Incorrect usage. The parameters you provided are not positive integers\n");
        return EXIT_FAILURE;
    }

    int rows = atoi(argv[1]);
    int cols = atoi(argv[2]);

    int **matrix;
    allocate_matrix(&matrix, rows, cols);
    initialize_matrix(matrix, rows, cols);
    write_matrix_to_file("matrix.txt", matrix, rows, cols);
    free_matrix(matrix, rows);

    printf("Matrix generated and saved to matrix.txt\n");
    return EXIT_SUCCESS;
}
