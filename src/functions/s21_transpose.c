#include "../s21_matrix.h"

int s21_transpose(matrix_t *A, matrix_t *result) {
  int exit_code = CODE_OK;
  if (!_check_allocation(A) || result == NULL)
    exit_code = CODE_INCORRECT_MATRIX_ERROR;
  else {
    exit_code = s21_create_matrix(A->columns, A->rows, result);
    for (int i = 0; i < A->rows; ++i)
      for (int j = 0; j < A->columns; ++j)
        result->matrix[j][i] = A->matrix[i][j];
  }
  return exit_code;
}