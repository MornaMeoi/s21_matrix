#include "check_s21_matrix.h"

START_TEST(null_ptr_check_s21_determinant) {
  double result;
  ck_assert_int_eq(s21_determinant(NULL, &result), CODE_INCORRECT_MATRIX_ERROR);
}
END_TEST

START_TEST(not_square_matrix_check_s21_determinant) {
  matrix_t test;
  double result;
  s21_create_matrix(4, 3, &test);
  ck_assert_int_eq(s21_determinant(&test, &result), CODE_CALCULATION_ERROR);
  s21_remove_matrix(&test);
}
END_TEST

START_TEST(one_row_check_s21_determinant) {
  matrix_t test;
  double result;
  s21_create_matrix(1, 1, &test);
  double test_data[] = {1.2432};
  _fill_matrix_with_values(&test, test_data);

  ck_assert_int_eq(s21_determinant(&test, &result), CODE_OK);
  ck_assert_double_eq_tol(test_data[0], result, 1e-7);
  s21_remove_matrix(&test);
}
END_TEST

START_TEST(simple_matrix_check_s21_determinant) {
  matrix_t test;
  double result;
  s21_create_matrix(2, 2, &test);
  double test_data[] = {1.2432, -432.1, 32.123, -0.321};
  _fill_matrix_with_values(&test, test_data);

  ck_assert_int_eq(s21_determinant(&test, &result), CODE_OK);
  ck_assert_double_eq_tol(13879.9492328, result, 1e-7);
  s21_remove_matrix(&test);
}
END_TEST

START_TEST(singular_matrix_check_s21_determinant) {
  matrix_t test;
  double result;
  s21_create_matrix(2, 2, &test);
  double test_data[] = {1.2, -2.3, 2.4, -4.6};
  _fill_matrix_with_values(&test, test_data);

  ck_assert_int_eq(s21_determinant(&test, &result), CODE_OK);
  ck_assert_double_eq_tol(0, result, 1e-7);
  s21_remove_matrix(&test);
}
END_TEST

START_TEST(common_matirx_check_s21_determinant) {
  matrix_t test;
  double result;
  s21_create_matrix(3, 3, &test);
  double test_data[] = {1.2, -2.3, 3.4, -4.5, 5.6, -6.7, 7.8, -8.9, 9.1};
  _fill_matrix_with_values(&test, test_data);

  ck_assert_int_eq(s21_determinant(&test, &result), CODE_OK);
  ck_assert_double_eq_tol(3.267, result, 1e-7);
  s21_remove_matrix(&test);
}
END_TEST

START_TEST(big_matrix_check_s21_determinant) {
  matrix_t test;
  double result;
  s21_create_matrix(5, 5, &test);
  double test_data[] = {
      5.,  -2., 3.,  -4.,  5.,  7.,   -8., 9.,  -10., 6.,  13.,  -14., 15.,
      -2., 17., 19., -20., 31., -22., 23., 25., -1.,  27., -28., 29.,
  };
  _fill_matrix_with_values(&test, test_data);

  ck_assert_int_eq(s21_determinant(&test, &result), CODE_OK);
  ck_assert_double_eq_tol(-13260., result, 1e-7);
  s21_remove_matrix(&test);
}
END_TEST

Suite *s21_determinant_suite() {
  Suite *s = suite_create("s21_determinant");
  TCase *tc_corner = tcase_create("corner");

  tcase_add_test(tc_corner, null_ptr_check_s21_determinant);
  tcase_add_test(tc_corner, not_square_matrix_check_s21_determinant);
  tcase_add_test(tc_corner, one_row_check_s21_determinant);
  tcase_add_test(tc_corner, simple_matrix_check_s21_determinant);
  tcase_add_test(tc_corner, singular_matrix_check_s21_determinant);
  tcase_add_test(tc_corner, common_matirx_check_s21_determinant);
  tcase_add_test(tc_corner, big_matrix_check_s21_determinant);
  suite_add_tcase(s, tc_corner);

  return s;
}