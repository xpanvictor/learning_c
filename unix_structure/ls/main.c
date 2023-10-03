// #include "apue.h"
#include <dirent.h>
#include <stdio.h>


int main(int argc, char *argv[])
{
  DIR *dir_handle;
  struct dirent *dir_reader;

  // check if dir to list content is valid
  if (argc != 2)
    fprintf(stderr, "Usage: ls <dir name>");

  if ((dir_handle = opendir(argv[1])) == NULL)
    printf("Could not open %s", argv[1]);

  while ((dir_reader = readdir(dir_handle)) != NULL)
    printf("%s\n", dir_reader->d_name);

  // close the handle 
  closedir(dir_handle);
  exit(0);
}

