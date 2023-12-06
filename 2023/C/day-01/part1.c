#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_INPUT "../../Inputs/Tests/day-01-part-1"

#define FILE_NOT_FOUND 2

int is_number(char input) { return EXIT_SUCCESS; };

int main(void) {
  FILE *fptr;
  fptr = fopen(FILE_INPUT, "r");

  if (fptr == NULL) {
    fprintf(stderr, "expected \"%s\" but no file was found\n", FILE_INPUT);
    return FILE_NOT_FOUND;
  }

  char chunk[256];
  while (fgets(chunk, sizeof(chunk), fptr) != NULL) {
    size_t len = strlen(chunk);

    if (len <= 0) {
      fprintf(stderr,
              "expected all inputs to have a length > than 0 but "
              "encountered a line of length %zu",
              len);
    }

    if (chunk[len - 1] == '\n') {
      chunk[len - 1] = '\0';
    }

    for (int i = 0; chunk[i] != '\0'; ++i) {

      if (chunk[i] >= '0' && chunk[i] <= '9') {
        fprintf(stdout, "%c", chunk[i]);
      }
    }
    fprintf(stdout, "\n");
  }

  fclose(fptr);
  return EXIT_SUCCESS;
}
