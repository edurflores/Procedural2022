// Ejercicio 6

#include <stdio.h>
#define N 10

void carga(int xarre[],int xi, int xlim)
{
	if(xi==xlim)
	{
		printf("\nArreglo cargado.");
		return;
	}else{
		printf("\nIngrese un numero entero: ");
		scanf("%d",&xarre[xi]);
		carga(xarre,xi+1,xlim);
	}
}

void funcionMayor(int xarre[], int xi, int xlim, int &xmax)
{
	if(xi==xlim) // Caso base: se recorrio todo el arreglo
	{
		printf("\nMayor valor encontrado: %d",xmax);
		return;
	}else{
		if(xarre[xi]>xmax)
		{
			xmax=xarre[xi]; // nuevo maximo
		}
		funcionMayor(xarre,xi+1,xlim,xmax);
		// Queda pendiente y sera ejecutado en la etapa de volver al punto de invocacion
		if(xarre[xi]==xmax)
		{
			printf("\nLa componente %d (%d) es igual al mayor.",xi,xarre[xi]);
		}
	}
}

main()
{
	int arre[N];
	int max=0;
	carga(arre,0,N);
	printf("\n----------------");
	funcionMayor(arre,0,N,max);
	printf("\nNota: Las componentes se cuentan desde cero.");
}
