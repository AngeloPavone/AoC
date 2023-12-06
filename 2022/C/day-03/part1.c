#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <stdbool.h>

#define FILE_NOT_FOUND 2
#define INPUT_FILE "../../Inputs/2022-day03"

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

int search_backpack(FILE* fptr)
{
  char chunk[64];
  size_t sum = 0;

  while (fgets(chunk, sizeof(chunk), fptr) != NULL)
  {
    size_t chunk_len = strlen(chunk);

    bool found = false;

    for (size_t i = 0; i < chunk_len / 2; ++i)
    {
      for (size_t j = chunk_len / 2; j < chunk_len; ++j)
      {
        if (found == true)
        {
          break;
        }

        if (chunk[j] == chunk[i])
        {
          found = true;
          if (chunk[j] >= 'a' && chunk[i] <= 'z')
          {
            sum += chunk[j] - 'a' + 1;
          }
          else if (chunk[j] >= 'A' && chunk[i] <= 'Z')
          {
            sum += chunk[j] - 'A' + 27;
          }
        }
      }
    }
  }
  return sum;
}

int main(void)
{
  FILE* fptr = openFile(INPUT_FILE);

  printf("part1: %d\n", search_backpack(fptr));

  fclose(fptr);

  return EXIT_SUCCESS;
};
