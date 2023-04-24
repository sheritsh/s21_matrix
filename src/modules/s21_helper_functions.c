#include "s21_helper_functions.h"

int s21_validate_matrix(int matrix_amount, matrix_t *A, ...) {
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

int s21_is_matrix_same_size(int matrix_amount, matrix_t *A, ...) {
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

double s21_mult_matrix_res(int i, int j, matrix_t *A, matrix_t *B) {
  double res = 0;

  // Burroughs reference
  for (int k = 0; k < B->rows; k++) {
    res += A->matrix[i][k] * B->matrix[k][j];
  }

  return res;
}

matrix_t *s21_create_minor(int excluded_row, int excluded_column, matrix_t *A) {
  if (A == NULL) {
    return NULL;
  }

  matrix_t *minor = malloc(sizeof(matrix_t));
  if (minor != NULL) {
    if (s21_create_matrix(A->rows - 1, A->columns - 1, minor) == 0) {
      for (int i = 0, minor_row = 0; i < A->rows; i++) {
        if (i == excluded_row) {
          continue;
        }
        for (int j = 0, minor_column = 0; j < A->columns; j++) {
          if (j == excluded_column) {
            continue;
          }
          minor->matrix[minor_row][minor_column] = A->matrix[i][j];
          minor_column++;
        }
        minor_row++;
      }
    }
  }

  return minor;
}

int s21_is_matrix_square(matrix_t *A) {
  if (A == NULL) {
    return 0;
  }
  return A->rows == A->columns ? 1 : 0;
}