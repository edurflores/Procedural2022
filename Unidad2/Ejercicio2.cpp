// Ejercicio 2

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define N 30
#define V 5

void cambiaNumeros(char xcadena[])
{
	int i=0;
	while(i<N)
	{
		if(xcadena[i]=='2')
		{
			xcadena[i]='0';
		}
		i++;
	}
	printf("\nSe han efectuado los cambios.");
	printf("\nCadena actualizada: ");
	puts(xcadena);
	return;	
}

void copiaPalabra(char xcadena[])
{
	char cadenanueva[N];
	strncpy(cadenanueva,xcadena,12);
	printf("\nCadena copiada: ");
	puts(cadenanueva);
	return;
}

int cuentaVocales(char xcadena[])
{
	int i=0, j=0, cont=0;
	char vocales[V] = {'A','E','I','O','U'};
	while(i<N)
	{
		while(j<V)
		{
			if( toupper(xcadena[i])==vocales[j] )
			{
				cont+=1;
			}
			j+=1;
		}
		j=0;
		i+=1;
	}
	return cont;
}

main()
{
	char cadena[N];
	printf("Ingrese 'Programacion Procedural 2022' :");
	gets(cadena);
	cambiaNumeros(cadena); // inciso a)
	printf("\n--------------");
	copiaPalabra(cadena); // inciso b)
	printf("\n--------------");
	printf("\nCantidad de vocales en la frase: %d",cuentaVocales(cadena)); // inciso c)
}
