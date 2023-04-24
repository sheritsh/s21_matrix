#ifndef S21_HELPER_FUNCTIONS
#define S21_HELPER_FUNCTIONS

#include "../s21_matrix.h"

/**
 * @brief The function validates matrix pointers and pointers to the location of
 * the matrices themselves in memory
 * @param matrix_amount
 * @param A pointer to the first matrix
 * @param ... pointers to other matrices
 * @return ERROR CODE :
 * 0 - all matrices have been successfully checked
 * 1 - an error occurred
 */
int s21_validate_matrix(int matrix_amount, matrix_t* A, ...);

/**
 * @brief The function checks if all passed matrices have the same dimensions
 * @param matrix_amount
 * @param A pointer to the first matrix
 * @param ... pointers to other matrices
 * @return CHECK STATUS :
 * 0 - matrices do not match in size
 * 1 - all matrices are identical in size
 */
int s21_is_matrix_same_size(int matrix_amount, matrix_t* A, ...);

/**
 * @brief Counting the multiplication of two matrices via formula
 * @param i shift by i elements
 * @param j shift by j elements
 * @param A pointer to the first matrix
 * @param B pointer to the second matrix
 * @return result in double
 */
double s21_mult_matrix_res(int i, int j, matrix_t* A, matrix_t* B);

#endif  // S21_HELPER_FUNCTIONS
