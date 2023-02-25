// Ejercicio 8

#include <stdio.h>
#define D 8 // departamentos
#define M 12 // mes


void inicializa(float xarre[], int xlim)
{
	int i;
	for(i=0;i<xlim;i++)
	{
		xarre[i]=0;
	}
	return;
}

void carga(float xtabla[D][M]) // inciso a)
{
	int i,j;
	float importe;
	printf("Cargue informacion de ventas.");
	printf("\n----------------");
	printf("\nIngrese numero de mes (1 a 12, o cero para terminar): ");
	scanf("%d",&j);
	while(j!=0)
	{
		if(j<=M || j>=1)
		{
			printf("\nIngrese numero de departamento (1 a %d): ",D);
			scanf("%d",&i);
			if(i>=1 || i<=D)
			{
				printf("\nIngrese importe: ");
				scanf("%f",&importe);
				xtabla[i-1][j-1]+=importe;
				printf("\nVenta registrada.");
			}else{
				printf("\nError. Numero invalido. Reintente.");
			}
		}else{
			printf("\nError. Numero invalido. Reintente.");
		}
		printf("\nIngrese numero de mes (1 a 12, o cero para terminar): ");
		scanf("%d",&j);
	}
	printf("\nSe han cargado las ventas.");
	return;
}

float calculaPromedioVenta(float xtabla[D][M])
{
	int i,j;
	float prom=0;
	for(i=0;i<D;i++)
	{
		for(j=0;j<M;j++)
		{
			prom+=xtabla[i][j];
		}
	}
	prom= prom/D;
	return(prom);
}

int menosVendio(float xtabla[D][M], int xmes)
{
	int i,impmin,codmin;
	impmin=xtabla[0][xmes]; // lo inicializa con la primera componente
	for(i=0;i<D;i++)
	{
		if(xtabla[i][xmes]<impmin)
		{
			impmin=xtabla[i][xmes];
			codmin=i;
		}
	}
	return(codmin+1);
}

main()
{
	int i,mes,depa;
	float tabla[D][M],promedio;
	for(i=0;i<D;i++)
	{
		inicializa(tabla[i],M);
	}
	carga(tabla); // inciso a)
	printf("\n----------------");
	printf("\nIngrese numero de mes: ");
	scanf("%d",&mes);
	printf("\nNumero de departamento que menos vendio en el mes %d: %d",mes,menosVendio(tabla,mes-1)); // inciso b)
	printf("\n----------------");
	promedio=calculaPromedioVenta(tabla); // para incisos c) y d)
	printf("\nImporte promedio de venta del supermercado: $ %.2f",promedio); // inciso c)
	printf("\n----------------");
	printf("\nComprobar si supera el promedio."); // inciso d)
	printf("\nIngrese numero de mes: ");
	scanf("%d",&mes);
	printf("\nIngrese numero de departamento: ");
	scanf("%d",&depa);
	if(tabla[depa-1][mes-1]>promedio)
	{
		printf("\nEl departamento supero el promedio en el mes dado.");
	}else{
		printf("\nEl departamento no supero el promedio en el mes dado.");
	}
}
