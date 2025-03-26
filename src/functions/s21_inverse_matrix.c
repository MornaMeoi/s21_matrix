#include "../s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int exit_code = CODE_OK;
  if (!_check_allocation(A) || result == NULL)
    exit_code = CODE_INCORRECT_MATRIX_ERROR;
  else if (A->rows != A->columns || A->rows == 1)
    exit_code = CODE_CALCULATION_ERROR;
  else {
    double determinant;
    s21_determinant(A, &determinant);
    if (determinant == 0.)
      exit_code = CODE_CALCULATION_ERROR;
    else {
      matrix_t calcs;
      s21_calc_complements(A, &calcs);
      s21_transpose(&calcs, result);
      for (int i = 0; i < result->rows; ++i)
        for (int j = 0; j < result->columns; ++j)
          result->matrix[i][j] /= determinant;
      s21_remove_matrix(&calcs);
    }
  }
  return exit_code;
}