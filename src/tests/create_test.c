#include <math.h>
#include <stdlib.h>
#include <check.h>

#include "../s21_matrix.h"


// void *test_malloc_fail(size_t size) {
//     (void)size;
//     return NULL;
// }

// #define malloc test_malloc_fail
// START_TEST(create_malloc_fail) {
//     matrix_t m;
//     int code = s21_create_matrix(3, 3, &m);

//     ck_assert_int_eq(code, 0);       
//     ck_assert_ptr_eq(m.matrix, NULL); 
// }
// END_TEST
// #undef malloc 

START_TEST(create_incorr1) {
    ck_assert_int_eq(s21_create_matrix(1, 2, NULL), 1);
}
END_TEST

START_TEST(create_incorr2) {
    matrix_t result = {0};
    ck_assert_int_eq(s21_create_matrix(0, 2, &result), 1);
    ck_assert_ptr_eq(result.matrix, NULL);
}
END_TEST

START_TEST(create_incorr3) {
    matrix_t result = {0};
    ck_assert_int_eq(s21_create_matrix(1,-2, &result), 1);
    ck_assert_ptr_eq(result.matrix, NULL);
}
END_TEST

START_TEST(create_corr1) {
    matrix_t result = {0};
    ck_assert_int_eq(s21_create_matrix(1, 1, &result), 0);
    ck_assert_int_eq(result.rows, 1);
    ck_assert_int_eq(result.columns, 1);
    ck_assert_ptr_ne(result.matrix, NULL);
    s21_remove_matrix(&result);
}
END_TEST

START_TEST(create_corr2) {
    matrix_t result = {0};
    ck_assert_int_eq(s21_create_matrix(2, 2, &result), 0);
    ck_assert_int_eq(result.rows, 2);
    ck_assert_int_eq(result.columns, 2);
    ck_assert_ptr_ne(result.matrix, NULL);
    s21_remove_matrix(&result);
}
END_TEST

START_TEST(create_corr3) {
    matrix_t result = {0};
    ck_assert_int_eq(s21_create_matrix(10, 15, &result), 0);
    ck_assert_int_eq(result.rows, 10);
    ck_assert_int_eq(result.columns, 15);
    ck_assert_ptr_ne(result.matrix, NULL);
    s21_remove_matrix(&result);
}
END_TEST

Suite *create_suite() {
  Suite *s = suite_create("s21_create");
  TCase *tc = tcase_create("Core");

  //tcase_add_test(tc, create_malloc_fail);
  tcase_add_test(tc, create_incorr1);
  tcase_add_test(tc, create_incorr2);
  tcase_add_test(tc, create_incorr3);
  tcase_add_test(tc, create_corr1);
  tcase_add_test(tc, create_corr2);
  tcase_add_test(tc, create_corr3);

  suite_add_tcase(s, tc);
  return s;
}