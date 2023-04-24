#include "s21_helper_functions.h"

int validate_matrix(int matrix_amount, matrix_t *A, ...) {
  int matrices_status = OK;

  va_list matrix_list;
  va_start(matrix_list, A);
  for (int i = 0; i < matrix_amount - 1 && matrices_status == OK; i++) {
    matrix_t *current_matrix = va_arg(matrix_list, matrix_t *);
    if (current_matrix == NULL || current_matrix->matrix == NULL) {
      matrices_status = INCORRECT_MATRIX;
    }
  }
  va_end(matrix_list);

  return matrices_status;
}

int is_matrix_same_size(int matrix_amount, matrix_t *A, ...) {
  if (A == NULL) {
    return FAILURE;
  }

  int dimensions_comp_status = SUCCESS;
  int rows_to_compare = A->rows;
  int columns_to_compare = A->columns;

  va_list matrix_list;
  va_start(matrix_list, A);
  for (int i = 0; i < matrix_amount - 1 && dimensions_comp_status == SUCCESS;
       i++) {
    matrix_t *current_matrix = va_arg(matrix_list, matrix_t *);
    if (current_matrix == NULL || current_matrix->rows != rows_to_compare ||
        current_matrix->columns != columns_to_compare) {
      dimensions_comp_status = FAILURE;
    }
  }
  va_end(matrix_list);

  return dimensions_comp_status;
}

double mult_matrix_res(int i, int j, matrix_t *A, matrix_t *B) {
  double res = 0;

  // Burroughs reference
  for (int k = 0; k < B->rows; k++) {
    res += A->matrix[i][k] * B->matrix[k][j];
  }

  return res;
}