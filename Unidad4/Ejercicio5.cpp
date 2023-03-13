// Ejercicio 5

#include <stdio.h>
#define N 10


void carga(int xarre[], int xi, int xlim)
{
	if(xi==xlim)
	{
		printf("\nSe ha cargado el arreglo.\n");
		return;
	}else{
		printf("\nIngrese un numero entero: ");
		scanf("%d",&xarre[xi]);
		carga(xarre,xi+1,xlim);
	}
}

void generaSubArre(int xarre[], int xsubarre[], int xi, int &xj, float &xprom) // Camino al caso base, calcula el promedio. De vuelta, genera el subarreglo
{
	if(xi==N) // Caso base (se recorrio todo el primer arreglo)
	{
		xprom= xprom/N;
		printf("\nPromedio del arreglo: %.2f",xprom);
		return;
	}else{
		xprom+= xarre[xi];
		generaSubArre(xarre,xsubarre,xi+1,xj,xprom); // Llamada caso general
		// Lo que sigue queda pendiente y se resuelve al volver al punto de invocacion (la vuelta).
		if(xarre[xi]>=xprom)
		{
			xsubarre[xj]=xarre[xi];
			xj+=1;
		}
	}
}

void muestra(int xarre[], int xi, int xsup)
{
	if(xi==xsup)
	{
		return;
	}else{
		printf(" %d ",xarre[xi]);
		muestra(xarre,xi+1,xsup);
	}
}

void busca(int xarre[],int xnum, int xi, int xsup)
{
	if(xi==xsup) // Caso base
	{
		return;
	}else{
		if(xarre[xi]==xnum) // Caso base
		{
			printf("\nSe encontro el numero.");
			return;
		}else{
			busca(xarre,xnum,xi+1,xsup); // Caso general
		}
	}
}

main()
{
	int arre[N], subarre[N]; 
	int j=0; // j es indice para el subarreglo y sirve como limite superior tambien
	int num;
	float prom=0;
	carga(arre,0,N); // inciso a)
	muestra(arre,0,N);
	generaSubArre(arre,subarre,0,j,prom); // inciso b)
	printf("\nSubarreglo generado.\n");
	muestra(subarre,0,j);
	//inciso c) omitido por redundancia
	printf("\nIngrese un numero a buscar en el subarreglo: "); // inciso d)
	scanf("%d",&num);
	busca(subarre,num,0,j);
}
