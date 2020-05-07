/*
 * All code in this file are pulled directly from Wikipedia.
 * https://en.wikipedia.org/wiki/LU_decomposition
 * All credit goes to Wikipedia.
 * Modifications made to change precision.
 */

#include <math.h>
#include "lu_decomposition.h"

// ------------------------------------------------------------

int LUPDecompose(long double **A, int N, long double Tol, int *P) {

    int i, j, k, imax;
    long double maxA, *ptr, absA;

    for (i = 0; i <= N; i++)
        P[i] = i;

    for (i = 0; i < N; i++) {
        maxA = 0.0;
        imax = i;

        for (k = i; k < N; k++)
            if ((absA = fabs(A[k][i])) > maxA) {
                maxA = absA;
                imax = k;
            }

        if (maxA < Tol) return 0;

        if (imax != i) {

            j = P[i];
            P[i] = P[imax];
            P[imax] = j;

            ptr = A[i];
            A[i] = A[imax];
            A[imax] = ptr;

            P[N]++;
        }

        for (j = i + 1; j < N; j++) {
            A[j][i] /= A[i][i];

            for (k = i + 1; k < N; k++)
                A[j][k] -= A[j][i] * A[i][k];
        }
    }

    return 1;
}

// ------------------------------------------------------------

void LUPSolve(long double **A, int *P, long double *b, int N, long double *x) {

    for (int i = 0; i < N; i++) {
        x[i] = b[P[i]];

        for (int k = 0; k < i; k++)
            x[i] -= A[i][k] * x[k];
    }

    for (int i = N - 1; i >= 0; i--) {
        for (int k = i + 1; k < N; k++)
            x[i] -= A[i][k] * x[k];

        x[i] = x[i] / A[i][i];
    }
}

// ------------------------------------------------------------

void LUPInvert(long double **A, int *P, int N, long double **IA) {

    for (int j = 0; j < N; j++) {
        for (int i = 0; i < N; i++) {
            if (P[i] == j)
                IA[i][j] = 1.0;
            else
                IA[i][j] = 0.0;

            for (int k = 0; k < i; k++)
                IA[i][j] -= A[i][k] * IA[k][j];
        }

        for (int i = N - 1; i >= 0; i--) {
            for (int k = i + 1; k < N; k++)
                IA[i][j] -= A[i][k] * IA[k][j];

            IA[i][j] = IA[i][j] / A[i][i];
        }
    }
}

// ------------------------------------------------------------

long double LUPDeterminant(long double **A, int *P, int N) {

    long double det = A[0][0];

    for (int i = 1; i < N; i++)
        det *= A[i][i];

    if ((P[N] - N) % 2 == 0)
        return det;
    else
        return -det;
}
