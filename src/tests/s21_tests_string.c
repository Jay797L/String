#include <check.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../s21_string.h"

START_TEST(test_strlen) {
  const char *str = "Hello";
  int expected_result = 5;
  int actual_result = s21_strlen(str);
  ck_assert_int_eq(actual_result, expected_result);

  const char *str_1 = "";
  int expected_result_1 = 0;
  int actual_result_1 = s21_strlen(str_1);
  ck_assert_int_eq(actual_result_1, expected_result_1);

  const char *str_2 = "A";
  int expected_result_2 = 1;
  int actual_result_2 = s21_strlen(str_2);
  ck_assert_int_eq(actual_result_2, expected_result_2);

  const char *str_3 = "abc\0def";
  int expected_result_3 = 3;
  int actual_result_3 = s21_strlen(str_3);
  ck_assert_int_eq(actual_result_3, expected_result_3);
}
END_TEST

START_TEST(test_strchr) {
  const char *str_1 = "Hello";
  int c_1 = 'o';
  const char *expected_result_1 = strchr(str_1, c_1);
  const char *actual_result_1 = s21_strchr(str_1, c_1);
  ck_assert_ptr_eq(actual_result_1, expected_result_1);

  const char *str_2 = "Hello, world!";
  const char *result_not_found = s21_strchr(str_2, 'z');
  ck_assert_ptr_eq(result_not_found, s21_NULL);

  const char *result_null_char = s21_strchr(str_2, '\0');
  ck_assert_ptr_eq(result_null_char, &str_2[strlen(str_2)]);
}
END_TEST

START_TEST(test_memchr) {
  const char str1[] = "Hello, world!";
  int c1 = 'o';
  size_t n1 = 10;
  void *expected_result1 = memchr(str1, c1, n1);
  void *actual_result1 = s21_memchr(str1, c1, n1);
  ck_assert_ptr_eq(actual_result1, expected_result1);

  const char str2[] = "Hello, world!";
  int c2 = 'z';
  size_t n2 = 14;
  void *expected_result2 = memchr(str2, c2, n2);
  void *actual_result2 = s21_memchr(str2, c2, n2);
  ck_assert_ptr_eq(actual_result2, expected_result2);

  const char str3[] = "Hello, world!";
  int c3 = 'd';
  size_t n3 = 14;
  void *expected_result3 = memchr(str3, c3, n3);
  void *actual_result3 = s21_memchr(str3, c3, n3);
  ck_assert_ptr_eq(actual_result3, expected_result3);

  const char str4[] = "Hello, world!";
  int c4 = ' ';
  size_t n4 = 6;
  void *expected_result4 = memchr(str4, c4, n4);
  void *actual_result4 = s21_memchr(str4, c4, n4);
  ck_assert_ptr_eq(actual_result4, expected_result4);

  const char str5[] = "Hello, world!";
  int c5 = 'w';
  size_t n5 = 10;
  void *expected_result5 = memchr(str5, c5, n5);
  void *actual_result5 = s21_memchr(str5, c5, n5);
  ck_assert_ptr_eq(actual_result5, expected_result5);

  const char str6[] = "";
  int c6 = 'o';
  size_t n6 = 0;
  void *expected_result6 = memchr(str6, c6, n6);
  void *actual_result6 = s21_memchr(str6, c6, n6);
  ck_assert_ptr_eq(actual_result6, expected_result6);

  const char str7[] = "A quick brown fox";
  int c7 = 'b';
  size_t n7 = 1;
  void *expected_result7 = memchr(str7, c7, n7);
  void *actual_result7 = s21_memchr(str7, c7, n7);
  ck_assert_ptr_eq(actual_result7, expected_result7);

  const char str8[] = "abcdefghijklmnopqrstuvwxyz";
  int c8 = 'y';
  size_t n8 = 26;
  void *expected_result8 = memchr(str8, c8, n8);
  void *actual_result8 = s21_memchr(str8, c8, n8);
  ck_assert_ptr_eq(actual_result8, expected_result8);

  const char str9[] = "Hello, world!";
  int c9 = '\0';
  size_t n9 = 14;
  void *expected_result9 = memchr(str9, c9, n9);
  void *actual_result9 = s21_memchr(str9, c9, n9);
  ck_assert_ptr_eq(actual_result9, expected_result9);
}
END_TEST

START_TEST(test_memcmp) {
  const char str1[] = "abc";
  const char str2[] = "abc";
  size_t n = 3;
  int expected_result = memcmp(str1, str2, n);
  int actual_result = s21_memcmp(str1, str2, n);
  ck_assert_int_eq(actual_result, expected_result);

  const char str3[] = "abc";
  const char str4[] = "abd";
  size_t n2 = 3;
  int expected_result2 = memcmp(str3, str4, n2);
  int actual_result2 = s21_memcmp(str3, str4, n2);
  ck_assert_int_eq(actual_result2, expected_result2);

  const char str5[] = "hello";
  const char str6[] = "hello";
  size_t n3 = 5;
  int expected_result3 = memcmp(str5, str6, n3);
  int actual_result3 = s21_memcmp(str5, str6, n3);
  ck_assert_int_eq(actual_result3, expected_result3);

  const char str7[] = "hello";
  const char str8[] = "world";
  size_t n4 = 3;
  int expected_result4 = memcmp(str7, str8, n4);
  int actual_result4 = s21_memcmp(str7, str8, n4);
  ck_assert_int_eq(actual_result4, expected_result4);

  const char str9[] = "abcd";
  const char str10[] = "abc";
  size_t n5 = 4;
  int expected_result5 = memcmp(str9, str10, n5);
  int actual_result5 = s21_memcmp(str9, str10, n5);
  ck_assert_int_eq(actual_result5, expected_result5);

  const char str11[] = "apple";
  const char str12[] = "apricot";
  size_t n6 = 5;
  int expected_result6 = memcmp(str11, str12, n6);
  int actual_result6 = s21_memcmp(str11, str12, n6);
  ck_assert_int_eq(actual_result6, expected_result6);

  const char str13[] = "test";
  const char str14[] = "tEst";
  size_t n7 = 4;
  int expected_result7 = memcmp(str13, str14, n7);
  int actual_result7 = s21_memcmp(str13, str14, n7);
  ck_assert_int_eq(actual_result7, expected_result7);

  const char str15[] = "hello";
  const char str16[] = "hello world";
  size_t n8 = 6;
  int expected_result8 = memcmp(str15, str16, n8);
  int actual_result8 = s21_memcmp(str15, str16, n8);
  ck_assert_int_eq(actual_result8, expected_result8);

  const char str17[] = "123456";
  const char str18[] = "123456";
  size_t n9 = 6;
  int expected_result9 = memcmp(str17, str18, n9);
  int actual_result9 = s21_memcmp(str17, str18, n9);
  ck_assert_int_eq(actual_result9, expected_result9);

  const char str19[] = "123456";
  const char str20[] = "123457";
  size_t n10 = 6;
  int expected_result10 = memcmp(str19, str20, n10);
  int actual_result10 = s21_memcmp(str19, str20, n10);
  ck_assert_int_eq(actual_result10, expected_result10);
}
END_TEST

START_TEST(test_memcpy) {
  const char src[] = "Hello";
  char dest[10];
  void *expected_result = memcpy(dest, src, strlen(src) + 1);
  void *actual_result = s21_memcpy(dest, src, strlen(src) + 1);
  ck_assert_str_eq((char *)actual_result, (char *)expected_result);

  const char src1[] = "abc";
  char dest1[10];
  void *expected_result1 = memcpy(dest1, src1, strlen(src1) + 1);
  void *actual_result1 = s21_memcpy(dest1, src1, strlen(src1) + 1);
  ck_assert_str_eq((char *)actual_result1, (char *)expected_result1);

  const char src2[] = "world";
  char dest2[10];
  void *expected_result2 = memcpy(dest2, src2, strlen(src2) + 1);
  void *actual_result2 = s21_memcpy(dest2, src2, strlen(src2) + 1);
  ck_assert_str_eq((char *)actual_result2, (char *)expected_result2);

  const char src3[] = "Test123";
  char dest3[20];
  void *expected_result3 = memcpy(dest3, src3, strlen(src3) + 1);
  void *actual_result3 = s21_memcpy(dest3, src3, strlen(src3) + 1);
  ck_assert_str_eq((char *)actual_result3, (char *)expected_result3);

  const char src4[] = "Copy me!";
  char dest4[20];
  void *expected_result4 = memcpy(dest4, src4, strlen(src4) + 1);
  void *actual_result4 = s21_memcpy(dest4, src4, strlen(src4) + 1);
  ck_assert_str_eq((char *)actual_result4, (char *)expected_result4);

  char src5[] = "";
  char dest5[10];
  void *expected_result5 = memcpy(dest5, src5, strlen(src5) + 1);
  void *actual_result5 = s21_memcpy(dest5, src5, strlen(src5) + 1);
  ck_assert_str_eq((char *)actual_result5, (char *)expected_result5);

  const char src6[] = "1234567890";
  char dest6[20];
  void *expected_result6 = memcpy(dest6, src6, strlen(src6) + 1);
  void *actual_result6 = s21_memcpy(dest6, src6, strlen(src6) + 1);
  ck_assert_str_eq((char *)actual_result6, (char *)expected_result6);

  const char src7[] = "ABCDE";
  char dest7[10];
  void *expected_result7 = memcpy(dest7, src7, strlen(src7) + 1);
  void *actual_result7 = s21_memcpy(dest7, src7, strlen(src7) + 1);
  ck_assert_str_eq((char *)actual_result7, (char *)expected_result7);

  const char src8[] = "test memcopy";
  char dest8[20];
  void *expected_result8 = memcpy(dest8, src8, strlen(src8) + 1);
  void *actual_result8 = s21_memcpy(dest8, src8, strlen(src8) + 1);
  ck_assert_str_eq((char *)actual_result8, (char *)expected_result8);

  const char src9[] = "memcpy";
  char dest9[10];
  void *expected_result9 = memcpy(dest9, src9, strlen(src9) + 1);
  void *actual_result9 = s21_memcpy(dest9, src9, strlen(src9) + 1);
  ck_assert_str_eq((char *)actual_result9, (char *)expected_result9);
}
END_TEST

START_TEST(test_memset) {
  char str[20];
  int c = 'A';
  size_t n;

  n = 3;
  memset(str, 'B', sizeof(str));
  void *expected_result = memset(str, c, n);
  void *actual_result = s21_memset(str, c, n);
  ck_assert_mem_eq(actual_result, expected_result, sizeof(str));

  n = sizeof(str);
  memset(str, 'B', sizeof(str));
  expected_result = memset(str, c, n);
  actual_result = s21_memset(str, c, n);
  ck_assert_mem_eq(actual_result, expected_result, sizeof(str));

  n = 0;
  memset(str, 'B', sizeof(str));
  expected_result = memset(str, c, n);
  actual_result = s21_memset(str, c, n);
  ck_assert_mem_eq(actual_result, expected_result, sizeof(str));

  n = sizeof(str) - 1;
  memset(str, 'B', sizeof(str));
  expected_result = memset(str, c, n);
  actual_result = s21_memset(str, c, n);
  ck_assert_mem_eq(actual_result, expected_result, sizeof(str));

  c = '\0';
  n = 5;
  memset(str, 'B', sizeof(str));
  expected_result = memset(str, c, n);
  actual_result = s21_memset(str, c, n);
  ck_assert_mem_eq(actual_result, expected_result, sizeof(str));
}
END_TEST

START_TEST(test_strncat) {
  char dest[20];
  const char src[] = " World";
  size_t n;

  n = 3;
  strcpy(dest, "Hello");
  char *expected_result = strncat(dest, src, n);
  char *actual_result = s21_strncat(dest, src, n);
  ck_assert_str_eq(actual_result, expected_result);

  n = 5;
  strcpy(dest, "Hello");
  expected_result = strncat(dest, src, n);
  actual_result = s21_strncat(dest, src, n);
  ck_assert_str_eq(actual_result, expected_result);

  n = 0;
  strcpy(dest, "Hello");
  expected_result = strncat(dest, src, n);
  actual_result = s21_strncat(dest, src, n);
  ck_assert_str_eq(actual_result, expected_result);

  n = sizeof(src) - 1;
  strcpy(dest, "Hello");
  expected_result = strncat(dest, src, n);
  actual_result = s21_strncat(dest, src, n);
  ck_assert_str_eq(actual_result, expected_result);

  n = 10;
  strcpy(dest, "Hello");
  expected_result = strncat(dest, src, n);
  actual_result = s21_strncat(dest, src, n);
  ck_assert_str_eq(actual_result, expected_result);
}
END_TEST

START_TEST(test_strncmp) {
  const char str1[] = "Hello";
  const char str2[] = "Helix";
  size_t n;

  n = 3;
  int expected_result = strncmp(str1, str2, n);
  int actual_result = s21_strncmp(str1, str2, n);
  ck_assert_int_eq(actual_result, expected_result);

  n = 5;
  expected_result = strncmp(str1, str2, n);
  actual_result = s21_strncmp(str1, str2, n);
  ck_assert_int_eq(actual_result, expected_result);

  n = 0;
  expected_result = strncmp(str1, str2, n);
  actual_result = s21_strncmp(str1, str2, n);
  ck_assert_int_eq(actual_result, expected_result);

  n = 6;
  expected_result = strncmp(str1, str2, n);
  actual_result = s21_strncmp(str1, str2, n);
  ck_assert_int_eq(actual_result, expected_result);

  const char str3[] = "Hello";
  const char str4[] = "Hello";
  n = 5;
  expected_result = strncmp(str3, str4, n);
  actual_result = s21_strncmp(str3, str4, n);
  ck_assert_int_eq(actual_result, expected_result);

  const char str5[] = "Hello";
  const char str6[] = "Hellooo";
  n = 8;
  expected_result = strncmp(str5, str6, n);
  actual_result = s21_strncmp(str5, str6, n);
  ck_assert_int_eq(actual_result, expected_result);
}
END_TEST

START_TEST(test_strncpy) {
  const char src[] = "Hello";
  char dest[10];
  size_t n;

  n = 3;
  memset(dest, 0, sizeof(dest));
  char *expected_result = strncpy(dest, src, n);
  char *actual_result = s21_strncpy(dest, src, n);
  ck_assert_str_eq(actual_result, expected_result);

  n = 5;
  memset(dest, 0, sizeof(dest));
  expected_result = strncpy(dest, src, n);
  actual_result = s21_strncpy(dest, src, n);
  ck_assert_str_eq(actual_result, expected_result);

  n = 0;
  memset(dest, 0, sizeof(dest));
  expected_result = strncpy(dest, src, n);
  actual_result = s21_strncpy(dest, src, n);
  ck_assert_str_eq(actual_result, expected_result);

  n = 7;
  memset(dest, 0, sizeof(dest));
  expected_result = strncpy(dest, src, n);
  actual_result = s21_strncpy(dest, src, n);
  ck_assert_str_eq(actual_result, expected_result);

  const char src2[] = "World!";
  n = 10;
  memset(dest, 0, sizeof(dest));
  expected_result = strncpy(dest, src2, n);
  actual_result = s21_strncpy(dest, src2, n);
  ck_assert_str_eq(actual_result, expected_result);

  const char src3[] = "Short";
  n = 6;
  memset(dest, 0, sizeof(dest));
  expected_result = strncpy(dest, src3, n);
  actual_result = s21_strncpy(dest, src3, n);
  ck_assert_str_eq(actual_result, expected_result);
}
END_TEST

START_TEST(test_strcspn) {
  const char str1[] = "Hello, world!";
  const char str2[] = "aeiou";
  size_t expected_result;
  size_t actual_result;

  expected_result = strcspn(str1, str2);
  actual_result = s21_strcspn(str1, str2);
  ck_assert_int_eq(actual_result, expected_result);

  expected_result = strcspn(str1, "o");
  actual_result = s21_strcspn(str1, "o");
  ck_assert_int_eq(actual_result, expected_result);

  expected_result = strcspn(str1, "");
  actual_result = s21_strcspn(str1, "");
  ck_assert_int_eq(actual_result, expected_result);

  expected_result = strcspn(str1, "aeiou");
  actual_result = s21_strcspn(str1, "aeiou");
  ck_assert_int_eq(actual_result, expected_result);

  expected_result = strcspn(str1, "xyz");
  actual_result = s21_strcspn(str1, "xyz");
  ck_assert_int_eq(actual_result, expected_result);

  const char str3[] = "Testing strcspn function";
  expected_result = strcspn(str3, "t");
  actual_result = s21_strcspn(str3, "t");
  ck_assert_int_eq(actual_result, expected_result);
}
END_TEST

START_TEST(test_strerror) {
  int errnum;
  char *expected_result;
  char *actual_result;

  errnum = EINVAL;
  expected_result = strerror(errnum);
  actual_result = s21_strerror(errnum);
  ck_assert_str_eq(actual_result, expected_result);

  errnum = EPERM;
  expected_result = strerror(errnum);
  actual_result = s21_strerror(errnum);
  ck_assert_str_eq(actual_result, expected_result);

  errnum = ENOENT;
  expected_result = strerror(errnum);
  actual_result = s21_strerror(errnum);
  ck_assert_str_eq(actual_result, expected_result);

  errnum = EIO;
  expected_result = strerror(errnum);
  actual_result = s21_strerror(errnum);
  ck_assert_str_eq(actual_result, expected_result);

  errnum = 0;
  expected_result = strerror(errnum);
  actual_result = s21_strerror(errnum);
  ck_assert_str_eq(actual_result, expected_result);

  errnum = ENOMEM;
  expected_result = strerror(errnum);
  actual_result = s21_strerror(errnum);
  ck_assert_str_eq(actual_result, expected_result);
}
END_TEST

START_TEST(test_s21_strerror_vs_strerror) {
  for (size_t code = 0; code < 133; code++) {
    const char *s21_error_msg = s21_strerror(code);
    const char *std_error_msg = strerror(code);

    ck_assert_str_eq(s21_error_msg, std_error_msg);
  }
}
END_TEST

START_TEST(test_strpbrk) {
  const char str1[] = "Hello, world!";
  const char str2[] = "aeiou";
  const char *expected_result;
  const char *actual_result;

  expected_result = strpbrk(str1, str2);
  actual_result = s21_strpbrk(str1, str2);
  ck_assert_ptr_eq(actual_result, expected_result);

  expected_result = strpbrk(str1, "o");
  actual_result = s21_strpbrk(str1, "o");
  ck_assert_ptr_eq(actual_result, expected_result);

  expected_result = strpbrk(str1, " ,!");
  actual_result = s21_strpbrk(str1, " ,!");
  ck_assert_ptr_eq(actual_result, expected_result);

  expected_result = strpbrk(str1, "xyz");
  actual_result = s21_strpbrk(str1, "xyz");
  ck_assert_ptr_eq(actual_result, expected_result);

  expected_result = strpbrk(str1, "r");
  actual_result = s21_strpbrk(str1, "r");
  ck_assert_ptr_eq(actual_result, expected_result);

  const char str3[] = "ABCDEFG";
  expected_result = strpbrk(str3, "XYZ");
  actual_result = s21_strpbrk(str3, "XYZ");
  ck_assert_ptr_eq(actual_result, expected_result);

  expected_result = strpbrk(str3, "AE");
  actual_result = s21_strpbrk(str3, "AE");
  ck_assert_ptr_eq(actual_result, expected_result);
}
END_TEST

START_TEST(test_strrchr) {
  const char str[] = "Hello, world!";
  int c;
  const char *expected_result;
  const char *actual_result;

  c = 'o';
  expected_result = strrchr(str, c);
  actual_result = s21_strrchr(str, c);
  ck_assert_ptr_eq(actual_result, expected_result);

  c = 'l';
  expected_result = strrchr(str, c);
  actual_result = s21_strrchr(str, c);
  ck_assert_ptr_eq(actual_result, expected_result);

  c = 'w';
  expected_result = strrchr(str, c);
  actual_result = s21_strrchr(str, c);
  ck_assert_ptr_eq(actual_result, expected_result);

  c = '!';
  expected_result = strrchr(str, c);
  actual_result = s21_strrchr(str, c);
  ck_assert_ptr_eq(actual_result, expected_result);

  c = 'H';
  expected_result = strrchr(str, c);
  actual_result = s21_strrchr(str, c);
  ck_assert_ptr_eq(actual_result, expected_result);

  c = 'z';
  expected_result = strrchr(str, c);
  actual_result = s21_strrchr(str, c);
  ck_assert_ptr_eq(actual_result, expected_result);

  c = '\0';
  expected_result = strrchr(str, c);
  actual_result = s21_strrchr(str, c);
  ck_assert_ptr_eq(actual_result, expected_result);
}
END_TEST

START_TEST(test_strstr) {
  const char haystack[] = "Hello, world!";
  const char *needle;
  const char *expected_result;
  const char *actual_result;

  needle = "world";
  expected_result = strstr(haystack, needle);
  actual_result = s21_strstr(haystack, needle);
  ck_assert_ptr_eq(actual_result, expected_result);

  needle = "Hello";
  expected_result = strstr(haystack, needle);
  actual_result = s21_strstr(haystack, needle);
  ck_assert_ptr_eq(actual_result, expected_result);

  needle = "world!";
  expected_result = strstr(haystack, needle);
  actual_result = s21_strstr(haystack, needle);
  ck_assert_ptr_eq(actual_result, expected_result);

  needle = "o";
  expected_result = strstr(haystack, needle);
  actual_result = s21_strstr(haystack, needle);
  ck_assert_ptr_eq(actual_result, expected_result);

  needle = "z";
  expected_result = strstr(haystack, needle);
  actual_result = s21_strstr(haystack, needle);
  ck_assert_ptr_eq(actual_result, expected_result);

  needle = "";
  expected_result = strstr(haystack, needle);
  actual_result = s21_strstr(haystack, needle);
  ck_assert_ptr_eq(actual_result, expected_result);

  needle = "worlds";
  expected_result = strstr(haystack, needle);
  actual_result = s21_strstr(haystack, needle);
  ck_assert_ptr_eq(actual_result, expected_result);
}
END_TEST

START_TEST(test_strtok) {
  char str1[] = "Hello, world!";
  char str2[] = "Hello, world!";
  const char delim[] = " ,!";
  char *expected_result = strtok(str1, delim);
  char *actual_result = s21_strtok(str2, delim);
  ck_assert_str_eq(actual_result, expected_result);

  while ((expected_result = strtok(NULL, delim)) != NULL) {
    actual_result = s21_strtok(NULL, delim);
    ck_assert_str_eq(actual_result, expected_result);
  }
}
END_TEST

Suite *test_string(void) {
  Suite *suite = suite_create("string");

  TCase *tcase_strlen = tcase_create("Test strlen");
  tcase_add_test(tcase_strlen, test_strlen);
  suite_add_tcase(suite, tcase_strlen);

  TCase *tcase_strchr = tcase_create("Test strchr");
  tcase_add_test(tcase_strchr, test_strchr);
  suite_add_tcase(suite, tcase_strchr);

  TCase *tcase_memchr = tcase_create("Test memchr");
  tcase_add_test(tcase_memchr, test_memchr);
  suite_add_tcase(suite, tcase_memchr);

  TCase *tcase_memcmp = tcase_create("Test memcmp");
  tcase_add_test(tcase_memcmp, test_memcmp);
  suite_add_tcase(suite, tcase_memcmp);

  TCase *tcase_memcpy = tcase_create("Test memcpy");
  tcase_add_test(tcase_memcpy, test_memcpy);
  suite_add_tcase(suite, tcase_memcpy);

  TCase *tcase_memset = tcase_create("Test memset");
  tcase_add_test(tcase_memset, test_memset);
  suite_add_tcase(suite, tcase_memset);

  TCase *tcase_strncat = tcase_create("Test strncat");
  tcase_add_test(tcase_strncat, test_strncat);
  suite_add_tcase(suite, tcase_strncat);

  TCase *tcase_strncmp = tcase_create("Test strncmp");
  tcase_add_test(tcase_strncmp, test_strncmp);
  suite_add_tcase(suite, tcase_strncmp);

  TCase *tcase_strncpy = tcase_create("Test strncpy");
  tcase_add_test(tcase_strncpy, test_strncpy);
  suite_add_tcase(suite, tcase_strncpy);

  TCase *tcase_strcspn = tcase_create("Test strcspn");
  tcase_add_test(tcase_strcspn, test_strcspn);
  suite_add_tcase(suite, tcase_strcspn);

  TCase *tcase_strerror = tcase_create("Test strerror");
  tcase_add_test(tcase_strerror, test_strerror);
  tcase_add_test(tcase_strerror, test_s21_strerror_vs_strerror);
  suite_add_tcase(suite, tcase_strerror);

  TCase *tcase_strpbrk = tcase_create("Test strpbrk");
  tcase_add_test(tcase_strpbrk, test_strpbrk);
  suite_add_tcase(suite, tcase_strpbrk);

  TCase *tcase_strrchr = tcase_create("Test strrchr");
  tcase_add_test(tcase_strrchr, test_strrchr);
  suite_add_tcase(suite, tcase_strrchr);

  TCase *tcase_strstr = tcase_create("Test strstr");
  tcase_add_test(tcase_strstr, test_strstr);
  suite_add_tcase(suite, tcase_strstr);

  TCase *tcase_strtok = tcase_create("Test strtok");
  tcase_add_test(tcase_strtok, test_strtok);
  suite_add_tcase(suite, tcase_strtok);

  return suite;
}