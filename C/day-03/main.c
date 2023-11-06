#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define SUCCESS               0
#define FILE_NOT_FOUND        1
#define EOF_REACHED           0
#define COULD_NOT_READ_CHUNKS 2

const char* INPUT_FILE = "../../Input/2022-day03";
char CHUNK[256];

FILE* openFile(const char* INPUT_FILE)
{
    FILE* fptr = fopen(INPUT_FILE, "r");

    if (fptr == NULL)
    {
        perror("ERROR: Input file not found");
        exit(FILE_NOT_FOUND);
    }
    return fptr;
}

char* part1(FILE* fptr)
{
    if (fgets(CHUNK, sizeof(CHUNK), fptr) != NULL)
    {
        return CHUNK;
    }
    else
    {
        return EOF_REACHED;
    }
    exit(COULD_NOT_READ_CHUNKS);
}

int main(void)
{

    FILE* fptr = openFile(INPUT_FILE);

    while (part1(fptr) != EOF_REACHED)
    {
        // TODO(angelo): implement part 1 :/
    }

    fclose(fptr);

    return SUCCESS;
};
