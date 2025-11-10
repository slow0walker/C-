#define _CRT_SECURE_NO_WARNINGS 1
#ifndef LINE_H
#define LINE_H

void clear_line(void);
void add_word(const char* word);
int space_remaining(void);

void write_line(void);
void flush_line(void);

#endif