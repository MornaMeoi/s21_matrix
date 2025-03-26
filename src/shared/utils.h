#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>

#include "../s21_matrix.h"

// void _print_matrix(const matrix_t *matrix);
int _check_allocation(const matrix_t *mat);
void _fill_matrix_with_values(matrix_t *mat, const double *arr);
int _col_max(const matrix_t *mat, int col);
void _swap_rows_inplace(matrix_t *mat, int first_row_idx, int second_row_idx);
int _make_triangle(const matrix_t *mat, matrix_t *result);
void _fill_minor_by_indices(const matrix_t *A, int row, int col,
                            matrix_t *result);

#endif