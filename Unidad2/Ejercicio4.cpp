// Ejercicio 4 (no probado)

#include <stdio.h>
#include <string.h>
#define P 50 // Cantidad de productos
#define K 22 // Cantidad de proveedores

struct producto{
	float precio;
	int stock;
};

struct proveedor{
	char nombre[30];
	int num;
	int compras;
};

void inicializa(int xarre[], int xlim)
{
	int i;
	for(i=0;i<xlim;i++)
	{
		xarre[i] = 0;
	}
	return;
}

void cargaProductos(producto xarre[])
{
	int i;
	printf("Cargue informacion de los productos.");
	printf("\n------------");
	for(i=0;i<P;i++)
	{
		printf("\nCodigo de producto: %d",i+1);
		printf("\nIngrese precio de costo: ");
		scanf("%f",&xarre[i].precio);
		printf("\nIngrese cantidad de stock: ");
		scanf("%d",&xarre[i].stock);
		printf("------------");
	}
	printf("\nSe han cargado los productos.");
	return;
}

void cargaProveedores(proveedor xarre[])
{
	int i;
	printf("\nCargue informacion de los proveedores.");
	printf("------------");
	for(i=0;i<K;i++)
	{
		printf("\nCodigo de proveedor: %d",i+1000);
		printf("\nIngrese nombre: ");
		gets(xarre[i].nombre);
		xarre[i].num = i+1000;
		xarre[i].compras = 0; // inicializa
		printf("------------");
	}
	printf("\nSe han cargado los proveedores.");
	return;
}

void venta(producto xprod[], proveedor xprov[], int xarrecomprados[]) // inciso b)
{
	int i,j; // i para proveedor, j para producto
	int cant; // variable para cantidad de unidades compradas
	printf("\nInformacion de venta.");
	printf("------------");
	printf("\nIngrese numero de proveedor (de 10000 a 1022, o cero para terminar): ");
	scanf("%d",&i);
	while(i!=0)
	{
		if(i>=1000 || i<=1022)
		{
			printf("\nIngrese codigo de producto (de 1 a 50): ");
			scanf("%d",&j);
			if(j>=1 || j<=50)
			{
				printf("\nIngrese cantidad de unidades compradas: ");
				scanf("%d",&cant);
				if(cant<=xprod[j].stock)
				{
					xprod[j].stock -= cant; // Actualiza stock restante
					xarrecomprados[j] += cant; // Actualiza unidades compradas
					xprov[i-1000].compras+=1; // Registra compra al proveedor
					printf("\nSe ha registrado la venta.");
					printf("\n------------");
					printf("\nIngrese numero de proveedor (de 10000 a 1022, o cero para terminar): "); // Se reinicia el proceso
					scanf("%d",&i);
				}else{
					printf("\nError. Cantidad de stock insuficiente. No pudo registrarse la venta.");
					printf("\n------------");
					printf("\nIngrese numero de proveedor (de 10000 a 1022, o cero para terminar): "); // Se reinicia el proceso
					scanf("%d",&i);
				}
			}else{
				printf("\nError. Valor incorrecto. Reintente.");
				printf("\nIngrese codigo de producto (de 1 a 50): ");
				scanf("%d",&j);
			}
		}else{
			printf("\nError. Valor incorrecto. Reintente.");
			printf("\nIngrese numero de proveedor (de 10000 a 1022, o cero para terminar): ");
			scanf("%d",&i);
		}
	}
	return;
}

void informaInversion(producto xprodu[], int xcomprados[]) // inciso c)
{
	int i;
	float total;
	printf("\nMonto invertido en cada producto.");
	printf("\n--------------------");
	printf("\nCodigo de producto | Dinero invertido");
	for(i=0;i<P;i++)
	{
		total = xprodu[i].precio * xcomprados[i]; // Calcula el total gastado en cada producto
		printf("\n%d | $ %.2f",i+1,total); // Lo muestra
		printf("\n------------");
		total = 0; // Reinicializa
	}
	return;
}

int generaNuevaProv(proveedor xarre[], proveedor xnuevo[]) // inciso d)
{
	int i, j=0, t=0; // i para recorrer viejo arreglo, j para recorrer nueva estructura, t es total de proveedores de la nueva estructura
	for(i=0;i<K;i++)
	{
		if(xarre[i].compras>10)
		{
			xnuevo[j]=xarre[i];
			j+=1;
		}
	}
	printf("\nSe ha generado la nueva estructura.");
	return(j);
}

void buscaProveedor(proveedor xarre[], int xlim) // inciso f)
{
	char nom[30];
	int ban=0; // bandera: cero no encontrado, uno encontrado
	int i=0; // indice para busqueda
	printf("\nIngrese nombre de proveedor a buscar: ");
	gets(nom);
	while(i<xlim && ban==0)
	{
		if(strcmp(xarre[i].nombre,nom)==1)
		{
			ban=1;
			printf("\nProveedor encontrado. Informacion.");
			printf("\n---------------------------------");
			printf("\nNombre: ");
			puts(xarre[i].nombre);
			printf("\nNumero: %d",xarre[i].num);
			printf("\nCantidad de compras realizadas: %d",xarre[i].compras);
		}else{
			i+=1;
		}
	}
	if(ban==0)
	{
		printf("\nError. Proveedor no encontrado o sus compras no llegaron a 10.");
	}
	return;
}

void ordena(proveedor xarre[], int xlim) // ordenamiento por burbuja, para inciso e)
{
	int i, indiceactual,indicesiguiente;
	proveedor aux; // variable auxiliar para ordenamiento
	for(i=0;i<xlim;i++)
	{
		for(indiceactual=0;indiceactual<xlim-1;indiceactual++)
		{
			indicesiguiente = indiceactual+1;
			if(xarre[indiceactual].nombre > xarre[indicesiguiente].nombre)
			{
				aux = xarre[indiceactual]; // asignacion de registros
				xarre[indiceactual] = xarre[indicesiguiente];
				xarre[indicesiguiente] = aux;
			}
		}
	}
	return;
}

void muestra(proveedor xarre[], int xlim) // inciso e)
{
	int i;
	printf("\nProveedores con mas de 10 compras.");
	printf("\n---------------------------------");
	printf("\nNombre | Numero | Compras");
	printf("\n---------------------------------");
	for(i=0;i<xlim;i++)
	{
		printf("\n %s | %d | %d",xarre[i].nombre,xarre[i].num,xarre[i].compras);
	}
	printf("\n---------------------------------");
	return;
}

main()
{
	producto arreprodu[P]; // arreglo de productos (codigos de 1 a 50)
	proveedor arreprov[K]; // arreglo de proveedores (numeros de 1000 a 1022)
	int arrecomprados[P]; // arreglo de acumuladores para productos comprados
	proveedor nuevoarre[K]; // nueva estructura de proveedores para el inciso d)
	int limnuevo; // Limite para la nueva estructura
	inicializa(arrecomprados,P);
	cargaProductos(arreprodu);
	printf("----------------------------");
	cargaProveedores(arreprov);
	printf("----------------------------");
	venta(arreprodu,arreprov,arrecomprados);  // inciso b)
	informaInversion(arreprodu,arrecomprados); // inciso c)
	limnuevo=generaNuevaProv(arreprov,nuevoarre); // inciso d)
	ordena(nuevoarre,limnuevo); // inciso e)
	muestra(nuevoarre,limnuevo); // inciso e)
	buscaProveedor(nuevoarre,limnuevo); // inciso f)
	
}
