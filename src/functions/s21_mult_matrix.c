#include "../s21_matrix.h"

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int exit_code = CODE_OK;
  if (!_check_allocation(A) || !_check_allocation(B))
    exit_code = CODE_INCORRECT_MATRIX_ERROR;
  else if (A->columns != B->rows)
    exit_code = CODE_CALCULATION_ERROR;
  else {
    exit_code = s21_create_matrix(A->rows, B->columns, result);
    if (exit_code == CODE_OK)
      for (int i = 0; i < result->rows; ++i)
        for (int j = 0; j < result->columns; ++j) {
          result->matrix[i][j] = 0;
          for (int k = 0; k < A->columns; ++k)
            result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
        }
  }
  return exit_code;
}