#include <math.h>
//#include <cstdlib> 
#include <iostream>
using namespace std;
 
int main(int argc, char *argv[]) 
{ 
        long int n;
	n=2000000000;
	double PI25DT = 3.141592653589793238462643;
	double h = 1.0 / (double) n;
	double sum = 0.0;
	for (int i = 1; i <= n; i++) {
		double x = h * ((double)i - 0.5);
		sum += (4.0 / (1.0 + x*x));
	}
	double pi = sum * h;
	cout << "El valor aproximado de PI es: " << pi << ", con un error de " << fabs(pi - PI25DT) << endl;
	return 0;
} 
