//
// Created by ivanu on 20.05.2024.
//

#ifndef LAB_OP_19_FILTER_WORD_H
#define LAB_OP_19_FILTER_WORD_H

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "../data_structures/string/string_.h"

int s_in_word(WordDescriptor word, char *s) {
    char *word_read = word.begin;
    char *s_read = s;
    size_t size_s = strlen_(s);

    while (word_read != word.end + 1) {
        if (*word_read == *s_read) {
            s_read++;
            size_s--;
        } else {
            size_s = strlen_(s);
            s_read = s;
        }

        if (size_s == 0)
            return 1;

        word_read++;
    }

    return 0;
}

void add_in_file(const char *filename, char *s) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Writing error\n");
        exit(1);
    }

    size_t string_length = strlen_(s);

    for (size_t i = 0; i <= string_length; i++)
        fprintf(file, "%c", s[i]);

    fclose(file);
}

void filter_word(const char *filename, char *s) {
    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error reading");
        exit(1);
    }

    char file_string[200];

    if (fgets(file_string, sizeof(file_string), file) == NULL) {
        printf("Error copy");
        exit(1);
    }

    fclose(file);

    BagOfWords string_words;
    getBagOfWords(&string_words, file_string);

    char string[200];
    char *string_rec = string;
    char *descriptor_read;
    for (int i = 0; i < string_words.size; i++) {
        if ((s_in_word(string_words.words[i], s))) {

            descriptor_read = string_words.words[i].begin;
            while(descriptor_read != string_words.words[i].end + 1){
                *string_rec = *descriptor_read;
                string_rec++;
                descriptor_read++;
            }
        }
    }

    add_in_file(filename, string);
}

void test1_filter_word() {
    const char filename[] = "C:\\Users\\ivanu\\CLionProjects\\lab_OP_19\\task_4_test_1.txt";

    add_in_file(filename, "hello world");
    char s[] = "ata";
    filter_word(filename, s);

    FILE *file = fopen(filename, "r");
    char data[100] = "";
    fgets(data, sizeof(data), file);
    fclose(file);

    assert(strcmp_("   ", data));
}

void test2_filter_word() {
    const char filename[] = "C:\\Users\\ivanu\\CLionProjects\\lab_OP_19\\task_4_test_2.txt";

    add_in_file(filename, "data");
    char s[] = "ata";
    filter_word(filename, s);

    FILE *file = fopen(filename, "r");
    char data[100] = "";
    fgets(data, sizeof(data), file);
    fclose(file);

    assert(strcmp_("data ", data));
}

void test3_filter_word() {
    const char filename[] = "C:\\Users\\ivanu\\CLionProjects\\lab_OP_19\\task_4_test_3.txt";

    add_in_file(filename, "data python trata asdataasd ata banana CLion");
    char s[] = "ata";
    filter_word(filename, s);

    FILE *file = fopen(filename, "r");
    char data[100] = "";
    fgets(data, sizeof(data), file);
    fclose(file);

    assert(strcmp_("data trata asdataasd ata", data));
}

void tests_filter_word() {
    test1_filter_word();
    test2_filter_word();
    test3_filter_word();
}

#endif //LAB_OP_19_FILTER_WORD_H
