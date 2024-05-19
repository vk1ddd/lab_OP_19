//
// Created by ivanu on 10.05.2024.
//

#ifndef PROJECT_COMBININGSTRINGS_H
#define PROJECT_COMBININGSTRINGS_H

void combiningStrings(char *s1, char *s2, char *stringResult) {
    WordDescriptor word1, word2;
    bool isW1Found, isW2Found;

    char *beginSearch1 = s1, *beginSearch2 = s2;
    int index = 1;
    char *result = stringResult;
    while ((isW1Found = getWord(beginSearch1, &word1)),
            (isW2Found = getWord(beginSearch2, &word2)),
            isW1Found || isW2Found) {

        if ( (index == 1 && isW1Found) || (index == 2 && isW2Found == false && isW1Found) ) {
            result = copy(word1.begin, word1.end, result);
            *result = ' ';
            result++;
            beginSearch1 = word1.end;
            index = 2;
        } else if ( (index == 2 && isW2Found) || (index == 1 && isW2Found) ) {
            result = copy(word2.begin, word2.end, result);
            *result = ' ';
            result++;
            beginSearch2 = word2.end;
            index = 1;
        }
    }
}

void test1_combiningStrings_empty(){
    char result[100] = "";
    char s1[] = "";
    char s2[] = "";
    combiningStrings(s1, s2, result);
    ASSERT_STRING(result, "");
}

void test2_combiningStrings_s1One_s2One(){
    char result[100] = "";
    char s1[] = "hello";
    char s2[] = "world";
    combiningStrings(s1, s2, result);
    ASSERT_STRING(result, "hello world ");
}

void test3_combiningStrings_s1One_s2Three(){
    char result[100] = "";
    char s1[] = "hello";
    char s2[] = "world hi wrld";
    combiningStrings(s1, s2, result);
    ASSERT_STRING(result, "hello world hi wrld ");
}

void test4_combiningStrings_s1Three_s2One(){
    char result[100] = "";
    char s1[] = "world hi wrld";
    char s2[] = "hello";
    combiningStrings(s1, s2, result);
    ASSERT_STRING(result, "world hello hi wrld ");
}

void test5_combiningStrings_Mixed(){
    char result[100] = "";
    char s1[] = "Hello world Hi";
    char s2[] = "CLion Pycharm";
    combiningStrings(s1, s2, result);
    ASSERT_STRING(result, "Hello CLion world Pycharm Hi ");
}

void test6_combiningStrings_s1Three_s2Empty(){
    char result[100] = "";
    char s1[] = "Hello world HI";
    char s2[] = "";
    combiningStrings(s1, s2, result);
    ASSERT_STRING(result, "Hello world HI ");
}

void test7_combiningStrings_s1Empyt_s2Three(){
    char result[100] = "";
    char s1[] = "";
    char s2[] = "Hello world HI";
    combiningStrings(s1, s2, result);
    ASSERT_STRING(result, "Hello world HI ");
}

void tests_combiningStrings() {
    test1_combiningStrings_empty();
    test2_combiningStrings_s1One_s2One();
    test3_combiningStrings_s1One_s2Three();
    test4_combiningStrings_s1Three_s2One();
    test5_combiningStrings_Mixed();
    test6_combiningStrings_s1Three_s2Empty();
    test7_combiningStrings_s1Empyt_s2Three();
}

#endif //PROJECT_COMBININGSTRINGS_H
