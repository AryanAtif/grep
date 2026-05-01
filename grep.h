#ifndef GREP_H
#define GREP_H

char* read_file (char* filename);
char** break_into_lines (char* data);

int get_lines_count (char* data);
#endif
