
void propagador_funcion( float valor, uint32 funcion, Neurona* destino ){


	puts("propagador_funcion");
	
	switch( funcion ){

		case 0:	// Pasar el valor
			
			destino->valor = valor;
			break;

		case 1:

			break;
		default:
			puts("Funcion no establecida");
	}


}

void propagador_neurona( Neurona* n, Capa* c_siguiente ){

	puts("propagador_neurona");

	uint32 n_conexiones = n->n_conexiones;

	for (int i = 0; i < n_conexiones; ++i){
		
		propagador_funcion( n->valor, n->funciones[ i ], &c_siguiente->neuronas[ n->conexiones[ i ] ] );

	}

}

void propagador_capa( Capa* c_actual, Capa* c_siguiente ){

	puts("propagador_capa");

	uint32 n_neuronas = c_actual->n_neuronas;

	for (int i = 0; i < n_neuronas; ++i){
		
		propagador_neurona( &c_actual->neuronas[i], c_siguiente );

	}
}

void propagador_ejecutar( Cerebro* c ){

	Capa* capa_actual;
	Capa* capa_siguiente;

	capa_siguiente = c->entrada;

	for (int i = 0; i < c->n_capas; ++i){
		
		capa_actual = capa_siguiente;
		capa_siguiente = c->capas[ i ];

		propagador_capa( capa_actual, capa_siguiente );

	}
	
	capa_actual = capa_siguiente;
	capa_siguiente = c->salida;

	propagador_capa( capa_actual, capa_siguiente );
}
