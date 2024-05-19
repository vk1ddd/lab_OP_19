//
// Created by ivanu on 07.05.2024.
//

#ifndef PROJECT_REPLACEDIGITSTOSPACE_H
#define PROJECT_REPLACEDIGITSTOSPACE_H

void replaceDigitToSpace(char *s){
    char *readPtr = _stringBuffer;
    char *recPtr = s;

    copy(s, getEndOfString(s) + 1, _stringBuffer);
    while(*readPtr != '\0'){
        if(isdigit(*readPtr)){
            for (int i = 0; i < *readPtr - 48; i++){
                *recPtr = ' ';
                recPtr++;
            }
        }else{
            *recPtr = *readPtr;
            recPtr++;
        }

        readPtr++;
    }

    *recPtr = '\0';
}

void test1_replaceDigitTiStart_empty(){
    char a[] = "";
    replaceDigitToSpace(a);
    ASSERT_STRING(a, "");
}

void test2_replaceDigitTiStart_word(){
    char a[] = "hello";
    replaceDigitToSpace(a);
    ASSERT_STRING(a, "hello");
}

void test3_replaceDigitTiStart_digit(){
    char a[] = "3";
    replaceDigitToSpace(a);
    ASSERT_STRING(a, "   ");
}

void test4_replaceDigitTiStart_wordWordDigits(){
    char a[] = "h3ll0";
    replaceDigitToSpace(a);
    ASSERT_STRING(a, "h   ll");
}

void tests_replaceDigitsToSpace(){
    test1_replaceDigitTiStart_empty();
    test2_replaceDigitTiStart_word();
    test3_replaceDigitTiStart_digit();
    test4_replaceDigitTiStart_wordWordDigits();
}

#endif //PROJECT_REPLACEDIGITSTOSPACE_H
