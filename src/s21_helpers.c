#include "s21_helpers.h"

int is_valid_matrix(const matrix_t *A) {
  return (A != NULL && A->matrix != NULL && A->rows > 0 && A->columns > 0);
}

void s21_copy_matrix(matrix_t *A, matrix_t *B) {
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      B->matrix[i][j] = A->matrix[i][j];
    }
  }
}

void s21_init_matrix(matrix_t *A, const double *arr) {
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      A->matrix[i][j] = arr[i * A->columns + j];
    }
  }
}

void s21_mult_number_str_matrix(matrix_t *A, int strA, double number,
                                matrix_t *B, int strB) {
  for (int i = 0; i < A->columns; i++) {
    B->matrix[strB][i] = A->matrix[strA][i] * number;
  }
}

void s21_sub_matrix_str(matrix_t *A, int strA, matrix_t *B, int strB,
                        matrix_t *result, int strRes) {
  for (int i = 0; i < A->columns; i++) {
    result->matrix[strRes][i] = A->matrix[strA][i] - B->matrix[strB][i];
  }
}

int zero_row_col_check(const matrix_t *A) {
  int exit_code = 0;

  for (int i = 0; i < A->rows && !exit_code; i++) {
    int count_zero_in_row = 0;
    for (int j = 0; j < A->columns; j++) {
      if (fabs(A->matrix[i][j]) <= EPS) {
        count_zero_in_row++;
      }
    }
    if (count_zero_in_row == A->columns) {
      exit_code = 1;
    }
  }

  for (int i = 0; i < A->columns && !exit_code; i++) {
    int count_zero_in_column = 0;
    for (int j = 0; j < A->rows; j++) {
      if (fabs(A->matrix[j][i]) <= EPS) {
        count_zero_in_column++;
      }
    }
    if (count_zero_in_column == A->rows) {
      exit_code = 1;
    }
  }

  return exit_code;
}

void s21_change_rows(int rows1, int rows2, matrix_t *A) {
  for (int j = 0; j < A->columns; j++) {
    double tmp = A->matrix[rows1][j];
    A->matrix[rows1][j] = A->matrix[rows2][j];
    A->matrix[rows2][j] = tmp;
  }
}

void s21_mul_neg1(int rows, matrix_t *A) {
  for (int j = 0; j < A->columns; j++) {
    A->matrix[rows][j] *= -1;
  }
}

void make_zero_element(int i, int j, matrix_t *A, matrix_t *vector_str) {
  if (A->matrix[j][j] == 0) {
    s21_change_rows(i, j, A);
    s21_mul_neg1(i, A);
  } else {
    double mul = A->matrix[i][j] / A->matrix[j][j];
    s21_mult_number_str_matrix(A, j, mul, vector_str, 0);
    s21_sub_matrix_str(A, i, vector_str, 0, A, i);
  }
}

void transform_to_echelon_form(matrix_t *A) {
  matrix_t vector_str;
  for (int i = 1; i < A->columns; i++) {
    for (int j = 0; j != i; j++) {
      s21_create_matrix(1, A->columns, &vector_str);
      if (A->matrix[i][j] != 0) {
        make_zero_element(i, j, A, &vector_str);
      }
      s21_remove_matrix(&vector_str);
    }
  }
}

void s21_init_minor_matrix(int m, int n, matrix_t *A, matrix_t *minor_matrix) {
  int row = 0;
  for (int i = 0; i < A->rows; i++) {
    int col = 0;
    for (int j = 0; j < A->columns && i != m; j++) {
      if (j != n) {
        minor_matrix->matrix[row][col] = A->matrix[i][j];
        col++;
      }
    }
    if (i != m) row++;
  }
}

void s21_mul_compl(matrix_t *A) {
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      A->matrix[i][j] *= pow(-1, i + j);
    }
  }
}

void s21_minor_matrix(matrix_t *A, matrix_t *minor, matrix_t *result) {
  double determinant;
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      s21_init_minor_matrix(i, j, A, minor);
      s21_determinant(minor, &determinant);
      result->matrix[i][j] = determinant;
    }
  }
}

void s21_mul_det(matrix_t *A, double det, matrix_t *res) {
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      res->matrix[i][j] = A->matrix[i][j] * (1.0 / det);
    }
  }
}