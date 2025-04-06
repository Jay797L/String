#ifndef S21_SSPF
#define S21_SSPF

#define S21_UPPERMODE 0
#define S21_LOWERMODE 1

#include <stdlib.h>

#include "s21_string.h"

char *getModifiedText(const char *str, int mode);
char getModificationChar(const char ch, int mode);

#endif