#include "check_s21_matrix.h"

START_TEST(null_ptr_check_s21_transpose) {
  matrix_t result;
  ck_assert_int_eq(s21_transpose(NULL, &result), CODE_INCORRECT_MATRIX_ERROR);
}
END_TEST

START_TEST(simple_check_s21_transpose) {
  matrix_t lhs, result, test;
  s21_create_matrix(1, 3, &lhs);
  s21_create_matrix(3, 1, &test);
  double test_data[] = {1.2, 3.4, 5.6};
  _fill_matrix_with_values(&lhs, test_data);
  _fill_matrix_with_values(&test, test_data);
  ck_assert_int_eq(s21_transpose(&lhs, &result), CODE_OK);
  ck_assert_int_eq(s21_eq_matrix(&test, &result), SUCCESS);
  s21_remove_matrix(&lhs);
  s21_remove_matrix(&test);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(common_check_s21_transpose) {
  matrix_t lhs, result, test;
  s21_create_matrix(3, 3, &lhs);
  s21_create_matrix(3, 3, &test);
  double lhs_data[] = {1.2, 3.4, -5.6, -7.8, 9.1, 1.112, 1.314, -1.516, 1.718},

         test_data[] = {1.2, -7.8, 1.314, 3.4, 9.1, -1.516, -5.6, 1.112, 1.718};
  _fill_matrix_with_values(&lhs, lhs_data);
  _fill_matrix_with_values(&test, test_data);
  ck_assert_int_eq(s21_transpose(&lhs, &result), CODE_OK);
  ck_assert_int_eq(s21_eq_matrix(&test, &result), SUCCESS);
  s21_remove_matrix(&lhs);
  s21_remove_matrix(&test);
  s21_remove_matrix(&result);
}
END_TEST

Suite *s21_transpose_suite() {
  Suite *s = suite_create("s21_transpose");
  TCase *tc_corner = tcase_create("corner");

  tcase_add_test(tc_corner, null_ptr_check_s21_transpose);
  tcase_add_test(tc_corner, simple_check_s21_transpose);
  tcase_add_test(tc_corner, common_check_s21_transpose);
  suite_add_tcase(s, tc_corner);

  return s;
}