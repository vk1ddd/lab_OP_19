//
// Created by ivanu on 07.05.2024.
//

#ifndef PROJECT_REMOVEEXTRASPACES_H
#define PROJECT_REMOVEEXTRASPACES_H

#include "../string_.h"

void removeExtraSpaces(char *s) {
    char *write_ptr = s;
    char *read_ptr = s;

    while (*read_ptr != '\0') {
        if (!(*read_ptr == ' ' && *(read_ptr + 1) == ' ')) {
            *write_ptr++ = *read_ptr;
        }

        read_ptr++;
    }

    *write_ptr = '\0';

}

void test1_empty() {
    char str[] = "";
    removeExtraSpaces(str);
    ASSERT_STRING("", str);
}

void test2_singleWord() {
    char str[] = "Hello";
    removeExtraSpaces(str);
    ASSERT_STRING("Hello", str);
}

void test3_singleWordWithSpaces() {
    char str[] = "  Hello  ";
    removeExtraSpaces(str);
    ASSERT_STRING(" Hello ", str);
}

void test4_two_wordsNoSpacesBetween() {
    char str[] = "HelloWorld";
    removeExtraSpaces(str);
    ASSERT_STRING("HelloWorld", str);
}

void test5_twoWordsWithOneSpaceBetween() {
    char str[] = "Hello World";
    removeExtraSpaces(str);
    ASSERT_STRING("Hello World", str);
}

void test6_twoWordsWithMultipleSpacesBetween() {
    char str[] = "     Hello     World    ";
    removeExtraSpaces(str);
    ASSERT_STRING(" Hello World ", str);
}

void tests_removeExtraSpaces() {
    test1_empty();
    test2_singleWord();
    test3_singleWordWithSpaces();
    test4_two_wordsNoSpacesBetween();
    test5_twoWordsWithOneSpaceBetween();
    test6_twoWordsWithMultipleSpacesBetween();
}


#endif //PROJECT_REMOVEEXTRASPACES_H
