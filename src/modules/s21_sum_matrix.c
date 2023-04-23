#include "../s21_matrix.h"

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  if (validate_matrix(2, A, B) || !is_matrix_same_size(2, A, B)) {
    return INCORRECT_MATRIX;
  }

  int error_code = OK;
  error_code = s21_create_matrix(A->rows, A->columns, result);
  if (!error_code) {
    for (int i = 0; i < A->rows && error_code == OK; i++) {
      for (int j = 0; j < A->columns && error_code == OK; j++) {
        result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
        if (!isfinite(result->matrix[i][j])) {
          error_code = CALCULATION_ERROR;
        }
      }
    }
  }

  return error_code;
}