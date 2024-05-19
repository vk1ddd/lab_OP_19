//
// Created by ivanu on 10.05.2024.
//

#ifndef PROJECT_NUMBEROFPALINDROMES_H
#define PROJECT_NUMBEROFPALINDROMES_H

#include <stdbool.h>
#include "../string_.h"
#include <assert.h>

bool isPalindromes(WordDescriptor word) {
    size_t check = word.end - word.begin;
    check = (check % 2 == 0 ? check : check + 1) / 2;

    char *wordEnd = word.end - 1;
    char *wordBegin = word.begin;
    for (check; check != 0; check--) {
        if (*wordBegin != *wordEnd)
            return false;

        wordBegin++;
        wordEnd--;
    }

    return true;
}

int numberOfPalindromes(char *s) {
    WordDescriptor word;
    int amount = 0;

    char *string = s;
    while (getWord(string, &word)) {
        if (*(word.end - 1) == ',')
            word.end--;

        if (isPalindromes(word))
            amount++;

        string = *word.end == ',' ? word.end + 1 : word.end;
    }

    return amount;
}

void test1_numberOfPalindromes_empty() {
    char a[] = "";
    assert(numberOfPalindromes(a) == 0);
}

void test2_numberOfPalindromes_onePaliWord() {
    char a[] = "aba";
    assert(numberOfPalindromes(a) == 1);
}

void test3_numberOfPalindromes_nonPoliWord() {
    char a[] = "Hello";
    assert(numberOfPalindromes(a) == 0);
}

void test4_numberOfPalindromes_ThreePaliWords() {
    char a[] = "aba, asdfjklkjfdsa, ThreeeerhT";
    assert(numberOfPalindromes(a) == 3);
}

void test5_numberOfPalindromes_mixedWords() {
    char a[] = "Hello, aba, Word, worddrow, hellolleh, wasd, asdsa";
    assert(numberOfPalindromes(a) == 4);
}

void tests_numberOfPalindromes() {
    test1_numberOfPalindromes_empty();
    test2_numberOfPalindromes_onePaliWord();
    test3_numberOfPalindromes_nonPoliWord();
    test4_numberOfPalindromes_ThreePaliWords();
    test5_numberOfPalindromes_mixedWords();
}

#endif //PROJECT_NUMBEROFPALINDROMES_H
