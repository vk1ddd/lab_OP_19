//
// Created by ivanu on 11.05.2024.
//

#ifndef PROJECT_STRINGWITHOUTWORDSEQUALLASTWORD_H
#define PROJECT_STRINGWITHOUTWORDSEQUALLASTWORD_H

void stringWithoutWordsEqualLastWord(char *s) {
    BagOfWords string;
    getBagOfWords(&string, s);

    char *rec = s;
    for (int i = 0; i < string.size; i++) {
        if (!areWordsEqual(string.words[i], string.words[string.size - 1])) {
            rec = copy(string.words[i].begin, string.words[i].end, rec);
            *rec = ' ';
            rec++;
        }
    }

    *rec = '\0';
}

void test1_stringWithoutWordsEqualLastWord_empty() {
    char s[] = "";
    stringWithoutWordsEqualLastWord(s);
    ASSERT_STRING(s, "");
}

void test2_stringWithoutWordsEqualLastWord() {
    char s[] = "Hello world";
    stringWithoutWordsEqualLastWord(s);
    ASSERT_STRING(s, "Hello ");
}

void test3_stringWithoutWordsEqualLastWord() {
    char s[] = "world hello world";
    stringWithoutWordsEqualLastWord(s);
    ASSERT_STRING(s, "hello ");
}

void test4_stringWithoutWordsEqualLastWord() {
    char s[] = "hi hello hi world hi";
    stringWithoutWordsEqualLastWord(s);
    ASSERT_STRING(s, "hello world ");
}

void tests_stringWithoutWordsEqualLastWord() {
    test1_stringWithoutWordsEqualLastWord_empty();
    test2_stringWithoutWordsEqualLastWord();
    test3_stringWithoutWordsEqualLastWord();
    test4_stringWithoutWordsEqualLastWord();
}

#endif //PROJECT_STRINGWITHOUTWORDSEQUALLASTWORD_H
