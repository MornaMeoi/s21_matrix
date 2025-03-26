#include "check_s21_matrix.h"

START_TEST(zeros_check_s21_create_matrix) {
  matrix_t test;
  ck_assert_int_eq(s21_create_matrix(0, 0, &test), CODE_INCORRECT_MATRIX_ERROR);
}
END_TEST

START_TEST(negative_row_check_s21_create_matrix) {
  matrix_t test;
  ck_assert_int_eq(s21_create_matrix(-5, 5, &test),
                   CODE_INCORRECT_MATRIX_ERROR);
}
END_TEST

START_TEST(negative_column_check_s21_create_matrix) {
  matrix_t test;
  ck_assert_int_eq(s21_create_matrix(5, -5, &test),
                   CODE_INCORRECT_MATRIX_ERROR);
}
END_TEST

START_TEST(null_pointer_check_s21_create_matrix) {
  ck_assert_int_eq(s21_create_matrix(5, 5, NULL), CODE_INCORRECT_MATRIX_ERROR);
}
END_TEST

START_TEST(common_matrix_check_s21_create_matrix) {
  matrix_t test;
  int test_rows = 3, test_columns = 3;
  ck_assert_int_eq(s21_create_matrix(test_rows, test_columns, &test), CODE_OK);
  ck_assert_int_eq(test.rows, test_rows);
  ck_assert_int_eq(test.columns, test_columns);
  s21_remove_matrix(&test);
}
END_TEST

START_TEST(additional_check_s21_create_matrix) {
  matrix_t test;
  int test1_rows = -1, test1_columns = -1, test2_rows = 25, test2_columns = 10,
      test3_rows = 10, test3_columns = 25;

  ck_assert_int_eq(s21_create_matrix(test1_rows, test1_columns, &test),
                   CODE_INCORRECT_MATRIX_ERROR);

  ck_assert_int_eq(s21_create_matrix(test2_rows, test2_columns, &test),
                   CODE_OK);
  ck_assert_int_eq(test.rows, test2_rows);
  ck_assert_int_eq(test.columns, test2_columns);
  s21_remove_matrix(&test);

  ck_assert_int_eq(s21_create_matrix(test3_rows, test3_columns, &test),
                   CODE_OK);
  ck_assert_int_eq(test.rows, test3_rows);
  ck_assert_int_eq(test.columns, test3_columns);
  s21_remove_matrix(&test);
}
END_TEST

Suite *s21_create_matrix_suite() {
  Suite *s = suite_create("s21_create_matrix");
  TCase *tc_corner = tcase_create("corner"),
        *tc_additional = tcase_create("additional");

  tcase_add_test(tc_corner, zeros_check_s21_create_matrix);
  tcase_add_test(tc_corner, negative_row_check_s21_create_matrix);
  tcase_add_test(tc_corner, negative_column_check_s21_create_matrix);
  tcase_add_test(tc_corner, null_pointer_check_s21_create_matrix);
  tcase_add_test(tc_corner, common_matrix_check_s21_create_matrix);
  suite_add_tcase(s, tc_corner);

  tcase_add_test(tc_additional, additional_check_s21_create_matrix);
  suite_add_tcase(s, tc_additional);
  return s;
}