#include "task/transposition_matrix.h"
#include "task/floating_point_number.h"
#include "task/calculating_an_expression.h"
#include "task/filter_word.h"
#include "task/long_words_in_lines.h"

int main(void) {
    tests_matrix_transpose();
    tests_floating_point_number();
    tests_calculating_an_expression();
    tests_filter_word();
    tests_long_words_in_lines();

    return 0;
}
