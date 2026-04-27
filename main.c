#include <stdio.h>

#include "grep.h"

int main (int argc, char **argv) 
{
  if (argc < 3) { printf ("Usage: ./grep [Options] Patterns [FILE]"); return 1;}
  
  char *options;
  char *pattern;
  char *file;
  int starting_cmd_index = 0;  /* Assuming that the user has entered not options */
 
  if (argc > 3) /* Or if they have entered an option*/
  {
    starting_cmd_index = 1;
    char *options = argv[1];                      // ./grep [OPTIONS] Pattern [FILE]
  }                                               //        ^^^^^^^^^
  pattern = argv[1 + starting_cmd_index];         // ./grep [OPTIONS] Pattern [FILE]
                                                  //                  ^^^^^^^
  file = argv[2 + starting_cmd_index];            // ./grep [OPTIONS] Pattern [FILE]
                                                  //                          ^^^^^^
  
  char *file_data = read_file(file);
  printf ("The data read: %s", file_data);
  return 0;
}
