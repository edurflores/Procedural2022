// Ejercicio 2

#include <stdio.h>

void tablamulti(int xnum, int xmulti)
{
	if(xmulti>10)
	{
		return;
	}else{
		printf("\n%d x %d = %d",xnum,xmulti,xnum*xmulti);
		tablamulti(xnum,xmulti+1);
	}
}


main()
{
	int num;
	printf("\nIngrese numero entre 1 y 9: ");
	scanf("%d",&num);
	if(num>0 && num<=9)
	{
		tablamulti(num,1);
	}else{
		printf("\nError. No ingreso un numero entre 1 y 9.");
	}
}
