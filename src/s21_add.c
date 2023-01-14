#include "s21_string.h"

// char *strtok(char *str, const char *delim)
// char *strerror(int errnum)
// char *strcat(char *dest, const char *src)
// char *strncat(char *dest, const char *src, size_t n)

char* s21_strncat(char* dest, const char* src, size_t n) {
  size_t dest_len = s21_strlen(dest);
  return s21_strncpy(dest + dest_len, src, n) - dest_len;
}

char* s21_strcat(char* restrict dest, const char* restrict src) {
  size_t dest_len = s21_strlen(dest);
  return s21_strcpy(dest + dest_len, src) - dest_len;
}

char* s21_strtok(char* restrict str, const char* restrict sep) {
  static char* last_stop;
  if (str == NULL) {
    str = last_stop;
  }
  char* res = str;
  if (str != NULL) {
    int code = 0;
    while (code == 0) {
      if (s21_strchr(sep, *str)) {
        ++str;
        ++res;
      } else if (*str == '\0') {
        code = 1;
      } else {
        code = 2;
      }
    }
    if (code != 1) {
      code = 0;
      while (code == 0) {
        if (*str == '\0') {
          last_stop = str;
          code = 1;
        } else if (s21_strchr(sep, *str)) {
          *str = '\0';
          last_stop = str + 1;
          code = 1;
        } else {
          ++str;
        }
      }
    } else {
      res = NULL;
    }
  } else {
    res = NULL;
  }
  return res;
}
