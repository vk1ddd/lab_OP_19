//
// Created by ivanu on 11.05.2024.
//

#ifndef PROJECT_GETWORDBEFOREWORDTHATINSECONDLINE_H
#define PROJECT_GETWORDBEFOREWORDTHATINSECONDLINE_H

WordDescriptor getWordBeforeWordThatInSecondLine(char *s1, char *s2){
    BagOfWords string1;
    BagOfWords string2;


    getBagOfWords(&string1, s1);
    getBagOfWords(&string2, s2);

    WordDescriptor empty;
    char a[] = "empty";
    getWord(a, &empty);
    freeWordDescriptor(&empty);


    for (int i = 0; i < string1.size; i++){
        for (int j = 0; j < string2.size; j++){
            if (areWordsEqual(string1.words[i], string2.words[j])){
                if (i > 0)
                    return string1.words[i - 1];
            }
        }
    }

    return empty;
}

void test1_getWordBeforeWordThatInSecondLine_empty(){
    char s1[] = "";
    char s2[] = "";
    WordDescriptor result1;
    result1 = getWordBeforeWordThatInSecondLine(s1, s2);
    char result[100];
    wordDescriptorToString(result1, result);
    ASSERT_STRING(result, "");
}

void test2_getWordBeforeWordThatInSecondLine(){
    char s1[] = "Hello world";
    char s2[] = "hi world";
    WordDescriptor result1;
    result1 = getWordBeforeWordThatInSecondLine(s1, s2);
    char result[100];
    wordDescriptorToString(result1, result);
    ASSERT_STRING(result, "Hello ");
}

void test3_getWordBeforeWordThatInSecondLine(){
    char s1[] = "world";
    char s2[] = "hi world";
    WordDescriptor result1;
    result1 = getWordBeforeWordThatInSecondLine(s1, s2);
    char result[100];
    wordDescriptorToString(result1, result);
    ASSERT_STRING(result, "");
}

void tests_getWordBeforeWordThatInSecondLine(){
    test1_getWordBeforeWordThatInSecondLine_empty();
    test2_getWordBeforeWordThatInSecondLine();
    test3_getWordBeforeWordThatInSecondLine();
}

#endif //PROJECT_GETWORDBEFOREWORDTHATINSECONDLINE_H
