
typedef struct cerebro{

	Capa* entrada;
	Capa* salida;
	Capa** capas;

	uint32 n_entradas;
	uint32 n_salidas;
	uint32 n_capas;
	uint32 capas_altura;

}Cerebro;


Cerebro* cerebro_nuevo( uint32 n_entradas, uint32 n_salidas, uint32 n_capas, uint32 capas_altura ){

	Cerebro* cerebro = malloc( sizeof( Cerebro ) );

	cerebro->n_entradas = n_entradas;
	cerebro->n_salidas = n_salidas;
	cerebro->n_capas = n_capas;
	cerebro->capas_altura = capas_altura;

	cerebro->entrada = capa_nueva( n_entradas );
	cerebro->salida = capa_nueva( n_salidas );

	cerebro->capas = malloc( sizeof( Capa* ) * n_capas );

	for( uint32 i = 0; i < n_capas; ++i ){
		cerebro->capas[i] = capa_nueva( capas_altura );
	}
	return cerebro;
}


//////////// DEBUG ////////////

uint32 cerebro_memoria( Cerebro* c ){

	puts("Cerebro memoria:");

	uint32 t = sizeof( *c );
	t += capa_memoria( c->entrada );
	t += capa_memoria( c->salida );

	for( int i = 0; i < c->n_capas; ++i ){
		t += capa_memoria( c->capas[i] );
	}

	printf("Cerebro memoria total = %u bytes\n", t);

	return t;
}

void cerebro_mostrar( Cerebro* c ){

	puts("cerebro_print:\n");

	printf("Sizeof cerebro  = %d\n", sizeof(*c) );
	printf("Sizeof capas = %d\n", sizeof(c->capas) );

	//printf("Numero de entradas = %d\n", c->n_entradas );
	printf("Numero de entradas = %d\nNumero de salidas = %d\nNumero de capas = %d\nAltura de capas = %d\n\n", c->n_entradas, c->n_salidas, c->n_capas, c->capas_altura );

	printf("Memoria utilizada por el cerebro = %u bytes\n\n", cerebro_memoria( c ) );
}

void cerebro_test(){

	puts("\nIniciando test de cerebro:\n");

	Cerebro* cerebro = cerebro_nuevo( 1, 3, 3, 1 );
	puts("Cerebro creado.\n");
	cerebro_mostrar( cerebro );
	puts("------\n");
}
