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

char** break_into_lines (char* data, int number_of_lines)
{
  char** data_line = malloc (sizeof (char*) * number_of_lines);
  if (data_line == NULL) {printf ("An error occured, memory could not be allocated.\n"); return NULL;}

  for (int i = 0; i < number_of_lines; i++) {data_line[i] = malloc (sizeof (char)); if (data_line[i] == NULL) {printf ("An error occured, memory could not be allocated.\n"); return NULL;}}

  int data_char_count = 0;
  int i = 0; 
  while (data[data_char_count] != '\0' && i < number_of_lines)
  {
    int j = 0;
    while (1)
    {
      data_line[i] = realloc (data_line[i], (j+2)*sizeof(char));
      if (data_line[i] == NULL) {printf ("An error occured, memory could not be allocated.\n"); return NULL;}

      if (data[data_char_count] == '\n' || data[data_char_count] == '\0')
      {
        data_line[i][j] = '\0';
        data_char_count++;
        if (data[data_char_count] == '\0') {return data_line;}
        i++;
        break;
      }
      
      data_line[i][j] = data[data_char_count];
      data_char_count++;
      j++;
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

