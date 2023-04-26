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
 * @brief Counting the multiplication of two matrices via formula. Be careful,
 * this function does not check pointers to matrices.
 * @param i shift by i elements
 * @param j shift by j elements
 * @param A pointer to the first matrix
 * @param B pointer to the second matrix
 * @return result in double
 */
double s21_mult_matrix_res(int i, int j, matrix_t* A, matrix_t* B);

/**
 * @brief Creates a minor matrix for the A[i][j] element. Be careful with this
 * function. Can return NULL!
 * @param excluded_row excluded row number
 * @param excluded_column excluded column number
 * @param A pointer to the initial matrix
 * @return Pointer to the resulting minor matrix
 */
matrix_t* s21_create_minor(int excluded_row, int excluded_column, matrix_t* A);

/**
 * @brief The function checks the matrix for squareness
 * @param A pointer to the input matrix
 * @return 1 - SUCCESS; 0 - ERROR
 */
int s21_is_matrix_square(matrix_t* A);

/**
 * @brief The function initializes the entire matrix with values
 * ​​​​from the given one and each time increasing by an iteration step
 * @param A pointer to the matrix to be initialized
 * @param start_value first value to initialize
 * @param iteration_step iteration step
 */
void s21_initialize_matrix(matrix_t* A, double start_value,
                           double iteration_step);

/**
 * @brief The function prints the entire matrix to the console
 * @param A pointer to the matrix
 */
void s21_print_matrix(matrix_t* A);

#endif  // S21_HELPER_FUNCTIONS
