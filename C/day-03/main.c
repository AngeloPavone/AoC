#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <stdbool.h>

#define FILE_NOT_FOUND 1

const char* INPUT_FILE = "../../Input/2022-day03";

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

int part1(FILE* fptr)
{
    char chunk[256];
    size_t sum = 0;

    while (fgets(chunk, sizeof(chunk), fptr) != NULL)
    {
        size_t chunk_len = strlen(chunk);
        bool found       = false;

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

void part2(FILE* fptr)
{
    char chunk[256];

    while (fgets(chunk, sizeof(chunk), fptr) != NULL)
    {
        puts(chunk);
    }
}

int main(void)
{
    FILE* fptr = openFile(INPUT_FILE);

    printf("part1: %d\n", part1(fptr));
    part2(fptr);

    fclose(fptr);
};
