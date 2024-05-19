//
// Created by ivanu on 08.05.2024.
//

#ifndef PROJECT_REPLACEWORD_H
#define PROJECT_REPLACEWORD_H

bool equal_WordDescriptor(WordDescriptor w1, WordDescriptor w2) {
    char *read1 = w1.begin;
    char *read2 = w2.begin;
    while (*read2 != *w2.end) {
        if (*read1 != *read2)
            return false;

        read1++;
        read2++;
    }

    return true;
}

void record(char *begin, WordDescriptor word) {
    char *check = findNonSpace(word.begin);
    while (check != word.end) {
        *begin = *check;
        begin++;
        check++;
    }
}

void replaceWord(char *source, char *w1, char *w2) {
    size_t w1Size = strlen_(w1);
    size_t w2Size = strlen_(w2);
    WordDescriptor word1 = {w1, w1 + w1Size};
    WordDescriptor word2 = {w2, w2 + w2Size};

    char *readPtr, *recPtr;

    if (w1Size >= w2Size) {
        readPtr = source;
        recPtr = source;
    } else {
        copy(source, getEndOfString(source), _stringBuffer);
        readPtr = _stringBuffer;
        recPtr = source;
    }

    WordDescriptor check;
    while (*readPtr != '\0') {
        check.begin = findNonSpace(readPtr);
        check.end = findSpace(readPtr);

        if (*readPtr == ' ' || !(equal_WordDescriptor(check, word1))) {
            *recPtr = *readPtr;
            recPtr++;
        } else {
            record(recPtr, word2);

            recPtr += w2Size;
            readPtr = findSpace(readPtr) - 1;
        }

        readPtr++;
    }

    *recPtr = '\0';
}

void test1_replaceWord_empty() {
    char source[] = "";
    char w1[] = "world";
    char w2[] = "hello";
    replaceWord(source, w1, w2);
    ASSERT_STRING("", source);
}

void test2_replaceWord_oneWord() {
    char source[] = "world";
    char w1[] = "world";
    char w2[] = "hello";
    replaceWord(source, w1, w2);
    ASSERT_STRING("hello", source);
}

void test3_replaceWord_LongWordToShotWord() {
    char source[] = "hello worldHello world";
    char w1[] = "worldHello";
    char w2[] = "hello";
    replaceWord(source, w1, w2);
    ASSERT_STRING("hello hello world", source);
}

void test3_replaceWord_replaceWordBetweenTwoWords() {
    char source[] = "hello world hello";
    char w1[] = "world";
    char w2[] = "hello";
    replaceWord(source, w1, w2);
    ASSERT_STRING("hello hello hello", source);
}

void tests_replaceWord() {
    test1_replaceWord_empty();
    test2_replaceWord_oneWord();
    test3_replaceWord_LongWordToShotWord();
    test3_replaceWord_replaceWordBetweenTwoWords();
}

#endif //PROJECT_REPLACEWORD_H
