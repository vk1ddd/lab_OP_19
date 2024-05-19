//
// Created by ivanu on 10.05.2024.
//

#ifndef PROJECT_WORDBEFOREFIRSTWORDWITHA_H
#define PROJECT_WORDBEFOREFIRSTWORDWITHA_H

typedef enum WordBeforeFirstWordWithAReturnCode {
    FIRST_WORD_WITH_A,
    NOT_FOUND_A_WORD_WITH_A,
    WORD_FOUND,
    EMPTY_STRING
} WordBeforeFirstWordWithAReturnCode;

bool lettersInWord(WordDescriptor word, char letters) {
    char *read = word.begin;
    while (*read != *(word.end + 1)) {
        if (*read == letters)
            return true;
        read++;
    }

    return false;
}

WordBeforeFirstWordWithAReturnCode wordBeforeFirstWordWithA(char *s, WordDescriptor *w) {
    char *beginSearch = s;

    WordDescriptor word1;
    if (!getWord(beginSearch, &word1)) {
        return EMPTY_STRING;
    }
    beginSearch = word1.end + 1;

    if (lettersInWord(word1, 'a') || lettersInWord(word1, 'A')) {
        return FIRST_WORD_WITH_A;
    }

    WordDescriptor word2;
    while (getWord(beginSearch, &word2)) {
        if (lettersInWord(word2, 'a') || lettersInWord(word2, 'A')) {
            *w = word1;
            return WORD_FOUND;
        }

        word1 = word2;

        beginSearch = word2.end + 1;
    }

    return NOT_FOUND_A_WORD_WITH_A;
}

void tests_wordBeforeFirstWordWithA() {
    WordDescriptor word;

    char s1[] = "";
    assert(wordBeforeFirstWordWithA(s1, &word) == EMPTY_STRING);

    char s2[] = "Pycharm";
    assert(wordBeforeFirstWordWithA(s2, &word) == FIRST_WORD_WITH_A);

    char s3[] = "hello pycharm";
    assert(wordBeforeFirstWordWithA(s3, &word) == WORD_FOUND);

    char got[MAX_WORD_SIZE];
    copy(word.begin, word.end, got);
    got[word.end - word.begin] = '\0';
    ASSERT_STRING("hello", got);

    char s4[] = "hello world hi";
    assert(wordBeforeFirstWordWithA(s4, &word) == NOT_FOUND_A_WORD_WITH_A);
}

#endif //PROJECT_WORDBEFOREFIRSTWORDWITHA_H
