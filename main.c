#include <stdio.h>
#include <stdlib.h>

typedef unsigned int uint32;

#include "neurona.c"
#include "capa.c"
#include "cerebro.c"


int main(){

	printf("\nRedes Neuronales.\n\n");

	//Capa* capa_0 = capa_nueva( 5 );

	//capa_0->neuronas[4]->valor = 0.999f;

	//neurona_printear( capa_0->neuronas[4] );

	capa_test();

	cerebro_test();

	return 0;

}
