#include "check_s21_matrix.h"

START_TEST(null_ptr_check_s21_mult_number) {
  matrix_t result;
  ck_assert_int_eq(s21_mult_number(NULL, 2.5, &result),
                   CODE_INCORRECT_MATRIX_ERROR);
}
END_TEST

START_TEST(common_number_check_s21_mult_number) {
  matrix_t lhs, result, test;
  s21_create_matrix(2, 2, &lhs);
  s21_create_matrix(2, 2, &test);
  double num = 2.5, lhs_test_data[] = {1.2,   3.4,   5.6,   7.8,  9.1,
                                       1.112, 1.314, 1.516, 1.718},
         result_test_data[] = {3.,   8.5,   14.,  19.5, 22.75,
                               2.78, 3.285, 3.79, 4.295};
  _fill_matrix_with_values(&lhs, lhs_test_data);
  _fill_matrix_with_values(&test, result_test_data);
  ck_assert_int_eq(s21_mult_number(&lhs, num, &result), CODE_OK);
  ck_assert_int_eq(s21_eq_matrix(&test, &result), SUCCESS);
  s21_remove_matrix(&lhs);
  s21_remove_matrix(&test);
  s21_remove_matrix(&result);
}
END_TEST

Suite *s21_mult_number_suite() {
  Suite *s = suite_create("s21_mult_number");
  TCase *tc_corner = tcase_create("corner");

  tcase_add_test(tc_corner, null_ptr_check_s21_mult_number);
  tcase_add_test(tc_corner, common_number_check_s21_mult_number);
  suite_add_tcase(s, tc_corner);

  return s;
}