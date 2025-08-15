#include <stdlib.h>
#include <check.h>

#include "../s21_matrix.h"
#include "../s21_helpers.h"

START_TEST(inverse_incorr1) {
    matrix_t res;
    ck_assert_int_eq(s21_inverse_matrix(NULL, &res), 1);
}
END_TEST

START_TEST(inverse_incorr2) {
    matrix_t A = {0};
    ck_assert_int_eq(s21_inverse_matrix(&A, NULL), 1);
}
END_TEST

START_TEST(inverse_incorr3) {
    ck_assert_int_eq(s21_inverse_matrix(NULL, NULL), 1);
}
END_TEST

START_TEST(inverse_incorr4) {
    matrix_t A;
    matrix_t res;
    s21_create_matrix(4, 3, &A);
    ck_assert_int_eq(s21_inverse_matrix(&A, &res), 2);
    s21_remove_matrix(&A);
}
END_TEST

START_TEST(inverse_incorr5) {
    matrix_t A;
    matrix_t res;
    s21_create_matrix(3, 4, &A);
    ck_assert_int_eq(s21_inverse_matrix(&A, &res), 2);
    s21_remove_matrix(&A);
}
END_TEST

START_TEST(inverse_corr1) {
    matrix_t A;
    matrix_t res;
    matrix_t expected;

    s21_create_matrix(3, 3, &A);
    double arr1[] = {2.0, 5.0, 7.0, 6.0, 3.0, 4.0, 5.0, -2.0, -3.0};
    s21_init_matrix(&A, arr1);

    ck_assert_int_eq(s21_inverse_matrix(&A, &res), 0); 

    s21_create_matrix(3, 3, &expected);
    double arr2[] = {1.0, -1.0, 1.0, -38.0, 41.0, -34.0, 27.0, -29.0, 24.0};
    s21_init_matrix(&expected, arr2);

    ck_assert_int_eq(s21_eq_matrix(&res, &expected), SUCCESS); 

    s21_remove_matrix(&A);
    s21_remove_matrix(&res);
    s21_remove_matrix(&expected);
}
END_TEST

START_TEST(inverse_corr2) {
    matrix_t A;
    matrix_t res;
    matrix_t expected;

    s21_create_matrix(3, 3, &A);
    double arr1[] = {1.0, 2.0, 3.0, 0.0, 4.0, 2.0, 5.0, 2.0, 1.0};
    s21_init_matrix(&A, arr1);

    ck_assert_int_eq(s21_inverse_matrix(&A, &res), 0); 

    s21_create_matrix(3, 3, &expected);
    double arr2[] = {0.0, -0.1, 0.2, -0.25, 0.35, 0.05, 0.5, -0.2, -0.1};
    s21_init_matrix(&expected, arr2);

    ck_assert_int_eq(s21_eq_matrix(&res, &expected), SUCCESS); 

    s21_remove_matrix(&A);
    s21_remove_matrix(&res);
    s21_remove_matrix(&expected);
}
END_TEST

START_TEST(inverse_corr3) {
    matrix_t A;
    matrix_t res;
    matrix_t expected;

    s21_create_matrix(1, 1, &A);
    double arr1[] = {5.2};
    s21_init_matrix(&A, arr1);

    ck_assert_int_eq(s21_inverse_matrix(&A, &res), 0); 

    s21_create_matrix(1, 1, &expected);
    double arr2[] = {1/5.2};
    s21_init_matrix(&expected, arr2);

    ck_assert_int_eq(s21_eq_matrix(&res, &expected), SUCCESS); 

    s21_remove_matrix(&A);
    s21_remove_matrix(&res);
    s21_remove_matrix(&expected);
}
END_TEST

START_TEST(inverse_corr4) {
    matrix_t A;
    matrix_t res;

    s21_create_matrix(3, 3, &A);
    double arr1[] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0};
    s21_init_matrix(&A, arr1);

    ck_assert_int_eq(s21_inverse_matrix(&A, &res), 2); 

    s21_remove_matrix(&A);
    s21_remove_matrix(&res);
}
END_TEST

Suite *inverse_suite() {
  Suite *s = suite_create("s21_inverse");
  TCase *tc = tcase_create("Core");

  tcase_add_test(tc, inverse_incorr1);
  tcase_add_test(tc, inverse_incorr2);
  tcase_add_test(tc, inverse_incorr3);
  tcase_add_test(tc, inverse_incorr4);
  tcase_add_test(tc, inverse_incorr5);
  tcase_add_test(tc, inverse_corr1);
  tcase_add_test(tc, inverse_corr2);
  tcase_add_test(tc, inverse_corr3);
  tcase_add_test(tc, inverse_corr4);

  suite_add_tcase(s, tc);
  return s;
}