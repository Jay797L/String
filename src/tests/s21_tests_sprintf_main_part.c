#include <check.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../s21_string.h"

START_TEST(test_sprintf_flag_minus_d_main_part) {
  char format[] = "%-d %-d %-d";
  char str1[2048] = "";
  char str2[2048] = "";
  int a1 = 54, a2 = INT_MIN, a3 = INT_MAX;
  int system_sprintf = sprintf(str1, format, a1, a2, a3);
  int s21_function = s21_sprintf(str2, format, a1, a2, a3);
  ck_assert_int_eq(system_sprintf, s21_function);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_flag_minus_c_main_part) {
  char format[] = "%-c %-c %-c";
  char str1[2048] = "";
  char str2[2048] = "";
  char a1 = 'A', a2 = 'B', a3 = 'C';
  int system_sprintf = sprintf(str1, format, a1, a2, a3);
  int s21_function = s21_sprintf(str2, format, a1, a2, a3);
  ck_assert_int_eq(system_sprintf, s21_function);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_flag_minus_s_main_part) {
  char format[] = "%-s %-s %-s";
  char str1[2048] = "";
  char str2[2048] = "";
  char a1[512] = "ABC", a2[512] = "BCD", a3[512] = "CDE";
  int system_sprintf = sprintf(str1, format, a1, a2, a3);
  int s21_function = s21_sprintf(str2, format, a1, a2, a3);
  ck_assert_int_eq(system_sprintf, s21_function);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_flag_minus_u_main_part) {
  char format[] = "%-u %-u %-u";
  char str1[2048] = "";
  char str2[2048] = "";
  unsigned int a1 = 5532, a2 = UINT_MAX, a3 = 0;
  int system_sprintf = sprintf(str1, format, a1, a2, a3);
  int s21_function = s21_sprintf(str2, format, a1, a2, a3);
  ck_assert_int_eq(system_sprintf, s21_function);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_flag_minus_percent_main_part) {
  char format[] = "%-% %-% %-%";
  char str1[2048] = "";
  char str2[2048] = "";
  int a1 = 1;
  int system_sprintf = sprintf(str1, format, a1);
  int s21_function = s21_sprintf(str2, format, a1);
  ck_assert_int_eq(system_sprintf, s21_function);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_flag_plus_d_main_part) {
  char format[] = "%+d";
  char str1[2048] = "";
  char str2[2048] = "";
  int a1 = INT_MIN;
  int system_sprintf = sprintf(str1, format, a1);
  int s21_function = s21_sprintf(str2, format, a1);
  ck_assert_int_eq(system_sprintf, s21_function);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_flag_plus_f_main_part) {
  char format[] = "%+f";
  char str1[2048] = "";
  char str2[2048] = "";
  float a1 = -231.434;
  int system_sprintf = sprintf(str1, format, a1);
  int s21_function = s21_sprintf(str2, format, a1);
  ck_assert_int_eq(system_sprintf, s21_function);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_flag_plus_u_main_part) {
  char format[] = "%+u %+u %+u";
  char str1[2048] = "";
  char str2[2048] = "";
  unsigned int a1 = 5532, a2 = UINT_MAX, a3 = 0;
  int system_sprintf = sprintf(str1, format, a1, a2, a3);
  int s21_function = s21_sprintf(str2, format, a1, a2, a3);
  ck_assert_int_eq(system_sprintf, s21_function);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_flag_plus_percent_main_part) {
  char format[] = "%+% %+% %+%";
  char str1[2048] = "";
  char str2[2048] = "";
  int a1 = 1;
  int system_sprintf = sprintf(str1, format, a1);
  int s21_function = s21_sprintf(str2, format, a1);
  ck_assert_int_eq(system_sprintf, s21_function);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_flag_space_u_main_part) {
  char format[] = "% u\n";
  char str1[512] = "";
  char str2[512] = "";
  unsigned int a1 = 6;
  int system_sprintf = sprintf(str1, format, a1);
  int s21_function = s21_sprintf(str2, format, a1);
  ck_assert_int_eq(system_sprintf, s21_function);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_flag_space_d_main_part) {
  char format[] = "% d\n";
  char str1[512] = "";
  char str2[512] = "";
  int a1 = -6;
  int system_sprintf = sprintf(str1, format, a1);
  int s21_function = s21_sprintf(str2, format, a1);
  ck_assert_int_eq(system_sprintf, s21_function);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_flag_space_f_main_part) {
  char format[] = "% f\n";
  char str1[512] = "";
  char str2[512] = "";
  float a1 = -6.;
  int system_sprintf = sprintf(str1, format, a1);
  int s21_function = s21_sprintf(str2, format, a1);
  ck_assert_int_eq(system_sprintf, s21_function);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_point_number_d_main_part) {
  char format[] = "%.5d\n";
  char str1[512] = "";
  char str2[512] = "";
  int a1 = 190;
  int system_sprintf = sprintf(str1, format, a1);
  int s21_function = s21_sprintf(str2, format, a1);
  ck_assert_int_eq(system_sprintf, s21_function);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_point_number_d_zero_main_part) {
  char format[] = "%.0d\n";
  char str1[512] = "";
  char str2[512] = "";
  int a1 = 190;
  int system_sprintf = sprintf(str1, format, a1);
  int s21_function = s21_sprintf(str2, format, a1);
  ck_assert_int_eq(system_sprintf, s21_function);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_point_number_u_zero_main_part) {
  char format[] = "%.0u\n";
  char str1[512] = "";
  char str2[512] = "";
  int a1 = 190;
  int system_sprintf = sprintf(str1, format, a1);
  int s21_function = s21_sprintf(str2, format, a1);
  ck_assert_int_eq(system_sprintf, s21_function);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_point_number_u_main_part) {
  char format[] = "%.5u\n";
  char str1[512] = "";
  char str2[512] = "";
  unsigned int a1 = 190;
  int system_sprintf = sprintf(str1, format, a1);
  int s21_function = s21_sprintf(str2, format, a1);
  ck_assert_int_eq(system_sprintf, s21_function);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_point_number_f_main_part) {
  char format[] = "%.5f\n";
  char str1[512] = "";
  char str2[512] = "";
  float a1 = 190;
  int system_sprintf = sprintf(str1, format, a1);
  int s21_function = s21_sprintf(str2, format, a1);
  ck_assert_int_eq(system_sprintf, s21_function);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_point_number_f_zero_main_part) {
  char format[] = "%.0f\n";
  char str1[512] = "";
  char str2[512] = "";
  float a1 = 190;
  int system_sprintf = sprintf(str1, format, a1);
  int s21_function = s21_sprintf(str2, format, a1);
  ck_assert_int_eq(system_sprintf, s21_function);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_point_number_s_main_part) {
  char format[] = "%.5s\n";
  char str1[512] = "";
  char str2[512] = "";
  char a1[100] = "190.4532532";
  int system_sprintf = sprintf(str1, format, a1);
  int s21_function = s21_sprintf(str2, format, a1);
  ck_assert_int_eq(system_sprintf, s21_function);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_point_d_main_part) {
  char format[] = "%.d %.d\n";
  char str1[512] = "";
  char str2[512] = "";
  int a1 = 190, a2 = -190;
  int system_sprintf = sprintf(str1, format, a1, a2);
  int s21_function = s21_sprintf(str2, format, a1, a2);
  ck_assert_int_eq(system_sprintf, s21_function);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_point_u_main_part) {
  char format[] = "%.u %.u\n";
  char str1[512] = "";
  char str2[512] = "";
  unsigned int a1 = 190, a2 = UINT_MAX;
  int system_sprintf = sprintf(str1, format, a1, a2);
  int s21_function = s21_sprintf(str2, format, a1, a2);
  ck_assert_int_eq(system_sprintf, s21_function);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_point_f_main_part) {
  char format[] = "%.f %.f\n";
  char str1[512] = "";
  char str2[512] = "";
  float a1 = 190.4532532, a2 = -190.4532;
  int system_sprintf = sprintf(str1, format, a1, a2);
  int s21_function = s21_sprintf(str2, format, a1, a2);
  ck_assert_int_eq(system_sprintf, s21_function);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_c_space) {
  char format[] = "%c";
  char str1[512] = "";
  char str2[512] = "";
  char a1 = ' ';
  int system_sprintf = sprintf(str1, format, a1);
  int s21_function = s21_sprintf(str2, format, a1);
  ck_assert_int_eq(system_sprintf, s21_function);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_c) {
  char format[] = "%c %c\n";
  char str1[512] = "";
  char str2[512] = "";
  char a1 = 'H', a2 = 'e';
  int system_sprintf = sprintf(str1, format, a1, a2);
  int s21_function = s21_sprintf(str2, format, a1, a2);
  ck_assert_int_eq(system_sprintf, s21_function);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_d_empty) {
  char format[] = "%d\n";
  char str1[512] = "";
  char str2[512] = "";
  char a1 = '\0';
  int system_sprintf = sprintf(str1, format, a1);
  int s21_function = s21_sprintf(str2, format, a1);
  ck_assert_int_eq(system_sprintf, s21_function);
  ck_assert_str_eq(str1, str1);
}
END_TEST

START_TEST(test_sprintf_d) {
  char format[] = "%d %d %d\n";
  char str1[512] = "";
  char str2[512] = "";
  int a1 = 10, a2 = 11, a3 = 12;
  int system_sprintf = sprintf(str1, format, a1, a2, a3);
  int s21_function = s21_sprintf(str2, format, a1, a2, a3);
  ck_assert_int_eq(system_sprintf, s21_function);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_d_num) {
  char format[] = "%1d %2d %3d %4d\n";
  char str1[512] = "";
  char str2[512] = "";
  int a1 = 12345, a2 = 12345, a3 = 12345, a4 = 12345;
  int system_sprintf = sprintf(str1, format, a1, a2, a3, a4);
  int s21_function = s21_sprintf(str2, format, a1, a2, a3, a4);
  ck_assert_int_eq(system_sprintf, s21_function);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_d_h) {
  char format[] = "%hd";
  char str1[512] = "";
  char str2[512] = "";
  short int a1 = SHRT_MAX;
  int system_sprintf = sprintf(str1, format, a1);
  int s21_function = s21_sprintf(str2, format, a1);
  ck_assert_int_eq(system_sprintf, s21_function);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_d_l) {
  char format[] = "%ld %ld %ld %ld\n";
  char str1[512] = "";
  char str2[512] = "";
  long a1 = LONG_MIN, a2 = -32000, a3 = -32000, a4 = LONG_MAX;
  int system_sprintf = sprintf(str1, format, a1, a2, a3, a4);
  int s21_function = s21_sprintf(str2, format, a1, a2, a3, a4);
  ck_assert_int_eq(system_sprintf, s21_function);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_f_empty) {
  char format[] = "%f\n";
  char str1[512] = "";
  char str2[512] = "";
  char a1 = '\0';
  int system_sprintf = sprintf(str1, format, a1);
  int s21_function = s21_sprintf(str2, format, a1);
  ck_assert_int_eq(system_sprintf, s21_function);
  ck_assert_str_eq(str1, str1);
}
END_TEST

START_TEST(test_sprintf_f) {
  char format[] = "%f %f";
  char str1[512] = "";
  char str2[512] = "";
  float a1 = 12.005, a2 = 0.2897992;
  int system_sprintf = sprintf(str1, format, a1, a2);
  int s21_function = s21_sprintf(str2, format, a1, a2);
  ck_assert_int_eq(system_sprintf, s21_function);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_f_num) {
  char format[] = "%5f";
  char str1[512] = "";
  char str2[512] = "";
  float a1 = 12.005;
  int system_sprintf = sprintf(str1, format, a1);
  int s21_function = s21_sprintf(str2, format, a1);
  ck_assert_int_eq(system_sprintf, s21_function);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_s_empty) {
  char format[] = "%s";
  char str1[512] = "";
  char str2[512] = "";
  char a1[100] = "";
  int system_sprintf = sprintf(str1, format, a1);
  int s21_function = s21_sprintf(str2, format, a1);
  ck_assert_int_eq(system_sprintf, s21_function);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_s_zero1) {
  char format[] = "%s";
  char str1[512] = "";
  char str2[512] = "";
  char a1[100] = "\0";
  int system_sprintf = sprintf(str1, format, a1);
  int s21_function = s21_sprintf(str2, format, a1);
  ck_assert_int_eq(system_sprintf, s21_function);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_s_zero2) {
  char format[] = "%s";
  char str1[512] = "";
  char str2[512] = "";
  char a1[100] = "Hel\0p me";
  int system_sprintf = sprintf(str1, format, a1);
  int s21_function = s21_sprintf(str2, format, a1);
  ck_assert_int_eq(system_sprintf, s21_function);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_s) {
  char format[] = "%s %s";
  char str1[512] = "";
  char str2[512] = "";
  char a1[100] = "Help", a2[100] = "me";
  int system_sprintf = sprintf(str1, format, a1, a2);
  int s21_function = s21_sprintf(str2, format, a1, a2);
  ck_assert_int_eq(system_sprintf, s21_function);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_s_num1) {
  char format[] = "%2s %s";
  char str1[512] = "";
  char str2[512] = "";
  char a1[100] = "Help", a2[100] = "me";
  int system_sprintf = sprintf(str1, format, a1, a2);
  int s21_function = s21_sprintf(str2, format, a1, a2);
  ck_assert_int_eq(system_sprintf, s21_function);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_s_num2) {
  char format[] = "%s %1s";
  char str1[512] = "";
  char str2[512] = "";
  char a1[100] = "Help", a2[100] = "me";
  int system_sprintf = sprintf(str1, format, a1, a2);
  int s21_function = s21_sprintf(str2, format, a1, a2);
  ck_assert_int_eq(system_sprintf, s21_function);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_s_num3) {
  char format[] = "%4s";
  char str1[512] = "";
  char str2[512] = "";
  char a1[100] = "Help";
  int system_sprintf = sprintf(str1, format, a1);
  int s21_function = s21_sprintf(str2, format, a1);
  ck_assert_int_eq(system_sprintf, s21_function);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_u_empty) {
  char format[] = "%u";
  char str1[512] = "";
  char str2[512] = "";
  char a1 = '\0';
  int system_sprintf = sprintf(str1, format, a1);
  int s21_function = s21_sprintf(str2, format, a1);
  ck_assert_int_eq(system_sprintf, s21_function);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_u) {
  char format[] = "%u %u %u";
  char str1[512] = "";
  char str2[512] = "";
  unsigned int a1 = -11, a2 = 11, a3 = UINT_MAX;
  int system_sprintf = sprintf(str1, format, a1, a2, a3);
  int s21_function = s21_sprintf(str2, format, a1, a2, a3);
  ck_assert_int_eq(system_sprintf, s21_function);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_u_num1) {
  char format[] = "%2u %3u %5u";
  char str1[512] = "";
  char str2[512] = "";
  unsigned int a1 = 11111, a2 = 22222, a3 = UINT_MAX;
  int system_sprintf = sprintf(str1, format, a1, a2, a3);
  int s21_function = s21_sprintf(str2, format, a1, a2, a3);
  ck_assert_int_eq(system_sprintf, s21_function);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_u_num2) {
  char format[] = "%5u %3u %5u";
  char str1[512] = "";
  char str2[512] = "";
  unsigned int a1 = 11111, a2 = 22222, a3 = UINT_MAX;
  int system_sprintf = sprintf(str1, format, a1, a2, a3);
  int s21_function = s21_sprintf(str2, format, a1, a2, a3);
  ck_assert_int_eq(system_sprintf, s21_function);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_u_h) {
  char format[] = "%hu %hu %hu";
  char str1[512] = "";
  char str2[512] = "";
  unsigned short int a1 = 101, a2 = 11, a3 = USHRT_MAX;
  int system_sprintf = sprintf(str1, format, a1, a2, a3);
  int s21_function = s21_sprintf(str2, format, a1, a2, a3);
  ck_assert_uint_eq(system_sprintf, s21_function);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_u_l) {
  char format[] = "%lu %lu %lu";
  char str1[512] = "";
  char str2[512] = "";
  unsigned long a1 = 101, a2 = 11, a3 = 4294967295;
  int system_sprintf = sprintf(str1, format, a1, a2, a3);
  int s21_function = s21_sprintf(str2, format, a1, a2, a3);
  ck_assert_int_eq(system_sprintf, s21_function);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_percent) {
  char format[] = "|%%%%%% %d|\n";
  char str1[1024] = "";
  char str2[1024] = "";
  int system_sprintf = sprintf(str1, format, 1);
  int s21_function = s21_sprintf(str2, format, 1);

  ck_assert_int_eq(system_sprintf, s21_function);
  ck_assert_str_eq(str1, str2);
}
END_TEST

Suite *test_sprintf(void) {
  Suite *s = suite_create("sprintf");

  TCase *tc = tcase_create("tc_sprintf");

  suite_add_tcase(s, tc);

  tcase_add_test(tc, test_sprintf_flag_minus_d_main_part);
  tcase_add_test(tc, test_sprintf_flag_minus_c_main_part);
  tcase_add_test(tc, test_sprintf_flag_minus_s_main_part);
  tcase_add_test(tc, test_sprintf_flag_minus_u_main_part);
  tcase_add_test(tc, test_sprintf_flag_minus_percent_main_part);
  tcase_add_test(tc, test_sprintf_flag_plus_d_main_part);
  tcase_add_test(tc, test_sprintf_flag_plus_f_main_part);
  tcase_add_test(tc, test_sprintf_flag_plus_u_main_part);
  tcase_add_test(tc, test_sprintf_flag_plus_percent_main_part);
  tcase_add_test(tc, test_sprintf_flag_space_d_main_part);
  tcase_add_test(tc, test_sprintf_flag_space_u_main_part);
  tcase_add_test(tc, test_sprintf_flag_space_f_main_part);
  tcase_add_test(tc, test_sprintf_point_number_d_main_part);
  tcase_add_test(tc, test_sprintf_point_number_d_zero_main_part);
  tcase_add_test(tc, test_sprintf_point_number_u_main_part);
  tcase_add_test(tc, test_sprintf_point_number_u_zero_main_part);
  tcase_add_test(tc, test_sprintf_point_number_f_main_part);
  tcase_add_test(tc, test_sprintf_point_number_f_zero_main_part);
  tcase_add_test(tc, test_sprintf_point_number_s_main_part);
  tcase_add_test(tc, test_sprintf_point_d_main_part);
  tcase_add_test(tc, test_sprintf_point_f_main_part);
  tcase_add_test(tc, test_sprintf_point_u_main_part);
  tcase_add_test(tc, test_sprintf_c_space);
  tcase_add_test(tc, test_sprintf_c);
  tcase_add_test(tc, test_sprintf_d_empty);
  tcase_add_test(tc, test_sprintf_d);
  tcase_add_test(tc, test_sprintf_d_num);
  tcase_add_test(tc, test_sprintf_d_h);
  tcase_add_test(tc, test_sprintf_d_l);
  tcase_add_test(tc, test_sprintf_f_empty);
  tcase_add_test(tc, test_sprintf_f);
  tcase_add_test(tc, test_sprintf_f_num);
  tcase_add_test(tc, test_sprintf_s_empty);
  tcase_add_test(tc, test_sprintf_s_zero1);
  tcase_add_test(tc, test_sprintf_s_zero2);
  tcase_add_test(tc, test_sprintf_s);
  tcase_add_test(tc, test_sprintf_s_num1);
  tcase_add_test(tc, test_sprintf_s_num2);
  tcase_add_test(tc, test_sprintf_s_num3);
  tcase_add_test(tc, test_sprintf_u_empty);
  tcase_add_test(tc, test_sprintf_u);
  tcase_add_test(tc, test_sprintf_u_num1);
  tcase_add_test(tc, test_sprintf_u_num2);
  tcase_add_test(tc, test_sprintf_u_h);
  tcase_add_test(tc, test_sprintf_u_l);
  tcase_add_test(tc, test_sprintf_percent);

  suite_add_tcase(s, tc);

  return s;
}