// Ejercicio 9

#include <stdio.h>
#define N 2 // dimension


void cargaMatriz(int xmatriz[N][N],int xi,int xj)
{
	if(xi==N)
	{
		printf("\nMatriz cargada.");
		printf("\n-------------------");
		return;
	}else{
		if(xj==N)
		{
			cargaMatriz(xmatriz,xi+1,0);
		}else{
			printf("\nIngrese valor para la fila %d, columna %d: ",xi+1,xj+1);
			scanf("%d",&xmatriz[xi][xj]);
			cargaMatriz(xmatriz,xi,xj+1);
		}
	}
}

int ProdEscalarFilas(int xfilaA[N], int xfilaB[N], int xj)
{
	if(xj==N)
	{
		return(0);
	}else{
		return((xfilaA[xj]*xfilaB[xj]) + ProdEscalarFilas(xfilaA,xfilaB,xj+1));
	}
}

int ProdEscalarColum(int xmatriz1[N][N], int xmatriz2[N][N], int xi, int xcolA, int xcolB)
{
	if(xi==N)
	{
		return(0);
	}else{
		return((xmatriz1[xi][xcolA]*xmatriz2[xi][xcolB])+ ProdEscalarColum(xmatriz1,xmatriz2,xi+1,xcolA,xcolB));
	}
}

main()
{
	int matriz1[N][N];
	int matriz2[N][N];
	int numA,numB;
	printf("\nCargue la matriz A.");
	cargaMatriz(matriz1,0,0); // inciso a)
	printf("\nCargue la matriz B.");
	cargaMatriz(matriz2,0,0);
	printf("\nProducto escalar segun filas."); // inciso b)
	printf("\nIngrese numero de fila de la matriz A: ");
	scanf("%d",&numA);
	if(numA<=N && numA>0)
	{
		printf("\nIngrese numero de fila de la matriz B: ");
		scanf("%d",&numB);
		if(numB<=N && numB>0)
		{
			printf("\nProducto escalar de las filas %d de A y %d de B: %d",numA,numB,ProdEscalarFilas(matriz1[numA-1],matriz2[numB-1],0));
		}else{
			printf("\nError. Numero de fila no valido.");
		}
	}else{
		printf("\nError. Numero de fila no valido.");
	}
	printf("\n-------------------");
	printf("\nProducto escalar segun columnas."); // inciso c)
	printf("\nIngrese numero de columna de la matriz A: ");
	scanf("%d",&numA);
	if(numA<=N && numA>0)
	{
		printf("\nIngrese numero de columna de la matriz B: ");
		scanf("%d",&numB);
		if(numB<=N && numB>0)
		{
			printf("\nProducto escalar de las columnas %d de A y %d de B: %d",numA,numB,ProdEscalarColum(matriz1,matriz2,0,numA-1,numB-1));
		}else{
			printf("\nError. Numero de fila no valido.");
		}
	}else{
		printf("\nError. Numero de fila no valido.");
	}
}
