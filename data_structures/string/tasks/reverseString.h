//
// Created by ivanu on 10.05.2024.
//

#ifndef PROJECT_REVERSESTRING_H
#define PROJECT_REVERSESTRING_H

void reverseString(char *s){
    if (strlen_(s) == 0)
        return;

    BagOfWords a;
    copy(s, getEndOfString(s), _stringBuffer);
    getBagOfWords(&a, _stringBuffer);


    char *rec = s;
    for (size_t i = (a.size - 1); i != -1; i--){
        rec = copy(a.words[i].begin, a.words[i].end, rec);
        *rec = ' ';
        rec++;
    }

    *rec = '\0';

    freeStringBuffer();
}

void test1_reverseString_empty(){
    char a[] = "";
    reverseString(a);
    ASSERT_STRING(a, "");
}

void test2_reverseString_ThreeWords(){
    char a[] = "hello world hi";
    reverseString(a);
    ASSERT_STRING(a, "hi world hello ");
}

void test3_reverseString_FourWords(){
    char a[] = "hello world hi CLion";
    reverseString(a);
    ASSERT_STRING(a, "CLion hi world hello ");
}

void test4_reverseString_OneWord(){
    char a[] = "hello";
    reverseString(a);
    ASSERT_STRING(a, "hello ");
}


void tests_reverseString(){
    test1_reverseString_empty();
    test2_reverseString_ThreeWords();
    test3_reverseString_FourWords();
    test4_reverseString_OneWord();
}

#endif //PROJECT_REVERSESTRING_H
