// Ejercicio 1

#include <stdio.h>
#define N 20

void genera(int xarre[])
{
	int i;
	for(i=0;i<N;i++)
	{
		printf("\nIngrese un numero:");
		scanf("%d",&xarre[i]);
	}
	return;
}

void muestraPares(int xarre[])
{
	int i;
	printf("\nContenido de posiciones pares");
	for(i=0;i<N;i++)
	{
		if(i%2 == 0)
		{
			printf("\nPosicion %d:%d",i,xarre[i]);
		}
	}
	return;
}

int cuentaPares(int xarre[])
{
	int i, cont=0;
	for(i=0;i<N;i++)
	{
		if(xarre[i]%2==0)
		{
			cont+=1;
		}
	}
	return cont;
}

main()
{
	int arre[N];
	genera(arre); // inciso a)
	muestraPares(arre); // inciso b)
	printf("\nCantidad de numeros pares que contiene:%d",cuentaPares(arre)); // inciso c)
}
