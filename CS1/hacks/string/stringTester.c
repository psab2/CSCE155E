/**
 * Prisha Sabherwal
 * 2024/10/31
 * main test driver program
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "string_utils.h"

int main(int argc, char **argv) {

    printf("Test replaceChar function\n");
    char str1A[] = "Hello";
    printf("Original: %s\n", str1A);
    replaceChar(str1A, 'o', '0');
    printf("After replaceChar: %s\n", str1A);
    printf("\n");

    char str1B[] = "Apple";
    printf("Original: %s\n", str1B);
    replaceChar(str1B, 'e', '5');
    printf("After replaceChar: %s\n", str1B);
    printf("\n");

    char str1C[] = "Cat";
    printf("Original: %s\n", str1C);
    replaceChar(str1C, 'a', 'P');
    printf("After replaceChar: %s\n", str1C);
    printf("\n");
    printf("----------------\n");

    printf("Test replaceCharCopy function\n");
    printf("Original: Hello\n");
    char *newStrA = replaceCharCopy("Hello", 'l', '1');
    printf("After replaceCharCopy: %s\n", newStrA);
    free(newStrA);
    printf("\n");

    printf("Original: World\n");
    char *newStrB = replaceCharCopy("World", 'W', 'w');
    printf("After replaceCharCopy: %s\n", newStrB);
    free(newStrB);
    printf("\n");

    printf("Original: Eight\n");
    char *newStrC = replaceCharCopy("Eight", 'E', '8');
    printf("After replaceCharCopy: %s\n", newStrC);
    free(newStrC);
    printf("\n");
    printf("----------------\n");

    printf("Test removeChar function\n");
    printf("Original: Hello\n");
    char str2A[] = "Hello";
    removeChar(str2A, 'l');
    printf("After removeChar: %s\n", str2A);
    printf("\n");

    printf("Original: Orange\n");
    char str2B[] = "Orange";
    removeChar(str2B, 'O');
    printf("After removeChar: %s\n", str2B);
    printf("\n");

    printf("Original: No way\n");
    char str2C[] = "No way";
    removeChar(str2C, 'w');
    printf("After removeChar: %s\n", str2C);
    printf("\n");
    printf("----------------\n");

    printf("Test removeCharCopy function\n");
    printf("Original: Hello\n");
    char *str3A = removeCharCopy("Hello", 'o');
    printf("After removeCharCopy: %s\n", str3A);
    free(str3A);
    printf("\n");

    printf("Original: App\n");
    char *str3B = removeCharCopy("Appoint", 't');
    printf("After removeCharCopy: %s\n", str3B);
    free(str3B);
    printf("\n");

    printf("Original: Shop\n");
    char *str3C = removeCharCopy("check", 'k');
    printf("After removeCharCopy: %s\n", str3C);
    free(str3C);
    printf("\n");
    printf("----------------\n");

    printf("Test lengthSplit function\n");
    printf("Original: Hello World, how are you?\n");
    char **splitStrA = lengthSplit("Hello World, how are you?", 3);
    for (int i = 0; i<9; i++) {
        printf("Split part %d: %s\n", i, splitStrA[i]);
    }
    free(splitStrA);
    printf("\n");

    printf("Original: Computer Science\n");
    char **splitStrB = lengthSplit("Computer Science", 2);
    for (int i = 0; i<8; i++) {
        printf("Split part %d: %s\n", i, splitStrB[i]);
    }
    free(splitStrB);
    printf("\n");

    printf("Original: My code works!\n");
    char **splitStrC = lengthSplit("My code works!", 7);
    for (int i = 0; i<2; i++) {
        printf("Split part %d: %s\n", i, splitStrC[i]);
    }
    free(splitStrC);
    printf("\n");

    return 0;
}
