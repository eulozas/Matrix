#include "s21_test_helpers.h"

void s21_init_matrix(matrix_t *A, const double *arr) {
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      A->matrix[i][j] = arr[i * A->columns + j];
    }
  }
}