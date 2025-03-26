#include "../s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int exit_code = rows > 0 && columns > 0 && result != NULL
                      ? CODE_OK
                      : CODE_INCORRECT_MATRIX_ERROR;
  if (exit_code == CODE_OK) {
    result->matrix = (double **)calloc(rows, sizeof(double *));
    for (int i = 0; i < rows; ++i)
      result->matrix[i] = (double *)calloc(columns, sizeof(double));
    result->rows = rows;
    result->columns = columns;
  }
  return exit_code;
}