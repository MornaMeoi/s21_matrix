#include "check_s21_matrix.h"

START_TEST(null_ptr_check_s21_calc_complements) {
  matrix_t result;
  ck_assert_int_eq(s21_calc_complements(NULL, &result),
                   CODE_INCORRECT_MATRIX_ERROR);
}
END_TEST

START_TEST(not_square_matrix_check_s21_calc_complements) {
  matrix_t test, result;
  s21_create_matrix(4, 3, &test);
  ck_assert_int_eq(s21_calc_complements(&test, &result),
                   CODE_CALCULATION_ERROR);
  s21_remove_matrix(&test);
}
END_TEST

START_TEST(one_row_check_s21_calc_complements) {
  matrix_t test, result;
  s21_create_matrix(1, 1, &test);

  ck_assert_int_eq(s21_calc_complements(&test, &result),
                   CODE_CALCULATION_ERROR);
  s21_remove_matrix(&test);
}
END_TEST

START_TEST(simple_matrix_check_s21_calc_complements) {
  matrix_t test, data, result;
  s21_create_matrix(2, 2, &test);
  s21_create_matrix(2, 2, &data);
  double test_data[] = {1.2432, -432.1, 32.123, -0.321},
         result_data[] = {-0.321, -32.123, 432.1, 1.2432};
  _fill_matrix_with_values(&test, test_data);
  _fill_matrix_with_values(&data, result_data);

  ck_assert_int_eq(s21_calc_complements(&test, &result), CODE_OK);
  ck_assert_int_eq(s21_eq_matrix(&data, &result), SUCCESS);
  s21_remove_matrix(&test);
  s21_remove_matrix(&data);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(common_matirx_check_s21_calc_complements) {
  matrix_t test, data, result;
  s21_create_matrix(3, 3, &test);
  s21_create_matrix(3, 3, &data);
  const double test_data[] = {1.2, -2.3, 3.4, -4.5, 5.6, -6.7, 7.8, -8.9, 9.1},
               result_data[] = {-8.67, -11.31, -3.63, -9.33, -15.6,
                                -7.26, -3.63,  -7.26, -3.63};
  _fill_matrix_with_values(&test, test_data);
  _fill_matrix_with_values(&data, result_data);

  ck_assert_int_eq(s21_calc_complements(&test, &result), CODE_OK);
  ck_assert_int_eq(s21_eq_matrix(&data, &result), SUCCESS);
  s21_remove_matrix(&test);
  s21_remove_matrix(&data);
  s21_remove_matrix(&result);
}
END_TEST

Suite *s21_calc_complements_suite() {
  Suite *s = suite_create("s21_calc_complements");
  TCase *tc_corner = tcase_create("corner");

  tcase_add_test(tc_corner, null_ptr_check_s21_calc_complements);
  tcase_add_test(tc_corner, not_square_matrix_check_s21_calc_complements);
  tcase_add_test(tc_corner, one_row_check_s21_calc_complements);
  tcase_add_test(tc_corner, simple_matrix_check_s21_calc_complements);
  tcase_add_test(tc_corner, common_matirx_check_s21_calc_complements);
  suite_add_tcase(s, tc_corner);

  return s;
}