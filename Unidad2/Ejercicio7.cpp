// Ejercicio 7

#include <stdio.h>
#define F 30 // Farmacias
#define M 80 // Medicamentos


void inicializa(int xtabla[F][M])
{
	int i,j;
	for(i=0;i<F;i++)
	{
		for(j=0;j<M;j++)
		{
			xtabla[i][j]=0;
		}
	}
	return;
}

void carga(int xtabla[F][M]) // inciso a)
{
	int i,j,cant;
	printf("Cargue informacion de las farmacias.");
	printf("\n-----------------------");
	for(i=0;i<F;i++)
	{
		printf("\nPara farmacia %d",i+1);
		printf("\n-------------");
		printf("\nIngrese codigo de medicamento (de 100 a 179, o cero para terminar): ");
		scanf("%d",&j);
		while(j!=0)
		{
			if(j>=100 || j<=179)
			{
				printf("\nIngrese cantidad de unidades: ");
				scanf("%d",&cant);
				xtabla[i][j-100]+=cant;
				printf("\nSe ha registrado la venta.");
			}else{
				printf("\nError. Codigo incorrecto. Reintente.");
			}
			printf("\nIngrese codigo de medicamento (de 100 a 179, o cero para terminar): ");
			scanf("%d",&j);
		}
	}
	return;
}

void totalVendidosMedicamentos(int xtabla[F][M]) // inciso b)
{
	int i,j,total;
	printf("\nTotal de unidades vendidas de cada medicamento.");
	printf("\n-----------------------");
	printf("\nCodigo | Total vendido");;
	for(j=0;j<M;j++)
	{
		total=0;
		for(i=0;i<F;i++)
		{
			total+=xtabla[i][j];
		}
		printf("\n %d | %d",j+100,total);
	}
	return;
}

void calculaMasVendido(int xarre[M]) // inciso c)
{
	int j,max,codmax;
	max=0; // guarda el valor maximo encontrado
	for(j=0;j<M;j++)
	{
		if(xarre[j]>max)
		{
			max=xarre[j]; // guarda maximo
			codmax=j; // guarda codigo del maximo (indice)
		}
	}
	printf("\n-------------");
	printf("\nMedicamento mas vendido en esta farmacia: %d",j+100);
	printf("\nUnidades vendidas: %d",max);
	return;
}

main()
{
	int tabla[F][M];
	int f;
	inicializa(tabla);
	carga(tabla); // inciso a)
	totalVendidosMedicamentos(tabla); // inciso b)
	printf("\n-------------");
	printf("\nIngrese codigo de farmacia (de 1 a 30): "); // inciso c)
	scanf("%d",&f);
	if(f>=1 || f<=30)
	{
		calculaMasVendido(tabla[f-1]);
	}else{
		printf("\nError. Codigo de farmacia incorrecto.");
	}
}
