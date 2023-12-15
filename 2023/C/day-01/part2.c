#define TEST_MODE

#define PRINT_ERROR_MESSAGE(err)                                               \
  fprintf(stderr, "ERROR: " #err " %d >> ", (err))

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char *test = "../../Inputs/Tests/day-01-part-2";
const char *part1 = "../../Inputs/day-02";

#ifdef TEST_MODE
#define FILE_INPUT test
#else
#define FILE_INPUT part1
#endif /* ifdef TEST_MODE */

typedef enum { false, true } bool;

typedef enum {
  FILE_NOT_FOUND = -1,
  CANT_MAP_STRING = -2,
  MALLOC_ERROR = -3,
} error_code;

int map_string_to_int(const char *input_word) {
  if (strcmp(input_word, "one") == 0) {
    return 1;
  } else if (strcmp(input_word, "two") == 0) {
    return 2;
  } else if (strcmp(input_word, "three") == 0) {
    return 3;
  } else if (strcmp(input_word, "four") == 0) {
    return 4;
  } else if (strcmp(input_word, "five") == 0) {
    return 5;
  } else if (strcmp(input_word, "six") == 0) {
    return 6;
  } else if (strcmp(input_word, "seven") == 0) {
    return 7;
  } else if (strcmp(input_word, "eight") == 0) {
    return 8;
  } else if (strcmp(input_word, "nine") == 0) {
    return 9;
  } else {
    PRINT_ERROR_MESSAGE(CANT_MAP_STRING);
    fprintf(stderr, "could not map input_word: %s to int", input_word);
    exit(CANT_MAP_STRING);
  };
}

const char *find_substring(const char *haystack, const char *needle) {
  char *result = strstr(haystack, needle);

  // if (result == NULL) {
  //   PRINT_ERROR_MESSAGE(MALLOC_ERROR);
  //   fprintf(stdout,
  //           "expected to successfuly allocate memory for string compair got "
  //           "%s instead\n",
  //           result);
  // }

  if (result != NULL) {
    size_t needle_len = strlen(needle);
    char *extracted_needle = malloc(needle_len + 1);

    if (extracted_needle != NULL) {
      memcpy(extracted_needle, result, needle_len);
      extracted_needle[needle_len] = '\0';

      return extracted_needle;
    }
  }
  return NULL;
}

size_t total = 0;

int main(void) {
  FILE *fptr;
  fptr = fopen(FILE_INPUT, "r");

  if (fptr == NULL) {
    PRINT_ERROR_MESSAGE(FILE_NOT_FOUND);
    fprintf(stderr, "expected file at \"%s\" but no file was found\n",
            FILE_INPUT);
    exit(FILE_NOT_FOUND);
  }

  char chunk[256];
  while (fgets(chunk, sizeof(chunk), fptr) != NULL) {

    size_t len = strlen(chunk);

    // TODO: fix the issue with searching finding substrings that are a
    // lower index but skipping over ones that are higher index
    const char *number_strings[] = {"one", "two",   "three", "four", "five",
                                    "six", "seven", "eight", "nine"};

    const int string_count = sizeof(number_strings) / sizeof(number_strings[0]);

    for (int i = 0; i < string_count; ++i) {
      const char *result = find_substring(chunk, number_strings[i]);
      // int maped_int = map_string_to_int(result);
      if (result != NULL) {
        fprintf(stdout, "%s\n", result);
      }
      // fprintf(stdout, "result: %s = %d\n", result, maped_int);
    };

    if (len <= 0) {
      fprintf(stderr,
              "expected all inputs to have a length > than 0 but "
              "encountered a line of length %zu",
              len);
    }

    size_t first = 0;
    bool found_first = false;

    for (int i = 0; !found_first; ++i) {
      if (isdigit(chunk[i])) {
        first = chunk[i] - '0';
        found_first = true;
      }
    }

    size_t second = 0;
    bool found_second = false;

    for (int j = len; !found_second; --j) {
      if (isdigit(chunk[j])) {
        second = chunk[j] - '0';
        found_second = true;
      }
    }

    size_t line_total = 0;
    line_total = (first * 10) + second;

    total += line_total;
  }

  fprintf(stdout, "Part2: %zu\n", total);
  fclose(fptr);
  return EXIT_SUCCESS;
}
