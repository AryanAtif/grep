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
