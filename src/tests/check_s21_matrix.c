#include "check_s21_matrix.h"

int main() {
  int number_failed = 0;
  Suite* suites[] = {s21_create_matrix_suite(),  s21_remove_matrix_suite(),
                     s21_eq_matrix_suite(),      s21_sum_matrix_suite(),
                     s21_sub_matrix_suite(),     s21_mult_number_suite(),
                     s21_mult_matrix_suite(),    s21_transpose_suite(),
                     s21_determinant_suite(),    s21_calc_complements_suite(),
                     s21_inverse_matrix_suite(), NULL};
  SRunner* sr = srunner_create(NULL);
  for (int i = 0; suites[i] != NULL; ++i) srunner_add_suite(sr, suites[i]);
  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}