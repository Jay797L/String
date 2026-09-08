#include <check.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../s21_string.h"

START_TEST(test_sscanf_c_space) {
  char format[] = "%c";
  char str[] = " ";
  char a1 = 3, b1 = 2;
  int system_scanf = sscanf(str, format, &a1);
  int s21_function = s21_sscanf(str, format, &b1);
  ck_assert_int_eq(system_scanf, s21_function);
  ck_assert_int_eq(a1, b1);
}
END_TEST

START_TEST(test_sscanf_c) {
  char format[] = "%c %c";
  char str[] = "Help me";
  char a1 = 'a', a2 = 'b', b1 = 'a', b2 = 'b';
  int system_scanf = sscanf(str, format, &a1, &a2);
  int s21_function = s21_sscanf(str, format, &b1, &b2);
  ck_assert_int_eq(system_scanf, s21_function);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
}
END_TEST

START_TEST(test_sscanf_c_star1) {
  char format[] = "%c %*c";
  char str[] = "Help me";
  char a1 = 'a', a2 = 'b', b1 = 'a', b2 = 'b';
  int system_scanf = sscanf(str, format, &a1, &a2);
  int s21_function = s21_sscanf(str, format, &b1, &b2);
  ck_assert_int_eq(system_scanf, s21_function);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
}
END_TEST

START_TEST(test_sscanf_c_star2) {
  char format[] = "%*c %c";
  char str[] = "Help me";
  char a1 = 'a', a2 = 'b', b1 = 'a', b2 = 'b';
  int system_scanf = sscanf(str, format, &a1, &a2);
  int s21_function = s21_sscanf(str, format, &b1, &b2);
  ck_assert_int_eq(system_scanf, s21_function);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
}
END_TEST

START_TEST(test_sscanf_d_space) {
  char format[] = "%d";
  char str[] = " ";
  char a1 = 1, b1 = 1;
  int system_scanf = sscanf(str, format, &a1);
  int s21_function = s21_sscanf(str, format, &b1);
  ck_assert_int_eq(system_scanf, s21_function);
  ck_assert_int_eq(a1, b1);
}
END_TEST

START_TEST(test_sscanf_d) {
  char format[] = "%d %d %d";
  char str[] = "10 11 12";
  int a1 = 1, a2 = 2, a3 = 3, b1 = 1, b2 = 2, b3 = 3;
  int system_scanf = sscanf(str, format, &a1, &a2, &a3);
  int s21_function = s21_sscanf(str, format, &b1, &b2, &b3);
  ck_assert_int_eq(system_scanf, s21_function);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
}
END_TEST

START_TEST(test_sscanf_d_num) {
  char format[] = "%1d %2d %3d %4d";
  char str[] = "12345 12345 12345 12345";
  int a1 = 1, a2 = 2, a3 = 3, a4 = 4, b1 = 1, b2 = 2, b3 = 3, b4 = 4;
  int system_scanf = sscanf(str, format, &a1, &a2, &a3, &a4);
  int s21_function = s21_sscanf(str, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(system_scanf, s21_function);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
}
END_TEST

START_TEST(test_sscanf_d_star1) {
  char format[] = "%*d %d";
  char str[] = "12345 67890";
  int a1 = 1, b1 = 1;
  int system_scanf = sscanf(str, format, &a1);
  int s21_function = s21_sscanf(str, format, &b1);
  ck_assert_int_eq(s21_function, system_scanf);
  ck_assert_int_eq(a1, b1);
}
END_TEST

START_TEST(test_sscanf_d_star2) {
  char format[] = "%d %*d";
  char str[] = "12345 67890";
  int a1 = 1, b1 = 1;
  int system_scanf = sscanf(str, format, &a1);
  int s21_function = s21_sscanf(str, format, &b1);
  ck_assert_int_eq(s21_function, system_scanf);
  ck_assert_int_eq(a1, b1);
}
END_TEST

START_TEST(test_sscanf_d_h1) {
  char format[] = "%hd %hd";
  char str[] = "65535 4";
  short int a1 = 1, a2 = 2, b1 = 1, b2 = 2;
  int system_scanf = sscanf(str, format, &a1, &a2);
  int s21_function = s21_sscanf(str, format, &b1, &b2);
  ck_assert_int_eq(system_scanf, s21_function);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
}
END_TEST

START_TEST(test_sscanf_d_h2) {
  char format[] = "%hd %hd";
  char str[] = "65535 4";
  unsigned short int a1 = 1, a2 = 2, b1 = 1, b2 = 2;
  int system_scanf = sscanf(str, format, &a1, &a2);
  int s21_function = s21_sscanf(str, format, &b1, &b2);
  ck_assert_int_eq(system_scanf, s21_function);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
}
END_TEST

START_TEST(test_sscanf_d_l1) {
  char format[] = "%ld %ld %ld %ld";
  char str[] = "-2200000 -32000 32000 2200000";
  long a1 = 1, a2 = 2, a3 = 3, a4 = 4, b1 = 1, b2 = 2, b3 = 3, b4 = 4;
  int system_scanf = sscanf(str, format, &a1, &a2, &a3, &a4);
  int s21_function = s21_sscanf(str, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(system_scanf, s21_function);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
}
END_TEST

START_TEST(test_sscanf_d_l2) {
  char format[] = "%ld %ld %ld %ld";
  char str[] = "-2200000 -32000 32000 2200000";
  unsigned long a1 = 1, a2 = 2, a3 = 3, a4 = 4, b1 = 1, b2 = 2, b3 = 3, b4 = 4;
  int system_scanf = sscanf(str, format, &a1, &a2, &a3, &a4);
  int s21_function = s21_sscanf(str, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(system_scanf, s21_function);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
}
END_TEST

START_TEST(test_sscanf_i_space) {
  char format[] = "%i";
  char str[] = " ";
  int a1 = 1, b1 = 1;
  int system_scanf = sscanf(str, format, &a1);
  int s21_function = s21_sscanf(str, format, &b1);
  ck_assert_int_eq(system_scanf, s21_function);
  ck_assert_int_eq(a1, b1);
}
END_TEST

START_TEST(test_sscanf_i1) {
  char format[] = "%i %i %i %i %i %i";
  char str[] = "-32000 32000 66000 0076400 076400 010610600";
  int a1 = 1, a2 = 2, a3 = 3, a4 = 4, a5 = 5, a6 = 6;
  int b1 = 1, b2 = 2, b3 = 3, b4 = 4, b5 = 5, b6 = 6;
  int system_scanf = sscanf(str, format, &a1, &a2, &a3, &a4, &a5, &a6);
  int s21_function = s21_sscanf(str, format, &b1, &b2, &b3, &b4, &b5, &b6);
  ck_assert_int_eq(system_scanf, s21_function);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(a5, b5);
  ck_assert_int_eq(a6, b6);
}
END_TEST

START_TEST(test_sscanf_i2) {
  char format[] = "%i %i";
  char str[] = "0x2A 4.2";
  int a1 = 1, a2 = 2, b1 = 1, b2 = 2;
  int system_scanf = sscanf(str, format, &a1, &a2);
  int s21_function = s21_sscanf(str, format, &b1, &b2);
  ck_assert_int_eq(system_scanf, s21_function);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
}
END_TEST

START_TEST(test_sscanf_i3) {
  char format[] = "%i %i";
  char str[] = "2e-3 33";
  int a1 = 1, b1 = 1;
  int system_scanf = sscanf(str, format, &a1);
  int s21_function = s21_sscanf(str, format, &b1);
  ck_assert_int_eq(system_scanf, s21_function);
  ck_assert_int_eq(a1, b1);
}
END_TEST

START_TEST(test_sscanf_i_num1) {
  char format[] = "%4i %1i";
  char str[] = "0x2A 42";
  int a1 = 1, a2 = 2, b1 = 1, b2 = 2;
  int system_scanf = sscanf(str, format, &a1, &a2);
  int s21_function = s21_sscanf(str, format, &b1, &b2);
  ck_assert_int_eq(system_scanf, s21_function);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
}
END_TEST

START_TEST(test_sscanf_i_num3) {
  char format[] = "%2i %8i";
  char str[] = "12 0x2F";
  int a1 = 1, a2 = 2, b1 = 1, b2 = 2;
  int system_scanf = sscanf(str, format, &a1, &a2);
  int s21_function = s21_sscanf(str, format, &b1, &b2);
  ck_assert_int_eq(system_scanf, s21_function);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
}
END_TEST

START_TEST(test_sscanf_i_star1) {
  char format[] = "%2i %*i";
  char str[] = "12 0x2F";
  int a1 = 1, b1 = 1;
  int system_scanf = sscanf(str, format, &a1);
  int s21_function = s21_sscanf(str, format, &b1);
  ck_assert_int_eq(s21_function, system_scanf);
  ck_assert_int_eq(a1, b1);
}
END_TEST

START_TEST(test_sscanf_i_star2) {
  char format[] = "%*i %8i";
  char str[] = "12 0x2F";
  int a1 = 1, b1 = 1;
  int system_scanf = sscanf(str, format, &a1);
  int s21_function = s21_sscanf(str, format, &b1);
  ck_assert_int_eq(s21_function, system_scanf);
  ck_assert_int_eq(a1, b1);
}
END_TEST

START_TEST(test_sscanf_i_h1) {
  char format[] = "%hi %hi %hi %hi";
  char str[] = "32000 66000 076400 0200720";
  short int a1 = 1, a2 = 2, a3 = 3, a4 = 4;
  short int b1 = 1, b2 = 2, b3 = 3, b4 = 4;
  int system_scanf = sscanf(str, format, &a1, &a2, &a3, &a4);
  int s21_function = s21_sscanf(str, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(system_scanf, s21_function);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
}
END_TEST

START_TEST(test_sscanf_i_h2) {
  char format[] = "%hi %hi %hi %hi";
  char str[] = "32000 66000 076400 0200720";
  unsigned short int a1 = 1, a2 = 2, a3 = 3, a4 = 4;
  unsigned short int b1 = 1, b2 = 2, b3 = 3, b4 = 4;
  int system_scanf = sscanf(str, format, &a1, &a2, &a3, &a4);
  int s21_function = s21_sscanf(str, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(system_scanf, s21_function);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
}
END_TEST

START_TEST(test_sscanf_i_l1) {
  char format[] = "%li %li %li %li %li %li";
  char str[] = "-32000 32000 66000 0076400 076400 010610600";
  long a1 = 1, a2 = 2, a3 = 3, a4 = 4, a5 = 5, a6 = 6;
  long b1 = 1, b2 = 2, b3 = 3, b4 = 4, b5 = 5, b6 = 6;
  int system_scanf = sscanf(str, format, &a1, &a2, &a3, &a4, &a5, &a6);
  int s21_function = s21_sscanf(str, format, &b1, &b2, &b3, &b4, &b5, &b6);
  ck_assert_int_eq(system_scanf, s21_function);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(a5, b5);
  ck_assert_int_eq(a6, b6);
}
END_TEST

START_TEST(test_sscanf_i_l2) {
  char format[] = "%li %li %li %li %li %li";
  char str[] = "-32000 32000 66000 0076400 076400 010610600";
  unsigned long a1 = 1, a2 = 2, a3 = 3, a4 = 4, a5 = 5, a6 = 6;
  unsigned long b1 = 1, b2 = 2, b3 = 3, b4 = 4, b5 = 5, b6 = 6;
  int system_scanf = sscanf(str, format, &a1, &a2, &a3, &a4, &a5, &a6);
  int s21_function = s21_sscanf(str, format, &b1, &b2, &b3, &b4, &b5, &b6);
  ck_assert_int_eq(system_scanf, s21_function);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(a5, b5);
  ck_assert_int_eq(a6, b6);
}
END_TEST

START_TEST(test_sscanf_i_l_h_hex1) {
  char format[] = "%li %li %hi %hi";
  char str[] = "0xA 0x7FFFFFFFF 0xE 0x7FFF";
  long a1 = 1, a2 = 2, b1 = 1, b2 = 2;
  short int a3 = 3, a4 = 4, b3 = 3, b4 = 4;
  int system_scanf = sscanf(str, format, &a1, &a2, &a3, &a4);
  int s21_function = s21_sscanf(str, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(system_scanf, s21_function);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
}
END_TEST

START_TEST(test_sscanf_i_l_h_hex2) {
  char format[] = "%li %li %hi %hi";
  char str[] = "0xA 0x7FFFFFFFF 0xE 0x7FFF";
  unsigned long a1 = 1, a2 = 2, b1 = 1, b2 = 2;
  unsigned short int a3 = 3, a4 = 4, b3 = 3, b4 = 4;
  int system_scanf = sscanf(str, format, &a1, &a2, &a3, &a4);
  int s21_function = s21_sscanf(str, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(system_scanf, s21_function);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
}
END_TEST

START_TEST(test_sscanf_e_E) {
  char format[] = "%e %E";
  char str[] = "12.6e-3 0.2897992";
  float a1 = 1., a2 = 2., b1 = 1., b2 = 2.;
  int system_scanf = sscanf(str, format, &a1, &a2);
  int s21_function = s21_sscanf(str, format, &b1, &b2);
  ck_assert_int_eq(system_scanf, s21_function);
  ck_assert_float_eq(a1, b1);
  ck_assert_float_eq(a2, b2);
}
END_TEST

START_TEST(test_sscanf_e_E_num) {
  char format[] = "%3e %5E";
  char str[] = "12.005 0.2897992";
  float a1 = 1., a2 = 2., b1 = 1., b2 = 2.;
  int system_scanf = sscanf(str, format, &a1, &a2);
  int s21_function = s21_sscanf(str, format, &b1, &b2);
  ck_assert_int_eq(system_scanf, s21_function);
  ck_assert_float_eq(a1, b1);
  ck_assert_float_eq(a2, b2);
}
END_TEST

START_TEST(test_sscanf_e_E_star1) {
  char format[] = "%*e %e";
  char str[] = "12.005 0.2897992";
  float a1 = 1., b1 = 1.;
  int system_scanf = sscanf(str, format, &a1);
  int s21_function = s21_sscanf(str, format, &b1);
  ck_assert_int_eq(s21_function, system_scanf);
  ck_assert_float_eq(a1, b1);
}
END_TEST

START_TEST(test_sscanf_e_E_star2) {
  char format[] = "%e %*e";
  char str[] = "12.1 0.2897992";
  float a1 = 1., b1 = 1.;
  int system_scanf = sscanf(str, format, &a1);
  int s21_function = s21_sscanf(str, format, &b1);
  ck_assert_int_eq(s21_function, system_scanf);
  ck_assert_float_eq(a1, b1);
}
END_TEST

START_TEST(test_sscanf_e_E_L) {
  char format[] = "%Le %Le";
  char str[] = "12.006 0.2897992";
  long double a1 = 1., a2 = 2., b1 = 1., b2 = 2.;
  int system_scanf = sscanf(str, format, &a1, &a2);
  int s21_function = s21_sscanf(str, format, &b1, &b2);
  ck_assert_int_eq(system_scanf, s21_function);
  ck_assert_double_eq(a1, b1);
  ck_assert_double_eq(a2, b2);
}
END_TEST

START_TEST(test_sscanf_f) {
  char format[] = "%f %f";
  char str[] = "12.005 0.2897992";
  float a1 = 1., a2 = 2., b1 = 1., b2 = 2.;
  int system_scanf = sscanf(str, format, &a1, &a2);
  int s21_function = s21_sscanf(str, format, &b1, &b2);
  ck_assert_int_eq(system_scanf, s21_function);
  ck_assert_float_eq(a1, b1);
  ck_assert_float_eq(a2, b2);
}
END_TEST

START_TEST(test_sscanf_f_num) {
  char format[] = "%5f %9f";
  char str[] = "12.005 0.289090392992";
  float a1 = 1., a2 = 2., b1 = 1., b2 = 2.;
  int system_scanf = sscanf(str, format, &a1, &a2);
  int s21_function = s21_sscanf(str, format, &b1, &b2);
  ck_assert_int_eq(system_scanf, s21_function);
  ck_assert_float_eq(a1, b1);
  ck_assert_float_eq(a2, b2);
}
END_TEST

START_TEST(test_sscanf_f_star1) {
  char format[] = "%f %*f";
  char str[] = "12.005 0.2897992";
  float a1 = 1., b1 = 1.;
  int system_scanf = sscanf(str, format, &a1);
  int s21_function = s21_sscanf(str, format, &b1);
  ck_assert_int_eq(s21_function, system_scanf);
  ck_assert_float_eq(a1, b1);
}
END_TEST

START_TEST(test_sscanf_f_star2) {
  char format[] = "%*f %f";
  char str[] = "12.005 0.2897992";
  float a1 = 1., b1 = 1.;
  int system_scanf = sscanf(str, format, &a1);
  int s21_function = s21_sscanf(str, format, &b1);
  ck_assert_int_eq(s21_function, system_scanf);
  ck_assert_float_eq(a1, b1);
}
END_TEST

START_TEST(test_sscanf_f_L) {
  char format[] = "%Lf %Lf";
  char str[] = "12.006 0.2897992";
  long double a1 = 1., a2 = 2., b1 = 1., b2 = 2.;
  int system_scanf = sscanf(str, format, &a1, &a2);
  int s21_function = s21_sscanf(str, format, &b1, &b2);
  ck_assert_int_eq(system_scanf, s21_function);
  ck_assert_double_eq(a1, b1);
  ck_assert_double_eq(a2, b2);
}
END_TEST

START_TEST(test_sscanf_g_G) {
  char format[] = "%g %G";
  char str[] = "0.3897992e-22 0.2897992E-22";
  float a1 = 1., a2 = 2., b1 = 1., b2 = 2.;
  int system_scanf = sscanf(str, format, &a1, &a2);
  int s21_function = s21_sscanf(str, format, &b1, &b2);
  ck_assert_int_eq(system_scanf, s21_function);
  ck_assert_float_eq(a1, b1);
  ck_assert_float_eq(a2, b2);
}
END_TEST

START_TEST(test_sscanf_g_G_num) {
  char format[] = "%3g %3G";
  char str[] = "0.3897992e-22 0.2897992E-22";
  float a1 = 1., a2 = 2., b1 = 1., b2 = 2.;
  int system_scanf = sscanf(str, format, &a1, &a2);
  int s21_function = s21_sscanf(str, format, &b1, &b2);
  ck_assert_int_eq(system_scanf, s21_function);
  ck_assert_float_eq(a1, b1);
  ck_assert_float_eq(a2, b2);
}
END_TEST

START_TEST(test_sscanf_g_G_star1) {
  char format[] = "%g %*G";
  char str[] = "0.3897992e-22 0.2897992E-22";
  float a1 = 1., b1 = 1.;
  int system_scanf = sscanf(str, format, &a1);
  int s21_function = s21_sscanf(str, format, &b1);
  ck_assert_int_eq(s21_function, system_scanf);
  ck_assert_float_eq(a1, b1);
}
END_TEST

START_TEST(test_sscanf_g_G_star2) {
  char format[] = "%*g %G";
  char str[] = "0.3897992e-22 0.2897992E-22";
  float a1 = 1., b1 = 1.;
  int system_scanf = sscanf(str, format, &a1);
  int s21_function = s21_sscanf(str, format, &b1);
  ck_assert_int_eq(s21_function, system_scanf);
  ck_assert_float_eq(a1, b1);
}
END_TEST

START_TEST(test_sscanf_g_G_L) {
  char format[] = "%Lg %LG";
  char str[] = "0.3897992e-22 0.2897992E-22";
  long double a1 = 1., a2 = 2., b1 = 1., b2 = 2.;
  int system_scanf = sscanf(str, format, &a1, &a2);
  int s21_function = s21_sscanf(str, format, &b1, &b2);
  ck_assert_int_eq(system_scanf, s21_function);
  ck_assert_double_eq(a1, b1);
  ck_assert_double_eq(a2, b2);
}
END_TEST

START_TEST(test_sscanf_o1) {
  char format[] = "%o %o";
  char str[] = "133 138";
  int a1 = 1, a2 = 2, b1 = 1, b2 = 2;
  int system_scanf = sscanf(str, format, &a1, &a2);
  int s21_function = s21_sscanf(str, format, &b1, &b2);
  ck_assert_int_eq(system_scanf, s21_function);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
}
END_TEST

START_TEST(test_sscanf_o2) {
  char format[] = "%o %o";
  char str[] = "777 133";
  int a1 = 1, a2 = 2, b1 = 1, b2 = 2;
  int system_scanf = sscanf(str, format, &a1, &a2);
  int s21_function = s21_sscanf(str, format, &b1, &b2);
  ck_assert_int_eq(system_scanf, s21_function);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
}
END_TEST

START_TEST(test_sscanf_o_num1) {
  char format[] = "%3o %2o";
  char str[] = "1364 13373";
  int a1 = 1, a2 = 2, b1 = 1, b2 = 2;
  int system_scanf = sscanf(str, format, &a1, &a2);
  int s21_function = s21_sscanf(str, format, &b1, &b2);
  ck_assert_int_eq(system_scanf, s21_function);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
}
END_TEST

START_TEST(test_sscanf_o_num2) {
  char format[] = "%o %2o";
  char str[] = "1364 13373";
  int a1 = 1, a2 = 2, b1 = 1, b2 = 2;
  int system_scanf = sscanf(str, format, &a1, &a2);
  int s21_function = s21_sscanf(str, format, &b1, &b2);
  ck_assert_int_eq(system_scanf, s21_function);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
}
END_TEST

START_TEST(test_sscanf_o_num3) {
  char format[] = "%2o %o";
  char str[] = "1364 13373";
  int a1 = 1, a2 = 2, b1 = 1, b2 = 2;
  int system_scanf = sscanf(str, format, &a1, &a2);
  int s21_function = s21_sscanf(str, format, &b1, &b2);
  ck_assert_int_eq(system_scanf, s21_function);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
}
END_TEST

START_TEST(test_sscanf_o_star1) {
  char format[] = "%*o %o";
  char str[] = "1364 13373";
  unsigned int a1 = 1, b1 = 1;
  int system_scanf = sscanf(str, format, &a1);
  int s21_function = s21_sscanf(str, format, &b1);
  ck_assert_int_eq(s21_function, system_scanf);
  ck_assert_int_eq(a1, b1);
}
END_TEST

START_TEST(test_sscanf_o_star2) {
  char format[] = "%o %*o";
  char str[] = "1364 13373";
  unsigned int a1 = 1, b1 = 1;
  int system_scanf = sscanf(str, format, &a1);
  int s21_function = s21_sscanf(str, format, &b1);
  ck_assert_int_eq(s21_function, system_scanf);
  ck_assert_int_eq(a1, b1);
}
END_TEST

START_TEST(test_sscanf_o_h1) {
  char format[] = "%ho %ho %ho";
  char str[] = "-177777 177777 277777";
  short int a1 = 1, a2 = 2, a3 = 3, b1 = 1, b2 = 2, b3 = 3;
  int system_scanf = sscanf(str, format, &a1, &a2, &a3);
  int s21_function = s21_sscanf(str, format, &b1, &b2, &b3);
  ck_assert_int_eq(system_scanf, s21_function);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
}
END_TEST

START_TEST(test_sscanf_o_h2) {
  char format[] = "%ho %ho %ho";
  char str[] = "-177777 177777 277777";
  unsigned short int a1 = 1, a2 = 2, a3 = 3, b1 = 1, b2 = 2, b3 = 3;
  int system_scanf = sscanf(str, format, &a1, &a2, &a3);
  int s21_function = s21_sscanf(str, format, &b1, &b2, &b3);
  ck_assert_int_eq(system_scanf, s21_function);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
}
END_TEST

START_TEST(test_sscanf_o_l1) {
  char format[] = "%lo %lo %lo";
  char str[] = "-177777 177777 277777";
  long a1 = 1, a2 = 2, a3 = 3, b1 = 1, b2 = 2, b3 = 3;
  int system_scanf = sscanf(str, format, &a1, &a2, &a3);
  int s21_function = s21_sscanf(str, format, &b1, &b2, &b3);
  ck_assert_int_eq(system_scanf, s21_function);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
}
END_TEST

START_TEST(test_sscanf_o_l2) {
  char format[] = "%lo %lo %lo";
  char str[] = "-177777 177777 277777";
  unsigned long a1 = 1, a2 = 2, a3 = 3, b1 = 1, b2 = 2, b3 = 3;
  int system_scanf = sscanf(str, format, &a1, &a2, &a3);
  int s21_function = s21_sscanf(str, format, &b1, &b2, &b3);
  ck_assert_int_eq(system_scanf, s21_function);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
}
END_TEST

START_TEST(test_sscanf_s_space) {
  char format[] = "%s";
  char str[] = "";
  char a1[100] = "", b1[100] = "";
  int system_scanf = sscanf(str, format, a1);
  int s21_function = s21_sscanf(str, format, b1);
  ck_assert_int_eq(system_scanf, s21_function);
  ck_assert_str_eq(a1, b1);
}
END_TEST

START_TEST(test_sscanf_s_zero1) {
  char format[] = "%s";
  char str[] = "\0";
  char a1[100] = "", b1[100] = "";
  int system_scanf = sscanf(str, format, a1);
  int s21_function = s21_sscanf(str, format, b1);
  ck_assert_int_eq(system_scanf, s21_function);
  ck_assert_str_eq(a1, b1);
}
END_TEST

START_TEST(test_sscanf_s_zero2) {
  char format[] = "%s";
  char str[] = "Hel\0p me";
  char a1[100] = "", a2[100] = "", b1[100] = "", b2[100] = "";
  int system_scanf = sscanf(str, format, a1, a2);
  int s21_function = s21_sscanf(str, format, b1, b2);
  ck_assert_int_eq(system_scanf, s21_function);
  ck_assert_str_eq(a1, b1);
  ck_assert_str_eq(a2, b2);
}
END_TEST

START_TEST(test_sscanf_s) {
  char format[] = "%s %s";
  char str[] = "Help me";
  char a1[100] = "", a2[100] = "", b1[100] = "", b2[100] = "";
  int system_scanf = sscanf(str, format, a1, a2);
  int s21_function = s21_sscanf(str, format, b1, b2);
  ck_assert_int_eq(system_scanf, s21_function);
  ck_assert_str_eq(a1, b1);
  ck_assert_str_eq(a2, b2);
}
END_TEST

START_TEST(test_sscanf_s_num1) {
  char format[] = "%2s %s";
  char str[] = "Help me";
  char a1[100] = "", a2[100] = "", b1[100] = "", b2[100] = "";
  int system_scanf = sscanf(str, format, a1, a2);
  int s21_function = s21_sscanf(str, format, b1, b2);
  ck_assert_int_eq(system_scanf, s21_function);
  ck_assert_str_eq(a1, b1);
  ck_assert_str_eq(a2, b2);
}
END_TEST

START_TEST(test_sscanf_s_num2) {
  char format[] = "%s %1s";
  char str[] = "Help me";
  char a1[100] = "", a2[100] = "", b1[100] = "", b2[100] = "";
  int system_scanf = sscanf(str, format, a1, a2);
  int s21_function = s21_sscanf(str, format, b1, b2);
  ck_assert_int_eq(system_scanf, s21_function);
  ck_assert_str_eq(a1, b1);
  ck_assert_str_eq(a2, b2);
}
END_TEST

START_TEST(test_sscanf_s_num3) {
  char format[] = "%10s %s";
  char str[] = "Help me";
  char a1[100] = "", a2[100] = "", b1[100] = "", b2[100] = "";
  int system_scanf = sscanf(str, format, a1, a2);
  int s21_function = s21_sscanf(str, format, b1, b2);
  ck_assert_int_eq(system_scanf, s21_function);
  ck_assert_str_eq(a1, b1);
  ck_assert_str_eq(a2, b2);
}
END_TEST

START_TEST(test_sscanf_s_star1) {
  char format[] = "%*s %s";
  char str[] = "Help me";
  char a1[100] = "", a2[100] = "", b1[100] = "", b2[100] = "";
  int system_scanf = sscanf(str, format, a1, a2);
  int s21_function = s21_sscanf(str, format, b1, b2);
  ck_assert_int_eq(system_scanf, s21_function);
  ck_assert_str_eq(a1, b1);
  ck_assert_str_eq(a2, b2);
}
END_TEST

START_TEST(test_sscanf_s_star2) {
  char format[] = "%s %*s";
  char str[] = "Help me";
  char a1[100] = "", a2[100] = "", b1[100] = "", b2[100] = "";
  int system_scanf = sscanf(str, format, a1, a2);
  int s21_function = s21_sscanf(str, format, b1, b2);
  ck_assert_int_eq(system_scanf, s21_function);
  ck_assert_str_eq(a1, b1);
  ck_assert_str_eq(a2, b2);
}
END_TEST

START_TEST(test_sscanf_u_space) {
  char format[] = "%u";
  char str[] = "";
  char a1, b1;
  int system_scanf = sscanf(str, format, &a1);
  int s21_function = s21_sscanf(str, format, &b1);
  ck_assert_int_eq(system_scanf, s21_function);  //-1
  ck_assert_int_eq(a1, b1);
}
END_TEST

START_TEST(test_sscanf_u) {
  char format[] = "%u %u %u";
  char str[] = "-11 11 4294967295";
  int a1 = 1, a2 = 2, a3 = 3, b1 = 1, b2 = 2, b3 = 3;
  int system_scanf = sscanf(str, format, &a1, &a2, &a3);
  int s21_function = s21_sscanf(str, format, &b1, &b2, &b3);
  ck_assert_int_eq(system_scanf, s21_function);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
}
END_TEST

START_TEST(test_sscanf_u_num1) {
  char format[] = "%2u %3u %5u";
  char str[] = "11111 22222 4294967295";
  int a1 = 1, a2 = 2, a3 = 3, b1 = 1, b2 = 2, b3 = 3;
  int system_scanf = sscanf(str, format, &a1, &a2, &a3);
  int s21_function = s21_sscanf(str, format, &b1, &b2, &b3);
  ck_assert_int_eq(system_scanf, s21_function);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
}
END_TEST

START_TEST(test_sscanf_u_num2) {
  char format[] = "%5u %3u %5u";
  char str[] = "11111 22222 4294967295";
  int a1 = 1, a2 = 2, a3 = 3, b1 = 1, b2 = 2, b3 = 3;
  int system_scanf = sscanf(str, format, &a1, &a2, &a3);
  int s21_function = s21_sscanf(str, format, &b1, &b2, &b3);
  ck_assert_int_eq(system_scanf, s21_function);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
}
END_TEST

START_TEST(test_sscanf_u_star1) {
  char format[] = "%*u %u";
  char str[] = "11111 22222";
  int a1 = 1, b1 = 1;
  int system_scanf = sscanf(str, format, &a1);
  int s21_function = s21_sscanf(str, format, &b1);
  ck_assert_int_eq(s21_function, system_scanf);
  ck_assert_int_eq(a1, b1);
}
END_TEST

START_TEST(test_sscanf_u_star2) {
  char format[] = "%u %*u";
  char str[] = "11111 22222";
  int a1 = 1, b1 = 1;
  int system_scanf = sscanf(str, format, &a1);
  int s21_function = s21_sscanf(str, format, &b1);
  ck_assert_int_eq(s21_function, system_scanf);
  ck_assert_int_eq(a1, b1);
}
END_TEST

START_TEST(test_sscanf_u_h1) {
  char format[] = "%hu %hu %hu";
  char str[] = "101 11 65535";
  short int a1 = 1, a2 = 2, a3 = 3, b1 = 1, b2 = 2, b3 = 3;
  int system_scanf = sscanf(str, format, &a1, &a2, &a3);
  int s21_function = s21_sscanf(str, format, &b1, &b2, &b3);
  ck_assert_uint_eq(system_scanf, s21_function);
  ck_assert_int_eq(a1, b1);
  ck_assert_uint_eq(a2, b2);
  ck_assert_uint_eq(a3, b3);
}
END_TEST

START_TEST(test_sscanf_u_h2) {
  char format[] = "%hu %hu %hu";
  char str[] = "101 11 65535";
  unsigned short int a1 = 1, a2 = 2, a3 = 3, b1 = 1, b2 = 2, b3 = 3;
  int system_scanf = sscanf(str, format, &a1, &a2, &a3);
  int s21_function = s21_sscanf(str, format, &b1, &b2, &b3);
  ck_assert_uint_eq(system_scanf, s21_function);
  ck_assert_int_eq(a1, b1);
  ck_assert_uint_eq(a2, b2);
  ck_assert_uint_eq(a3, b3);
}
END_TEST

START_TEST(test_sscanf_u_l1) {
  char format[] = "%lu %lu %lu";
  char str[] = "101 11 18446744073709551615";
  long a1 = 1, a2 = 2, a3 = 3, b1 = 1, b2 = 2, b3 = 3;
  int system_scanf = sscanf(str, format, &a1, &a2, &a3);
  int s21_function = s21_sscanf(str, format, &b1, &b2, &b3);
  ck_assert_int_eq(system_scanf, s21_function);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
}
END_TEST

START_TEST(test_sscanf_u_l2) {
  char format[] = "%lu %lu %lu";
  char str[] = "101 11 18446744073709551615";
  unsigned long a1 = 1, a2 = 2, a3 = 3, b1 = 1, b2 = 2, b3 = 3;
  int system_scanf = sscanf(str, format, &a1, &a2, &a3);
  int s21_function = s21_sscanf(str, format, &b1, &b2, &b3);
  ck_assert_int_eq(system_scanf, s21_function);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
}
END_TEST

START_TEST(test_sscanf_x_X) {
  char format[] = "%x %X";
  char str[] = "3B 3B";
  int a1 = 1, a2 = 2, b1 = 1, b2 = 2;
  int system_scanf = sscanf(str, format, &a1, &a2);
  int s21_function = s21_sscanf(str, format, &b1, &b2);
  ck_assert_int_eq(system_scanf, s21_function);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
}
END_TEST

START_TEST(test_sscanf_x_X_num1) {
  char format[] = "%1x %2X";
  char str[] = "3B 3B";
  int a1 = 1, a2 = 2, b1 = 1, b2 = 2;
  int system_scanf = sscanf(str, format, &a1, &a2);
  int s21_function = s21_sscanf(str, format, &b1, &b2);
  ck_assert_int_eq(system_scanf, s21_function);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
}
END_TEST

START_TEST(test_sscanf_x_X_num2) {
  char format[] = "%2x %1X";
  char str[] = "3B 3B";
  int a1 = 1, a2 = 2, b1 = 1, b2 = 2;
  int system_scanf = sscanf(str, format, &a1, &a2);
  int s21_function = s21_sscanf(str, format, &b1, &b2);
  ck_assert_int_eq(system_scanf, s21_function);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
}
END_TEST

START_TEST(test_sscanf_x_X_star1) {
  char format[] = "%*x %X";
  char str[] = "3b 4B";
  int a1 = 1, b1 = 1;
  int system_scanf = sscanf(str, format, &a1);
  int s21_function = s21_sscanf(str, format, &b1);
  ck_assert_int_eq(s21_function, system_scanf);
  ck_assert_int_eq(a1, b1);
}
END_TEST

START_TEST(test_sscanf_x_X_star2) {
  char format[] = "%x %*X";
  char str[] = "3b 4B";
  int a1 = 1, b1 = 1;
  int system_scanf = sscanf(str, format, &a1);
  int s21_function = s21_sscanf(str, format, &b1);
  ck_assert_int_eq(s21_function, system_scanf);
  ck_assert_int_eq(a1, b1);
}
END_TEST

START_TEST(test_sscanf_x_X_h1) {
  char format[] = "%hx %hX";
  char str[] = "3B 4B";
  short int a1 = 1, a2 = 2, b1 = 1, b2 = 2;
  int system_scanf = sscanf(str, format, &a1, &a2);
  int s21_function = s21_sscanf(str, format, &b1, &b2);
  ck_assert_int_eq(system_scanf, s21_function);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
}
END_TEST

START_TEST(test_sscanf_x_X_h2) {
  char format[] = "%hx %hX";
  char str[] = "3B 4B";
  unsigned short int a1 = 1, a2 = 2, b1 = 1, b2 = 2;
  int system_scanf = sscanf(str, format, &a1, &a2);
  int s21_function = s21_sscanf(str, format, &b1, &b2);
  ck_assert_int_eq(system_scanf, s21_function);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
}
END_TEST

START_TEST(test_sscanf_x_X_l1) {
  char format[] = "%lx %lX";
  char str[] = "3B 4B";
  long a1 = 1, a2 = 2, b1 = 1, b2 = 2;
  int system_scanf = sscanf(str, format, &a1, &a2);
  int s21_function = s21_sscanf(str, format, &b1, &b2);
  ck_assert_int_eq(system_scanf, s21_function);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
}
END_TEST

START_TEST(test_sscanf_x_X_l2) {
  char format[] = "%lx %lX";
  char str[] = "3B 4B";
  unsigned long a1 = 1, a2 = 2, b1 = 1, b2 = 2;
  int system_scanf = sscanf(str, format, &a1, &a2);
  int s21_function = s21_sscanf(str, format, &b1, &b2);
  ck_assert_int_eq(system_scanf, s21_function);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
}
END_TEST

START_TEST(test_sscanf_p) {
  const char *input = "Address: 0x7ffeeefb8a2c";
  void *ptr = s21_NULL;
  sscanf(input, "Address: %p", &ptr);
  ck_assert_ptr_ne(ptr, s21_NULL);
}
END_TEST

START_TEST(test_sscanf_n) {
  char format[] = "%d %n %n %n";
  char str[] = "12 123 1234 12345";
  int o1, o2, o3, o4, s1, s2, s3, s4;
  int system_sscanf = sscanf(str, format, &o1, &o2, &o3, &o4);
  int s21_function = s21_sscanf(str, format, &s1, &s2, &s3, &s4);
  ck_assert_int_eq(system_sscanf, s21_function);
  ck_assert_int_eq(o1, s1);
  ck_assert_int_eq(o2, s2);
  ck_assert_int_eq(o3, s3);
  ck_assert_int_eq(o4, s4);
}
END_TEST

START_TEST(test_sscanf_percent) {
  char format[] = "%s";
  char str[] = "Yes 100% right!";
  char a1[100] = "", b1[100] = "";
  int system_scanf = sscanf(str, format, &a1);
  int s21_function = s21_sscanf(str, format, &b1);
  ck_assert_int_eq(s21_function, system_scanf);
  ck_assert_str_eq(a1, b1);
}
END_TEST

Suite *test_sscanf(void) {
  Suite *s = suite_create("\x1b[93;105m sscanf \x1b[0;0m");

  TCase *tc = tcase_create("tc_sscanf");

  suite_add_tcase(s, tc);

  tcase_add_test(tc, test_sscanf_c_space);
  tcase_add_test(tc, test_sscanf_c);
  tcase_add_test(tc, test_sscanf_c_star1);
  tcase_add_test(tc, test_sscanf_c_star2);
  tcase_add_test(tc, test_sscanf_d_space);
  tcase_add_test(tc, test_sscanf_d);
  tcase_add_test(tc, test_sscanf_d_num);
  tcase_add_test(tc, test_sscanf_d_star1);
  tcase_add_test(tc, test_sscanf_d_star2);
  tcase_add_test(tc, test_sscanf_d_h1);
  tcase_add_test(tc, test_sscanf_d_h2);
  tcase_add_test(tc, test_sscanf_d_l1);
  tcase_add_test(tc, test_sscanf_d_l2);
  tcase_add_test(tc, test_sscanf_i_space);
  tcase_add_test(tc, test_sscanf_i1);
  tcase_add_test(tc, test_sscanf_i2);
  tcase_add_test(tc, test_sscanf_i3);
  tcase_add_test(tc, test_sscanf_i_num1);
  tcase_add_test(tc, test_sscanf_i_num3);
  tcase_add_test(tc, test_sscanf_i_star1);
  tcase_add_test(tc, test_sscanf_i_star2);
  tcase_add_test(tc, test_sscanf_i_h1);
  tcase_add_test(tc, test_sscanf_i_h2);
  tcase_add_test(tc, test_sscanf_i_l1);
  tcase_add_test(tc, test_sscanf_i_l2);
  tcase_add_test(tc, test_sscanf_i_l_h_hex1);
  tcase_add_test(tc, test_sscanf_i_l_h_hex2);
  tcase_add_test(tc, test_sscanf_e_E);
  tcase_add_test(tc, test_sscanf_e_E_num);
  tcase_add_test(tc, test_sscanf_e_E_star1);
  tcase_add_test(tc, test_sscanf_e_E_star2);
  tcase_add_test(tc, test_sscanf_e_E_L);
  tcase_add_test(tc, test_sscanf_f);
  tcase_add_test(tc, test_sscanf_f_num);
  tcase_add_test(tc, test_sscanf_f_star1);
  tcase_add_test(tc, test_sscanf_f_star2);
  tcase_add_test(tc, test_sscanf_f_L);
  tcase_add_test(tc, test_sscanf_g_G);
  tcase_add_test(tc, test_sscanf_g_G_num);
  tcase_add_test(tc, test_sscanf_g_G_star1);
  tcase_add_test(tc, test_sscanf_g_G_star2);
  tcase_add_test(tc, test_sscanf_g_G_L);
  tcase_add_test(tc, test_sscanf_o1);
  tcase_add_test(tc, test_sscanf_o2);
  tcase_add_test(tc, test_sscanf_o_num1);
  tcase_add_test(tc, test_sscanf_o_num2);
  tcase_add_test(tc, test_sscanf_o_num3);
  tcase_add_test(tc, test_sscanf_o_star1);
  tcase_add_test(tc, test_sscanf_o_star2);
  tcase_add_test(tc, test_sscanf_o_h1);
  tcase_add_test(tc, test_sscanf_o_h2);
  tcase_add_test(tc, test_sscanf_o_l1);
  tcase_add_test(tc, test_sscanf_o_l2);
  tcase_add_test(tc, test_sscanf_s_space);
  tcase_add_test(tc, test_sscanf_s_zero1);
  tcase_add_test(tc, test_sscanf_s_zero2);
  tcase_add_test(tc, test_sscanf_s);
  tcase_add_test(tc, test_sscanf_s_num1);
  tcase_add_test(tc, test_sscanf_s_num2);
  tcase_add_test(tc, test_sscanf_s_num3);
  tcase_add_test(tc, test_sscanf_s_star1);
  tcase_add_test(tc, test_sscanf_s_star2);
  // tcase_add_test(tc, test_sscanf_s_l);
  tcase_add_test(tc, test_sscanf_u_space);
  tcase_add_test(tc, test_sscanf_u);
  tcase_add_test(tc, test_sscanf_u_num1);
  tcase_add_test(tc, test_sscanf_u_num2);
  tcase_add_test(tc, test_sscanf_u_star1);
  tcase_add_test(tc, test_sscanf_u_star2);
  tcase_add_test(tc, test_sscanf_u_h1);
  tcase_add_test(tc, test_sscanf_u_h2);
  tcase_add_test(tc, test_sscanf_u_l1);
  tcase_add_test(tc, test_sscanf_u_l2);
  tcase_add_test(tc, test_sscanf_x_X);
  tcase_add_test(tc, test_sscanf_x_X_num1);
  tcase_add_test(tc, test_sscanf_x_X_num2);
  tcase_add_test(tc, test_sscanf_x_X_star1);
  tcase_add_test(tc, test_sscanf_x_X_star2);
  tcase_add_test(tc, test_sscanf_x_X_h1);
  tcase_add_test(tc, test_sscanf_x_X_h2);
  tcase_add_test(tc, test_sscanf_x_X_l1);
  tcase_add_test(tc, test_sscanf_x_X_l2);
  tcase_add_test(tc, test_sscanf_p);
  tcase_add_test(tc, test_sscanf_n);
  tcase_add_test(tc, test_sscanf_percent);

  return s;
}