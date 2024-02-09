/*	MPI_PI calcula el valor de PI con error en base a un predefinido. 
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <sys/time.h>
#include <sys/utsname.h>
#include <mpi.h>

#define MASTER             0
#define PI      3.1415926535

/* TIRADAS es una constante definida, se puede cambiar su valor y recompilar */
#define TIRADAS    100000000

 main (int argc, char *argv[]) 
{
	int proc_id, n_procs, limite_inf, limite_sup, n_dentro, i;
	double pi_local, pi_total, x, y, z, error, start_time, end_time;

	n_dentro = 0;

	/* Inicio MPI */
	MPI_Init(, );

	/* Obtener rango y tamaño del comm_world */
	MPI_..............
	MPI_.................;

	/* Unicamente el maestro imprime en pantalla los datos iniciales */ 
	if (proc_id == MASTER)
	{
		system("clear");
		printf("## Implementación de Montecarlo para el cálculo de PI\n\n");

		printf("## Total de procesadores: %d\n", n_procs);
		printf("## Comienzo del programa con %d tiradas.\n\n", TIRADAS);
	        srand(time(NULL));

	}

	/* Procedimiento: Obtener un numero aleatorio, calcular por Pitágoras si está dentro del
 * 	círculo, y si cumple, incrementar la cuenta... */

        srand(time(NULL));

	if (proc_id == MASTER)
		start_time = MPI_Wtime();

	for (i = 1; i <= TIRADAS; ++i)
	{
		x = rand()/(double)RAND_MAX;
		y = rand()/(double)RAND_MAX;

		z = pow(x, 2) + pow(y, 2);

		if (z <= 1.0)
			n_dentro+=1;
	}

	/*... Luego calcular PI con la cuenta dada... */
	???????????? = 4.0 * (double)n_dentro/(double)TIRADAS;

	/* Actualizar el resultado, suma de todos los cálculos... */
	MPI_......................
	if (proc_id != MASTER)
		printf("~ Se ha enviado el valor de PI: %g, del proceso: %d\n", pi_local, proc_id);

	MPI_Barrier(MPI_COMM_WORLD);

	/* Unicamente maestro: calcular la media, error, imprimir resultados. */
	if (proc_id == MASTER)
	{
		pi_total = pi_total / n_procs;
		error = fabs((pi_total - PI)/PI) * 100;

		end_time = MPI_Wtime();

		printf("## Valor real:		%11.10f\n", PI);
		printf("## Valor calculado:	%11.10f\n", pi_total);
		printf("## Error:		%10.8f\n", error);
		printf("## Tiempo empleado:	%10.8f\n\n", end_time - start_time);
	}

	/* Terminar espacio MPI */
	MPI_Finalize();

	return 0;
}

