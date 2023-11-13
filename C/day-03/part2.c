#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <stdbool.h>

#define FILE_NOT_FOUND 1

const char* INPUT_FILE1 = "../../Input/2022-day03";

FILE* openFile(const char* file)
{
  FILE* fptr = fopen(file, "r");

  if (fptr == NULL)
  {
    printf("ERROR: No such file or directory: %s\n", file);
    exit(FILE_NOT_FOUND);
  }
  return fptr;
}

void search_backpack(FILE* file)
{
}

int main(void)
{
  FILE* fptr = openFile(INPUT_FILE1);

  search_backpack(fptr);

  fclose(fptr);

  return 0;
}
