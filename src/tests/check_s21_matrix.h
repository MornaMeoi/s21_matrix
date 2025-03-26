#ifndef CHECK_S21_MATRIX_H
#define CHECK_S21_MATRIX_H

#include <check.h>

#include "../s21_matrix.h"

Suite *s21_create_matrix_suite();
Suite *s21_remove_matrix_suite();
Suite *s21_eq_matrix_suite();
Suite *s21_sum_matrix_suite();
Suite *s21_sub_matrix_suite();
Suite *s21_mult_number_suite();
Suite *s21_mult_matrix_suite();
Suite *s21_transpose_suite();
Suite *s21_determinant_suite();
Suite *s21_calc_complements_suite();
Suite *s21_inverse_matrix_suite();

#endif