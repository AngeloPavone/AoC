#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <stdbool.h>

#define FILE_NOT_FOUND 2
#define PRIORITY_FOUND 7
#define INPUT_FILE "../../Inputs/2022-day03"

#define ASCI_VALUE(char) ((int)char)

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
  char chunk[64]           = { 0 };
  unsigned char bitmap[53] = { 0 };
  size_t linenumber        = 0;
  size_t elf_id            = 0;
  size_t bitmap_index      = 0;
  size_t priority          = 0;

  /* this is undefined behavior that will give a garbage value for priority when compiling with clang
   * but not gcc because priority is never explicitly initialized and only added to */
  // size_t linenumber, elf_id, bitmap_index, priority;

  while (fgets(chunk, sizeof(chunk), fptr) != NULL)
  {
    size_t chunk_len = strlen(chunk);
    linenumber++;
    elf_id = linenumber % 3;

    for (size_t i = 0; i < chunk_len; ++i)
    {
      if (chunk[i] >= ASCI_VALUE('a') && chunk[i] <= ASCI_VALUE('z'))
      {
        bitmap_index = chunk[i] - ASCI_VALUE('a') + 1;
      }
      else
      {
        bitmap_index = chunk[i] - ASCI_VALUE('A') + 27;
      }

      bitmap[bitmap_index] |= 1 << elf_id;

      if (bitmap[bitmap_index] == PRIORITY_FOUND)
      {
        priority += bitmap_index;
        memset(bitmap, 0, sizeof(bitmap));
        break;
      }
    }
  }
  return priority;
}

int main(void)
{
  FILE* fptr = openFile(INPUT_FILE);

  printf("part2: %d\n", search_backpack(fptr));

  fclose(fptr);

  return EXIT_SUCCESS;
}
