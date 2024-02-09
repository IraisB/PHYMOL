#include <math.h>
#include "mpi.h"   // Biblioteca de MPI
#include <iostream>
using namespace std;
 
int main(int argc, char *argv[]) 
{ 
        long int n;
	int rank, size;  // Variables propias de MPI
	double PI25DT = 3.141592653589793238462643;
	double mypi; // Valor local de pi
	double pi; // Valor global de pi
	double h;
	double sum;

    	MPI_Init(&argc, &argv); // Inicializamos los procesos
    	MPI_Comm_size(MPI_COMM_WORLD, &size); // Obtenemos el numero total de procesos
    	MPI_Comm_rank(MPI_COMM_WORLD, &rank); // Obtenemos el valor de nuestro identificador
	
	n=2000000000;
        h = 1.0 / (double) n;
        sum = 0.0;
	for (int i =   ; i <=   ; i+   ) {
		double x = h * ((double)i - 0.5);
		sum += (4.0 / (1.0 + x*x));
	}
	 = sum * h;
	MPI_Reduce(&     , // Valor local de PI
		   &      ,  // Dato sobre el que vamos a reducir el resto
		      ,	  // Numero de datos que vamos a reducir
		   MPI_DOUBLE,  // Tipo de dato que vamos a reducir
		   MPI_SUM,  // Operacion que aplicaremos
		      , // proceso que va a recibir el dato reducido
		   MPI_COMM_WORLD);

	if (rank == 0) //Solo imprime el proceso 0
	cout << "El valor aproximado de PI es: " << pi << ", con un error de " << fabs(pi - PI25DT) << endl;

        MPI_Finalize(); //Finalizamos los procesos
	return 0;
} 
