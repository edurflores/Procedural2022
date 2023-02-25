// Ejercicio 6

#include <stdio.h>
#define A 6 // numero de area tematica
#define T 4 // numero de turno


void inicializa(int xtabla[A][T])
{
	int i,j;
	for(i=0;i<A;i++)
	{
		for(j=0;j<T;j++)
		{
			xtabla[i][j]=0;
		}
	}
	return;
}

void carga(int xtabla[A][T]) // inciso a)
{
	int i,j;
	printf("Inscripcion de alumnos.");
	printf("\n-------------------");
	printf("\nIngrese numero de area (de 1 a 6, o cero para terminar): ");
	scanf("%d",&i);
	while(i!=0)
	{
		printf("\nIngrese numero de turno (de 1 a 4): ");
		scanf("%d",&j);
		if(i>=A+1 || j>=T+1 || i<0 || j<0){
			printf("\nError. Usted introdujo un valor incorrecto. No se realizo la inscripcion.");
		}else{
			xtabla[i-1][j-1]+=1;
			printf("\nSe ha realizado la inscripcion.");
			printf("\n---------");
		}
		printf("\nIngrese numero de area (de 1 a 6, o cero para terminar): ");
		scanf("%d",&i);
	}
	printf("\n-------------------");
	return;
}

void devuelveInscriptos(int xarea[A]) // inciso b)
{
	int j;
	for(j=0;j<T;j++)
	{
		printf("\n-----------------");
		printf("\n %d | %d",j+1,xarea[j]);
	}
	return;
	printf("\n-----------------");
}

float calculaPromedio(int xarea[A]) // inciso c)
{
	float prom=0;
	int j;
	for(j=0;j<T;j++)
	{
		prom+=xarea[j];
	}
	prom= prom/T;
	return(prom);
}

main()
{
	int tabla[A][T]; // tabla de contadores
	int i,j;
	inicializa(tabla);
	carga(tabla); // inciso a)
	printf("\nCantidad de inscriptos en cada turno");  // inciso b)
	for(i=0;i<T;i++)
	{
		printf("\nArea nro. %d",i+1);
		printf("\nTurno | Inscriptos");
		devuelveInscriptos(tabla[i]);
	}
	printf("\nPromedio de inscriptos."); // inciso c)
	printf("\nIngrese numero de area tematica (de 1 a 6): ");
	scanf("%d",&i);
	if(i>=A+1 || i<0){
		printf("\nError. Usted introdujo un valor incorrecto. Operacion abortada.");
	}else{
		printf("\nPromedio de inscriptos para el area %d: %.2f",i,calculaPromedio(tabla[i-1]));
		printf("\n-------------------");
	}
}
