
typedef struct capa{

	Neurona* neuronas;
	uint32 n_neuronas;

}Capa;


Capa* capa_nueva( uint32 tamano ){

	Capa* capa = malloc( sizeof( Capa ) );
	capa->neuronas = malloc( sizeof( Neurona ) * tamano );
	capa->n_neuronas = tamano;

	return capa;

}

//////////// DEBUG ///////////

uint32 capa_memoria( Capa* c ){

	puts("Capa_memoria");

	uint32 t = sizeof( Capa );

	for( int i = 0; i < c->n_neuronas; ++i){
		uint32 t_n = neurona_memoria( &c->neuronas[i] );
		t += t_n;
		printf("memoria_neurona_en_capa %d = %u\n", i, t_n );

	}

	return t;
}

void capa_test(){

	puts("Iniciando test de capa\n");

	uint32 n_neuronas = 5;

	Capa* capa = capa_nueva( n_neuronas );

	capa->neuronas[0].valor = 0.01f;
	neurona_conectar( &capa->neuronas[0], 5, 10 );

	capa->neuronas[1].valor = 0.1f;
	capa->neuronas[2].valor = 1.f;
	capa->neuronas[3].valor = 10.0f;
	capa->neuronas[4].valor = 100.0f;
	neurona_conectar( &capa->neuronas[4], 15, 20 );
	neurona_conectar( &capa->neuronas[4], 25, 30 );
	neurona_conectar( &capa->neuronas[4], 35, 40 );

	for(int i = 0; i < n_neuronas; ++i ){
		printf("neurona n %d = %f\n", i, capa->neuronas[i].valor );
	}

	printf("Tamano en memoria de capa = %ubytes\n", capa_memoria( capa ) );
	printf( "sizeof neurona = %d\n", sizeof( capa->neuronas[0] ) );


	puts("------");

}
