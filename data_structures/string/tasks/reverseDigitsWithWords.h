//
// Created by ivanu on 07.05.2024.
//

#ifndef PROJECT_REVERSEDIGITSWITHWORDS_H
#define PROJECT_REVERSEDIGITSWITHWORDS_H

#include "../string_.h"

void reverseDigitToStart(WordDescriptor word) {
    char *endStringBuffer = copy(word.begin, word.end, _stringBuffer);

    char *recPosition = copyIfReverse(endStringBuffer - 1,
                                      _stringBuffer - 1,
                                      word.begin, isdigit);

    copyIf(_stringBuffer, endStringBuffer, recPosition, isalpha);
}

void reverseDigitToBeginningLetters(char *s) {
    char *beginSearch = s;
    WordDescriptor word;

    while (getWord(beginSearch, &word)) {
        reverseDigitToStart(word);
        beginSearch = word.end;
    }
}

void digitToEnd(WordDescriptor word) {
    char *endStringBuffer = copy(word.begin, word.end, _stringBuffer);

    char *recPosition = copyIf(_stringBuffer,
                               endStringBuffer,
                               word.begin, isalpha);

    copyIf(_stringBuffer, endStringBuffer, recPosition, isdigit);
}

void digitsToEndLetters(char *s) {
    char *beginSearch = s;
    WordDescriptor word;

    while (getWord(beginSearch, &word)) {
        digitToEnd(word);
        beginSearch = word.end;
    }
}

void test_reverseDigitToBeginningLetters_twoWordsWithDigits() {
    char a[] = "Hello123 wor3ld2";
    reverseDigitToBeginningLetters(a);
    ASSERT_STRING(a, "321Hello 23world");
}

void test1_digitsToEndLetters_oneWordWithDigits() {
    char a[] = "Hel223lo";
    digitsToEndLetters(a);
    ASSERT_STRING(a, "Hello223");
}

void test2_digitsToEndLetters_twoWordsWithDigits() {
    char a[] = "Hel223lo 2w1orld";
    digitsToEndLetters(a);
    ASSERT_STRING(a, "Hello223 world21");
}

void tests_reverseDigitsWithWords() {
    test_reverseDigitToBeginningLetters_twoWordsWithDigits();
    test1_digitsToEndLetters_oneWordWithDigits();
    test2_digitsToEndLetters_twoWordsWithDigits();
}

#endif //PROJECT_REVERSEDIGITSWITHWORDS_H
