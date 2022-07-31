#include<stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct nodo{
 struct nodo *padre;
 struct nodo *izquierdo;
 struct nodo *derecho;
 int valor;
};

struct nodo *crear_nodo(struct nodo *padre, int valor);
void agregar_valor(struct nodo *arbol, int valor);

int main(){
 struct nodo *arbol;
 arbol = crear_nodo(NULL,1);
 agregar_valor(arbol,2);
 agregar_valor(arbol,3);
 agregar_valor(arbol,4);
 agregar_valor(arbol,5);
 
 return 0;
}

struct nodo *crear_nodo(struct nodo *padre, int valor){
 struct nodo *n = calloc(sizeof(struct nodo),1);
 n->padre = padre;
 n->valor = valor;
 return n;
}

void agregar_valor(struct nodo *arbol, int valor){
 struct nodo *temp, *pivote;
 int derecho = 0;
 if(arbol){
  temp = arbol;
  while(temp !=NULL){
   pivote = temp;
   if(valor>temp->valor){
    temp = temp->derecho;  
    derecho = 1;    
   }else{
    temp = temp->izquierdo;
    derecho = 0;
   }
  }
  temp = crear_nodo(pivote,valor);
  if(derecho){
   printf("Insertando %i el lado derecho de %i\n",valor,pivote->valor); 
   pivote->derecho = temp;
  }else{
   printf("Insertando %i el lado izquierdo de %i\n",valor,pivote->valor);
   pivote->izquierdo = temp;
  }
 }else{
  printf("EL arbol no esta inicializado");
 }
}
