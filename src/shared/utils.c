#include "../s21_matrix.h"

/*void _print_matrix(const matrix_t *matrix) {
  for (int i = 0; i < matrix->rows; ++i) {
    for (int j = 0; j < matrix->columns; ++j) {
      printf("%lf", matrix->matrix[i][j]);
      if (j != matrix->columns - 1) putchar(' ');
    }
    if (i != matrix->rows - 1) putchar('\n');
  }
}*/

int _check_allocation(const matrix_t *mat) {
  return mat != NULL && mat->matrix != NULL && mat->rows > 0 &&
         mat->columns > 0;
}

void _fill_matrix_with_values(matrix_t *mat, const double *arr) {
  for (int i = 0; i < mat->rows; ++i)
    for (int j = 0; j < mat->columns; ++j)
      mat->matrix[i][j] = arr[i * mat->columns + j];
}

int _col_max(const matrix_t *mat, int col) {
  double max = fabs(mat->matrix[col][col]);
  int maxPos = col;
  for (int i = col + 1; i < mat->rows; ++i) {
    double element = fabs(mat->matrix[i][col]);
    if (element > max) {
      max = element;
      maxPos = i;
    }
  }
  return maxPos;
}

void _swap_rows_inplace(matrix_t *mat, int first_row_idx, int second_row_idx) {
  for (int j = 0; j < mat->columns; ++j) {
    double temp = mat->matrix[first_row_idx][j];
    mat->matrix[first_row_idx][j] = mat->matrix[second_row_idx][j];
    mat->matrix[second_row_idx][j] = temp;
  }
}

int _make_triangle(const matrix_t *mat, matrix_t *result) {
  s21_mult_number((matrix_t *)mat, 1, result);
  int swap_count = 0;
  for (int i = 0; i < result->rows - 1; ++i) {
    int i_max = _col_max(result, i);
    if (i != i_max) {
      _swap_rows_inplace(result, i, i_max);
      ++swap_count;
    }
    for (int j = i + 1; j < result->rows; ++j) {
      double multiplier = -result->matrix[j][i] / result->matrix[i][i];
      for (int k = i; k < mat->rows; ++k)
        result->matrix[j][k] += result->matrix[i][k] * multiplier;
    }
  }
  return swap_count % 2 ? -1 : 1;
}

void _fill_minor_by_indices(const matrix_t *A, int row, int col,
                            matrix_t *result) {
  for (int i = 0; i < A->rows; ++i) {
    int res_row = i < row ? i : i - 1;
    for (int j = 0; j < A->columns; ++j) {
      int res_col = j < col ? j : j - 1;
      if (i != row && j != col)
        result->matrix[res_row][res_col] = A->matrix[i][j];
    }
  }
}