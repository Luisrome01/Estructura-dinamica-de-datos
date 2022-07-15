//Prueba listas exposicion estructuras dinamicas de datos
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Nodo {
	char dato[50];
	struct Nodo* siguiente;
} Nodo;
typedef struct Lista {
	Nodo* cabeza;
	int longitud;
} Lista;

struct Lista* crearLista(){
	struct Lista* lista = (struct Lista*) malloc(sizeof(struct Lista));
	lista->cabeza = NULL;
	lista->longitud = 0;
	return lista;
}
Nodo* CrearNodo(char *dato){
	Nodo* nodo = (Nodo*) malloc (sizeof (Nodo));
	strncpy(nodo->dato, dato, 50);
	nodo->siguiente=NULL;
	return nodo;
}
void DestruirNodo(Nodo* nodo) {
	free(nodo);
}
void insertarComienzo(Lista* lista, char *dato){
	Nodo* nodo = CrearNodo(dato);
	nodo->siguiente = lista->cabeza;
	lista->cabeza = nodo;
	lista->longitud++;
	}
void insertarFinal(Lista* lista, char *dato){
	Nodo*nodo = CrearNodo(dato);
	if (lista->cabeza == NULL) {
		lista->cabeza = nodo;
	} else {
Nodo* puntero = lista->cabeza;
	while (puntero->siguiente){
		puntero = puntero->siguiente;	
}
puntero->siguiente = nodo;
}
lista->longitud++;
}
void InsertarN(int n, Lista* lista, char *dato){
	n = n-1;
	Nodo* nodo = CrearNodo(dato);
	if (lista->cabeza == NULL) {
		lista->cabeza == nodo;
	} else {
		Nodo* puntero = lista->cabeza;
		int posicion = 0;
		while (posicion < n && puntero->siguiente){
			puntero = puntero->siguiente;
			posicion++;
		} if (posicion != n){
			printf ("\n No hay datos aqui \n");
			}
		nodo->siguiente = puntero->siguiente; 
		puntero->siguiente = nodo; 
	}
	lista->longitud++;
}
void Obtener(int n, Lista* lista){
	if (lista->cabeza == NULL){
		printf ("\n La lista esta vacia \n");
	} else {
			Nodo* puntero = lista->cabeza;
		int posicion = 0;
		while (posicion < n && puntero->siguiente){
			puntero = puntero->siguiente;
			posicion++;
		}
		if (posicion != n){
			printf ("\n No hay ningun dato aqui \n");
		}else {
		printf("\n%s\n",&puntero->dato);
	}
	}
}
int longitud(Lista* lista) {
	return lista->longitud;
}
void EliminarPrincipio(Lista* lista){
	if(lista->cabeza){
	Nodo* eliminado = lista->cabeza;
	lista->cabeza = lista->cabeza->siguiente;
	DestruirNodo(eliminado);
	lista->longitud--;
	printf ("Se ha eliminado el dato de la lista\n");
}  else {
	printf("\n La lista ya se encuentra vacia \n");
}
}
void EliminarUltimo(Lista* lista){
	if(lista->cabeza){
		if(lista->cabeza->siguiente) {
		
		Nodo* puntero = lista->cabeza;
		while (puntero->siguiente->siguiente){
			puntero = puntero->siguiente;
		}
		Nodo* eliminado = puntero->siguiente;
		puntero->siguiente=NULL;
		DestruirNodo(eliminado);
		lista->longitud--;
		printf ("Se ha eliminado el dato de la lista\n");
	} else {
		Nodo* eliminado = lista->cabeza;
		lista->cabeza = NULL;
		DestruirNodo(eliminado);
		lista->longitud--;
		printf ("Se ha eliminado el dato de la lista\n");
	}
	} else{
		printf ("\n La lista ya se encuentra vacia \n");
	}
}
void EliminarN(int n, Lista* lista){
	if (lista->cabeza) {
		if (n == 0) {
			Nodo* eliminado = lista->cabeza;
			lista->cabeza = lista->cabeza->siguiente;
			DestruirNodo(eliminado);
			lista->longitud--;
			printf ("Se ha eliminado el dato de la lista\n");
		} else if (n < lista->longitud) {
			Nodo* puntero = lista->cabeza;
		int posicion = 0;
		while(posicion < (n - 1)) {
			puntero = puntero->siguiente;
			posicion++;
		}
		Nodo* eliminado = puntero->siguiente;
		puntero->siguiente = eliminado->siguiente;
		DestruirNodo(eliminado);
		lista->longitud--;	
		printf ("Se ha eliminado el dato de la lista\n");
		}else{
			printf("\n No hay ningun dato aqui \n");
		}
	}
}
void MostrarLista(Lista* lista){
	if (lista->cabeza == NULL){
		printf("\n La lista se encuentra vacia \n");
	} else {
		Nodo* puntero = lista->cabeza;
		int posicion = 0;
		while (posicion < lista->longitud){
			printf(" %s \n", &puntero->dato);
			puntero = puntero->siguiente;
			posicion++;
		}
	}
}


int main(){
	struct Lista* l = crearLista();
	int repetidor = true;
	int opcion;
	while (repetidor){
	
	printf ("Escoja una opcion: \n");
	printf ("1. Agregar dato \n");
	printf ("2. Ver lista \n");
	printf ("3. Eliminar dato \n");
	printf ("4. Salir\n");
	scanf ("%d", &opcion);
	switch (opcion){
		case 1: 
		char nombre[50];
		int opcionAgregar;
		printf ("Escoja una opcion: \n");
		printf ("1 Agregar al comienzo \n");
		printf ("2 Agregar al final \n");
		printf ("Cancelar \n");
		scanf ("%d", &opcionAgregar);
		switch(opcionAgregar){
			case 1: 
			printf ("\nIntroduzca el dato \n");
			scanf ("%s", &nombre);
			insertarComienzo(l,nombre);
			break;
			case 2: 
			printf ("\nIntroduzca el dato \n");
			scanf ("%s", &nombre);
			insertarFinal(l,nombre);
			break;
			case 3:
				int n;
			printf ("\nIntroduzca el dato \n");
			scanf ("%s", &nombre);
			default:
			break;
		}
		system("pause");
system ("cls");
		break;
		case 2:
		MostrarLista(l);
		system("pause");
system ("cls");
		break;
		case 3:
		int opcionEliminar;
		printf ("Introduzca el numero de la opcion de su preferencia: \n");
		printf ("1 Eliminar al comienzo \n");
		printf ("2 Eliminar al final \n");
		printf ("Cancelar \n");
		scanf ("%d", &opcionEliminar);
		switch(opcionEliminar) {
			case 1: 
			EliminarPrincipio(l);
			break;
			case 2: 
			EliminarUltimo(l);
	
		break;
		}
		system("pause");
	system ("cls");
		break;
		case 4:
			repetidor = false;
	break;
	default:
		printf("Introduzca una opcion valida \n");
		system("pause");
system ("cls");
	}

}
	return 0;
}
