cmake_minimum_required(VERSION 3.28)
project(lab_OP_19 C)

set(CMAKE_C_STANDARD 11)

add_executable(code main.c
        data_structures/matrix/matrix.h
        data_structures/matrix/matrix.c
        task/transposition_matrix.h
        task/floating_point_number.h
        data_structures/string/string_.h
        data_structures/string/string_.c
        task/calculating_an_expression.h
)
