#include <check.h>
#include <stdlib.h>

Suite *test_string(void);
Suite *test_sprintf(void);
Suite *test_sscanf(void);
Suite *test_csharp_funcs(void);

int main(void) {
  Suite *suite = test_string();
  SRunner *suite_runner = srunner_create(suite);
  srunner_add_suite(suite_runner, test_sprintf());
  srunner_add_suite(suite_runner, test_sscanf());
  srunner_add_suite(suite_runner, test_csharp_funcs());

  srunner_run_all(suite_runner, CK_NORMAL);
  int failed_count = srunner_ntests_failed(suite_runner);
  srunner_free(suite_runner);

  return failed_count == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}