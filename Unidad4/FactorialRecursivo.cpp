// Factorial recursivo

#include <stdio.h>

int factorial(int n)
{
	if(n==0) // Caso base
	{
		return(1);
	}else{
		return n * factorial(n-1); // Caso general
	}
}

main()
{
	int num;
	printf("\nIngrese numero para calcular su factorial: ");
	scanf("%d",&num);
	printf("\nEl factorial de %d es: %d",num,factorial(num));
}
