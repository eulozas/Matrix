#include <stdlib.h>
#include <check.h>

#include "../s21_matrix.h"
#include "../s21_helpers.h"

START_TEST(transpose_incorr1) {
    matrix_t A;
    s21_create_matrix(2, 2, &A);
    ck_assert_int_eq(s21_transpose(&A, NULL), 1);
    s21_remove_matrix(&A);
}
END_TEST

START_TEST(transpose_incorr2) {
    matrix_t res;
    ck_assert_int_eq(s21_transpose(NULL, &res), 1);
}
END_TEST

START_TEST(transpose_incorr3) {
    ck_assert_int_eq(s21_transpose(NULL, NULL), 1);
}
END_TEST

START_TEST(transpose_corr1) {
    matrix_t A;
    matrix_t res;
    matrix_t expected;

    s21_create_matrix(3, 3, &A);
    double arr1[] = {2.0, 5.0, 7.0, 6.0, 3.0, 4.0, 5.0, -2.0, -3.0};
    s21_init_matrix(&A, arr1);

    ck_assert_int_eq(s21_transpose(&A, &res), 0); 

    s21_create_matrix(3, 3, &expected);
    double arr2[] = {2.0, 6.0, 5.0, 5.0, 3.0, -2.0, 7.0, 4.0, -3.0};
    s21_init_matrix(&expected, arr2);

    ck_assert_int_eq(s21_eq_matrix(&res, &expected), SUCCESS); 

    s21_remove_matrix(&A);
    s21_remove_matrix(&res);
    s21_remove_matrix(&expected);
}
END_TEST

START_TEST(transpose_corr2) {
    matrix_t A;
    matrix_t res;
    matrix_t expected;

    s21_create_matrix(1, 1, &A);
    double arr1[] = {3.12345};
    s21_init_matrix(&A, arr1);

    ck_assert_int_eq(s21_transpose(&A, &res), 0); 

    s21_create_matrix(1, 1, &expected);
    double arr2[] = {3.12345};
    s21_init_matrix(&expected, arr2);

    ck_assert_int_eq(s21_eq_matrix(&res, &expected), SUCCESS); 

    s21_remove_matrix(&A);
    s21_remove_matrix(&res);
    s21_remove_matrix(&expected);
}
END_TEST

START_TEST(transpose_corr3) {
    matrix_t A;
    matrix_t res;
    matrix_t expected;

    s21_create_matrix(1, 2, &A);
    double arr1[] = {1.0, 2.5};
    s21_init_matrix(&A, arr1);

    ck_assert_int_eq(s21_transpose(&A, &res), 0); 

    s21_create_matrix(2, 1, &expected);
    double arr2[] = {1.0, 2.5};
    s21_init_matrix(&expected, arr2);

    ck_assert_int_eq(s21_eq_matrix(&res, &expected), SUCCESS); 

    s21_remove_matrix(&A);
    s21_remove_matrix(&res);
    s21_remove_matrix(&expected);
}
END_TEST

START_TEST(transpose_corr4) {
    matrix_t A;
    matrix_t res;
    matrix_t expected;

    s21_create_matrix(2, 3, &A);
    double arr1[] = {1.0, 2.0, 2.0, 5.0, 6.0, 7.0};
    s21_init_matrix(&A, arr1);

    ck_assert_int_eq(s21_transpose(&A, &res), 0); 

    s21_create_matrix(3, 2, &expected);
    double arr2[] = {1.0, 5.0, 2.0, 6.0, 2.0, 7.0};
    s21_init_matrix(&expected, arr2);

    ck_assert_int_eq(s21_eq_matrix(&res, &expected), SUCCESS); 

    s21_remove_matrix(&A);
    s21_remove_matrix(&res);
    s21_remove_matrix(&expected);
}
END_TEST

Suite *transpose_suite() {
  Suite *s = suite_create("s21_transpose");
  TCase *tc = tcase_create("Core");

  tcase_add_test(tc, transpose_incorr1);
  tcase_add_test(tc, transpose_incorr2);
  tcase_add_test(tc, transpose_incorr3);
  tcase_add_test(tc, transpose_corr1);
  tcase_add_test(tc, transpose_corr2);
  tcase_add_test(tc, transpose_corr3);
  tcase_add_test(tc, transpose_corr4);

  suite_add_tcase(s, tc);
  return s;
}