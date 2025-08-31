#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// random string generator function
void rand_string(char *str, size_t size) {
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    if (size) {
        for (size_t i = 0; i < size; i++) {
            int key = rand() % (int)(sizeof(charset) - 1);
            str[i] = charset[key];
        }
        str[size] = '\0'; // null-terminate
    }
}

// random string generator wrapper function
char* rand_string_alloc(size_t size)
{
     char *s = malloc(size + 1);
     if (s) {
         rand_string(s, size); // student-developed function
     }
     return s;
}

int main()
{
    char *str;
    size_t size = 10;  // specify a value for size of word

    /* seed the randomizer */
    srand((unsigned)time(NULL));

    printf("Today's random word: ");
    str = rand_string_alloc(size);
    printf("%s\n", str);
    free(str);

    return 0;
}
