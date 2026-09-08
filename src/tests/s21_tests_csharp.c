#include <check.h>
#include <stdlib.h>

#include "../s21_string.h"

START_TEST(test_to_lower1) {
  char str[] = "hello world!";
  char *result = s21_to_lower(str);
  ck_assert_ptr_ne(result, s21_NULL);
  ck_assert_str_eq(result, "hello world!");
  if (result != s21_NULL) {
    free(result);
  }
}
END_TEST

START_TEST(test_to_lower2) {
  char str[] = "Hello World!";
  char *result = s21_to_lower(str);
  ck_assert_ptr_ne(result, s21_NULL);
  ck_assert_str_eq(result, "hello world!");
  if (result != s21_NULL) {
    free(result);
  }
}
END_TEST

START_TEST(test_to_lower3) {
  char str[] = "HELLO WORLD!";
  char *result = s21_to_lower(str);
  ck_assert_ptr_ne(result, s21_NULL);
  ck_assert_str_eq(result, "hello world!");
  if (result != s21_NULL) {
    free(result);
  }
}
END_TEST

START_TEST(test_to_lower4) {
  char str[] = "hELLO wORLD!";
  char *result = s21_to_lower(str);
  ck_assert_ptr_ne(result, s21_NULL);
  ck_assert_str_eq(result, "hello world!");
  if (result != s21_NULL) {
    free(result);
  }
}
END_TEST

START_TEST(test_to_lower_null) {
  char *result = s21_to_lower(s21_NULL);
  ck_assert_ptr_eq(result, s21_NULL);
  if (result != s21_NULL) {
    free(result);
  }
}
END_TEST

START_TEST(test_to_upper1) {
  char str[] = "HELLO WORLD!";
  char *result = s21_to_upper(str);
  ck_assert_ptr_ne(result, s21_NULL);
  ck_assert_str_eq(result, "HELLO WORLD!");
  if (result != s21_NULL) {
    free(result);
  }
}
END_TEST

START_TEST(test_to_upper2) {
  char str[] = "Hello World!";
  char *result = s21_to_upper(str);
  ck_assert_ptr_ne(result, s21_NULL);
  ck_assert_str_eq(result, "HELLO WORLD!");
  if (result != s21_NULL) {
    free(result);
  }
}
END_TEST

START_TEST(test_to_upper3) {
  char str[] = "hello world!";
  char *result = s21_to_upper(str);
  ck_assert_ptr_ne(result, s21_NULL);
  ck_assert_str_eq(result, "HELLO WORLD!");
  if (result != s21_NULL) {
    free(result);
  }
}
END_TEST

START_TEST(test_to_upper4) {
  char str[] = "hELLO wORLD!";
  char *result = s21_to_upper(str);
  ck_assert_ptr_ne(result, s21_NULL);
  ck_assert_str_eq(result, "HELLO WORLD!");
  if (result != s21_NULL) {
    free(result);
  }
}
END_TEST

START_TEST(test_to_upper_null) {
  char *str = s21_NULL;
  char *result = s21_to_upper(str);
  ck_assert_ptr_eq(result, s21_NULL);
  if (result != s21_NULL) {
    free(result);
  }
}
END_TEST

START_TEST(test_insert1) {
  char src[] = "HelloWorld!";
  char str[] = " ";
  s21_size_t start_index = 0;
  char *result = s21_insert(src, str, start_index);
  ck_assert_ptr_ne(result, s21_NULL);
  ck_assert_str_eq(result, " HelloWorld!");
  if (result != s21_NULL) {
    free(result);
  }
}
END_TEST

START_TEST(test_insert2) {
  char src[] = "HelloWorld!";
  char str[] = " ";
  s21_size_t start_index = 5;
  char *result = s21_insert(src, str, start_index);
  ck_assert_ptr_ne(result, s21_NULL);
  ck_assert_str_eq(result, "Hello World!");
  if (result != s21_NULL) {
    free(result);
  }
}
END_TEST

START_TEST(test_insert3) {
  char src[] = "HelloWorld!";
  char str[] = " ";
  s21_size_t start_index = 11;
  char *result = s21_insert(src, str, start_index);
  ck_assert_ptr_ne(result, s21_NULL);
  ck_assert_str_eq(result, "HelloWorld! ");
  if (result != s21_NULL) {
    free(result);
  }
}
END_TEST

START_TEST(test_insert4) {
  char src[] = "HelloWorld!";
  char str[] = "Maybe, ";
  s21_size_t start_index = 0;
  char *result = s21_insert(src, str, start_index);
  ck_assert_ptr_ne(result, s21_NULL);
  ck_assert_str_eq(result, "Maybe, HelloWorld!");
  if (result != s21_NULL) {
    free(result);
  }
}
END_TEST

START_TEST(test_insert5) {
  char src[] = "HelloWorld!";
  char str[] = "Only 5 people say me ";
  s21_size_t start_index = 0;
  char *result = s21_insert(src, str, start_index);
  ck_assert_ptr_ne(result, s21_NULL);
  ck_assert_str_eq(result, "Only 5 people say me HelloWorld!");
  if (result != s21_NULL) {
    free(result);
  }
}
END_TEST

START_TEST(test_insert6) {
  char src[] = "HelloWorld!";
  char str[] = ", or goodbye?";
  s21_size_t start_index = 10;
  char *result = s21_insert(src, str, start_index);
  ck_assert_ptr_ne(result, s21_NULL);
  ck_assert_str_eq(result, "HelloWorld, or goodbye?!");
  if (result != s21_NULL) {
    free(result);
  }
}
END_TEST

START_TEST(test_insert_null_src) {
  char *src = s21_NULL;
  char str[] = ", or goodbye?";
  s21_size_t start_index = 10;
  char *result = s21_insert(src, str, start_index);
  ck_assert_ptr_eq(result, s21_NULL);
  if (result != s21_NULL) {
    free(result);
  }
}
END_TEST

START_TEST(test_insert_null_str) {
  char src[] = "NULL";
  char *str = s21_NULL;
  s21_size_t start_index = 10;
  char *result = s21_insert(src, str, start_index);
  ck_assert_ptr_eq(result, s21_NULL);
  if (result != s21_NULL) {
    free(result);
  }
}
END_TEST

START_TEST(test_insert_start_index_out) {
  char src[] = "NULL";
  char str[] = " = ZERO";
  s21_size_t start_index = 20;
  char *result = s21_insert(src, str, start_index);
  ck_assert_ptr_eq(result, s21_NULL);
  if (result != s21_NULL) {
    free(result);
  }
}
END_TEST

START_TEST(test_insert_empty1) {
  char src[] = "NULL";
  char str[] = "";
  s21_size_t start_index = 2;
  char *result = s21_insert(src, str, start_index);
  ck_assert_ptr_ne(result, s21_NULL);
  ck_assert_str_eq(result, "NULL");
  if (result != s21_NULL) {
    free(result);
  }
}
END_TEST

START_TEST(test_insert_empty2) {
  char src[] = "";
  char str[] = "NULL";
  s21_size_t start_index = 0;
  char *result = s21_insert(src, str, start_index);
  ck_assert_ptr_ne(result, s21_NULL);
  ck_assert_str_eq(result, "NULL");
  if (result != s21_NULL) {
    free(result);
  }
}
END_TEST

START_TEST(test_trim1) {
  char src[] = "1TRIM THIS!1";
  char trim_chars[] = "1";
  char *result = s21_trim(src, trim_chars);
  ck_assert_ptr_ne(result, s21_NULL);
  ck_assert_str_eq(result, "TRIM THIS!");
  if (result != s21_NULL) {
    free(result);
  }
}
END_TEST

START_TEST(test_trim2) {
  char src[] = "1TRIM THIS!1";
  char trim_chars[] = "1T0";
  char *result = s21_trim(src, trim_chars);
  ck_assert_ptr_ne(result, s21_NULL);
  ck_assert_str_eq(result, "RIM THIS!");
  if (result != s21_NULL) {
    free(result);
  }
}
END_TEST

START_TEST(test_trim3) {
  char src[] = "1TRIM THIS!!";
  char trim_chars[] = "!";
  char *result = s21_trim(src, trim_chars);
  ck_assert_ptr_ne(result, s21_NULL);
  ck_assert_str_eq(result, "1TRIM THIS");
  if (result != s21_NULL) {
    free(result);
  }
}
END_TEST

START_TEST(test_trim4) {
  char src[] = "1TRIM THIS!1";
  char trim_chars[] = "2";
  char *result = s21_trim(src, trim_chars);
  ck_assert_ptr_ne(result, s21_NULL);
  ck_assert_str_eq(result, "1TRIM THIS!1");
  if (result != s21_NULL) {
    free(result);
  }
}
END_TEST

START_TEST(test_trim_empty1) {
  char src[] = "1TRIM THIS!1";
  char trim_chars[] = "";
  char *result = s21_trim(src, trim_chars);
  ck_assert_ptr_ne(result, s21_NULL);
  ck_assert_str_eq(result, "1TRIM THIS!1");
  if (result != s21_NULL) {
    free(result);
  }
}
END_TEST

START_TEST(test_trim_null_src) {
  char *src = s21_NULL;
  char trim_chars[] = "123";
  char *result = s21_trim(src, trim_chars);
  ck_assert_ptr_eq(result, s21_NULL);
  if (result != s21_NULL) {
    free(result);
  }
}
END_TEST

START_TEST(test_trim_null_trim_chars) {
  char src[] = "123";
  char *trim_chars = s21_NULL;
  char *result = s21_trim(src, trim_chars);
  ck_assert_ptr_ne(result, s21_NULL);
  ck_assert_str_eq(result, "123");
  if (result != s21_NULL) {
    free(result);
  }
}
END_TEST

Suite *test_csharp_funcs(void) {
  Suite *s = suite_create("c_sharp_funcs_suite");

  TCase *tc_lower = tcase_create("to_lower_tc");
  tcase_add_test(tc_lower, test_to_lower1);
  tcase_add_test(tc_lower, test_to_lower2);
  tcase_add_test(tc_lower, test_to_lower3);
  tcase_add_test(tc_lower, test_to_lower4);
  tcase_add_test(tc_lower, test_to_lower_null);
  suite_add_tcase(s, tc_lower);

  TCase *tc_upper = tcase_create("to_upper_tc");
  tcase_add_test(tc_upper, test_to_upper1);
  tcase_add_test(tc_upper, test_to_upper2);
  tcase_add_test(tc_upper, test_to_upper3);
  tcase_add_test(tc_upper, test_to_upper4);
  tcase_add_test(tc_upper, test_to_upper_null);
  suite_add_tcase(s, tc_upper);

  TCase *tc_insert = tcase_create("insert_tc");
  tcase_add_test(tc_insert, test_insert1);
  tcase_add_test(tc_insert, test_insert2);
  tcase_add_test(tc_insert, test_insert3);
  tcase_add_test(tc_insert, test_insert4);
  tcase_add_test(tc_insert, test_insert5);
  tcase_add_test(tc_insert, test_insert6);
  tcase_add_test(tc_insert, test_insert_null_src);
  tcase_add_test(tc_insert, test_insert_null_str);
  tcase_add_test(tc_insert, test_insert_start_index_out);
  tcase_add_test(tc_insert, test_insert_empty1);
  tcase_add_test(tc_insert, test_insert_empty2);
  suite_add_tcase(s, tc_insert);

  TCase *tc_trim = tcase_create("trim_tc");
  tcase_add_test(tc_trim, test_trim1);
  tcase_add_test(tc_trim, test_trim2);
  tcase_add_test(tc_trim, test_trim3);
  tcase_add_test(tc_trim, test_trim4);
  tcase_add_test(tc_trim, test_trim_empty1);
  tcase_add_test(tc_trim, test_trim_null_src);
  tcase_add_test(tc_trim, test_trim_null_trim_chars);
  suite_add_tcase(s, tc_trim);

  return s;
}