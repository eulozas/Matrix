#include <math.h>
#include <stdlib.h>
#include <check.h>

#include "../s21_matrix.h"

START_TEST(determinant_incorr1) {
  double res;
  ck_assert_int_eq(s21_determinant(NULL, &res), 1);
}
END_TEST

Suite *determinant_suite() {
  Suite *s = suite_create("s21_determinant");
  TCase *tc = tcase_create("Core");

  tcase_add_test(tc, determinant_incorr1);

  suite_add_tcase(s, tc);
  return s;
}
