#include "s21_string.h"

char* s21_strchr(const char* src, int sym) {
    char* res = NULL;
    int stop = 0;
    while (*src != '\0' && !stop) {
        if (*src == sym) {
            res = (char*)src;
            stop = 1;
        } else {
            ++src;
        }
    }
    return res;
}

int compare(const char* haystack, const char* needle) {
    int return_code = 1;
    int stop = 0;

    while (*haystack && *needle && !stop) {
        if (*haystack != *needle) {
            return_code = 0;
            stop = 1;
        }
        ++haystack;
        ++needle;
    }

    if (*needle != '\0') {
        return_code = 0;
    }
    return return_code;
}

char* s21_strstr(const char* haystack, const char* needle) {
    int stop = 0;
    char* result = NULL;

    while (*haystack != '\0' && !stop) {
        if ((*haystack == *needle) && compare(haystack, needle)) {
            result = (char*)haystack;
            stop = 1;
        }
        ++haystack;
    }

    return result;
}