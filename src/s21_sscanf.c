#include "s21_sscanf.h"

int s21_sscanf(const char *str, const char *format, ...) {
  int result = -1;
  int statusEnd = 1;
  s21_size_t offsetFormat = 0;
  s21_size_t offsetStr = 0;

  va_list nextParam;
  va_start(nextParam, format);

  while (statusEnd == 1) {
    statusEnd = 0;
    if (s21_isspace(format[offsetFormat]) == 0) {
      if (format[offsetFormat] == '%' || format[offsetFormat] == '*') {
        s21_specifierPrototype prot;
        if (format[offsetFormat] == '*') {
          offsetFormat++;
          prot = getSpecifierPrototype(format, &offsetFormat, 0);
        } else if (format[offsetFormat] == '%') {
          offsetFormat++;
          prot = getSpecifierPrototype(format, &offsetFormat, 1);
        }
        if (prot.specifier != -1) {
          int readStatus =
              setValue(prot, str, &offsetStr,
                       (prot.canWrite == 1 && prot.specifier != '%')
                           ? va_arg(nextParam, void *)
                           : NULL);
          if (readStatus > 0) {
            statusEnd = 1;
            if (prot.canWrite == 1 && prot.specifier != 'n' &&
                prot.specifier != '%') {
              if (result < 0) {
                result = 0;
              }
              result += 1;
            }
          }
        } else if (format[offsetFormat] == str[offsetStr]) {
          offsetStr++;
          statusEnd = 1;
        }
      }
    } else {
      while (s21_isspace(str[offsetStr]) == 1) {
        offsetStr++;
      }
      offsetFormat += 1;
      statusEnd = 1;
    }
  }
  return result;
}

s21_specifierPrototype getSpecifierPrototype(const char *format,
                                             s21_size_t *currentIndex,
                                             int canWrite) {
  s21_specifierPrototype prot;
  prot.canWrite = getStatusWriteFormat(format, currentIndex, canWrite);
  prot.width = getWidthFormat(format, currentIndex);
  prot.length = getLengthFormat(format, currentIndex);
  prot.specifier = getSpecifierFormat(format, currentIndex);
  return prot;
}

int getStatusWriteFormat(const char *format, s21_size_t *currentIndex,
                         int canWrite) {
  int returnValue = -1;
  if (canWrite == 0) {
    returnValue = canWrite;
  } else {
    if (format[*currentIndex] == '*') {
      returnValue = 0;
      *currentIndex += 1;
    } else {
      returnValue = 1;
    }
  }
  return returnValue;
}

s21_size_t getWidthFormat(const char *format, s21_size_t *currentIndex) {
  s21_size_t returnValue = 0;
  while (format[*currentIndex] >= '0' && format[*currentIndex] <= '9') {
    returnValue *= 10;
    returnValue += format[*currentIndex] - '0';
    *currentIndex += 1;
  }
  if (returnValue == 0) {
    returnValue = 0 - 1;
  }
  return returnValue;
}

char getLengthFormat(const char *format, s21_size_t *currentIndex) {
  char returnValue = -1;
  if (format[*currentIndex] == 'l' || format[*currentIndex] == 'L' ||
      format[*currentIndex] == 'h') {
    returnValue = format[*currentIndex];
    *currentIndex += 1;
  }
  return returnValue;
}

char getSpecifierFormat(const char *format, s21_size_t *currentIndex) {
  char returnValue = -1;
  if (s21_strchr("cdieEfgGosuxXpn%%", format[*currentIndex]) != s21_NULL) {
    returnValue = format[*currentIndex];
    *currentIndex += 1;
  }
  return returnValue;
}

int setValue(s21_specifierPrototype prot, const char *str,
             s21_size_t *currentIndex, void *object) {
  int statusWrite = 0;
  destinationObject result;
  result.lDouble = 0;
  if (prot.specifier == 'c' || prot.specifier == 's') {
    result.str = object;
  }

  int (*getValue)(s21_specifierPrototype prot, const char *str,
                  s21_size_t *currentIndex, destinationObject *result);
  getValue = getReadMethod(prot);
  statusWrite = getValue(prot, str, currentIndex, &result);

  if (prot.canWrite == 1 && statusWrite > 0 && prot.specifier != 's' &&
      prot.specifier != 'c') {
    s21_memcpy(object, &result, getSize(prot));
    statusWrite = 1;
  }
  return statusWrite;
}

void *getReadMethod(s21_specifierPrototype prot) {
  void *returnMethod = NULL;
  if (prot.specifier == 's') {
    returnMethod = readString;
  } else if (prot.specifier == 'c') {
    returnMethod = readChar;
  } else if (prot.specifier == 'p') {
    returnMethod = readPointer;
  } else if (prot.specifier == '%') {
  } else if (prot.specifier == 'n') {
    returnMethod = readSpecN;

  } else if (s21_strchr("diouxX", prot.specifier) != s21_NULL) {
    returnMethod = readDigits;
  } else if (isScienceNotation(prot) == 1) {
    returnMethod = readSienceNotation;
  }
  return returnMethod;
}

int readSienceNotation(s21_specifierPrototype prot, const char *str,
                       s21_size_t *currentIndex, destinationObject *result) {
  clearSpace(str, currentIndex);
  int countWrite = 0, startIndex = *currentIndex,
      sign = checkSign(str, currentIndex), systemNumber = 10, dot = 1,
      exponent = -1, statusEnd = 0;
  while (statusEnd == 0 && *currentIndex - startIndex < prot.width) {
    statusEnd = 1;
    if (str[*currentIndex] == '.' && dot == 1 && exponent == -1) {
      statusEnd = 0;
      dot = 0;
      *currentIndex += 1;
    } else if ((str[*currentIndex] == 'e' || str[*currentIndex] == 'E') &&
               exponent == -1 && countWrite > 0) {
      statusEnd = 0;
      exponent = 0;
      *currentIndex += 1;
      if (prot.length == 'L') {
        result->lDouble *= sign;
      } else {
        result->fl *= sign;
      }
      sign = checkSign(str, currentIndex);
    } else {
      int tempValue = isDecimal(str[*currentIndex]);
      if (tempValue > -1) {
        countWrite++;
        *currentIndex += 1;
        statusEnd = 0;
        if (exponent >= 0) {
          exponent *= systemNumber;
          exponent += tempValue;
        } else {
          if (prot.length == 'L') {
            result->lDouble *= systemNumber;
            result->lDouble += tempValue;
          } else {
            result->fl *= systemNumber;
            result->fl += tempValue;
          }
          if (dot <= 0) {
            dot--;
          }
        }
      }
    }
  }
  if (countWrite > 0) {
    addFractionValueScienceNotation(
        prot, result,
        (dot < 0 ? dot : 0) + (sign * (exponent > -1 ? exponent : 0)));
  }
  return countWrite;
}

int readDigits(s21_specifierPrototype prot, const char *str,
               s21_size_t *currentIndex, destinationObject *result) {
  clearSpace(str, currentIndex);
  int countWrite = 0, statusEnd = 0, systemNumber = 10, sign = 1;
  s21_size_t startIndex = *currentIndex;
  sign = checkSign(str, currentIndex);
  if (prot.specifier == 'i') {
    systemNumber = readNumberSystem(str, currentIndex);
  } else {
    systemNumber = getSystemNumber(prot);
  }
  countWrite += *currentIndex - startIndex;
  while (statusEnd == 0 && *currentIndex - startIndex < prot.width) {
    statusEnd = 1;
    int tempValue = readNumber(str, currentIndex, systemNumber);
    if (tempValue >= 0) {
      statusEnd = 0;
      countWrite++;
      result->lInteger *= systemNumber;
      result->lInteger += tempValue;
      *currentIndex += 1;
    }
  }
  if (countWrite > 0) {
    result->lInteger *= sign;
  }
  return countWrite;
}

int readNumber(const char *str, s21_size_t *currentIndex, int system) {
  int value = -1;
  switch (system) {
    case 8: {
      value = isOctal(str[*currentIndex]);
      break;
    }
    case 10: {
      value = isDecimal(str[*currentIndex]);
      break;
    }
    case 16: {
      value = isHex(str[*currentIndex]);
      break;
    }
  }
  return value;
}

int readString(s21_specifierPrototype prot, const char *str,
               s21_size_t *currentIndex, destinationObject *result) {
  if (prot.specifier == 's') {
    clearSpace(str, currentIndex);
  }
  int countWrite = 0, statusEnd = 0, startIndex = *currentIndex;
  while (statusEnd == 0 && str[*currentIndex] != '\0') {
    statusEnd = 1;
    if (s21_isspace(str[*currentIndex]) == 0) {
      statusEnd = 0;
      if (prot.canWrite == 1) {
        result->str[*currentIndex - startIndex] = str[*currentIndex];
      }
      countWrite++;
      *currentIndex += 1;
    }
    if (prot.width > 0 && *currentIndex - startIndex >= prot.width) {
      statusEnd = 1;
    }
  }
  if (countWrite > 0 && prot.canWrite == 1) {
    result->str[*currentIndex - startIndex + 1] = '\0';
  }
  return countWrite;
}

int readChar(s21_specifierPrototype prot, const char *str,
             s21_size_t *currentIndex, destinationObject *result) {
  if (prot.width == (s21_size_t)0 - 1) {
    prot.width = 0;
  }
  int countWrite = 0, statusEnd = 0, startIndex = *currentIndex;
  while (statusEnd == 0 && str[*currentIndex] != '\0') {
    if (prot.canWrite == 1) {
      result->str[*currentIndex - startIndex] = str[*currentIndex];
    }
    countWrite++;
    *currentIndex += 1;
    if (*currentIndex - startIndex >= prot.width) {
      statusEnd = 1;
    }
  }
  return countWrite;
}

int readSpecN(s21_specifierPrototype prot, const char *str,
              s21_size_t *currentIndex, destinationObject *result) {
  prot.canWrite = prot.canWrite;
  str = str;
  result->lInteger = *currentIndex;
  return 1;
}

int readPointer(s21_specifierPrototype prot, const char *str,
                s21_size_t *currentIndex, destinationObject *result) {
  unsigned long long int currentValue = 0;
  *currentIndex += 1;
  clearSpace(str, currentIndex);
  int countWrite = 0, statusEnd = 0, systemNumber = 10, sign = 1,
      startIndex = *currentIndex, overflow = 0;

  if (isNotSignNumber(prot) == 1) {
    sign = 0;
  } else {
    sign = checkSign(str, currentIndex);
  }
  systemNumber = readNumberSystem(str, currentIndex);
  if (systemNumber == 8) {
    systemNumber = 10;
  }
  while (statusEnd == 0) {
    statusEnd = 1;
    int tempValue = readNumber(str, currentIndex, systemNumber);
    if (tempValue >= 0) {
      statusEnd = 0;
      countWrite++;
      unsigned long long int checkValue = currentValue;
      checkValue *= systemNumber;
      checkValue += tempValue;
      if (checkValue > currentValue) {
        currentValue = checkValue;
      } else {
        currentValue = 0 - 1;
        overflow = 1;
      }
      *currentIndex += 1;
    }
    if (prot.width > 0 && *currentIndex - startIndex > prot.width) {
      statusEnd = 1;
    }
  }
  if (sign == -1 && overflow == 0) {
    currentValue = 0 - currentValue;
  }
  if (countWrite > 0) {
    result->pointer = (void *)currentValue;
  }
  return countWrite;
}

int isDecimal(char currentChar) {
  int returnValue = -1;
  if (currentChar >= '0' && currentChar <= '9') {
    returnValue = currentChar - '0';
  }
  return returnValue;
}

int isOctal(char currentChar) {
  int returnValue = -1;
  if (currentChar >= '0' && currentChar <= '7') {
    returnValue = currentChar - '0';
  }
  return returnValue;
}

int isHex(char currentChar) {
  int returnValue = 0;
  if (currentChar >= '0' && currentChar <= '9') {
    returnValue = currentChar - '0';
  } else if (currentChar >= 'a' && currentChar <= 'f') {
    returnValue = currentChar - 'a' + 10;
  } else if (currentChar >= 'A' && currentChar <= 'F') {
    returnValue = currentChar - 'A' + 10;
  } else {
    returnValue = -1;
  }
  return returnValue;
}

int getSystemNumber(s21_specifierPrototype prot) {
  int result = 10;
  if (prot.specifier == 'o' || prot.specifier == 'O') {
    result = 8;
  } else if (prot.specifier == 'x' || prot.specifier == 'X') {
    result = 16;
  }
  return result;
}

void clearSpace(const char *str, s21_size_t *currentIndex) {
  while (s21_isspace(str[*currentIndex]) == 1) {
    *currentIndex += 1;
  }
}

int checkSign(const char *str, s21_size_t *currentIndex) {
  int result = 1;
  if (str[*currentIndex] == '-') {
    result = -1;
    *currentIndex += 1;
  } else if (str[*currentIndex] == '+') {
    *currentIndex += 1;
  }
  return result;
}

int readNumberSystem(const char *str, s21_size_t *currentIndex) {
  int system = 10;
  if (str[*currentIndex] == '0') {
    system = 8;
    *currentIndex += 1;
    if (str[*currentIndex] == 'x' || str[*currentIndex] == 'X') {
      system = 16;
      *currentIndex += 1;
    }
  }
  return system;
}

void addFractionValueScienceNotation(s21_specifierPrototype prot,
                                     destinationObject *result, int dot) {
  if (prot.length == 'L') {
    result->lDouble *= powl(10.0, dot);
  } else {
    result->fl *= powf(10.0, dot);
  }
}

size_t getSize(s21_specifierPrototype prot) {
  size_t result = 0;
  if (prot.specifier == 'c') {
    result = sizeof(char);
    if (prot.width > 0) {
      result *= prot.width;
    }
  } else if (prot.specifier == 'd' || prot.specifier == 'i' ||
             isNotSignNumber(prot) == 1) {
    if (prot.length == 'h') {
      result = sizeof(short int);
    } else if (prot.length == 'l') {
      result = sizeof(long int);
    } else {
      result = sizeof(int);
    }
  } else if (isScienceNotation(prot) == 1) {
    if (prot.length == 'L') {
      result = sizeof(long double);
    } else {
      result = sizeof(float);
    }
  } else if (prot.specifier == 'p') {
    result = sizeof(void *);
  } else if (prot.specifier == 'n') {
    result = sizeof(int);
  }
  return result;
}

int isScienceNotation(s21_specifierPrototype prot) {
  int result = 0;
  if (s21_strchr("eEfFgG", prot.specifier) != s21_NULL) {
    result = 1;
  }
  return result;
}

int isNotSignNumber(s21_specifierPrototype prot) {
  int result = 0;
  if (s21_strchr("oxXu", prot.specifier) != s21_NULL) {
    result = 1;
  }
  return result;
}
int s21_isspace(char character) {
  int result = 0;
  if (character == ' ' || character == '\t' || character == '\n' ||
      character == '\v' || character == '\f' || character == '\r') {
    result = 1;
  }
  return result;
}
