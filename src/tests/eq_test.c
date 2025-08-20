#include <check.h>

#include "../s21_matrix.h"
#include "s21_test_helpers.h"

START_TEST(eq_incorr1) {
  matrix_t A = {0};
  ck_assert_int_eq(s21_eq_matrix(&A, NULL), FAILURE);
}
END_TEST

START_TEST(eq_incorr2) {
  matrix_t A = {0};
  ck_assert_int_eq(s21_eq_matrix(NULL, &A), FAILURE);
}
END_TEST

START_TEST(eq_incorr3) { ck_assert_int_eq(s21_eq_matrix(NULL, NULL), FAILURE); }
END_TEST

START_TEST(eq_incorr4) {
  matrix_t A;
  s21_create_matrix(1, 1, &A);
  ck_assert_int_eq(s21_eq_matrix(&A, NULL), FAILURE);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(eq_corr_f1) {
  matrix_t A;
  matrix_t B;
  s21_create_matrix(4, 3, &A);
  s21_create_matrix(3, 3, &B);
  ck_assert_int_eq(s21_eq_matrix(&A, &B), FAILURE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(eq_corr_f2) {
  matrix_t A;
  matrix_t B;
  s21_create_matrix(3, 3, &A);
  const double arr1[] = {2.0, 5.0, 7.0, 6.0, 3.0, 4.0, 5.0, -2.0, -3.0};
  s21_init_matrix(&A, arr1);
  s21_create_matrix(3, 1, &B);
  const double arr2[] = {2.0, 5.0, 7.0, 6.0, 3.0, 4.0, 5.0, -2.0, -4.0};
  s21_init_matrix(&B, arr2);
  ck_assert_int_eq(s21_eq_matrix(&A, &B), FAILURE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(eq_corr_f3) {
  matrix_t A;
  matrix_t B;
  s21_create_matrix(3, 3, &A);
  const double arr1[] = {2.123347, 5.0, 7.0, 6.0, 3.0, 4.0, 5.0, -2.0, -3.0};
  s21_init_matrix(&A, arr1);
  s21_create_matrix(3, 3, &B);
  const double arr2[] = {2.123346, 5.0, 7.0, 6.0, 3.0, 4.0, 5.0, -2.0, -4.0};
  s21_init_matrix(&B, arr2);
  ck_assert_int_eq(s21_eq_matrix(&A, &B), FAILURE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(eq_corr_f4) {
  matrix_t A;
  matrix_t B;
  s21_create_matrix(1, 1, &A);
  const double arr1[] = {2.123340};
  s21_init_matrix(&A, arr1);
  s21_create_matrix(1, 1, &B);
  const double arr2[] = {2.123341};
  s21_init_matrix(&B, arr2);
  ck_assert_int_eq(s21_eq_matrix(&A, &B), FAILURE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(eq_corr_f5) {
  matrix_t A;
  matrix_t B;
  s21_create_matrix(1, 1, &A);
  const double arr1[] = {3.123340};
  s21_init_matrix(&A, arr1);
  s21_create_matrix(1, 1, &B);
  const double arr2[] = {2.123340};
  s21_init_matrix(&B, arr2);
  ck_assert_int_eq(s21_eq_matrix(&A, &B), FAILURE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(eq_corr_f6) {
  matrix_t A;
  matrix_t B;
  s21_create_matrix(1, 1, &A);
  const double arr1[] = {-20.123349};
  s21_init_matrix(&A, arr1);
  s21_create_matrix(1, 1, &B);
  const double arr2[] = {-20.123343};
  s21_init_matrix(&B, arr2);
  ck_assert_int_eq(s21_eq_matrix(&A, &B), FAILURE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(eq_corr_f7) {
  matrix_t A;
  matrix_t B;
  s21_create_matrix(2, 2, &A);
  const double arr1[] = {1.0, 2.0, 3.0, 4.0};
  s21_init_matrix(&A, arr1);
  s21_create_matrix(2, 2, &B);
  const double arr2[] = {1.1, 2.0, 3.0, 4.0};
  s21_init_matrix(&B, arr2);
  ck_assert_int_eq(s21_eq_matrix(&A, &B), FAILURE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(eq_corr1) {
  matrix_t A;
  matrix_t B;
  s21_create_matrix(3, 3, &A);
  const double arr1[] = {2.0, 5.0, 7.12345, 6.0,       3.0,
                         4.0, 5.0, -2.0,    -3.1234561};
  s21_init_matrix(&A, arr1);
  s21_create_matrix(3, 3, &B);
  const double arr2[] = {2.0, 5.0, 7.12345, 6.0,       3.0,
                         4.0, 5.0, -2.0,    -3.1234569};
  s21_init_matrix(&B, arr2);
  ck_assert_int_eq(s21_eq_matrix(&A, &B), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(eq_corr2) {
  matrix_t A;
  matrix_t B;
  s21_create_matrix(2, 3, &A);
  const double arr1[] = {0.012345999, 5.0, 7.12345, 6.0, 3.0, 4.0};
  s21_init_matrix(&A, arr1);
  s21_create_matrix(2, 3, &B);
  const double arr2[] = {0.01234511111, 5.0, 7.12345, 6.0, 3.0, 4.0};
  s21_init_matrix(&B, arr2);
  ck_assert_int_eq(s21_eq_matrix(&A, &B), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(eq_corr3) {
  matrix_t A;
  matrix_t B;
  s21_create_matrix(2, 2, &A);
  const double arr1[] = {0.0, 5.0, 0.0, 6.0, 3.0, 99999999565.0000001};
  s21_init_matrix(&A, arr1);
  s21_create_matrix(2, 2, &B);
  const double arr2[] = {0.0, 5.0, 0.0, 6.0, 3.0, 99999999565.0000009};
  s21_init_matrix(&B, arr2);
  ck_assert_int_eq(s21_eq_matrix(&A, &B), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(eq_corr4) {
  matrix_t A;
  matrix_t B;
  s21_create_matrix(1, 1, &A);
  const double arr1[] = {123.99999999};
  s21_init_matrix(&A, arr1);
  s21_create_matrix(1, 1, &B);
  const double arr2[] = {123.999999111};
  s21_init_matrix(&B, arr2);
  ck_assert_int_eq(s21_eq_matrix(&A, &B), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(eq_corr5) {
  matrix_t A;
  matrix_t B;
  s21_create_matrix(1, 1, &A);
  const double arr1[] = {-123.99999999};
  s21_init_matrix(&A, arr1);
  s21_create_matrix(1, 1, &B);
  const double arr2[] = {-123.999999111};
  s21_init_matrix(&B, arr2);
  ck_assert_int_eq(s21_eq_matrix(&A, &B), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(eq_corr6) {
  matrix_t A;
  matrix_t B;
  s21_create_matrix(1, 1, &A);
  const double arr1[] = {-0.555556999};
  s21_init_matrix(&A, arr1);
  s21_create_matrix(1, 1, &B);
  const double arr2[] = {-0.555556000};
  s21_init_matrix(&B, arr2);
  ck_assert_int_eq(s21_eq_matrix(&A, &B), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(eq_corr7) {
  matrix_t A;
  matrix_t B;
  s21_create_matrix(2, 2, &A);
  const double arr1[] = {1.000003, 2.0, 3.0, 4.0};
  s21_init_matrix(&A, arr1);
  s21_create_matrix(2, 2, &B);
  const double arr2[] = {1.000004, 2.0, 3.0, 4.0};
  s21_init_matrix(&B, arr2);

  ck_assert_int_eq(s21_eq_matrix(&A, &B), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

Suite *eq_suite() {
  Suite *s = suite_create("s21_eq");
  TCase *tc = tcase_create("Core");

  tcase_add_test(tc, eq_incorr1);
  tcase_add_test(tc, eq_incorr2);
  tcase_add_test(tc, eq_incorr3);
  tcase_add_test(tc, eq_incorr4);
  tcase_add_test(tc, eq_corr_f1);
  tcase_add_test(tc, eq_corr_f2);
  tcase_add_test(tc, eq_corr_f3);
  tcase_add_test(tc, eq_corr_f4);
  tcase_add_test(tc, eq_corr_f5);
  tcase_add_test(tc, eq_corr_f6);
  tcase_add_test(tc, eq_corr_f7);
  tcase_add_test(tc, eq_corr1);
  tcase_add_test(tc, eq_corr2);
  tcase_add_test(tc, eq_corr3);
  tcase_add_test(tc, eq_corr4);
  tcase_add_test(tc, eq_corr5);
  tcase_add_test(tc, eq_corr6);
  tcase_add_test(tc, eq_corr7);

  suite_add_tcase(s, tc);
  return s;
}