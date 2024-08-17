#include <stdio.h>

#include "hello_world.h"

#define EXPECTED "Hello, World!"

/*
 * Test if string is "Hello, World!"
 * Return -1 if it is, otherwise return the index of the first mismatch.
 */
int string_test(const char* s) {
    const char* expected = EXPECTED;

#ifndef ENTIRE_STRING
    // Here, we can't use strncmp because the string has the const qualifier
    for (int i = 0; i < 13; ++i)  // 13 is the length of "Hello, World!"
        if (!s[i] || s[i] != expected[i]) return i;
    if (s[13]) return 13;  // Extra characters
#else
    // To base on '\0' we could use:
    const char* e = expected;
    for (; *e; ++e) {
        if (!*s) return e - expected;
        if (*s++ != *e) return e - expected;
    }
    if (*s) return e - expected; // Extra characters
#endif

    return -1;
}

int main() {
    /* A more simple solution would just print "Hello, World!" and return 0
     * But it needs to be adapted to Exercism's test, by using an external
     * file and a function to return the string
     *
     * Above is the simplest solution, the original hello_world for C language:
     * printf("Hello, World!\n");
     * return 0;
     */

    const char* s = hello();
    const int result = string_test(s);
    if (result > -1) {
        printf("Test failed!\n");
        printf("Expected: %s\n", EXPECTED);
        printf("Got: %s\n", s);
        printf("Mismatch at index %d\n", result);
        if (result < 13)
            printf("Mismatched characters: '%c' != '%c'\n", s[result],
                   EXPECTED[result]);
        else {
            printf("Got extra characters: '");
            for (const char* p = s + 13; *p; ++p) printf("%c", *p);
            printf("'\n");
        }

        return 1;
    }

    printf("Test passed: %s\n", s);
    return 0;
}
