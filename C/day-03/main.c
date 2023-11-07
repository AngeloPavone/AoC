#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <stdbool.h>

#define FILE_NOT_FOUND 1

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

int part1(FILE* fptr)
{
    size_t sum = 0;
    while (fgets(CHUNK, sizeof(CHUNK), fptr) != NULL)
    {
        size_t chunk_len = strlen(CHUNK);
        bool found       = false;

        for (size_t i = 0; i < chunk_len / 2; ++i)
        {
            for (size_t j = chunk_len / 2; j < chunk_len; ++j)
            {
                if (found == true)
                {
                    break;
                }

                if (CHUNK[j] == CHUNK[i])
                {
                    if (CHUNK[j] >= 'a' && CHUNK[i] <= 'z')
                    {
                        sum += CHUNK[j] - 'a' + 1;
                        found = true;
                    }
                    else if (CHUNK[j] >= 'A' && CHUNK[i] <= 'Z')
                    {
                        sum += CHUNK[j] - 'A' + 27;
                        found = true;
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

    printf("%d\n", part1(fptr));

    fclose(fptr);
};
