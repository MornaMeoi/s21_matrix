#include "../s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int exit_code = CODE_OK;
  if (!_check_allocation(A) || result == NULL)
    exit_code = CODE_INCORRECT_MATRIX_ERROR;
  else if (A->rows != A->columns || A->rows == 1)
    exit_code = CODE_CALCULATION_ERROR;
  else {
    s21_create_matrix(A->rows, A->columns, result);
    matrix_t minor;
    s21_create_matrix(A->rows - 1, A->columns - 1, &minor);
    double minor_determinant;
    for (int i = 0; i < result->rows; ++i)
      for (int j = 0; j < result->columns; ++j) {
        _fill_minor_by_indices(A, i, j, &minor);
        s21_determinant(&minor, &minor_determinant);
        result->matrix[i][j] = ((i + j) % 2 ? -1 : 1) * minor_determinant;
      }
    s21_remove_matrix(&minor);
  }
  return exit_code;
}