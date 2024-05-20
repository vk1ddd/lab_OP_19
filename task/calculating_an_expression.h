//
// Created by ivanu on 19.05.2024.
//

#ifndef LAB_OP_19_CALCULATING_AN_EXPRESSION_H
#define LAB_OP_19_CALCULATING_AN_EXPRESSION_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

int calculating(const char* expression) {
    int a, b, c;
    char op1, op2;
    int result;

    if (sscanf(expression, "%d %c %d %c %d", &a, &op1, &b, &op2, &c) == 5) {
        if (op2 == '+') {
            result = (op1 == '+') ? (a + b + c) : (a * b + c);
        } else if (op2 == '-') {
            result = (op1 == '+') ? (a + b - c) : (a * b - c);
        } else if (op2 == '*') {
            result = (op1 == '+') ? (a + b * c) : (a * b * c);
        } else if (op2 == '/') {
            result = (op1 == '+') ? (a + b / c) : (a * b / c);
        }
    } else if (sscanf(expression, "%d %c %d", &a, &op1, &b) == 3) {
        if (op1 == '+') {
            result = a + b;
        } else if (op1 == '-') {
            result = a - b;
        } else if (op1 == '*') {
            result = a * b;
        } else if (op1 == '/') {
            result = a / b;
        }
    } else {
        printf("Error.\n");
        exit(1);
    }

    return result;
}

void calculating_an_expression(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Reading error\n");
        exit(1);
    }

    char expression[100];
    if (fgets(expression, sizeof(expression), file) == NULL) {
        printf("Read error\n");
        fclose(file);
        exit(1);
    }
    fclose(file);

    int result = calculating(expression);

    file = fopen(filename, "a");
    if (file == NULL) {
        printf("Writing error\n");
        exit(1);
    }
    fprintf(file, " = %d", result);
    fclose(file);
}

void test1_calculating_an_expression(){
    const char filename[] = "C:\\Users\\ivanu\\CLionProjects\\lab_OP_19\\task_3_test_1.txt";
    char expression[] = "1 + 1";
    FILE *file = fopen(filename, "w");
    fputs(expression, file);

    fclose(file);

    calculating_an_expression(filename);

    file = fopen(filename, "r");

    char answer[50];
    fgets(answer, sizeof(answer), file);
    fclose(file);

    assert(strcmp_(answer, "1 + 1 = 2 "));
}

void test2_calculating_an_expression(){
    const char filename[] = "C:\\Users\\ivanu\\CLionProjects\\lab_OP_19\\task_3_test_2.txt";
    char expression[] = "3 * 4 + 2";
    FILE *file = fopen(filename, "w");
    fputs(expression, file);

    fclose(file);

    calculating_an_expression(filename);

    file = fopen(filename, "r");

    char answer[50];
    fgets(answer, sizeof(answer), file);
    fclose(file);

    assert(strcmp_(answer, "3 * 4 + 2 = 14 "));
}

void tests_calculating_an_expression(){
    test1_calculating_an_expression();
    test2_calculating_an_expression();
}

#endif //LAB_OP_19_CALCULATING_AN_EXPRESSION_H
