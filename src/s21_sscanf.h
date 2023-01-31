#ifndef C2_S21_STRINGPLUS_0_S21_SSCANF_H
#define C2_S21_STRINGPLUS_0_S21_SSCANF_H

typedef struct ReaderFormat {
  int skip_assignment;  // true if asterisk before specification
  int width;
  int parsed_length;
  char length;
  char specification;
} ReaderFormat;

void init_reader(ReaderFormat* reader);
void parse_into_reader(ReaderFormat* reader,
                       const char* src);  // src = pointer to '%'

int s21_sscanf(const char* str, const char* format, ...);

#endif  // C2_S21_STRINGPLUS_0_S21_SSCANF_H