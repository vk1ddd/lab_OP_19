//
// Created by ivanu on 11.05.2024.
//

#ifndef PROJECT_ISEQUALWORDSINSTRING_H
#define PROJECT_ISEQUALWORDSINSTRING_H

bool isEqualWordsInString(char *s1) {
    BagOfWords string1;
    BagOfWords string2;

    getBagOfWords(&string1, s1);
    copy(s1, getEndOfString(s1), _stringBuffer);
    getBagOfWords(&string2, _stringBuffer);

    int index = 0;

    for (int i = 0; i < string1.size; i++) {
        for (int j = 0; j < string2.size; j++) {
            if (areWordsEqual(string1.words[i], string2.words[j])) {
                index++;
            }
        }
        if (index > 1)
            return true;

        index = 0;
    }

    freeStringBuffer();

    return false;
}

void test1_isEqualWordsInString_empty(){
    char a[] = "";
    assert(!isEqualWordsInString(a));
}

void test2_isEqualWordsInString_ThereAreNoIdenticalWords(){
    char a[] = "hello world hi";
    assert(!isEqualWordsInString(a));
}

void test3_isEqualWordsInString_ThereAreTheSameWords(){
    char a[] = "hello world hello hi";
    assert(isEqualWordsInString(a));
}


void tests_isEqualWordsInString() {
    test1_isEqualWordsInString_empty();
    test2_isEqualWordsInString_ThereAreNoIdenticalWords();
    test3_isEqualWordsInString_ThereAreTheSameWords();
}

#endif //PROJECT_ISEQUALWORDSINSTRING_H
