#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define SUCCESS        0
#define FILE_NOT_FOUND NULL

const char* INPUT_FILE = "../../Input/2022-day03";
char CHUNK[256];

FILE* openFile(const char* INPUT_FILE)
{
    FILE* fptr = fopen(INPUT_FILE, "r");

    if (fptr == NULL)
    {
        perror("ERROR: file not found");
        return FILE_NOT_FOUND;
    }
    return fptr;
}

void readLines(FILE* fptr)
{
    while (fgets(CHUNK, sizeof(CHUNK), fptr) != NULL)
    {
        printf("%s", CHUNK);
    }
}

int main(void)
{

    FILE* fptr = openFile(INPUT_FILE);

    readLines(fptr);

    fclose(fptr);

    return 0;
};
