#include "../s21_matrix.h"

int s21_determinant(matrix_t *A, double *result) {
  int exit_code = CODE_OK;
  if (!_check_allocation(A) || result == NULL)
    exit_code = CODE_INCORRECT_MATRIX_ERROR;
  else if (A->rows != A->columns)
    exit_code = CODE_CALCULATION_ERROR;
  else {
    matrix_t triangle;
    *result = _make_triangle(A, &triangle);
    for (int i = 0; i < triangle.rows; ++i) *result *= triangle.matrix[i][i];
    s21_remove_matrix(&triangle);
  }
  return exit_code;
}