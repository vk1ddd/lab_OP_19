//
// Created by ivanu on 18.05.2024.
//

#ifndef LAB_OP_19_FLOATING_POINT_NUMBER_H
#define LAB_OP_19_FLOATING_POINT_NUMBER_H

#include "../data_structures/string/string_.h"

void float_point_number(char *filename){
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("reading error\n");
        exit(1);
    }

    float *numbers;
    numbers = malloc(sizeof(float) * 100);
    size_t count = 0;
    while (!feof(file)) {
        float x;
        if (fscanf(file, "%f", &x) == 1) {
            if (count % 100 == 0 && count != 0) {
                numbers = realloc(&numbers, sizeof(float) * 100);
            }
            numbers[count++] = x;
        }
    }

    fclose(file);

    file = fopen(filename, "w");
    if (file == NULL) {
        printf("Writing error\n");
        free(numbers);
        exit(1);
    }
    for (size_t i = 0; i < count; i++) {
        fprintf(file, "%.2f ", numbers[i]);
    }

    fclose(file);
    free(numbers);
}

void test1_float_point_number(){
    const char filename[] = "C:\\Users\\ivanu\\CLionProjects\\lab_OP_19\\task_2_test_1.txt";

    float number = 123.456;
    FILE* file = fopen(filename, "w");
    fprintf(file, "%f", number);
    fclose(file);

    float_point_number(filename);

    file = fopen(filename, "r");
    char data[10];
    fscanf_s(file, "%s", data);
    fclose(file);

    char check[10] = "123.46";

    assert(strcmp_(data, check) == 0);
}

void test2_float_point_number(){
    const char filename[] = "C:\\Users\\ivanu\\CLionProjects\\lab_OP_19\\task_2_test_2.txt";

    float number1 = 123.456;
    float number2 = 0.123132;
    float number3 = 13123.1;
    float number4 = 3434.23;
    float number5 = 23;

    FILE* file = fopen(filename, "w");
    fprintf(file, "%f %f %f %f %f", number1, number2, number3, number4, number5);
    fclose(file);

    float_point_number(filename);

    file = fopen(filename, "r");
    char data[100];
    fgets(data, sizeof(data), file);
    fclose(file);

    char check[100] = "123.46 0.12 13123.10 3434.23 23.00 ";

    assert(strcmp_(data, check) == 0);
}

void tests_floating_point_number(){
    test1_float_point_number();
    test2_float_point_number();
}

#endif //LAB_OP_19_FLOATING_POINT_NUMBER_H
