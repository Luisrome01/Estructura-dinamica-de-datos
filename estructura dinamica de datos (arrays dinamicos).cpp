/*media de precio de productos de un supermercado*/
#include<stdio.h>
#include<stdlib.h>

int main(){

    int n, i , cont = 0;

    float *p, mediaprecio;

    printf("Indique el numero de productos\n");
    scanf("%d", &n);

    p = (float *) malloc (n* sizeof(float));

    mediaprecio= 0 ;

    for( i= 0 ; i < n; i++){

        printf("precio ($) del producto #: %d\n", i +1 );
        scanf("%f", &p[i]);
        mediaprecio = mediaprecio + p[i];
    }

    mediaprecio =  mediaprecio/ n;

    for( i= 0 ; i < n; i++ ){

        if( p[i] > mediaprecio){
            cont++;
        }
    }
	printf("La media de los precios ($) : %.2f\n", mediaprecio);
    printf("Hay  %d de  productos sobre la media de precios", cont);

    free(p);

return 0 ;
}
