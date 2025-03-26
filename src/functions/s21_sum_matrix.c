#include "../s21_matrix.h"

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int exit_code = CODE_OK;
  if (!_check_allocation(A) || !_check_allocation(B))
    exit_code = CODE_INCORRECT_MATRIX_ERROR;
  else if (A->rows != B->rows || A->columns != B->columns)
    exit_code = CODE_CALCULATION_ERROR;
  else {
    exit_code = s21_create_matrix(A->rows, A->columns, result);
    if (exit_code == CODE_OK)
      for (int i = 0; i < A->rows; ++i)
        for (int j = 0; j < A->columns; ++j)
          result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
  }
  return exit_code;
}