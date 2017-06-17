#include <stdio.h>
#include <stdlib.h>

typedef unsigned int uint32;

#include "neurona.c"
#include "capa.c"
#include "cerebro.c"

#include "prueba_cerebro.c"

int main(){

	printf("\nRedes Neuronales.\n\n");

	//Capa* capa_0 = capa_nueva( 5 );

	//capa_0->neuronas[4]->valor = 0.999f;

	//neurona_printear( capa_0->neuronas[4] );

	neurona_test();

	//capa_test();

	//cerebro_test();
	prueba_cerebro_iniciar();
	return 0;

}
