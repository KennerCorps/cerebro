
void propagador_funcion( Neurona* n ){


	puts("propagador_funcion");

	printf("Valor inicial = %f\n", n->valor);
	
	switch( n->funcion ){

		case 0:	// Pasar el valor
			n->valor = funciones_identidad( n->valor );
			break;
		case 1:
			n->valor = funciones_salto_binario( n->valor );
			break;
		case 2:
			n->valor = funciones_logistica( n->valor );
			break;
		case 3:
			n->valor = funciones_tanh( n->valor );
			break;
		case 4:
			n->valor = funciones_arctan( n->valor );
			break;
		case 5:
			n->valor = funciones_lineal_rectificada( n->valor );
			break;
		case 6:
			n->valor = funciones_lineal_rectificada_perdida( n->valor );
			break;
		case 7:
			n->valor = funciones_softplus( n->valor );
			break;
		case 8:
			n->valor = funciones_sinusoide( n->valor );
			break;
		case 9:
			n->valor = funciones_identidad_curva( n->valor );
			break;
		case 10:
			n->valor = funciones_sinc( n->valor );
			break;
		case 11:
			n->valor = funciones_gauss( n->valor );
			break;
		default:
			puts("Funcion no establecida");
	}

	printf("Valor final = %f\n", n->valor);


}

void propagador_neurona( Neurona* n, Capa* c_siguiente ){

	puts("propagador_neurona");

	propagador_funcion( n );

	uint32 n_conexiones = n->n_conexiones;

	for (int i = 0; i < n_conexiones; ++i){

		c_siguiente->neuronas[ n->conexiones[ i ] ].valor += n->valor * n->pesos[ i ];
		
		//propagador_funcion( n->valor, n->funciones[ i ], &c_siguiente->neuronas[ n->conexiones[ i ] ] );

	}

}

void propagador_capa( Capa* c_actual, Capa* c_siguiente ){

	puts("propagador_capa");

	uint32 n_neuronas = c_actual->n_neuronas;

	capa_mostrar( c_actual );

	for (int i = 0; i < n_neuronas; ++i){

		printf("Neurona n%d\n", i);
		propagador_neurona( &c_actual->neuronas[i], c_siguiente );

	}
}

void propagador_ejecutar( Cerebro* c ){

	Capa* capa_actual;
	Capa* capa_siguiente;

	capa_siguiente = c->entrada;

	for (int i = 0; i < c->n_capas; ++i){

		printf("Capa n%d\n", i);
		
		capa_actual = capa_siguiente;
		capa_siguiente = c->capas[ i ];

		propagador_capa( capa_actual, capa_siguiente );

	}
	
	capa_actual = capa_siguiente;
	capa_siguiente = c->salida;

	propagador_capa( capa_actual, capa_siguiente );
}
