#include "check_s21_matrix.h"

START_TEST(null_ptr_check_s21_inverse_matrix) {
  matrix_t result;
  ck_assert_int_eq(s21_inverse_matrix(NULL, &result),
                   CODE_INCORRECT_MATRIX_ERROR);
}
END_TEST

START_TEST(not_square_matrix_check_s21_inverse_matrix) {
  matrix_t test, result;
  s21_create_matrix(4, 3, &test);
  ck_assert_int_eq(s21_inverse_matrix(&test, &result), CODE_CALCULATION_ERROR);
  s21_remove_matrix(&test);
}
END_TEST

START_TEST(one_row_check_s21_inverse_matrix) {
  matrix_t test, result;
  s21_create_matrix(1, 1, &test);

  ck_assert_int_eq(s21_inverse_matrix(&test, &result), CODE_CALCULATION_ERROR);
  s21_remove_matrix(&test);
}
END_TEST

START_TEST(zero_determinant_check_s21_inverse_matrix) {
  matrix_t test, result;
  s21_create_matrix(2, 2, &test);
  double test_data[] = {1.2, -2.3, 2.4, -4.6};
  _fill_matrix_with_values(&test, test_data);

  ck_assert_int_eq(s21_inverse_matrix(&test, &result), CODE_CALCULATION_ERROR);
  s21_remove_matrix(&test);
}
END_TEST

START_TEST(simple_matrix_check_s21_inverse_matrix) {
  matrix_t test, data, result;
  s21_create_matrix(2, 2, &test);
  s21_create_matrix(2, 2, &data);
  double test_data[] = {1.2, -2.3, -5.6, 4.2},
         result_data[] = {-15. / 28., -115. / 392., -5. / 7., -15. / 98.};
  _fill_matrix_with_values(&test, test_data);
  _fill_matrix_with_values(&data, result_data);

  ck_assert_int_eq(s21_inverse_matrix(&test, &result), CODE_OK);
  ck_assert_int_eq(s21_eq_matrix(&data, &result), SUCCESS);
  s21_remove_matrix(&test);
  s21_remove_matrix(&data);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(common_matirx_check_s21_inverse_matrix) {
  matrix_t test, data, result;
  s21_create_matrix(3, 3, &test);
  s21_create_matrix(3, 3, &data);
  const double test_data[] = {1., 5., 8., 3., 2., 1., 4., 4., 2.},
               result_data[] = {0.,        1,          -1. / 2.,
                                -1. / 11., -15. / 11., 23. / 22.,
                                2. / 11.,  8. / 11.,   -13. / 22.};
  _fill_matrix_with_values(&test, test_data);
  _fill_matrix_with_values(&data, result_data);

  ck_assert_int_eq(s21_inverse_matrix(&test, &result), CODE_OK);
  ck_assert_int_eq(s21_eq_matrix(&data, &result), SUCCESS);
  s21_remove_matrix(&test);
  s21_remove_matrix(&data);
  s21_remove_matrix(&result);
}
END_TEST

Suite *s21_inverse_matrix_suite() {
  Suite *s = suite_create("s21_inverse_matrix");
  TCase *tc_corner = tcase_create("corner");

  tcase_add_test(tc_corner, null_ptr_check_s21_inverse_matrix);
  tcase_add_test(tc_corner, not_square_matrix_check_s21_inverse_matrix);
  tcase_add_test(tc_corner, one_row_check_s21_inverse_matrix);
  tcase_add_test(tc_corner, zero_determinant_check_s21_inverse_matrix);
  tcase_add_test(tc_corner, simple_matrix_check_s21_inverse_matrix);
  tcase_add_test(tc_corner, common_matirx_check_s21_inverse_matrix);
  suite_add_tcase(s, tc_corner);

  return s;
}