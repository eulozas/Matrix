#include <check.h>
#include <stdlib.h>

#include "../s21_helpers.h"
#include "../s21_matrix.h"

START_TEST(mult_incorr1) {
  matrix_t A = {0};
  s21_create_matrix(1, 1, &A);
  matrix_t B = {0};
  ck_assert_int_eq(s21_mult_matrix(&A, &B, NULL), 1);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(mult_incorr2) {
  matrix_t A = {0};
  matrix_t res;
  ck_assert_int_eq(s21_mult_matrix(&A, NULL, &res), 1);
}
END_TEST

START_TEST(mult_incorr3) {
  matrix_t B = {0};
  matrix_t res;
  ck_assert_int_eq(s21_mult_matrix(NULL, &B, &res), 1);
}
END_TEST

START_TEST(mult_incorr4) {
  ck_assert_int_eq(s21_mult_matrix(NULL, NULL, NULL), 1);
}
END_TEST

START_TEST(mult_incorr5) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t res;
  ck_assert_int_eq(s21_mult_matrix(&A, &B, &res), 1);
}
END_TEST

START_TEST(mult_incorr6) {
  matrix_t A;
  matrix_t B;
  matrix_t res;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(4, 3, &B);
  ck_assert_int_eq(s21_mult_matrix(&A, &B, &res), 2);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(mult_incorr7) {
  matrix_t A;
  matrix_t B;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);
  ck_assert_int_eq(s21_mult_matrix(&A, &B, NULL), 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(mult_corr1) {
  matrix_t A;
  matrix_t B;
  matrix_t res;
  matrix_t expected;

  s21_create_matrix(2, 2, &A);
  double arr1[] = {1.0, 2.0, 5.0, 6.0};
  s21_init_matrix(&A, arr1);

  s21_create_matrix(2, 2, &B);
  double arr2[] = {3.0, 4.0, 7.0, 8.0};
  s21_init_matrix(&B, arr2);

  ck_assert_int_eq(s21_mult_matrix(&A, &B, &res), 0);

  s21_create_matrix(2, 2, &expected);
  double arr3[] = {17.0, 20.0, 57.0, 68.0};
  s21_init_matrix(&expected, arr3);

  ck_assert_int_eq(s21_eq_matrix(&res, &expected), SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&res);
  s21_remove_matrix(&expected);
}
END_TEST

START_TEST(mult_corr2) {
  matrix_t A;
  matrix_t B;
  matrix_t res;
  matrix_t expected;

  s21_create_matrix(1, 1, &A);
  double arr1[] = {3.12345};
  s21_init_matrix(&A, arr1);

  s21_create_matrix(1, 1, &B);
  double arr2[] = {2.12345};
  s21_init_matrix(&B, arr2);

  ck_assert_int_eq(s21_mult_matrix(&A, &B, &res), 0);

  s21_create_matrix(1, 1, &expected);
  double arr3[] = {6.6324899025};
  s21_init_matrix(&expected, arr3);

  ck_assert_int_eq(s21_eq_matrix(&res, &expected), SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&res);
  s21_remove_matrix(&expected);
}
END_TEST

Suite *mult_suite() {
  Suite *s = suite_create("s21_mult");
  TCase *tc = tcase_create("Core");

  tcase_add_test(tc, mult_incorr1);
  tcase_add_test(tc, mult_incorr2);
  tcase_add_test(tc, mult_incorr3);
  tcase_add_test(tc, mult_incorr4);
  tcase_add_test(tc, mult_incorr5);
  tcase_add_test(tc, mult_incorr6);
  tcase_add_test(tc, mult_incorr7);
  tcase_add_test(tc, mult_corr1);
  tcase_add_test(tc, mult_corr2);

  suite_add_tcase(s, tc);
  return s;
}