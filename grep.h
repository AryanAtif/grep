#ifndef GREP_H
#define GREP_H

char* read_file (char* filename);
char** break_into_lines (char* data, int number_of_lines);

int get_lines_count (char* data);
#endif
