#include <check.h>
#include <stdlib.h>

#include "../s21_helpers.h"
#include "../s21_matrix.h"

START_TEST(calc_complements_incorr1) {
  matrix_t A;
  matrix_t res;
  s21_create_matrix(2, 2, &A);
  ck_assert_int_eq(s21_calc_complements(NULL, &res), 1);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(calc_complements_incorr2) {
  matrix_t A;
  s21_create_matrix(2, 2, &A);
  ck_assert_int_eq(s21_calc_complements(&A, NULL), 1);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(calc_complements_incorr3) {
  ck_assert_int_eq(s21_calc_complements(NULL, NULL), 1);
}
END_TEST

START_TEST(calc_complements_incorr4) {
  matrix_t A;
  matrix_t res;
  s21_create_matrix(4, 3, &A);
  ck_assert_int_eq(s21_calc_complements(&A, &res), 2);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(calc_complements_incorr5) {
  matrix_t A;
  matrix_t res;
  s21_create_matrix(3, 4, &A);
  ck_assert_int_eq(s21_calc_complements(&A, &res), 2);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(calc_complements_corr1) {
  matrix_t A;
  matrix_t res;
  matrix_t expected;

  s21_create_matrix(3, 3, &A);
  const double arr1[] = {2.0, 5.0, 7.0, 6.0, 3.0, 4.0, 5.0, -2.0, -3.0};
  s21_init_matrix(&A, arr1);

  ck_assert_int_eq(s21_calc_complements(&A, &res), 0);

  s21_create_matrix(3, 3, &expected);
  const double arr2[] = {-1.0, 38.0, -27.0, 1.0,  -41.0,
                         29.0, -1.0, 34.0,  -24.0};
  s21_init_matrix(&expected, arr2);

  ck_assert_int_eq(s21_eq_matrix(&res, &expected), SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&res);
  s21_remove_matrix(&expected);
}
END_TEST

START_TEST(calc_complements_corr2) {
  matrix_t A;
  matrix_t res;
  matrix_t expected;

  s21_create_matrix(3, 3, &A);
  const double arr1[] = {1.0, 2.0, 3.0, 0.0, 4.0, 2.0, 5.0, 2.0, 1.0};
  s21_init_matrix(&A, arr1);

  ck_assert_int_eq(s21_calc_complements(&A, &res), 0);

  s21_create_matrix(3, 3, &expected);
  const double arr2[] = {0.0, 10.0, -20.0, 4.0, -14.0, 8.0, -8.0, -2.0, 4.0};
  s21_init_matrix(&expected, arr2);

  ck_assert_int_eq(s21_eq_matrix(&res, &expected), SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&res);
  s21_remove_matrix(&expected);
}
END_TEST

START_TEST(calc_complements_corr3) {
  matrix_t A;
  matrix_t res;
  matrix_t expected;

  s21_create_matrix(1, 1, &A);
  const double arr1[] = {5.3435};
  s21_init_matrix(&A, arr1);

  ck_assert_int_eq(s21_calc_complements(&A, &res), 0);

  s21_create_matrix(1, 1, &expected);
  const double arr2[] = {1.0};
  s21_init_matrix(&expected, arr2);

  ck_assert_int_eq(s21_eq_matrix(&res, &expected), SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&res);
  s21_remove_matrix(&expected);
}
END_TEST

Suite *calc_complements_suite() {
  Suite *s = suite_create("s21_calc_complements");
  TCase *tc = tcase_create("Core");

  tcase_add_test(tc, calc_complements_incorr1);
  tcase_add_test(tc, calc_complements_incorr2);
  tcase_add_test(tc, calc_complements_incorr3);
  tcase_add_test(tc, calc_complements_incorr4);
  tcase_add_test(tc, calc_complements_incorr5);
  tcase_add_test(tc, calc_complements_corr1);
  tcase_add_test(tc, calc_complements_corr2);
  tcase_add_test(tc, calc_complements_corr3);

  suite_add_tcase(s, tc);
  return s;
}