#include <check.h>
#include <stdlib.h>

Suite *create_suite(void);
Suite *remove_suite(void);
Suite *sum_suite(void);

int main(void) {
  int number_failed = 0;

  SRunner *sr = srunner_create(create_suite());
  srunner_add_suite(sr, remove_suite());
  srunner_add_suite(sr, sum_suite());


  srunner_run_all(sr, CK_VERBOSE);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);

  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}