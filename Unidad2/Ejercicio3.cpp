// Ejercicio 3

#include <stdio.h>
#define N 10 // Cantidad alumnos

struct alumno{
	char nombre[20];
	char apellido[20];
	int docu; // DNI
};

void carga(alumno xarre[])
{
	int i;
	printf("Cargue informacion de los alumnos.");
	for(i=0;i<N;i++)
	{
		printf("\nAlumno nro. %d",i+1);
		printf("\nIngrese nombre: ");
		fflush(stdin);
		gets(xarre[i].nombre);
		printf("\nIngrese apellido: ");
		fflush(stdin);
		gets(xarre[i].apellido);
		printf("\nIngrese DNI (numero sin puntos): ");
		scanf("%d",&xarre[i].docu);
		printf("\n------");
	}
	return;
}

void lista(alumno xarre[])
{
	int i;
	printf("\nLista de alumnos");
	for(i=0;i<N;i++)
	{
		printf("\nNombre: ");
		puts(xarre[i].nombre);
		printf("\nApellido: ");
		puts(xarre[i].apellido);
		printf("\nDNI: %d",xarre[i].docu);
		printf("\n------");
	}
	return;
}

int cuentaDNImayor(alumno xarre[])
{
	int i, cont=0;
	for(i=0;i<N;i++)
	{
		if(xarre[i].docu > 40000000)
		{
			cont+=1;
		}
	}
	return cont;
}

main()
{
	alumno arre[N]; // arreglo de struct alumno
	
	carga(arre); // inciso a)
	printf("\nSe han cargado los alumnos.");
	printf("\n------");
	lista(arre); // inciso b)
	printf("\nCantidad de alumnos con DNI mayor a 40 millones: %d",cuentaDNImayor(arre));
	printf("\n------");
}
