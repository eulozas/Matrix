#include <check.h>
#include <stdlib.h>

#include "../s21_helpers.h"
#include "../s21_matrix.h"

START_TEST(remove_incorr1) { s21_remove_matrix(NULL); }
END_TEST

START_TEST(remove_incorr2) {
  matrix_t A = {0};
  A.rows = 4;
  s21_remove_matrix(&A);
  ck_assert_ptr_null(A.matrix);
  ck_assert_int_eq(A.rows, 0);
  ck_assert_int_eq(A.columns, 0);
}
END_TEST

START_TEST(remove_corr1) {
  matrix_t A = {0};
  s21_create_matrix(4, 3, &A);
  const double arr1[] = {2.0, 5.0,  7.0,  6.0, 3.0, 4.0,
                         5.0, -2.0, -3.0, 1.0, 1.0, 1.0};
  s21_init_matrix(&A, arr1);

  s21_remove_matrix(&A);
  ck_assert_ptr_null(A.matrix);
  ck_assert_int_eq(A.rows, 0);
  ck_assert_int_eq(A.columns, 0);
}
END_TEST

START_TEST(remove_corr2) {
  matrix_t A = {0};
  s21_create_matrix(3, 3, &A);
  A.matrix[0][1] = 456.7;

  s21_remove_matrix(&A);
  ck_assert_ptr_null(A.matrix);
  ck_assert_int_eq(A.rows, 0);
  ck_assert_int_eq(A.columns, 0);
}
END_TEST

START_TEST(remove_corr3) {
  matrix_t A = {0};
  s21_create_matrix(4, 3, &A);
  const double arr1[] = {2.0, 5.0,  7.0,  6.0, 3.0, 4.0,
                         5.0, -2.0, -3.0, 1.0, 1.0, 1.0};
  s21_init_matrix(&A, arr1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&A);
  ck_assert_ptr_null(A.matrix);
  ck_assert_int_eq(A.rows, 0);
  ck_assert_int_eq(A.columns, 0);
}
END_TEST

Suite *remove_suite() {
  Suite *s = suite_create("s21_remove");
  TCase *tc = tcase_create("Core");

  tcase_add_test(tc, remove_incorr1);
  tcase_add_test(tc, remove_incorr2);
  tcase_add_test(tc, remove_corr1);
  tcase_add_test(tc, remove_corr2);
  tcase_add_test(tc, remove_corr3);

  suite_add_tcase(s, tc);
  return s;
}