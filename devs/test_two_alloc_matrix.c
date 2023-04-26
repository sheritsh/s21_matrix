#include <stdio.h>
#include <stdlib.h>

#define rows 6
#define columns 4

void initialize_matrix(double **A);
void print_matrix(double **A);

int main(void) {
  double **A = (double **)malloc(rows * sizeof(double *));
  double *vals = (double *)malloc(rows * columns * sizeof(double));
  for (int i = 0; i < columns; i++) {
    A[i] = vals + rows * i;
  }
  initialize_matrix(A);
  print_matrix(A);
  printf("-----------------\n");
  printf("[%.f]", A[1][1]);
  free(A);
  free(vals);
  A = NULL;
  vals = NULL;
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