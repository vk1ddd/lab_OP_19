//
// Created by ivanu on 12.05.2024.
//

#ifndef PROJECT_LETTERSBELONGSTRING_H
#define PROJECT_LETTERSBELONGSTRING_H

bool lettersBelongString(char* string, WordDescriptor word) {
    bool include[26] = {0};

    char* start = string;
    char* end = getEndOfString(string);

    while (start != end) {
        if (isalpha(*start))
            include[*start - 97] = true;

        start++;
    }

    while (word.begin != word.end) {
        if (!include[*word.begin - 97])
            return false;

        word.begin++;
    }

    return true;
}

void test1_lettersBelongString_empty(){
    char a[] = "";
    WordDescriptor word;
    getWord("", &word);

    assert(!lettersBelongString(a, word));
}

void test2_lettersBelongString_emptyWord(){
    char a[] = "hello";
    WordDescriptor word;
    getWord("", &word);

    assert(!lettersBelongString(a, word));
}

void test3_lettersBelongString_emptyString(){
    char a[] = "";
    WordDescriptor word;
    getWord("hello", &word);

    assert(!lettersBelongString(a, word));
}

void test4_lettersBelongString_notInString(){
    char a[] = "hello";
    WordDescriptor word;
    getWord("world", &word);

    assert(!lettersBelongString(a, word));
}

void test5_lettersBelongString_lettersInString(){
    char a[] = "hello";
    WordDescriptor word;
    getWord("hello", &word);

    assert(lettersBelongString(a, word));
}

void tests_lettersBelongString(){
    test1_lettersBelongString_empty();
    test2_lettersBelongString_emptyWord();
    test3_lettersBelongString_emptyString();
    test4_lettersBelongString_notInString();
    test5_lettersBelongString_lettersInString();
}

#endif //PROJECT_LETTERSBELONGSTRING_H
