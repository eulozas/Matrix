#include <math.h>
#include <stdlib.h>
#include <check.h>

#include "../s21_matrix.h"

START_TEST(sum_incorr1) {
  matrix_t B;
  matrix_t result;
  ck_assert_int_eq(s21_sum_matrix(NULL, &B, &result), 1);
}
END_TEST

START_TEST(sum_incorr2) {
  matrix_t A;
  matrix_t result;
  ck_assert_int_eq(s21_sum_matrix(&A, NULL, &result), 1);
}
END_TEST

START_TEST(sum_incorr3) {
  matrix_t A;
  matrix_t B;
  
  ck_assert_int_eq(s21_sum_matrix(&A, &B, NULL), 1);
}
END_TEST

// START_TEST(sum_incorr4) {
//   matrix_t A;
//   matrix_t B;
//   matrix_t result;
//   s21_create_matrix(1,2,&A);
//   A.matrix[0][0]=1.0;
//   A.matrix[0][1]=2.0;

//   s21_create_matrix(2,1,&B);
//   B.matrix[0][0]=1.0;
//   B.matrix[1][0]=2.0;
  
//   ck_assert_int_eq(s21_sum(&A, &B, &result), 2);
//   s21_remove_matrix(&A);
//   s21_remove_matrix(&B);
// }
// END_TEST

Suite *sum_suite() {
  Suite *s = suite_create("s21_sum");
  TCase *tc = tcase_create("Core");

  tcase_add_test(tc, sum_incorr1);
  tcase_add_test(tc, sum_incorr2);
  tcase_add_test(tc, sum_incorr3);

  suite_add_tcase(s, tc);
  return s;
}