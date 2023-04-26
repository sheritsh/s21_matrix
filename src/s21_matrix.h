/* created by sheritsh // Oleg Polovinko ※ School 21, Kzn */
#ifndef S21_MATRIX_H
#define S21_MATRIX_H

#include <math.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 1
#define FAILURE 0

typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
} matrix_t;

enum ERROR_CODES { OK, INCORRECT_MATRIX, CALCULATION_ERROR };

#include "modules/s21_helper_functions.h"

/**
 * @brief Creates a matrix and physically allocates space for it in memory (on
 * the heap)
 * @param rows number of rows
 * @param columns number of columns
 * @param result pointer to the memory location where the matrix needs to be
 * created
 * @return ERROR CODE :
 * 0 - OK
 * 1 - Error, incorrect matrix
 * 2 - Calculation error (mismatched matrix sizes; matrix for which calculations
 * cannot be performed, etc.)
 */
int s21_create_matrix(int rows, int columns, matrix_t *result);

/**
 * @brief Remove the matrix and frees  allocated memory areas
 * @param A matrix pointer
 */
void s21_remove_matrix(matrix_t *A);

/**
 * @brief Compares two matrices. They are considered the same if they have the
 * same size and all elements A[i][j] == B[i][j]
 * @param A pointer to the first matrix
 * @param B pointer to the second matrix
 * @return 0 - FAILURE, 1 - SUCCESS
 */
int s21_eq_matrix(matrix_t *A, matrix_t *B);

/**
 * @brief The sum of two matrices A = m × n and B = m × n of the same size is a
 * matrix C = m × n = A + B of the same size whose elements are defined by the
 * equations C(i,j) = A(i,j) + B(i,j). The comparison must be up to and
 * including 7 decimal places
 * @param A pointer to the first matrix
 * @param B pointer to the second matrix
 * @param result pointer to the resulting matrix
 * @return ERROR CODE :
 * 0 - OK
 * 1 - Error, incorrect matrix
 * 2 - Calculation error (mismatched matrix sizes; matrix for which calculations
 * cannot be performed, etc.)
 */
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

/**
 * @brief The difference of two matrices A = m × n and B = m × n of the same
 * size is a matrix C = m × n = A - B of the same size whose elements are
 * defined by the equations C(i,j) = A(i,j) - B(i,j)
 * @param A pointer to the first matrix
 * @param B pointer to the second matrix
 * @param result pointer to the resulting matrix
 * @return ERROR CODE :
 * 0 - OK
 * 1 - Error, incorrect matrix
 * 2 - Calculation error (mismatched matrix sizes; matrix for which calculations
 * cannot be performed, etc.)
 */
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

/**
 * @brief The product of the matrix A = m × n by the number λ is the matrix B =
 * m × n = λ × A whose elements are defined by the equations B = λ × A(i,j)
 * @param A pointer to the input matrix
 * @param number real number
 * @param result pointer to the resulting matrix
 * @return ERROR CODE :
 * 0 - OK
 * 1 - Error, incorrect matrix
 * 2 - Calculation error (mismatched matrix sizes; matrix for which calculations
 * cannot be performed, etc.)
 */
int s21_mult_number(matrix_t *A, double number, matrix_t *result);

/**
 * @brief The product of A = m × k by B = k × n is a matrix C = m × n = A × B of
 * size m × n whose elements are defined by the equation C(i,j) = A(i,1) ×
 * B(1,j) + A(i,2) × B(2,j) + ... + A(i,k) × B(k,j)
 * @param A pointer to the first matrix
 * @param B pointer to the second matrix
 * @param result pointer to the resulting matrix
 * @return ERROR CODE :
 * 0 - OK
 * 1 - Error, incorrect matrix
 * 2 - Calculation error (mismatched matrix sizes; matrix for which calculations
 * cannot be performed, etc.)
 */
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

/**
 * @brief The transpose of matrix A is in switching its rows with its columns
 * with their numbers retained
 * @param A pointer to the input matrix
 * @param result pointer to the resulting matrix
 * @return ERROR CODE :
 * 0 - OK
 * 1 - Error, incorrect matrix
 * 2 - Calculation error (mismatched matrix sizes; matrix for which calculations
 * cannot be performed, etc.)
 */
int s21_transpose(matrix_t *A, matrix_t *result);

/**
 * @brief The algebraic complement of a matrix element is the value of the minor
 * multiplied by -1^(i+j)
 * @param A pointer to the input matrix
 * @param result pointer to the resulting matrix
 * @return ERROR CODE :
 * 0 - OK
 * 1 - Error, incorrect matrix
 * 2 - Calculation error (mismatched matrix sizes; matrix for which calculations
 * cannot be performed, etc.)
 */
int s21_calc_complements(matrix_t *A, matrix_t *result);

/**
 * @brief The determinant is a number that is associated to each square matrix
 * and calculated from the elements. The determinant can only be calculated for
 * a square matrix.
 * @param A pointer to the input matrix
 * @param result pointer to the resulting matrix
 * @return ERROR CODE :
 * 0 - OK
 * 1 - Error, incorrect matrix
 * 2 - Calculation error (mismatched matrix sizes; matrix for which calculations
 * cannot be performed, etc.)
 */
int s21_determinant(matrix_t *A, double *result);

/**
 * @brief A matrix A to the power of -1 is called the inverse of a square matrix
 * A if the product of these matrices equals the identity matrix. If the
 * determinant of the matrix is zero, then it does not have an inverse.
 * @param A pointer to the input matrix
 * @param result pointer to the resulting matrix
 * @return ERROR CODE :
 * 0 - OK
 * 1 - Error, incorrect matrix
 * 2 - Calculation error (mismatched matrix sizes; matrix for which calculations
 * cannot be performed, etc.)
 */
int s21_inverse_matrix(matrix_t *A, matrix_t *result);

#endif