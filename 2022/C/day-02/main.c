#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define INPUT_FILE "input"

int main(void) {
  FILE *fptr;
  fptr = fopen(INPUT_FILE, "r");

  if (fptr == NULL) {
    perror("\e[0;31m ERROR: Unable to read specified file");
    return 1;
  }

  while(fgets(line, sizeof(line), fptr) != NULL) {
  }


  fclose(fptr);

  return 0;
}
