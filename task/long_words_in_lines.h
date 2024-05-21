//
// Created by ivanu on 21.05.2024.
//

#ifndef LAB_OP_19_LONG_WORDS_IN_LINES_H
#define LAB_OP_19_LONG_WORDS_IN_LINES_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <assert.h>
#include "../data_structures/string/string_.h"

char *selecting_and_recording_long_words(char *string) {
    BagOfWords string_words;
    getBagOfWords(&string_words, string);

    size_t max_len = 0;
    int index_max_word = 0;
    char word[50];
    for (int i = 0; i < string_words.size; i++) {
        wordDescriptorToString(string_words.words[i], word);
        if (max_len < strlen_(word)){
            max_len = strlen_(word);
            index_max_word = i;
        }
    }

    char* answer = (char*)malloc((max_len + 1) * sizeof(char));
    wordDescriptorToString(string_words.words[index_max_word], answer);

    return answer;
}

void long_words_in_lines(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Reading error\n");
        exit(1);
    }

    char string[200];
    char string_with_long_words[100];
    char *rec = string_with_long_words;
    while (fgets(string, sizeof(string), file) != NULL) {
        char *long_word = selecting_and_recording_long_words(string);
        while(*rec != *findSpace(long_word)){
            *rec = *long_word;
            long_word++;
            rec++;
        }
        *rec = '\n';
        rec++;
    }

    fclose(file);

    file = fopen(filename, "w");
    fputs(string_with_long_words, file);
    fclose(file);
}

void test1_long_words_in_lines() {
    const char filename[] = "C:\\Users\\ivanu\\CLionProjects\\lab_OP_19\\task_5_test_1.txt";

    char line1[] = "hi hello world";
    char line2[] = "short short short longlongword";
    char line3[] = "I !love CLionn";

    FILE *file = fopen(filename, "w");

    fprintf(file, "%s \n", line1);
    fprintf(file, "%s \n", line2);
    fprintf(file, "%s \n", line3);

    fclose(file);

    long_words_in_lines(filename);

    file = fopen(filename, "r");

    char res_line1[50];
    fscanf(file, "%s\n", res_line1);

    char res_line2[50];
    fscanf(file, "%s\n", res_line2);

    char res_line3[50];
    fscanf(file, "%s\n", res_line3);

    fclose(file);

    assert(strcmp_(res_line1, "hello "));
    assert(strcmp_(res_line2, "longlongword "));
    assert(strcmp_(res_line3, "CLionn "));
}

void tests_long_words_in_lines() {
    test1_long_words_in_lines();
}

#endif //LAB_OP_19_LONG_WORDS_IN_LINES_H
