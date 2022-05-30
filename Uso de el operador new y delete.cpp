// Ejercicio, devuelve un numero determinado (determinado por el usuario) de numeros aleatorios del 0 al 99



#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main()
{
	int num, i;
	int *aleatorio;
	
	
	printf("Numero de elementos: ");
	scanf("%d", &num);
	
	aleatorio = new int[num];

	for (i = 0 ; i < num ; i++ ){
		aleatorio[i] = rand() % 100;
	}
	
	printf("\nNumeros: ");
	for (i = 0 ; i < num ; i++)
		printf("%d ", aleatorio[i]);
	
	delete(aleatorio);	
	
}
