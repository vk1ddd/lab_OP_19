//
// Created by ivanu on 09.05.2024.
//

#ifndef PROJECT_LEXICOGRAPHICALLYCORRECT_H
#define PROJECT_LEXICOGRAPHICALLYCORRECT_H

#include "../string_.h"
#include <assert.h>

int lexicographicFinding(WordDescriptor w1, WordDescriptor w2){
    while (*w1.begin && (*w1.begin == *w2.begin)) {
        w1.begin++;
        w2.begin++;
    }

    return *(const unsigned char*) w1.begin - *(const unsigned char*) w2.begin;
}

bool lexicographicallyCorrect(char *s){
    char* beginSearch = s;
    WordDescriptor word1, word2;

    if (!getWord(beginSearch, &word1))
        return true;

    beginSearch = word1.end;

    while (getWord(beginSearch, &word2)) {
        if (lexicographicFinding(word1, word2) <= 0)
            word1 = word2;
        else
            return false;

        beginSearch = word2.end;
    }

    return true;
}

void test1_lexicographicallyCorrect_empty(){
    char a[] = "";
    assert(lexicographicallyCorrect(a));
}

void test2_lexicographicallyCorrect_ABC(){
    char a[] = "a b c";
    assert(lexicographicallyCorrect(a));
}

void test3_lexicographicallyCorrect_ABA(){
    char a[] = "A B A";
    assert(!lexicographicallyCorrect(a));
}

void test4_lexicographicallyCorrect_helloWord(){
    char a[] = "hello word";
    assert(lexicographicallyCorrect(a));
}

void test5_lexicographicallyCorrect_WordHello(){
    char a[] = "word hello";
    assert(!lexicographicallyCorrect(a));
}

void tests_lexicographicallyCorrect(){
    test1_lexicographicallyCorrect_empty();
    test2_lexicographicallyCorrect_ABC();
    test3_lexicographicallyCorrect_ABA();
    test4_lexicographicallyCorrect_helloWord();
    test5_lexicographicallyCorrect_WordHello();
}

#endif //PROJECT_LEXICOGRAPHICALLYCORRECT_H
