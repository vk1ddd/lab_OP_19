//
// Created by ivanu on 05.05.2024.
//

#ifndef PROJECT_REMOVENONLETTERS_H
#define PROJECT_REMOVENONLETTERS_H

#include "../string_.h"
#include <ctype.h>

void  removeNonLetters(char  *s)  {
    char  *endSource  =  getEndOfString(s);
    char  *destination  =  copyIf(s,  endSource,  s,  isgraph);
    *destination  =  '\0';
}

void test1_one_space(){
    char a[] = "Hello world";
    removeNonLetters(a);
    ASSERT_STRING(a, "Helloworld");
}

void test2_empty(){
    char a[] = "";
    removeNonLetters(a);
    ASSERT_STRING(a, "");
}

void test3_emptyWithSpace(){
    char a[] = "   ";
    removeNonLetters(a);
    ASSERT_STRING(a, "");
}

void test4_withoutSpaces(){
    char a[] = "Helloworld";
    removeNonLetters(a);
    ASSERT_STRING(a, "Helloworld");
}

void test5_spaceBeforeAndAfter(){
    char a[] = " Helloworld ";
    removeNonLetters(a);
    ASSERT_STRING(a, "Helloworld");
}

void tests_removeNonLetters(){
    test1_one_space();
    test2_empty();
    test3_emptyWithSpace();
    test4_withoutSpaces();
    test5_spaceBeforeAndAfter();
}

#endif //PROJECT_REMOVENONLETTERS_H
