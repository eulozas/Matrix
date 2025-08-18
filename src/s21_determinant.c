#include "s21_helpers.h"
#include "s21_matrix.h"

int s21_determinant(matrix_t *A, double *result) {
  if (!is_valid_matrix(A) || !result) {
    return 1;
  }

  int exit_code = 0;
  if (A->rows != A->columns) {
    exit_code = 2;
  }

  if (!exit_code) {
    if (A->rows == 1 && A->columns == 1) {
      *result = A->matrix[0][0];
    } else if (zero_row_col_check(A)) {
      *result = 0.0;
    } else {
      matrix_t B;
      s21_create_matrix(A->rows, A->columns, &B);
      s21_copy_matrix(A, &B);
      transform_to_echelon_form(&B);
      *result = B.matrix[0][0];
      for (int i = 1; i < B.rows; i++) {
        *result *= B.matrix[i][i];
      }
      s21_remove_matrix(&B);
    }
  }
  return exit_code;
}