//
// Created by ivanu on 10.05.2024.
//

#ifndef PROJECT_LASTWORDINFIRSTSTRINGINSECONDSTRING_H
#define PROJECT_LASTWORDINFIRSTSTRINGINSECONDSTRING_H

WordDescriptor lastWordInFirstStringInSecondString(char *s1, char *s2) {
    BagOfWords string1;
    BagOfWords string2;
    getBagOfWords(&string1, s1);
    getBagOfWords(&string2, s2);

    WordDescriptor answer;
    int index = 0;
    WordDescriptor empty;
    empty.begin = "";
    empty.end = empty.begin;

    for (int i = 0; i < string1.size; i++) {
        for (int j = 0; j < string2.size; j++) {
            if (areWordsEqual(string1.words[i], string2.words[j])) {
                answer.begin = string1.words[i].begin;
                answer.end = string1.words[i].end;
                index = 1;
            }
        }
    }

    if (index == 0)
        return empty;

    return answer;
}

void test1_lastWordInFirstStringInSecondString() {
    char s1[] = "hello world apelsini";
    char s2[] = "apelsini say hello";
    WordDescriptor word = lastWordInFirstStringInSecondString(s1, s2);
    char a[100];
    wordDescriptorToString(word, a);
    ASSERT_STRING(a, "apelsini");
}

void test2_lastWordInFirstStringInSecondString() {
    char s1[] = "hello world";
    char s2[] = "apelsini say";
    WordDescriptor word = lastWordInFirstStringInSecondString(s1, s2);
    char a[100];
    wordDescriptorToString(word, a);
    ASSERT_STRING(a, "");
}

void test3_lastWordInFirstStringInSecondString() {
    char s1[] = "hello";
    char s2[] = "hello";
    WordDescriptor word = lastWordInFirstStringInSecondString(s1, s2);
    char a[100];
    wordDescriptorToString(word, a);
    ASSERT_STRING(a, "hello");
}

void tests_lastWordInFirstStringInSecondString() {
    test1_lastWordInFirstStringInSecondString();
    test2_lastWordInFirstStringInSecondString();
    test3_lastWordInFirstStringInSecondString();
}

#endif //PROJECT_LASTWORDINFIRSTSTRINGINSECONDSTRING_H
