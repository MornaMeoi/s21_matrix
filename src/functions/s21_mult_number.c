#include "../s21_matrix.h"

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  int exit_code = CODE_OK;
  if (!_check_allocation(A))
    exit_code = CODE_INCORRECT_MATRIX_ERROR;
  else {
    exit_code = s21_create_matrix(A->rows, A->columns, result);
    if (exit_code == CODE_OK)
      for (int i = 0; i < A->rows; ++i)
        for (int j = 0; j < A->columns; ++j)
          result->matrix[i][j] = A->matrix[i][j] * number;
  }
  return exit_code;
}