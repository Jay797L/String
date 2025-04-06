#include "s21_sprintf.h"

int s21_sprintf(char *str, const char *format, ...) {
  s21_size_t offsetFormat = 0;
  s21_size_t offsetStr = 0;
  s21_size_t lenFormat = 0;
  lenFormat=s21_strlen(format);

  va_list nextParam;
  va_start(nextParam, format);
  for (; offsetFormat < lenFormat;) {
    if (format[offsetFormat] == '%') {
      offsetFormat++;
      s21_specifierPrototypeSprintf *prot =
          getSpecifierPrototypeSprintf(format, &offsetFormat);
      if (prot->specifier != -1) {
        char *currentStr = getStr(prot, nextParam);
        // precision
          s21_size_t strLen = 0;
          strLen=s21_strlen(currentStr);
          currentStr = applyPrecision(currentStr, *prot, strLen);
          // flags
          strLen = s21_strlen(currentStr);
          currentStr = applyFlags(currentStr, *prot, strLen);
          // width
          strLen = s21_strlen(currentStr);
          currentStr = applyWidth(currentStr, *prot, strLen);
          for (s21_size_t i = 0; i < strLen; offsetStr++, i++) {
            str[offsetStr] = currentStr[i];
          }
          free(currentStr);
      }
      free(prot);
    } else {
      str[offsetStr] = format[offsetFormat];
      offsetFormat++;
      offsetStr++;
    }
  }
  va_end(nextParam);
  return (int)offsetStr;
}

s21_specifierPrototypeSprintf *getSpecifierPrototypeSprintf(
    const char *format, s21_size_t *currentIndex) {
  s21_specifierPrototypeSprintf *prot =
      calloc(1, sizeof(s21_specifierPrototypeSprintf));
  prot->sign = 0;
  prot->flag = s21_strchr(" -+", format[*currentIndex]) != s21_NULL
                   ? format[*currentIndex]
                   : -1;
  if (prot->flag != -1) {
    *currentIndex += 1;
  }
  prot->width = getWidthFormatSprintf(format, currentIndex);
  prot->precision = getPrecisionFormat(format, currentIndex);
  prot->length = s21_strchr("hl", format[*currentIndex]) != s21_NULL
                     ? format[*currentIndex]
                     : -1;
  if (prot->length != -1) {
    *currentIndex += 1;
  }
  prot->specifier = s21_strchr("cdfsu%%", format[*currentIndex]) != s21_NULL
                        ? format[*currentIndex]
                        : -1;
  if (prot->specifier != -1) {
    *currentIndex += 1;
  }
  if (prot->precision == -1) {
    prot->precision = getDefaultValueOfPrecision(*prot);
  }
  return prot;
}

s21_size_t getWidthFormatSprintf(const char *format, s21_size_t *currentIndex) {
  s21_size_t returnValue = 0;
  while (format[*currentIndex] >= '0' && format[*currentIndex] <= '9') {
    returnValue *= 10;
    returnValue += format[*currentIndex] - '0';
    *currentIndex += 1;
  }
  return returnValue;
}

int getPrecisionFormat(const char *format, s21_size_t *currentIndex) {
  int returnValue = -1;
  if (format[*currentIndex] == '.') {
    returnValue = 0;
    *currentIndex += 1;
    while (format[*currentIndex] >= '0' && format[*currentIndex] <= '9') {
      returnValue *= 10;
      returnValue += format[*currentIndex] - '0';
      *currentIndex += 1;
    }
  }
  return returnValue;
}

int getDefaultValueOfPrecision(s21_specifierPrototypeSprintf prot) {
  int returnValue = -1;
  if (s21_strchr("du", prot.specifier) != s21_NULL) {
    returnValue = 1;
  } else if (prot.specifier == 'f') {
    returnValue = 6;
  }
  return returnValue;
}

char *applyPrecision(char *str, s21_specifierPrototypeSprintf prot,
                     s21_size_t lenStr) {
  char *returnValue = str;
  if (s21_strchr("du", prot.specifier) != s21_NULL) {
    if (prot.precision > (int)lenStr) {
      returnValue = s21_realloc(returnValue, (prot.precision + 1) * sizeof(char));
      char *temp = calloc(prot.precision + 1, sizeof(char));
      s21_strncpy(temp, returnValue, prot.precision * sizeof(char));
      s21_strncpy(&returnValue[prot.precision - (int)lenStr], temp, lenStr);
      free(temp);
      returnValue[prot.precision] = '\0';
      returnValue = s21_memset(returnValue, '0', prot.precision - lenStr);
    }
  } else if (prot.specifier == 's') {
    if (prot.precision < (int)lenStr && prot.precision != -1) {
      returnValue = s21_realloc(returnValue, (prot.precision + 1) * sizeof(char));
      returnValue[prot.precision] = '\0';
    }
  }
  return returnValue;
}

char *applyFlags(char *str, s21_specifierPrototypeSprintf prot,
                 s21_size_t lenStr) {
  char *returnValue = str;
  if (s21_strchr("df", prot.specifier) != s21_NULL) {
    if (prot.sign == -1 || s21_strchr(" +", prot.flag) != s21_NULL) {
      returnValue = s21_realloc(returnValue, (lenStr + 2) * sizeof(char));
      char *temp = calloc(lenStr + 1, sizeof(char));
      s21_strncpy(temp, returnValue, lenStr * sizeof(char));
      s21_strncpy(&(returnValue[1]), temp, lenStr * sizeof(char));
      free(temp);
      returnValue[lenStr + 1] = '\0';
      *returnValue = prot.sign == -1 ? '-' : prot.flag == '+' ? '+' : ' ';
    }
  }
  return returnValue;
}

char *applyWidth(char *str, s21_specifierPrototypeSprintf prot,
                 s21_size_t lenStr) {
  char *returnValue = str;
  if (prot.width > (int)lenStr) {
    returnValue = s21_realloc(returnValue, (prot.width + 1) * sizeof(char));
    char *temp = calloc(prot.width + 1, sizeof(char));
    s21_strncpy(temp, returnValue, prot.width * sizeof(char));
    if (prot.flag != '-') {
      s21_strncpy(&returnValue[prot.width - lenStr], temp,
                  lenStr * sizeof(char));
      returnValue[prot.width] = '\0';
    }
    free(temp);
    s21_memset(
        prot.flag != '-' ? returnValue : &returnValue[prot.width - (int)lenStr],
        ' ', prot.width - lenStr);
    if (prot.flag != '-') {
      returnValue[prot.width] = '\0';
    }
  }
  return returnValue;
}

char *getStr(s21_specifierPrototypeSprintf *prot, va_list nextParam) {
  char *returnValue = s21_NULL;
  if (s21_strchr("du", prot->specifier) != s21_NULL) {
    if (prot->length == 'l') {
      if (prot->specifier == 'u') {
        returnValue =
            longIntToString(prot, va_arg(nextParam, unsigned long int));
      } else {
        returnValue = longIntToString(prot, va_arg(nextParam, long int));
      }
    } else {
      if (prot->specifier == 'u') {
        returnValue = longIntToString(prot, va_arg(nextParam, unsigned int));
      } else {
        returnValue = longIntToString(prot, va_arg(nextParam, int));
      }
    }
  } else if (prot->specifier == 'f') {
    returnValue = doubleToString(prot, va_arg(nextParam, double));
  } else if (prot->specifier == 'c') {
    returnValue = calloc(2, sizeof(char));
    int temp = va_arg(nextParam, int);
    *returnValue = (char)temp;
    returnValue[1] = '\0';
  } else if (prot->specifier == 's') {
    char *temp = va_arg(nextParam, char *);
    s21_size_t lenStr = 0;
    lenStr=s21_strlen(temp);
    returnValue = calloc(lenStr + 1, sizeof(char));
    s21_strncpy(returnValue, temp, lenStr);
  } else if (prot->specifier == '%') {
    returnValue = calloc(2, sizeof(char));
    *returnValue = '%';
  }
  return returnValue;
}

char *doubleToString(s21_specifierPrototypeSprintf *prot, double value) {
  double wholePart = 0, fractionalpart = 0;
  char *returnValue = calloc(1000, sizeof(char));
  s21_size_t offsetReturnValue = 0;
  if (value < 0) {
    prot->sign = -1;
    value *= prot->sign;
  } else {
    prot->sign = 1;
  }
  fractionalpart = modf(value, &wholePart);
  if (wholePart != 0) {
    int delim = 0;
    while (wholePart > pow(10, delim)) {
      delim += 1;
      int temp = (int)(fmod(wholePart, pow(10, delim))) / pow(10, delim - 1);
      returnValue[offsetReturnValue] = temp + '0';
      offsetReturnValue++;
    }
    expandString(returnValue, &returnValue[offsetReturnValue - 1]);
  } else {
    returnValue[offsetReturnValue] = '0';
    offsetReturnValue++;
  }

  if (prot->precision != 0) {
    returnValue[offsetReturnValue] = '.';
    offsetReturnValue++;
    for (int i = 1; i <= prot->precision; i++) {
      int temp = (int)(i == prot->precision ? round(fractionalpart * 10)
                                            : fractionalpart * 10);
      returnValue[offsetReturnValue] = temp + '0';
      fractionalpart = (fractionalpart * 10) - temp;
      offsetReturnValue++;
    }
  }
  returnValue = s21_realloc(returnValue, sizeof(char) * (offsetReturnValue+1));
  returnValue[offsetReturnValue] = '\0';
  return returnValue;
}

char *longIntToString(s21_specifierPrototypeSprintf *prot,
                      long long int value) {
  char *returnValue = calloc(100, sizeof(char));
  s21_size_t offsetReturnValue = 0;
  if (value < 0) {
    prot->sign = -1;
  } else {
    prot->sign = 1;
  }
  if (value != 0) {
    while (value != 0) {
      int temp = (value % 10) * prot->sign;
      returnValue[offsetReturnValue] = temp + '0';
      value = value / 10;
      offsetReturnValue++;
    }
    expandString(returnValue, &returnValue[offsetReturnValue - 1]);
  } else {
    returnValue[offsetReturnValue] = '0';
    offsetReturnValue++;
  }
  returnValue = s21_realloc(returnValue, sizeof(char) * (offsetReturnValue+1));
  returnValue[offsetReturnValue] = '\0';
  return returnValue;
}

void expandString(char *first, char *last) {
  for (; last - first >= 1; first++, last--) {
    char temp = *first;
    *first = *last;
    *last = temp;
  }
}

void *s21_realloc(void *src, s21_size_t size){
  char *returnValue=calloc(size, sizeof(char));
  s21_size_t lenSrc=0;
  lenSrc=s21_strlen(src);
  returnValue=s21_memcpy(returnValue, src, size>lenSrc?lenSrc:size);
  free(src);
  return returnValue;
}