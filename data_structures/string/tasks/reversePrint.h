//
// Created by ivanu on 09.05.2024.
//

#ifndef PROJECT_REVERSEPRINT_H
#define PROJECT_REVERSEPRINT_H

void printWordDescriptor(WordDescriptor word) {
    while (word.begin != word.end) {
        printf("%c", *word.begin);
        word.begin++;
    }
    printf(" ");
}


void reversePrint(char* s) {
    getBagOfWords(&_bag, s);

    if (_bag.size >= 1)
        for (int i = (int) _bag.size - 1; i >= 0; i--)
            printWordDescriptor(_bag.words[i]);

    printf("\n");
}

void test1_reversePrint_empty(){
    char a[] = "";
    reversePrint(a);
}

void test2_reversePrint_twoWords(){
    char a[] = "hello world";
    reversePrint(a);
}

void test3_reversePrint_ThreeWords(){
    char a[] = "hi hello world";
    reversePrint(a);
}

void tests_reversePrint(){
    printf("\n");
    test1_reversePrint_empty();
    test2_reversePrint_twoWords();
    test3_reversePrint_ThreeWords();
    printf("\n");
}

#endif //PROJECT_REVERSEPRINT_H
