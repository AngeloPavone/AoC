#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INPUT_FILE "input"

int main(void) {
  FILE *fptr;
  char line[8];

  size_t section_total = 0;
  size_t *elf_array = NULL;
  size_t count = 0;
  size_t i = 0;

  fptr = fopen(INPUT_FILE, "r");

  if (fptr == NULL) {
    perror("\e[0;31m ERROR: Unable to read specified file");
    return 1;
  }

  while (fgets(line, sizeof(line), fptr) != NULL) {
    size_t number = atoi(line);
    if (number != 0) {
      section_total += number;
    } else if (number == 0) {
      ++count;
      if (elf_array == NULL) {
        elf_array = (size_t *)malloc(count * sizeof(size_t));
        if (elf_array == NULL) {
          perror("\e[0;31m ERROR: Failed to allocate memory for elf_array");
          return 2;
        }
      }
      elf_array[i] = section_total;
      ++i;
      section_total = 0;
    }
  }

  // calculat the last section since their is no 0 to trigger the calculation in
  // the above loop
  if (section_total > 0) {
    elf_array[i] = section_total;
    ++count;
  }

  for (size_t j = 1; j < count; ++j) {
    for (size_t k = 0; k < count; ++k) {
      if (elf_array[k] > elf_array[j]) {
        int temp = elf_array[j];
        elf_array[j] = elf_array[k];
        elf_array[k] = temp;
      }
    }
  }

  for (size_t i = count - 1; i >= count - 3; --i) {
    printf("elf_array[%zu]: %zu\n", i, elf_array[i]);
  }
    printf("answer: %zu", elf_array[count - 1] + elf_array[count - 2] + elf_array[count - 3]);

  fclose(fptr);
  free(elf_array);

  return 0;
}
