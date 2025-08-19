#include <check.h>

#include "../s21_matrix.h"
#include "s21_test_helpers.h"

START_TEST(sub_incorr1) {
  matrix_t A = {0};
  matrix_t B = {0};
  ck_assert_int_eq(s21_sub_matrix(&A, &B, NULL), 1);
}
END_TEST

START_TEST(sub_incorr2) {
  matrix_t A = {0};
  s21_create_matrix(1, 1, &A);
  matrix_t res;
  ck_assert_int_eq(s21_sub_matrix(&A, NULL, &res), 1);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(sub_incorr3) {
  matrix_t B = {0};
  matrix_t res;
  ck_assert_int_eq(s21_sub_matrix(NULL, &B, &res), 1);
}
END_TEST

START_TEST(sub_incorr4) {
  ck_assert_int_eq(s21_sub_matrix(NULL, NULL, NULL), 1);
}
END_TEST

START_TEST(sub_incorr5) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t res;
  ck_assert_int_eq(s21_sub_matrix(&A, &B, &res), 1);
}
END_TEST

START_TEST(sub_incorr6) {
  matrix_t A;
  matrix_t B;
  matrix_t res;
  s21_create_matrix(4, 3, &A);
  s21_create_matrix(3, 3, &B);
  ck_assert_int_eq(s21_sub_matrix(&A, &B, &res), 2);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(sub_incorr7) {
  matrix_t A;
  matrix_t B;
  matrix_t res;
  s21_create_matrix(4, 4, &A);
  s21_create_matrix(4, 3, &B);
  ck_assert_int_eq(s21_sub_matrix(&A, &B, &res), 2);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(sub_incorr8) {
  matrix_t A;
  matrix_t B;
  s21_create_matrix(4, 4, &A);
  s21_create_matrix(4, 4, &B);
  ck_assert_int_eq(s21_sub_matrix(&A, &B, NULL), 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(sub_corr1) {
  matrix_t A;
  matrix_t B;
  matrix_t res;
  matrix_t expected;

  s21_create_matrix(3, 3, &A);
  const double arr1[] = {2.0, 5.0, 7.0, 6.0, 3.0, 4.0, 5.0, -2.0, -3.0};
  s21_init_matrix(&A, arr1);

  s21_create_matrix(3, 3, &B);
  const double arr2[] = {2.0, 5.0, 7.0, 6.0, 3.0, 4.0, 5.0, -2.0, -4.0};
  s21_init_matrix(&B, arr2);

  ck_assert_int_eq(s21_sub_matrix(&A, &B, &res), 0);

  s21_create_matrix(3, 3, &expected);
  const double arr3[] = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0};
  s21_init_matrix(&expected, arr3);

  ck_assert_int_eq(s21_eq_matrix(&res, &expected), SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&res);
  s21_remove_matrix(&expected);
}
END_TEST

START_TEST(sub_corr2) {
  matrix_t A;
  matrix_t B;
  matrix_t res;
  matrix_t expected;

  s21_create_matrix(1, 1, &A);
  const double arr1[] = {3.12345};
  s21_init_matrix(&A, arr1);

  s21_create_matrix(1, 1, &B);
  const double arr2[] = {2.12345};
  s21_init_matrix(&B, arr2);

  ck_assert_int_eq(s21_sub_matrix(&A, &B, &res), 0);

  s21_create_matrix(1, 1, &expected);
  const double arr3[] = {1.0};
  s21_init_matrix(&expected, arr3);

  ck_assert_int_eq(s21_eq_matrix(&res, &expected), SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&res);
  s21_remove_matrix(&expected);
}
END_TEST

Suite *sub_suite() {
  Suite *s = suite_create("s21_sub");
  TCase *tc = tcase_create("Core");

  tcase_add_test(tc, sub_incorr1);
  tcase_add_test(tc, sub_incorr2);
  tcase_add_test(tc, sub_incorr3);
  tcase_add_test(tc, sub_incorr4);
  tcase_add_test(tc, sub_incorr5);
  tcase_add_test(tc, sub_incorr6);
  tcase_add_test(tc, sub_incorr7);
  tcase_add_test(tc, sub_incorr8);
  tcase_add_test(tc, sub_corr1);
  tcase_add_test(tc, sub_corr2);

  suite_add_tcase(s, tc);
  return s;
}