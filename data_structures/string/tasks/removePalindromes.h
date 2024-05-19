//
// Created by ivanu on 11.05.2024.
//

#ifndef PROJECT_REMOVEPALINDROMES_H
#define PROJECT_REMOVEPALINDROMES_H

void removePalindromes(char *s){
    BagOfWords string;
    getBagOfWords(&string, s);

    char *rec = s;
    for(int i = 0; i < string.size; i++){
        if(!isPalindromes(string.words[i])){
            rec = copy(string.words[i].begin, string.words[i].end, rec);
            *rec = ' ';
            rec++;
        }
    }

    *rec = '\0';
}

void test1_removePalindromes_empty(){
    char a[] = "";
    removePalindromes(a);
    ASSERT_STRING(a, "");
}

void test2_removePalindromes_WithoutPali(){
    char a[] = "Hello world";
    removePalindromes(a);
    ASSERT_STRING(a, "Hello world ");
}

void test3_removePalindromes_onePali(){
    char a[] = "HelloolleH";
    removePalindromes(a);
    ASSERT_STRING(a, "");
}

void test4_removePalindromes_mixed(){
    char a[] = "Hello HelloolleH world";
    removePalindromes(a);
    ASSERT_STRING(a, "Hello world ");
}

void tests_removePalindromes(){
    test1_removePalindromes_empty();
    test2_removePalindromes_WithoutPali();
    test3_removePalindromes_onePali();
    test4_removePalindromes_mixed();
}

#endif //PROJECT_REMOVEPALINDROMES_H
