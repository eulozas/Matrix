#include <stdlib.h>
#include <check.h>

#include "../s21_matrix.h"
#include "../s21_helpers.h"

START_TEST(mult_num_incorr1) {
    matrix_t A = {0};
    double n = 1.0;
    ck_assert_int_eq(s21_mult_number(&A, n, NULL), 1);
}
END_TEST

START_TEST(mult_num_incorr2) {
    matrix_t res;
    double n = 1.0;
    ck_assert_int_eq(s21_mult_number(NULL, n, &res), 1);
}
END_TEST


START_TEST(mult_num_incorr3) {
    double n = 1.0;
    ck_assert_int_eq(s21_mult_number(NULL, n, NULL), 1);
}
END_TEST

START_TEST(mult_num_corr1) {
    matrix_t A;
    double n = 1.0;
    matrix_t res;
    matrix_t expected;

    s21_create_matrix(3, 3, &A);
    double arr1[] = {2.0, 5.0, 7.0, 6.0, 3.0, 4.0, 5.0, -2.0, -3.0};
    s21_init_matrix(&A, arr1);

    ck_assert_int_eq(s21_mult_number(&A, n, &res), 0); 

    s21_create_matrix(3, 3, &expected);
    double arr2[] = {2.0, 5.0, 7.0, 6.0, 3.0, 4.0, 5.0, -2.0, -3.0};
    s21_init_matrix(&expected, arr2);

    ck_assert_int_eq(s21_eq_matrix(&res, &expected), SUCCESS); 

    s21_remove_matrix(&A);
    s21_remove_matrix(&res);
    s21_remove_matrix(&expected);
}
END_TEST

START_TEST(mult_num_corr2) {
    matrix_t A;
    double n = -1.2;
    matrix_t res;
    matrix_t expected;

    s21_create_matrix(1, 1, &A);
    double arr1[] = {2.0};
    s21_init_matrix(&A, arr1);

    ck_assert_int_eq(s21_mult_number(&A, n, &res), 0); 

    s21_create_matrix(1, 1, &expected);
    double arr2[] = {-2.4};
    s21_init_matrix(&expected, arr2);

    ck_assert_int_eq(s21_eq_matrix(&res, &expected), SUCCESS); 

    s21_remove_matrix(&A);
    s21_remove_matrix(&res);
    s21_remove_matrix(&expected);
}
END_TEST

START_TEST(mult_num_corr3) {
    matrix_t A;
    double n = 0.0;
    matrix_t res;
    matrix_t expected;

    s21_create_matrix(1, 1, &A);
    double arr1[] = {2.0};
    s21_init_matrix(&A, arr1);

    ck_assert_int_eq(s21_mult_number(&A, n, &res), 0); 

    s21_create_matrix(1, 1, &expected);
    double arr2[] = {0.0};
    s21_init_matrix(&expected, arr2);

    ck_assert_int_eq(s21_eq_matrix(&res, &expected), SUCCESS); 

    s21_remove_matrix(&A);
    s21_remove_matrix(&res);
    s21_remove_matrix(&expected);
}
END_TEST

Suite *mult_num_suite() {
  Suite *s = suite_create("s21_mult_num");
  TCase *tc = tcase_create("Core");

  tcase_add_test(tc, mult_num_incorr1);
  tcase_add_test(tc, mult_num_incorr2);
  tcase_add_test(tc, mult_num_incorr3);
  tcase_add_test(tc, mult_num_corr1);
  tcase_add_test(tc, mult_num_corr2);
  tcase_add_test(tc, mult_num_corr3);

  suite_add_tcase(s, tc);
  return s;
}