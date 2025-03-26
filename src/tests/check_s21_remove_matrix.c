#include "check_s21_matrix.h"

START_TEST(common_matrix_check_s21_remove_matrix) {
  matrix_t test;
  s21_create_matrix(5, 5, &test);
  s21_remove_matrix(&test);
  ck_assert_int_eq(test.rows, 0);
  ck_assert_int_eq(test.columns, 0);
  ck_assert_ptr_null(test.matrix);
}
END_TEST

START_TEST(additional_check_s21_remove_matrix) {
  matrix_t test;
  int test1_rows = 25, test1_columns = 10, test2_rows = 10, test2_columns = 25;

  s21_create_matrix(test1_rows, test1_columns, &test);
  s21_remove_matrix(&test);
  ck_assert_int_eq(test.rows, 0);
  ck_assert_int_eq(test.columns, 0);
  ck_assert_ptr_null(test.matrix);

  s21_create_matrix(test2_rows, test2_columns, &test);
  s21_remove_matrix(&test);
  ck_assert_int_eq(test.rows, 0);
  ck_assert_int_eq(test.columns, 0);
  ck_assert_ptr_null(test.matrix);
}
END_TEST

Suite *s21_remove_matrix_suite() {
  Suite *s = suite_create("s21_remove_matrix");
  TCase *tc_corner = tcase_create("corner"),
        *tc_additional = tcase_create("additional");

  tcase_add_test(tc_corner, common_matrix_check_s21_remove_matrix);
  suite_add_tcase(s, tc_corner);

  tcase_add_test(tc_additional, additional_check_s21_remove_matrix);
  suite_add_tcase(s, tc_additional);
  return s;
}