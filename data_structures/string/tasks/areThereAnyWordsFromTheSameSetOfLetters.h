//
// Created by ivanu on 11.05.2024.
//

#ifndef PROJECT_ARETHEREANYWORDSFROMTHESAMESETOFLETTERS_H
#define PROJECT_ARETHEREANYWORDSFROMTHESAMESETOFLETTERS_H

#include <stdlib.h>

int compare_letters(const void *s1, const void *s2) {
    return *(char *) s1 - *(char *) s2;
}

void sort_word_letters(WordDescriptor *word) {
    qsort(word->begin, word->end - word->begin, sizeof(char), compare_letters);
}

bool areThereAnyWordsFromTheSameSetOfLetters(char *s) {
    copy(s, getEndOfString(s), _stringBuffer);

    BagOfWords string;
    getBagOfWords(&string, s);

    freeStringBuffer();

    for (int i = 0; i < string.size; i++) {
        sort_word_letters(&string.words[i]);
    }

    for (int i = 0; i < string.size; i++)
        for (int j = i + 1; j < string.size; j++)
            if (areWordsEqual(string.words[i], string.words[j]))
                return true;

    return false;
}

void test1_areThereAnyWordsFromTheSameSetOfLetters_empty() {
    char s[] = "";
    assert(!areThereAnyWordsFromTheSameSetOfLetters(s));
}

void test2_areThereAnyWordsFromTheSameSetOfLetters_ThereAreNoIdenticalWords() {
    char s[] = "hello world hi";
    assert(!areThereAnyWordsFromTheSameSetOfLetters(s));
}

void test3_areThereAnyWordsFromTheSameSetOfLetters_ThereAreTheSameWords() {
    char s[] = "hello world ohlel";
    assert(areThereAnyWordsFromTheSameSetOfLetters(s));
}

void tests_areThereAnyWordsFromTheSameSetOfLetters() {
    test1_areThereAnyWordsFromTheSameSetOfLetters_empty();
    test2_areThereAnyWordsFromTheSameSetOfLetters_ThereAreNoIdenticalWords();
    test3_areThereAnyWordsFromTheSameSetOfLetters_ThereAreTheSameWords();
}

#endif //PROJECT_ARETHEREANYWORDSFROMTHESAMESETOFLETTERS_H
