#include "s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result){
    if(!result || rows <= 0 || columns <= 0){
        return 1;
    }

    int exit_code = 0;
    result->rows = rows;
    result->columns = columns;

    result->matrix = malloc(result->rows * sizeof(double*));
    if(!result->matrix){
        exit_code = 1;
    }
    for(int i = 0; i < result->rows && !exit_code; i++){
        result->matrix[i] = malloc(result->columns * sizeof(double));
        if(!result->matrix[i]){
            exit_code = 1;
            for (int j = 0; j < i; j++) {
                free(result->matrix[j]);
            }
            free(result->matrix);
            result->matrix = NULL;
        }
    }

    return exit_code;
}