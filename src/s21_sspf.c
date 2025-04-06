#include "s21_sspf.h"

void *s21_to_upper(const char *str) {
  return getModifiedText(str, S21_UPPERMODE);
}

void *s21_to_lower(const char *str) {
  return getModifiedText(str, S21_LOWERMODE);
}

char *getModifiedText(const char *str, int mode) {
  char *returnValue = s21_NULL;
  if (str) {
    s21_size_t strLen = s21_strlen(str);
    if (strLen > 0) {
      returnValue = calloc(strLen + 1, sizeof(char));
      for (s21_size_t i = 0; i < strLen; i++) {
        returnValue[i] = getModificationChar(str[i], mode);
      }
      returnValue[strLen] = '\0';
    }
  }
  return returnValue;
}

char getModificationChar(const char ch, int mode) {
  char returnValue = ch;
  switch (mode) {
    case 0: {
      if (ch >= 'a' && ch <= 'z') {
        returnValue -= 32;
      }
      break;
    }
    case 1: {
      if (ch >= 'A' && ch <= 'Z') {
        returnValue += 32;
      }
      break;
    }
  };
  return returnValue;
}

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  char *returnValue = s21_NULL;
  if (src && str) {
    s21_size_t srcLen = s21_strlen(src);
    s21_size_t strLen = s21_strlen(str);
    if (srcLen >= start_index) {
      s21_size_t sizeStr = srcLen + strLen > start_index + strLen
                               ? srcLen + strLen
                               : start_index + strLen;
      sizeStr += 1;
      returnValue = calloc(sizeStr, sizeof(char));
      returnValue = s21_memset(returnValue, ' ', sizeStr);
      returnValue[sizeStr - 1] = '\0';
      returnValue = s21_strncpy(returnValue, src, start_index);
      s21_strncpy(&returnValue[start_index], str, strLen);
      if (start_index < srcLen) {
        s21_strncpy(&returnValue[start_index + strLen], &src[start_index],
                    srcLen - start_index);
      }
    }
  }
  return returnValue;
}

void *s21_trim(const char *src, const char *trim_chars) {
  char *returnValue = s21_NULL;
  if (src) {
    s21_size_t strLen = s21_strlen(src);
    s21_size_t startIndex = 0;
    while (startIndex < strLen &&
           s21_strchr(trim_chars, src[startIndex]) != s21_NULL) {
      startIndex++;
    }
    if (strLen > 0) {
      strLen--;
    }
    while (startIndex < strLen &&
           s21_strchr(trim_chars, src[strLen]) != s21_NULL) {
      strLen--;
    }
    if (startIndex < strLen) {
      returnValue = calloc(((strLen + 1) - startIndex) + 1, sizeof(char));
      returnValue[((strLen + 1) - startIndex)] = '\0';
      for (s21_size_t i = 0; startIndex <= strLen; startIndex++, i++) {
        returnValue[i] = (char)src[startIndex];
      }
    }
  }
  return returnValue;
}