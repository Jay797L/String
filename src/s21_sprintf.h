#ifndef S21_SPRINTF
#define S21_SPRINTF

#include <math.h>
#include <stdarg.h>
#include <stdlib.h>

#include "s21_string.h"

typedef struct specProtSprintf {
  char flag;
  int width;
  int precision;
  char length;
  char specifier;
  int sign;
} s21_specifierPrototypeSprintf;

s21_specifierPrototypeSprintf *getSpecifierPrototypeSprintf(
    const char *format, s21_size_t *currentIndex);
s21_size_t getWidthFormatSprintf(const char *format, s21_size_t *currentIndex);
int getPrecisionFormat(const char *format, s21_size_t *currentIndex);
int getDefaultValueOfPrecision(s21_specifierPrototypeSprintf prot);
char *applyPrecision(char *str, s21_specifierPrototypeSprintf prot,
                     s21_size_t lenStr);
char *applyFlags(char *str, s21_specifierPrototypeSprintf prot,
                 s21_size_t lenStr);
char *applyWidth(char *str, s21_specifierPrototypeSprintf prot,
                 s21_size_t lenStr);
char *getStr(s21_specifierPrototypeSprintf *prot, va_list nextParam);

char *doubleToString(s21_specifierPrototypeSprintf *prot, double value);
char *longIntToString(s21_specifierPrototypeSprintf *prot, long long int value);
void expandString(char *first, char *last);
void *s21_realloc(void *src, s21_size_t size);

#endif
