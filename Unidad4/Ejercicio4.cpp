 // Ejercicio 4

#include <stdio.h>
#define L 6 // cantidad de lenguajes de programacion

void inicializa(int xarre[],int xindice, int xsup) // arreglo, indice y limite superior respectivamente
{
	if(xindice==xsup) // caso base
	{
		return;
	}else{
		xarre[xindice]=0;
		inicializa(xarre,xindice+1,xsup);
	}
}

void muestra(int xarre[],int xindice, int xsup)
{
	if(xindice==xsup) //
	{
		return;
	}else{
		printf("\n%d",xarre[xindice]);
		muestra(xarre,xindice+1,xsup);
	}
}

void carga(int xarre[],int xindice, int xsup)
{
	if(xindice==xsup)
	{
		printf("\nSe ha cargado la informacion del arreglo.");
		return;
	}else{
		printf("\nIngrese cantidad de electores del lenguaje %d: ",xindice+1);
		scanf("%d",&xarre[xindice]);
		printf("\nRegistrado.");
		carga(xarre,xindice+1,xsup);
	}
}

void muestraMenos4000(int xarre[],int xindice, int xsup)
{
	if(xindice==xsup)
	{
		return;
	}else{
		if(xarre[xindice]<4000)
		{
			printf("\nEl lenguaje %d fue elegido por menos de 4000 encuestados.",xindice+1);
		}
		muestraMenos4000(xarre,xindice+1,xsup);
	}
}

void masElegido(int xarre[],int xindice, int xsup, int &xmax, int &xcodmax)
{
	if(xindice==xsup)
	{
		return;
	}else{
		if(xarre[xindice]>xmax)
		{
			xmax=xarre[xindice]; // guarda el maximo
			xcodmax=xindice;
		}
		masElegido(xarre,xindice+1,xsup,xmax,xcodmax);
	}
}

int calculaTotal(int xarre[], int xindice, int xsup)
{
	if(xindice==xsup)
	{
		return(0);
	}else{
		return xarre[xindice] + calculaTotal(xarre,xindice+1,xsup);
	}
}

int calculaEncuestados(int xarre[], int xindice, int xsup, int &xcont) // inciso e)
{
	if(xindice==xsup)
	{
		return(0);
	}else{
		if(xarre[xindice]>9000)
		{
			xcont+=1;
		}
		if(xarre[xindice]<5000)
		{
			return(1 + calculaEncuestados(xarre,xindice+1,xsup,xcont));
		}else{
			return(0 + calculaEncuestados(xarre,xindice+1,xsup,xcont));
		}
	}
}

main()
{
	int arre[L]; // arreglo de contadores
	int max=0,codmax;
	int cont=0; // contador de cantidad de lenguajes elegidos por 9000 encuestados
	inicializa(arre,0,L);
	// muestra(arre,0,L);
	carga(arre,0,L); // inciso a)
	muestra(arre,0,L);
	muestraMenos4000(arre,0,L); // inciso b)
	masElegido(arre,0,L,max,codmax); // inciso c)
	printf("\nEl lenguaje mas elegido es %d con cantidad de encuestados: %d",codmax+1,max);
	printf("\nTotal de encuestas realizadas: %d",calculaTotal(arre,0,L)); // inciso d)
	printf("\nCantidad de lenguajes que fueron elegidos por menos de 5000 encuestados: %d",calculaEncuestados(arre,0,L,cont)); // inciso e)
	printf("\nCantidad de lenguajes que fueron elegidos por mas de 9000 encuestados: %d",cont);
}
