/* created by sheritsh // Oleg Polovinko ※ School 21, Kzn */
#ifndef UNIT_TESTS_H
#define UNIT_TESTS_H

#include <check.h>

#include "../s21_matrix.h"
Suite* s21_matrix_inv(void);
typedef enum errors {
  INVALID = 1,
  CALC_ERR = 2,
  Matrix_NULL = 2,
} Err;

#endif  // UNIT_TESTS_H