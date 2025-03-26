#include "check_s21_matrix.h"

START_TEST(null_ptr_check_s21_mult_matrix) {
  matrix_t rhs, result;
  s21_create_matrix(4, 3, &rhs);
  ck_assert_int_eq(s21_mult_matrix(NULL, &rhs, &result),
                   CODE_INCORRECT_MATRIX_ERROR);
  s21_remove_matrix(&rhs);
}
END_TEST

START_TEST(unequal_dimensions_check_s21_mult_matrix) {
  matrix_t lhs, rhs, result;
  s21_create_matrix(3, 1, &lhs);
  s21_create_matrix(3, 1, &rhs);
  ck_assert_int_eq(s21_mult_matrix(&lhs, &rhs, &result),
                   CODE_CALCULATION_ERROR);
  s21_remove_matrix(&lhs);
  s21_remove_matrix(&rhs);
}
END_TEST

START_TEST(common_mult_matrix_check_s21_mult_matrix) {
  matrix_t lhs, rhs, result, test;
  s21_create_matrix(1, 3, &lhs);
  s21_create_matrix(3, 1, &rhs);
  s21_create_matrix(1, 1, &test);

  double lhs_test_data[] = {1.2, 3.4, 5.6}, rhs_test_data[] = {-1.2, -3.4, 1.2},
         result_test_data[] = {-6.28};
  _fill_matrix_with_values(&lhs, lhs_test_data);
  _fill_matrix_with_values(&rhs, rhs_test_data);
  _fill_matrix_with_values(&test, result_test_data);
  ck_assert_int_eq(s21_mult_matrix(&lhs, &rhs, &result), CODE_OK);
  ck_assert_int_eq(s21_eq_matrix(&test, &result), SUCCESS);

  s21_remove_matrix(&lhs);
  s21_remove_matrix(&rhs);
  s21_remove_matrix(&test);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(additional_check_s21_mult_matrix) {
  matrix_t lhs, rhs, result, test;
  s21_create_matrix(5, 1, &lhs);
  s21_create_matrix(1, 5, &rhs);
  s21_create_matrix(5, 5, &test);

  double lhs_test_data[] = {1.2, 3.4, 5.6, 5.5, 0.321},
         rhs_test_data[] = {-1.2, -3.4, 1.2, 4.7, 0.12},
         result_test_data[] = {-1.44,   -4.08,   1.44,   5.64,   0.144,
                               -4.08,   -11.56,  4.08,   15.98,  0.408,
                               -6.72,   -19.04,  6.72,   26.32,  0.672,
                               -6.6,    -18.7,   6.6,    25.85,  0.66,
                               -0.3852, -1.0914, 0.3852, 1.5087, 0.03852};
  _fill_matrix_with_values(&lhs, lhs_test_data);
  _fill_matrix_with_values(&rhs, rhs_test_data);
  _fill_matrix_with_values(&test, result_test_data);
  ck_assert_int_eq(s21_mult_matrix(&lhs, &rhs, &result), CODE_OK);
  ck_assert_int_eq(s21_eq_matrix(&test, &result), SUCCESS);

  s21_remove_matrix(&lhs);
  s21_remove_matrix(&rhs);
  s21_remove_matrix(&test);
  s21_remove_matrix(&result);
}
END_TEST

Suite *s21_mult_matrix_suite() {
  Suite *s = suite_create("s21_mult_matrix");
  TCase *tc_corner = tcase_create("corner"),
        *tc_additional = tcase_create("additional");

  tcase_add_test(tc_corner, null_ptr_check_s21_mult_matrix);
  tcase_add_test(tc_corner, unequal_dimensions_check_s21_mult_matrix);
  tcase_add_test(tc_corner, common_mult_matrix_check_s21_mult_matrix);
  suite_add_tcase(s, tc_corner);

  tcase_add_test(tc_additional, additional_check_s21_mult_matrix);
  suite_add_tcase(s, tc_additional);

  return s;
}