#include <stdio.h>
#include <stdlib.h>

#define N 2048
#define blocksize 32

double A[N][N];
double B[N][N];
double C[N][N];

void fillmats(int n, double a[n][n], double b[n][n])
{
   int i, j ;
   for (i=0; i<n; i++)
      for (j=0 ; j<n; j++) {
        a[i][j] = (double)(rand() % blocksize);
        b[i][j] = (double)(rand() % blocksize);
      }
}

void print_array(int n, double a[n][n])
{
    int i, j;

    for (i=0; i<n; i++) {
        for (j = 0; j < n; j++)
            fprintf(stdout, "%lf ", a[i][j]);
        fprintf(stdout, "\n");
    }
    fprintf(stdout, "\n");
}

void basicmm(int n, double a[n][n], double b[n][n], double c[n][n])
{
   int i, j, k ;
   for (i=0;i<n; i++)
      for (j = 0; j<n; j++)
	//#pragma no_interchange
         for (k=0;k<n; k++)
            a[i][j] += b[i][k]* c[k][j] ;
}

void basicmm_simd(int n, double a[n][n], double b[n][n], double c[n][n])
{
	// pragmas added so compiler can generate better code
   int i, j, k ;
   for (i=0;i<n; i++)
      for (j = 0; j<n; j++)
         #pragma simd
         for (k=0;k<n; k++)
            a[i][j] += b[i][k]* c[k][j] ;
}

void basicmm_reorder(int n, double a[n][n], double b[n][n], double c[n][n])
{
   int i, j, k ;
   for (i=0;i<n; i++)
    for (k=0;k<n; k++)
      for (j = 0; j<n; j++)
            a[i][j] += b[i][k]* c[k][j] ;
}

void basicmm_reorder_simd(int n, double a[n][n], double b[n][n], double c[n][n])
{
	// pragmas added so compiler can generate better code
   int i, j, k ;
   for (i=0;i<n; i++)
    for (k=0;k<n; k++)
      #pragma simd
      for (j = 0; j<n; j++)
            a[i][j] += b[i][k]* c[k][j] ;
}

void basicmm_reorder_simd_blocking(int n, double a[n][n], double b[n][n], double c[n][n], int blockSize)
{
   int i, j, k, iInner, jInner, kInner ;
   for (i = 0; i < n; i+=blockSize)
    for (k = 0 ; k < n; k+=blockSize)
       for (j=0; j<n ; j+= blockSize)
          for (iInner = i; iInner<i+blockSize; iInner++)
             for (kInner = k ; kInner<k+blockSize ; kInner++)
               //#pragma vector aligned
               #pragma simd aligned
               for (jInner = j ; jInner<j+blockSize; jInner++)
                 a[iInner][jInner] += b[iInner][kInner] * c[kInner][jInner];
}

int main()
{
    fillmats(N, B, C);

#ifdef TEST
    print_array(N, B);
    print_array(N, C);
#endif

    //basicmm(N, A, B, C);
    //basicmm_simd(N, A, B, C);
    //basicmm_reorder(N, A, B, C);
    //basicmm_reorder_simd(N, A, B, C);
   basicmm_reorder_simd_blocking(N, A, B, C, blocksize);

#ifdef TEST
    print_array(N, A);
#endif
    return 0;
}
