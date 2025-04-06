#ifndef S21_SSCANF
#define S21_SSCANF

#include <math.h>
#include <stdarg.h>
#include <stdlib.h>

#include "s21_string.h"

typedef union destObj {
  char *str;
  long int lInteger;
  float fl;
  void *pointer;
  long double lDouble;
} destinationObject;

typedef struct specProt {
  int canWrite;
  s21_size_t width;
  char length;
  char specifier;
} s21_specifierPrototype;

s21_specifierPrototype getSpecifierPrototype(const char *format,
                                             s21_size_t *currentIndex,
                                             int canWrite);

int getStatusWriteFormat(const char *format, s21_size_t *currentIndex,
                         int canWrite);

s21_size_t getWidthFormat(const char *format, s21_size_t *currentIndex);

char getLengthFormat(const char *format, s21_size_t *currentIndex);

char getSpecifierFormat(const char *format, s21_size_t *currentIndex);

int setValue(s21_specifierPrototype prot, const char *str,
             s21_size_t *currentIndex, void *object);

void *getReadMethod(s21_specifierPrototype prot);

int readSienceNotation(s21_specifierPrototype prot, const char *str,
                       s21_size_t *currentIndex, destinationObject *result);

int readDigits(s21_specifierPrototype prot, const char *str,
               s21_size_t *currentIndex, destinationObject *result);

int readNumber(const char *str, s21_size_t *currentIndex, int system);

int readString(s21_specifierPrototype prot, const char *str,
               s21_size_t *currentIndex, destinationObject *result);

int readChar(s21_specifierPrototype prot, const char *str,
             s21_size_t *currentIndex, destinationObject *result);

int readSpecN(s21_specifierPrototype prot, const char *str,
              s21_size_t *currentIndex, destinationObject *result);

int readPointer(s21_specifierPrototype prot, const char *str,
                s21_size_t *currentIndex, destinationObject *result);

int isDecimal(char currentChar);

int isOctal(char currentChar);

int isHex(char currentChar);

int getSystemNumber(s21_specifierPrototype prot);

void clearSpace(const char *str, s21_size_t *currentIndex);

int checkSign(const char *str, s21_size_t *currentIndex);

int readNumberSystem(const char *str, s21_size_t *currentIndex);

void addFractionValueScienceNotation(s21_specifierPrototype prot,
                                     destinationObject *result, int dot);

size_t getSize(s21_specifierPrototype prot);

int isScienceNotation(s21_specifierPrototype prot);

int isNotSignNumber(s21_specifierPrototype prot);

int s21_isspace(char character);
#endif