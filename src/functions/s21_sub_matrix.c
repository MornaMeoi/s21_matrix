#include "../s21_matrix.h"

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  matrix_t temp;
  s21_mult_number(B, -1, &temp);
  int exit_code = s21_sum_matrix(A, &temp, result);
  s21_remove_matrix(&temp);
  return exit_code;
}