// #define TEST_MODE
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char *test = "../../Inputs/Tests/day-01-part-1";
const char *part1 = "../../Inputs/day-01";

typedef enum
{
  FILE_NOT_FOUND = 2,
} error_code;

#ifdef TEST_MODE
#define FILE_INPUT test
#else
#define FILE_INPUT part1
#endif /* ifdef TEST_MODE */

size_t total = 0;

int main(void)
{
  FILE *fptr;
  fptr = fopen(FILE_INPUT, "r");

  if(fptr == NULL)
  {
    fprintf(stderr, "ERROR: expected \"%s\" but it could not be found\n",
            FILE_INPUT);
    return FILE_NOT_FOUND;
  }

  char chunk[256];
  while(fgets(chunk, sizeof(chunk), fptr) != NULL)
  {

    size_t len = strlen(chunk);

    if(len <= 0)
    {
      fprintf(stderr,
              "expected all inputs to have a length > than 0 but "
              "encountered a line of length %zu",
              len);
    }

    size_t first = 0;
    _Bool found_first = false;

    for(int i = 0; !found_first; ++i)
    {
      if(isdigit(chunk[i]))
      {
        first = chunk[i] - '0';
        found_first = true;
      }
    }

    size_t second = 0;
    _Bool found_second = false;

    for(int j = len; !found_second; --j)
    {
      if(isdigit(chunk[j]))
      {
        second = chunk[j] - '0';
        found_second = true;
      }
    }

    size_t line_total = 0;
    line_total = (first * 10) + second;

    total += line_total;
  }

  fprintf(stdout, "Part1: %zu\n", total);

  fclose(fptr);
  return EXIT_SUCCESS;
}
