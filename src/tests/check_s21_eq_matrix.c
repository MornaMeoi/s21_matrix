#include "check_s21_matrix.h"

START_TEST(null_ptr_check_s21_eq_matrix) {
  matrix_t rhs;
  s21_create_matrix(4, 3, &rhs);
  ck_assert_int_eq(s21_eq_matrix(NULL, &rhs), FAILURE);
  s21_remove_matrix(&rhs);
}
END_TEST

START_TEST(unequal_rows_check_s21_eq_matrix) {
  matrix_t lhs, rhs;
  s21_create_matrix(4, 4, &lhs);
  s21_create_matrix(3, 4, &rhs);
  ck_assert_int_eq(s21_eq_matrix(&lhs, &rhs), FAILURE);
  s21_remove_matrix(&lhs);
  s21_remove_matrix(&rhs);
}
END_TEST

START_TEST(unequal_columns_check_s21_eq_matrix) {
  matrix_t lhs, rhs;
  s21_create_matrix(4, 4, &lhs);
  s21_create_matrix(4, 3, &rhs);
  ck_assert_int_eq(s21_eq_matrix(&lhs, &rhs), FAILURE);
  s21_remove_matrix(&lhs);
  s21_remove_matrix(&rhs);
}
END_TEST

START_TEST(common_equal_matrix_check_s21_eq_matrix) {
  matrix_t lhs, rhs;
  s21_create_matrix(3, 3, &lhs);
  s21_create_matrix(3, 3, &rhs);
  double test_data[] = {1.2,    -3.4,  5.6,   -7.8,  9.1,
                        -1.112, 1.314, 1.516, -1.718};
  _fill_matrix_with_values(&lhs, test_data);
  _fill_matrix_with_values(&rhs, test_data);
  ck_assert_int_eq(s21_eq_matrix(&lhs, &rhs), SUCCESS);
  s21_remove_matrix(&lhs);
  s21_remove_matrix(&rhs);
}
END_TEST

START_TEST(common_unequal_matrix_check_s21_eq_matrix) {
  matrix_t lhs, rhs;
  s21_create_matrix(3, 3, &lhs);
  s21_create_matrix(3, 3, &rhs);
  double lhs_test_data[] = {1.2,   -3.4,  5.6,   -7.8, 9.1,
                            1.112, 1.314, 1.516, 1.718},
         rhs_test_data[] = {1.2,   -3.4,  5.6,  -7.8, 9.1,
                            1.112, 1.314, 2.28, 1.718};
  _fill_matrix_with_values(&lhs, lhs_test_data);
  _fill_matrix_with_values(&rhs, rhs_test_data);
  ck_assert_int_eq(s21_eq_matrix(&lhs, &rhs), FAILURE);
  s21_remove_matrix(&lhs);
  s21_remove_matrix(&rhs);
}
END_TEST

START_TEST(out_of_precision_check_s21_eq_matrix) {
  matrix_t lhs, rhs;
  s21_create_matrix(2, 2, &lhs);
  s21_create_matrix(2, 2, &rhs);
  double lhs_test_data[] = {0.123456742, -0.123456759, -0.123456772,
                            0.123456747},
         rhs_test_data[] = {0.123456731, -0.123456786, -0.123456799, 0.1234567};
  _fill_matrix_with_values(&lhs, lhs_test_data);
  _fill_matrix_with_values(&rhs, rhs_test_data);
  ck_assert_int_eq(s21_eq_matrix(&lhs, &rhs), SUCCESS);
  s21_remove_matrix(&lhs);
  s21_remove_matrix(&rhs);
}
END_TEST

Suite *s21_eq_matrix_suite() {
  Suite *s = suite_create("s21_eq_matrix");
  TCase *tc_corner = tcase_create("corner");

  tcase_add_test(tc_corner, null_ptr_check_s21_eq_matrix);
  tcase_add_test(tc_corner, unequal_rows_check_s21_eq_matrix);
  tcase_add_test(tc_corner, unequal_columns_check_s21_eq_matrix);
  tcase_add_test(tc_corner, common_equal_matrix_check_s21_eq_matrix);
  tcase_add_test(tc_corner, common_unequal_matrix_check_s21_eq_matrix);
  tcase_add_test(tc_corner, out_of_precision_check_s21_eq_matrix);
  suite_add_tcase(s, tc_corner);

  return s;
}