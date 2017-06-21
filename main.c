#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef unsigned int uint32;

#include "neurona.c"
#include "capa.c"
#include "cerebro.c"

#include "funciones.c"
#include "propagador.c"

#include "mi_cerebro.c"

//#include "prueba_cerebro.c"

int main(){

	printf("\nRedes Neuronales.\n\n");

	Cerebro* c = crear_mi_cerebro();

	propagador_ejecutar( c );

	return 0;

}
