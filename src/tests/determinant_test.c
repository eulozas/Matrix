#include <check.h>

#include "../s21_matrix.h"
#include "s21_test_helpers.h"

START_TEST(determinant_incorr1) {
  double res;
  ck_assert_int_eq(s21_determinant(NULL, &res), 1);
}
END_TEST

START_TEST(determinant_incorr2) {
  matrix_t A;
  s21_create_matrix(1, 1, &A);
  ck_assert_int_eq(s21_determinant(&A, NULL), 1);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_incorr3) {
  ck_assert_int_eq(s21_determinant(NULL, NULL), 1);
}
END_TEST

START_TEST(determinant_incorr4) {
  matrix_t A;
  double res;
  s21_create_matrix(4, 3, &A);
  ck_assert_int_eq(s21_determinant(&A, &res), 2);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_incorr5) {
  matrix_t A;
  double res;
  s21_create_matrix(3, 4, &A);
  ck_assert_int_eq(s21_determinant(&A, &res), 2);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_corr1) {
  matrix_t A;
  double res;
  double expected = -1.0;

  s21_create_matrix(3, 3, &A);
  const double arr1[] = {2.0, 5.0, 7.0, 6.0, 3.0, 4.0, 5.0, -2.0, -3.0};
  s21_init_matrix(&A, arr1);

  ck_assert_int_eq(s21_determinant(&A, &res), 0);
  ck_assert_double_eq_tol(res, expected, EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_corr2) {
  matrix_t A;
  double res;
  double expected = -42.0;

  s21_create_matrix(4, 4, &A);
  const double arr1[] = {1.0, 2.0, 3.0, 4.0, 4.0, 5.0, 6.0, 6.0,
                         7.0, 8.0, 9.0, 9.0, 1.0, 8.0, 1.0, 1.0};
  s21_init_matrix(&A, arr1);

  ck_assert_int_eq(s21_determinant(&A, &res), 0);
  ck_assert_double_eq_tol(res, expected, EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_corr3) {
  matrix_t A;
  double res;
  double expected = 91.0;

  s21_create_matrix(5, 5, &A);
  const double arr1[] = {0.0, 1.0, 7.0,  5.0, 0.0, 5.0, 4.0, 7.0, 5.0,
                         0.0, 5.0, 12.0, 2.0, 1.0, 0.0, 1.0, 1.0, 1.0,
                         1.0, 0.0, 7.0,  2.0, 2.0, 4.0, 1.0};
  s21_init_matrix(&A, arr1);

  ck_assert_int_eq(s21_determinant(&A, &res), 0);
  ck_assert_double_eq_tol(res, expected, EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_corr4) {
  matrix_t A;
  double res;
  double expected = -19.352;

  s21_create_matrix(3, 3, &A);
  const double arr1[] = {0.56, 1.0, 1.0, 2.2, 7.8, 1.0, 5.56, 2.0, 7.0};
  s21_init_matrix(&A, arr1);

  ck_assert_int_eq(s21_determinant(&A, &res), 0);
  ck_assert_double_eq_tol(res, expected, EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_corr5) {
  matrix_t A;
  double res;
  double expected = 0.0;

  s21_create_matrix(3, 3, &A);
  const double arr1[] = {0.0, 0.0, 0.0, 2.2, 7.8, 1.0, 5.56, 2.0, 7.0};
  s21_init_matrix(&A, arr1);

  ck_assert_int_eq(s21_determinant(&A, &res), 0);
  ck_assert_double_eq_tol(res, expected, EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_corr6) {
  matrix_t A;
  double res;
  double expected = -8.352;

  s21_create_matrix(3, 3, &A);
  const double arr1[] = {0.56, 1.0, 1.0, 0.0, 7.8, 1.0, 5.56, 2.0, 7.0};
  s21_init_matrix(&A, arr1);

  ck_assert_int_eq(s21_determinant(&A, &res), 0);
  ck_assert_double_eq_tol(res, expected, EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_corr7) {
  matrix_t A;
  double res;
  double expected = -8.56;

  s21_create_matrix(1, 1, &A);
  const double arr1[] = {-8.56};
  s21_init_matrix(&A, arr1);

  ck_assert_int_eq(s21_determinant(&A, &res), 0);
  ck_assert_double_eq_tol(res, expected, EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_corr8) {
  matrix_t A;
  double res;
  double expected = 0.0;

  s21_create_matrix(2, 2, &A);
  const double arr1[] = {0.0, 1.0, 0.0, 1.0};
  s21_init_matrix(&A, arr1);

  ck_assert_int_eq(s21_determinant(&A, &res), 0);
  ck_assert_double_eq_tol(res, expected, EPS);
  s21_remove_matrix(&A);
}
END_TEST

Suite *determinant_suite() {
  Suite *s = suite_create("s21_determinant");
  TCase *tc = tcase_create("Core");

  tcase_add_test(tc, determinant_incorr1);
  tcase_add_test(tc, determinant_incorr2);
  tcase_add_test(tc, determinant_incorr3);
  tcase_add_test(tc, determinant_incorr4);
  tcase_add_test(tc, determinant_incorr5);
  tcase_add_test(tc, determinant_corr1);
  tcase_add_test(tc, determinant_corr2);
  tcase_add_test(tc, determinant_corr3);
  tcase_add_test(tc, determinant_corr4);
  tcase_add_test(tc, determinant_corr5);
  tcase_add_test(tc, determinant_corr6);
  tcase_add_test(tc, determinant_corr7);
  tcase_add_test(tc, determinant_corr8);

  suite_add_tcase(s, tc);
  return s;
}