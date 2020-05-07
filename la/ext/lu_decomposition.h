/*
 * Declarations for LU decomposition functions.
 * Implementations in lu_decomposition.c are pulled directly from Wikipedia.
 * https://en.wikipedia.org/wiki/LU_decomposition
 * All credit goes to Wikipedia.
 */

int LUPDecompose(long double **A, int N, long double Tol, int *P);

void LUPSolve(long double **A, int *P, long double *b, int N, long double *x);

void LUPInvert(long double **A, int *P, int N, long double **IA);

long double LUPDeterminant(long double **A, int *P, int N);
