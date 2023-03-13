// Ejercicio 8

#include <stdio.h>
#define O 2 // Orden de la matriz (cuadrada)

void cargaMatriz(int xmatriz[O][O],int xi,int xj)
{
	if(xi==O)
	{
		printf("\nMatriz cargada.");
		printf("\n-------------------");
		return;
	}else{
		if(xj==O)
		{
			cargaMatriz(xmatriz,xi+1,0);
		}else{
			printf("\nIngrese valor para la fila %d, columna %d: ",xi+1,xj+1);
			scanf("%d",&xmatriz[xi][xj]);
			cargaMatriz(xmatriz,xi,xj+1);
		}
	}
}

int calculaTraza(int xmatriz[O][O],int xi, int xj)
{
	if(xi==O && xj==O)
	{
		return(0);
	}else{
		return(xmatriz[xi][xj] + calculaTraza(xmatriz,xi+1,xj+1));
	}
}

main()
{
	int matriz[O][O];
	cargaMatriz(matriz,0,0);
	printf("\nTraza de la matriz: %d",calculaTraza(matriz,0,0)); // Traza = suma de ls elementos de la diagonal principal
}
