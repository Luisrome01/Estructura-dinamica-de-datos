//Prueba Colas exposicion estructuras dinamicas de datos
#include <stdlib.h>
#include <stdio.h>

struct nodo {
	int info;
	struct nodo* otronodo;
};
struct cola{
	struct nodo *primero, *ultimo;
};
struct nodo* crearNodo(int info){
struct nodo* nuevo = (struct nodo*) malloc(sizeof(struct nodo)); //nodo nuevo junto con malloc devuelve 
nuevo->info = info;
nuevo->otronodo=NULL;
return nuevo;
}
struct cola* crearCola(){
	struct cola* c = (struct cola*) malloc(sizeof(struct cola));
	c->primero = c->ultimo = NULL;
	return c;
}
void agregar (int info, struct cola* *c){          				//es un puntero a void.
	struct nodo* nuevo = crearNodo(info);
	if((*c)->primero==NULL){
		(*c)->primero = (*c)->ultimo = nuevo;
		return;
	}
	(*c)->ultimo->otronodo=nuevo;
	(*c)->ultimo = nuevo;
}
void eliminar(struct cola* *c){
if ((*c)->primero == NULL)	
{
	printf("La cola esta vacia \n");
}
else {	
struct nodo* eliminado = (*c)->primero;

(*c)->primero = eliminado->otronodo;
if ((*c)->primero==NULL) {
	(*c)->ultimo = NULL;
}
free(eliminado);
printf ("Dato eliminado de la cola \n");	
}
}
void mostrar(struct cola* *c){
	if((*c)->primero==NULL) {
	printf("La cola esta vacia \n");	
	}else {
	printf("Dato %d \n", (*c)->primero->info);
}
}

int main(){
	struct cola* c = crearCola();
	int repetidor = true;                   //int: palabra reservada
	int opcion;

	while(repetidor){
printf ("  1) Agregar dato a la cola \n 2) Mostrar primer dato en la cola \n 3) Eliminar primer dato de la cola \n 4) Finalizar \n");
scanf ("%d", &opcion);
switch(opcion){
	case 1:
	int datoo;
	printf("Introduzca dato a ingresar  \n");
	scanf ("%d", &datoo);
	agregar(datoo,&c);
	printf ("Dato agregado a la cola \n"); 
	system("pause");
system ("cls");
	break;
	case 2:
		mostrar(&c);
		system("pause");
system ("cls");
	break;
	case 3:
		eliminar(&c);
system("pause");
system ("cls");
	break;
	case 4:
		repetidor = false;
	break;
	default:
		printf("Intente de nuevo \n");
		system("pause");
system ("cls");
break;
}
}	return 0;
}
