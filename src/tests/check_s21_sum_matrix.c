#include "check_s21_matrix.h"

START_TEST(null_ptr_check_s21_sum_matrix) {
  matrix_t rhs, result;
  s21_create_matrix(4, 3, &rhs);
  ck_assert_int_eq(s21_sum_matrix(NULL, &rhs, &result),
                   CODE_INCORRECT_MATRIX_ERROR);
  s21_remove_matrix(&rhs);
}
END_TEST

START_TEST(unequal_rows_check_s21_sum_matrix) {
  matrix_t lhs, rhs, result;
  s21_create_matrix(4, 4, &lhs);
  s21_create_matrix(3, 4, &rhs);
  ck_assert_int_eq(s21_sum_matrix(&lhs, &rhs, &result), CODE_CALCULATION_ERROR);
  s21_remove_matrix(&lhs);
  s21_remove_matrix(&rhs);
}
END_TEST

START_TEST(unequal_columns_check_s21_sum_matrix) {
  matrix_t lhs, rhs, result;
  s21_create_matrix(4, 4, &lhs);
  s21_create_matrix(4, 3, &rhs);
  ck_assert_int_eq(s21_sum_matrix(&lhs, &rhs, &result), CODE_CALCULATION_ERROR);
  s21_remove_matrix(&lhs);
  s21_remove_matrix(&rhs);
}
END_TEST

START_TEST(common_sum_matrix_check_s21_sum_matrix) {
  matrix_t lhs, rhs, result, test;
  s21_create_matrix(2, 2, &lhs);
  s21_create_matrix(2, 2, &rhs);
  s21_create_matrix(2, 2, &test);
  double lhs_test_data[] = {1.2, 3.4, -1.2, -3.4},
         rhs_test_data[] = {-1.2, -3.4, 1.2, 3.4},
         result_test_data[] = {0., 0., 0., 0.};
  _fill_matrix_with_values(&lhs, lhs_test_data);
  _fill_matrix_with_values(&rhs, rhs_test_data);
  _fill_matrix_with_values(&test, result_test_data);
  ck_assert_int_eq(s21_sum_matrix(&lhs, &rhs, &result), CODE_OK);
  ck_assert_int_eq(s21_eq_matrix(&test, &result), SUCCESS);
  s21_remove_matrix(&lhs);
  s21_remove_matrix(&rhs);
  s21_remove_matrix(&test);
  s21_remove_matrix(&result);
}
END_TEST

Suite *s21_sum_matrix_suite() {
  Suite *s = suite_create("s21_sum_matrix");
  TCase *tc_corner = tcase_create("corner");

  tcase_add_test(tc_corner, null_ptr_check_s21_sum_matrix);
  tcase_add_test(tc_corner, unequal_rows_check_s21_sum_matrix);
  tcase_add_test(tc_corner, unequal_columns_check_s21_sum_matrix);
  tcase_add_test(tc_corner, common_sum_matrix_check_s21_sum_matrix);
  suite_add_tcase(s, tc_corner);

  return s;
}