//
// Created by ivanu on 19.03.2024.
//
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>
#include "matrix.h"

matrix getMemMatrix(int nRows, int nCols) {
    int **values = (int **) malloc(sizeof(int *) * nRows);
    assert(values != NULL);
    for (int i = 0; i < nRows; i++) {
        values[i] = (int *) malloc(sizeof(int) * nCols);
        assert(values[i] != NULL);
    }
    return (matrix) {values, nRows, nCols};
}

matrix *getMemArrayOfMatrices(int nMatrices, int nRows, int nCols) {
    matrix *ms = (matrix *) malloc(sizeof(matrix) * nMatrices);
    for (int i = 0; i < nMatrices; i++)
        ms[i] = getMemMatrix(nRows, nCols);
    return ms;
}

void freeMemMatrix(matrix *m) {
    for (int i = 0; i < m->nRows; ++i) {
        free(m->values[i]);
    }
    free(m->values);
}

void freeMemMatrices(matrix *ms, int nMatrices) {
    for (int i = 0; i < nMatrices; i++) {
        freeMemMatrix(&ms[i]);
    }
    free(ms);
}

void inputMatrix(matrix *m) {
    for (int i = 0; i < m->nRows; i++) {
        for (int j = 0; j < m->nCols; j++) {
            scanf("%d", &m->values[i][j]);
        }
    }
}

void inputMatrices(matrix *ms, int nMatrices) {
    for (int i = 0; i < nMatrices; i++) {
        inputMatrix(&(ms[i]));
    }
}

void outputMatrix(matrix m) {
    // Пройти по каждой строке матрицы
    for (int i = 0; i < m.nRows; i++) {
        // Вывести верхнюю границу строки
        printf("+");
        for (int k = 0; k < m.nCols; k++) {
            printf("---+");
        }
        printf("\n");

        // Пройти по каждому столбцу в текущей строке
        for (int j = 0; j < m.nCols; j++) {
            // Вывести значение элемента в текущей позиции
            printf("| %d ", m.values[i][j]);
        }
        // Вывести символ для границы справа
        printf("|\n");
    }

    // Вывести нижнюю границу матрицы
    printf("+");
    for (int k = 0; k < m.nCols; k++) {
        printf("---+");
    }
    printf("\n");
}

//вывод массива из nMatrices матриц, хранящейся по адресу ms.
void outputMatrices(matrix *ms, int nMatrices) {
    for (int i = 0; i < nMatrices; i++) {
        outputMatrix(ms[i]);
    }
}

void swapRows(matrix m, int i1, int i2) {
    assert((i1 != i2) && (i1 >= 0 && i2 >= 0) && (i1 < m.nCols && i2 < m.nCols));

    int *temp = m.values[i1];
    m.values[i1] = m.values[i2];
    m.values[i2] = temp;
}

void swapColumns(matrix m, int j1, int j2) {
    assert((j1 != j2) && (j1 >= 0 && j2 >= 0) && (j1 < m.nCols && j2 < m.nCols));

    int temp;
    for (int i = 0; i < m.nRows; i++) {
        temp = m.values[i][j1];
        m.values[i][j1] = m.values[i][j2];
        m.values[i][j2] = temp;
    }
}

void insertionSortRowsMatrixByRowCriteria(matrix m, int (*criteria)(int *, int)) {
    int *array = malloc(m.nRows * sizeof(int));
    assert(array != NULL);

    for (int row = 0; row < m.nRows; row++) {
        array[row] = criteria(m.values[row], m.nCols);
    }

    for (int i = 0; i < m.nRows - 1; i++) {
        for (int j = 0; j < m.nRows - 1 - i; j++) {
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
                swapRows(m, j, j + 1);
            }
        }
    }

    free(array);
}

void selectionSortColsMatrixByColCriteria(matrix m, int (*criteria)(int *, int)) {
    int *array = malloc(sizeof(int) * m.nCols);
    int *temp_criteria = malloc(sizeof(int) * m.nRows);
    assert((array != NULL) && (temp_criteria != NULL));

    for (int col = 0; col < m.nCols; col++) {
        for (int row = 0; row < m.nRows; row++) {
            temp_criteria[row] = m.values[row][col];
        }
        array[col] = criteria(temp_criteria, m.nRows);
    }
    free(temp_criteria);

    int temp;
    for (int i = 0; i < m.nCols - 1; i++) {
        for (int col = 0; col < m.nCols - 1 - i; col++) {
            if (array[col] > array[col + 1]) {
                temp = array[col + 1];
                array[col + 1] = array[col];
                array[col] = temp;
                swapColumns(m, col, col + 1);
            }
        }
    }

    free(array);
}

bool isSquareMatrix(matrix *m) {
    return m->nRows == m->nCols;
}

bool areTwoMatricesEqual(matrix *m1, matrix *m2) {
    if ((m1->nCols != m2->nCols) || (m1->nRows != m2->nRows))
        return false;

    for (int row = 0; row < m1->nRows; row++) {
        if (memcmp(m1->values[row], m2->values[row], sizeof(int) * m1->nCols) != 0)
            return false;
    }

    return true;
}

bool isEMatrix(matrix *m) {
    int row_col = 0;
    while (row_col < m->nCols && row_col < m->nRows) {
        if (m->values[row_col][row_col] != 1)
            return false;
        row_col++;
    }

    return true;
}

bool isSymmetricMatrix(matrix *m) {
    if (!isSquareMatrix(m))
        return false;

    for (int row = 0; row < m->nRows; row++) {
        for (int col = 0; col < m->nCols; col++) {
            if (m->values[row][col] != m->values[col][row]) {
                return false;
            }
        }
    }

    return true;
}

void transposeSquareMatrix(matrix *m) {
    int temp;
    for (int row = 0; row < m->nRows; row++) {
        for (int col = 0; col < row; col++) {
            temp = m->values[row][col];
            m->values[row][col] = m->values[col][row];
            m->values[col][row] = temp;
        }
    }
}

void transposeMatrix(matrix *m) {
    matrix new_m = getMemMatrix(m->nCols, m->nRows);

    for (int row = 0; row < m->nRows; row++) {
        for (int col = 0; col < m->nCols; col++) {
            new_m.values[col][row] = m->values[row][col];
        }
    }

    freeMemMatrix(m);
    *m = new_m;
}

position getMinValuePos(matrix m) {
    position min_pos = {0, 0};
    int min = m.values[0][0];
    for (int row = 0; row < m.nRows; row++) {
        for (int col = 0; col < m.nCols; col++) {
            if (m.values[row][col] < min) {
                min = m.values[row][col];
                min_pos.rowIndex = row;
                min_pos.colIndex = col;
            }
        }
    }

    return min_pos;
}

position getMaxValuePos(matrix m) {
    position max_pos = {0, 0};
    int max = m.values[0][0];
    for (int row = 0; row < m.nRows; row++) {
        for (int col = 0; col < m.nCols; col++) {
            if (m.values[row][col] > max) {
                max = m.values[row][col];
                max_pos.rowIndex = row;
                max_pos.colIndex = col;
            }
        }
    }

    return max_pos;
}

matrix createMatrixFromArray(const int *a, int nRows, int nCols) {
    matrix m = getMemMatrix(nRows, nCols);

    int k = 0;
    for (int i = 0; i < nRows; i++)
        for (int j = 0; j < nCols; j++)
            m.values[i][j] = a[k++];

    return m;
}

matrix *createArrayOfMatrixFromArray(const int *values, size_t nMatrices, size_t nRows, size_t nCols) {
    matrix *ms = getMemArrayOfMatrices(nMatrices, nRows, nCols);

    int l = 0;
    for (size_t k = 0; k < nMatrices; k++)
        for (size_t i = 0; i < nRows; i++)
            for (size_t j = 0; j < nCols; j++)
                ms[k].values[i][j] = values[l++];

    return ms;
}
