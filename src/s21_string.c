#include "s21_string.h"

void *s21_memchr(const void *str, int c, s21_size_t n) {
  const unsigned char *ptr = (const unsigned char *)str;
  unsigned char ch = (unsigned char)c;
  unsigned char *result = s21_NULL;
  for (s21_size_t i = 0; i < n && result == s21_NULL; i++) {
    if (ptr[i] == ch) {
      result = (void *)(ptr + i);
    }
  }
  return result;
}

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  const unsigned char *ptr1 = (const unsigned char *)str1;
  const unsigned char *ptr2 = (const unsigned char *)str2;
  int result = 0;
  for (s21_size_t i = 0; i < n && result == 0; i++) {
    if (ptr1[i] != ptr2[i]) {
      result = ptr1[i] - ptr2[i];
    }
  }
  return result;
}

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  unsigned char *d = (unsigned char *)dest;
  const unsigned char *s = (const unsigned char *)src;
  for (s21_size_t i = 0; i < n; i++) {
    d[i] = s[i];
  }
  return dest;
}

void *s21_memset(void *str, int c, s21_size_t n) {
  unsigned char *ptr = (unsigned char *)str;
  for (s21_size_t i = 0; i < n; i++) {
    ptr[i] = (unsigned char)c;
  }
  return str;
}

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  char *d = dest;
  while (*d != '\0') {
    d++;
  }
  while (n > 0 && *src != '\0') {
    *d++ = *src++;
    n--;
  }
  *d = '\0';
  return dest;
}

char *s21_strchr(const char *str, int c) {
  char *result = s21_NULL;
  char ch = (char)c;
  if (str) {
    for (s21_size_t i = 0; str[i] != '\0' && result == s21_NULL; i++) {
      if (str[i] == ch) {
        result = (char *)&str[i];
      }
    }
  }

  if (ch == '\0') {
    result = (char *)&str[s21_strlen(str)];  // обработка конца строки
  }
  return result;
}

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  int result = 0;
  for (s21_size_t i = 0; i < n && result == 0 && *str1 != '\0' && *str2 != '\0';
       i++) {
    result = str1[i] - str2[i];
  }
  return result;
}

char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
  s21_size_t i = 0;
  for (; i < n && src[i] != '\0'; i++) {
    dest[i] = src[i];
  }
  for (; i < n; i++) {
    dest[i] = '\0';
  }
  return dest;
}

s21_size_t s21_strcspn(const char *str1, const char *str2) {
  const char *p1;
  const char *p2;
  for (p1 = str1; *p1 != '\0'; p1++) {
    for (p2 = str2; *p2 != '\0'; p2++) {
      if (*p1 == *p2) {
        return p1 - str1;
      }
    }
  }
  return p1 - str1;
}

s21_size_t s21_strlen(const char *str) {
  const char *p = str;
  while (*p != '\0') {
    p++;
  }
  return p - str;
}

char *s21_strpbrk(const char *str1, const char *str2) {
  while (*str1) {
    const char *s2 = str2;
    while (*s2) {
      if (*str1 == *s2) {
        return (char *)str1;
      }
      s2++;
    }
    str1++;
  }
  return s21_NULL;
}

char *s21_strrchr(const char *str, int c) {
  char *result = s21_NULL;
  int i = s21_strlen(str);
  char ch = (char)c;
  for (; i >= 0 && result == s21_NULL; i--) {
    if (str[i] == ch) {
      result = (char *)&str[i];
    }
  }
  return result;
}

char *s21_strstr(const char *haystack, const char *needle) {
  char *result = s21_NULL;
  if (*needle == '\0') {
    result = (char *)haystack;
  }
  while (*haystack != '\0' && result == s21_NULL) {
    const char *hStart = haystack;
    const char *nStart = needle;
    while (*hStart != '\0' && *nStart != '\0' && *hStart == *nStart) {
      hStart++;
      nStart++;
    }
    if (*nStart == '\0') {
      result = (char *)haystack;
    }
    haystack++;
  }
  return result;
}

char *s21_strtok(char *str, const char *delim) {
  static char *last_ptr = s21_NULL;
  if (str == s21_NULL) {
    str = last_ptr;
  }
  char *token;
  if (str == s21_NULL || *str == '\0') {
    token = s21_NULL;
  } else {
    while (*str && s21_strchr(delim, *str)) {
      str++;
    }
    if (*str == '\0') {
      last_ptr = s21_NULL;
      token = s21_NULL;
    } else {
      token = str;
      while (*str && !s21_strchr(delim, *str)) {
        str++;
      }
      if (*str) {
        *str++ = '\0';
        last_ptr = str;
      } else {
        last_ptr = s21_NULL;
      }
    }
  }
  return token;
}

#if defined(__APPLE__)
#define S21_ERRLIST_SIZE 107
char unknown_err[256] = "Unknown error: ";
static const char *const s21_errors[S21_ERRLIST_SIZE] = {
    "Undefined error: 0",
    "Operation not permitted",
    "No such file or directory",
    "No such process",
    "Interrupted system call",
    "Input/output error",
    "Device not configured",
    "Argument list too long",
    "Exec format error",
    "Bad file descriptor",
    "No child processes",
    "Resource deadlock avoided",
    "Cannot allocate memory",
    "Permission denied",
    "Bad address",
    "Block device required",
    "Resource busy",
    "File exists",
    "Cross-device link",
    "Operation not supported by device",
    "Not a directory",
    "Is a directory",
    "Invalid argument",
    "Too many open files in system",
    "Too many open files",
    "Inappropriate ioctl for device",
    "Text file busy",
    "File too large",
    "No space left on device",
    "Illegal seek",
    "Read-only file system",
    "Too many links",
    "Broken pipe",
    "Numerical argument out of domain",
    "Result too large",
    "Resource temporarily unavailable",
    "Operation now in progress",
    "Operation already in progress",
    "Socket operation on non-socket",
    "Destination address required",
    "Message too long",
    "Protocol wrong type for socket",
    "Protocol not available",
    "Protocol not supported",
    "Socket type not supported",
    "Operation not supported",
    "Protocol family not supported",
    "Address family not supported by protocol family",
    "Address already in use",
    "Can't assign requested address",
    "Network is down",
    "Network is unreachable",
    "Network dropped connection on reset",
    "Software caused connection abort",
    "Connection reset by peer",
    "No buffer space available",
    "Socket is already connected",
    "Socket is not connected",
    "Can't send after socket shutdown",
    "Too many references: can't splice",
    "Operation timed out",
    "Connection refused",
    "Too many levels of symbolic links",
    "File name too long",
    "Host is down",
    "No route to host",
    "Directory not empty",
    "Too many processes",
    "Too many users",
    "Disc quota exceeded",
    "Stale NFS file handle",
    "Too many levels of remote in path",
    "RPC struct is bad",
    "RPC version wrong",
    "RPC prog. not avail",
    "Program version wrong",
    "Bad procedure for program",
    "No locks available",
    "Function not implemented",
    "Inappropriate file type or format",
    "Authentication error",
    "Need authenticator",
    "Device power is off",
    "Device error",
    "Value too large to be stored in data type",
    "Bad executable (or shared library)",
    "Bad CPU type in executable",
    "Shared library version mismatch",
    "Malformed Mach-o file",
    "Operation canceled",
    "Identifier removed",
    "No message of desired type",
    "Illegal byte sequence",
    "Attribute not found",
    "Bad message",
    "EMULTIHOP (Reserved)",
    "No message available on STREAM",
    "ENOLINK (Reserved)",
    "No STREAM resources",
    "Not a STREAM",
    "Protocol error",
    "STREAM ioctl timeout",
    "Operation not supported on socket",
    "Policy not found",
    "State not recoverable",
    "Previous owner died",
    "Interface output queue is full"};
#endif

#if defined(__linux__)
#define S21_ERRLIST_SIZE 134
char unknown_err[256] = "Unknown error ";
static const char *const s21_errors[S21_ERRLIST_SIZE] = {
    "Success",
    "Operation not permitted",
    "No such file or directory",
    "No such process",
    "Interrupted system call",
    "Input/output error",
    "No such device or address",
    "Argument list too long",
    "Exec format error",
    "Bad file descriptor",
    "No child processes",
    "Resource temporarily unavailable",
    "Cannot allocate memory",
    "Permission denied",
    "Bad address",
    "Block device required",
    "Device or resource busy",
    "File exists",
    "Invalid cross-device link",
    "No such device",
    "Not a directory",
    "Is a directory",
    "Invalid argument",
    "Too many open files in system",
    "Too many open files",
    "Inappropriate ioctl for device",
    "Text file busy",
    "File too large",
    "No space left on device",
    "Illegal seek",
    "Read-only file system",
    "Too many links",
    "Broken pipe",
    "Numerical argument out of domain",
    "Numerical result out of range",
    "Resource deadlock avoided",
    "File name too long",
    "No locks available",
    "Function not implemented",
    "Directory not empty",
    "Too many levels of symbolic links",
    "Unknown error 41",
    "No message of desired type",
    "Identifier removed",
    "Channel number out of range",
    "Level 2 not synchronized",
    "Level 3 halted",
    "Level 3 reset",
    "Link number out of range",
    "Protocol driver not attached",
    "No CSI structure available",
    "Level 2 halted",
    "Invalid exchange",
    "Invalid request descriptor",
    "Exchange full",
    "No anode",
    "Invalid request code",
    "Invalid slot",
    "Unknown error 58",
    "Bad font file format",
    "Device not a stream",
    "No data available",
    "Timer expired",
    "Out of streams resources",
    "Machine is not on the network",
    "Package not installed",
    "Object is remote",
    "Link has been severed",
    "Advertise error",
    "Srmount error",
    "Communication error on send",
    "Protocol error",
    "Multihop attempted",
    "RFS specific error",
    "Bad message",
    "Value too large for defined data type",
    "Name not unique on network",
    "File descriptor in bad state",
    "Remote address changed",
    "Can not access a needed shared library",
    "Accessing a corrupted shared library",
    ".lib section in a.out corrupted",
    "Attempting to link in too many shared libraries",
    "Cannot exec a shared library directly",
    "Invalid or incomplete multibyte or wide character",
    "Interrupted system call should be restarted",
    "Streams pipe error",
    "Too many users",
    "Socket operation on non-socket",
    "Destination address required",
    "Message too long",
    "Protocol wrong type for socket",
    "Protocol not available",
    "Protocol not supported",
    "Socket type not supported",
    "Operation not supported",
    "Protocol family not supported",
    "Address family not supported by protocol",
    "Address already in use",
    "Cannot assign requested address",
    "Network is down",
    "Network is unreachable",
    "Network dropped connection on reset",
    "Software caused connection abort",
    "Connection reset by peer",
    "No buffer space available",
    "Transport endpoint is already connected",
    "Transport endpoint is not connected",
    "Cannot send after transport endpoint shutdown",
    "Too many references: cannot splice",
    "Connection timed out",
    "Connection refused",
    "Host is down",
    "No route to host",
    "Operation already in progress",
    "Operation now in progress",
    "Stale file handle",
    "Structure needs cleaning",
    "Not a XENIX named type file",
    "No XENIX semaphores available",
    "Is a named type file",
    "Remote I/O error",
    "Disk quota exceeded",
    "No medium found",
    "Wrong medium type",
    "Operation canceled",
    "Required key not available",
    "Key has expired",
    "Key has been revoked",
    "Key was rejected by service",
    "Owner died",
    "State not recoverable",
    "Operation not possible due to RF-kill",
    "Memory page has hardware error"};
#endif

char *s21_strerror(int errnum) {
  s21_size_t err_num = (s21_size_t)errnum;
  if (errnum >= 0 && err_num < S21_ERRLIST_SIZE) {
    return (char *)s21_errors[errnum];
  } else {
    int idx = 0;
    int is_negative = 0;
    char num_str[256] = "\0";
    if (errnum < 0) {
      is_negative = 1;
      errnum *= -1;
    }
    while (errnum > 0) {
      num_str[idx++] = (errnum % 10) + '0';
      errnum /= 10;
    }
    if (is_negative) {
      num_str[idx++] = '-';
    }
    for (int j = 0; j < idx / 2; ++j) {
      char temp = num_str[j];
      num_str[j] = num_str[idx - j - 1];
      num_str[idx - j - 1] = temp;
    }
    return s21_strncat(unknown_err, num_str, s21_strlen(num_str));
  }
}
