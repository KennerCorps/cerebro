#include <stdio.h>
#include <stdlib.h>

typedef unsigned int uint32;

#include "neurona.c"
#include "capa.c"
#include "cerebro.c"

#include "propagador.c"

//#include "prueba_cerebro.c"

int main(){

	printf("\nRedes Neuronales.\n\n");

	//Capa* capa_0 = capa_nueva( 5 );

	//capa_0->neuronas[4]->valor = 0.999f;

	//neurona_printear( capa_0->neuronas[4] );

	//neurona_test();

	//capa_test();

	//cerebro_test();

	Cerebro* c;

	c = cerebro_nuevo(3,3, 10, 3);

	Capa* entrada = c->entrada;
	Capa* capa_0 = c->capas[0];

	capa_conectar( entrada, 0, 0, 0 );
	

	propagador_ejecutar( c );
	//prueba_cerebro_iniciar();
	return 0;

}
