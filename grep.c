#include <stdio.h>
#include <stdlib.h>

#include "grep.h"

char* read_file (char* filename)
{
  FILE* file = fopen (filename, "r");  // reading the file
  if (file == NULL) { printf ("There was an error reading the file. Make sure that the file exists.\n"); return NULL;}

  char *data_read = malloc(sizeof (char));
  if (data_read == NULL) { printf ("There was an error allocating memory to read the file.\n"); return NULL;}
   
  /* get the file length */
  long file_length;
  fseek(file, 0L, SEEK_END);  
  file_length = ftell(file);
  fseek(file, 0L, SEEK_SET);

  int i = 0;
  while (i < file_length)
  {
    data_read[i] = fgetc (file);
    i++;
    data_read =  realloc(data_read, (i + 1) * sizeof (char)); // increase the string size for the next iteration
  }

  data_read[i] = '\0';
  return data_read;
}

char** break_into_lines (char* data)
{
  int number_of_lines = get_lines_count (data);
  
  char** data_line = malloc (sizeof (char*) * number_of_lines);
  for (int i = 0; i < number_of_lines; i++) {data_line[i] = malloc (sizeof (char));}

  int data_char_count = 0;
  for (int i = 0; data[data_char_count] != '\0'; i++)
  {
    for (int j = 0; ; j++)
    { 
      if (data[data_char_count] == '\n')
      {
        data_line[i][j] = '\0';
        data_char_count++;
        break;
      }
      
      data_line[i][j] = data[data_char_count];
      data_line[i] = realloc (data_line, (j+1)*sizeof(char));
      data_char_count++;
    }
  }
}

int get_lines_count (char* data)
{
  int lines_count = 0;

  int i = 0;
  while (data[i] != '\0')
  {
    if (data[i] == '\n') {lines_count++;}
    i++;
  }

  return lines_count;
}

