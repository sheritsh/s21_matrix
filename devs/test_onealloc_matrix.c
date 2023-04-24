#include <stdio.h>
#include <stdlib.h>

#define rows 5
#define columns 5

void initialize_matrix(double **A);
void print_matrix(double **A);

int main(void) {
  printf("Size of double %ld\n", sizeof(double));
  printf("Size of double* %ld\n", sizeof(double *));
  double **A = (double **)calloc(rows + rows*columns, sizeof(double)); // 
  double *start = (double *)(A + rows);

  for (int i = 0; i < columns; i++) {
    A[i] = start + i * columns;
  }
  initialize_matrix(A);
  print_matrix(A);
  printf("-----------------\n");
  printf("[%.f]\n", A[1][1]);
  printf("%.10f\n", 1e-7);
  free(A);
  A = NULL;
  return 0;
}

void initialize_matrix(double **A) {
  int counter = 1;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      A[i][j] = counter;
      counter++;
    }
  }
}

void print_matrix(double **A) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      printf("%.f\t", A[i][j]);
    }
    printf("\n");
  }
}