#include "../s21_matrix.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int result = SUCCESS;
  if (!_check_allocation(A) || !_check_allocation(B) || A->rows != B->rows ||
      A->columns != B->columns)
    result = FAILURE;
  for (int i = 0; result && i < A->rows; ++i)
    for (int j = 0; result && j < A->columns; ++j)
      if (fabs(A->matrix[i][j] - B->matrix[i][j]) >= 1e-7) result = FAILURE;
  return result;
}