// Ejercicio 5

#include <stdio.h>
#include <stdlib.h> // para funciones rand y srand
#include <time.h> // para funcion srand
#define F 5
#define C 4


void generaTabla(int xtabla[F][C])
{
	int i,j;
	srand(time(NULL));
	for(i=0;i<F;i++)
	{
		for(j=0;j<C;j++)
		{
			xtabla[i][j]= rand() % 150; // numero aleatorio entre 0 y 150
		}
	}
	printf("\nTabla generada.");
	return;
}

int sumaFila(int xarre[]) // inciso a)
{
	int i, total=0;
	for(i=0;i<C;i++)
	{
		total += xarre[i];
	}
	return(total);
}

float promTerColumna(int xtabla[F][C])
{
	float prom=0;
	int i;
	for(i=0;i<F;i++)
	{
		prom += xtabla[i][2]; // 2 es la tercera columna
	}
	prom= prom/F;
	return(prom);
}

void cuentaMayores(int xtabla[F][C]) // inciso c)
{
	int i,j;
	int cont=0;
	for(i=0;i<F;i++)
	{
		for(j=0;j<C;j++)
		{
			if(xtabla[i][j]>100)
			{
				cont+=1;
			}
		}
	}
	printf("\nCantidad de numeros mayores a 100: %d",cont);
	return;
}

void muestraTabla(int xtabla[F][C])
{
	int i,j;
	for(i=0;i<F;i++)
	{
		printf("\n------");
		for(j=0;j<C;j++)
		{
			printf("\n%d",xtabla[i][j]);
			printf("\n---");
		}
	}
	return;
}

main()
{
	int tabla[F][C];
	int i,tot=0;
	generaTabla(tabla);
	// muestraTabla(tabla); opcional para ver la tabla
	for(i=0;i<F;i++)
	{
		printf("\nResultado de suma fila %d : %d",i+1,sumaFila(tabla[i])); // inciso a)
		printf("\n-----------------");
	}
	printf("\nPromedio de la tercera columna: %.2f",promTerColumna(tabla)); // inciso b)
	cuentaMayores(tabla); // inciso c)
}
