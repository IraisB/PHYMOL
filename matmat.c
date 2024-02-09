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
         for (k=0;k<n; k++)
            a[i][j] += b[i][k]* c[k][j] ;
}

void basicmm_simd(int n, double a[n][n], double b[n][n], double c[n][n])
{
	// Add vectorization
   int i, j, k ;
   for (i=0;i<n; i++)
      for (j = 0; j<n; j++)
         for (k=0;k<n; k++)
            a[i][j] += b[i][k]* c[k][j] ;
}

void basicmm_reorder(int n, double a[n][n], double b[n][n], double c[n][n])
{
	// Optimize interchanging loops
   int i, j, k ;
   for ()
    for ()
      for ()
            a[i][j] += b[i][k]* c[k][j] ;
}

void basicmm_reorder_simd(int n, double a[n][n], double b[n][n], double c[n][n])
{
	// Loops reordered and vectorization
   int i, j, k ;
   for ()
    for ()
      for ()
            a[i][j] += b[i][k]* c[k][j] ;
}

void basicmm_reorder_simd_blocking(int n, double a[n][n], double b[n][n], double c[n][n], int blockSize)
{

	// Add blocking and vectorization
	
   int i, j, k, iInner, jInner, kInner ;
   for ()
    for ()
       for ()
          for ()
             for ()
               for ()
                 a[][] += b[][] * c[][];
}

int main()
{
    fillmats(N, B, C);

#ifdef TEST
    print_array(N, B);
    print_array(N, C);
#endif

    basicmm(N, A, B, C);
    //basicmm_simd(N, A, B, C);
    //basicmm_reorder(N, A, B, C);
    //basicmm_reorder_simd(N, A, B, C);
    //basicmm_reorder_simd_blocking(N, A, B, C, blocksize);

#ifdef TEST
    print_array(N, A);
#endif
    return 0;
}
