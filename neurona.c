typedef struct neurona{

	float valor;

	uint32* conexiones;
	uint32* funciones;

	uint32 n_conexiones;


}Neurona;

void neurona_iniciar( Neurona* n ){
	n->n_conexiones = 0;
	n->valor = 0.f;

	n->conexiones = 0;
	n->funciones = 0;
}


void neurona_conectar( Neurona* n, uint32 neurona_capa_siguiente, uint32 funcion ){

	printf("Conectando neurona a neurona %u con funcion %u\n", neurona_capa_siguiente, funcion );
	n->n_conexiones += 1;

	if( n->n_conexiones == 1 ){
		puts("Neurona sin conexiones previas");
		n->conexiones = malloc( sizeof(uint32) * n->n_conexiones );
		n->funciones  = malloc( sizeof(uint32) * n->n_conexiones );
	}
	else{
		n->conexiones = realloc( n->conexiones, sizeof(uint32) * n->n_conexiones );
		n->funciones  = realloc( n->funciones, sizeof(uint32) * n->n_conexiones );
	}

	n->conexiones[ n->n_conexiones - 1 ] = neurona_capa_siguiente;
	n->funciones[ n->n_conexiones - 1 ] = funcion;

}

//////////// DEBUG: ////////////


uint32 neurona_memoria( Neurona* n ){

	uint32 t = sizeof( Neurona );

	if( n->conexiones ) {
		t += sizeof( n->conexiones );
		t += sizeof( n->funciones );
	}
	return t;

}

void neurona_mostrar( Neurona* n ){

	puts("Mostrando neurona:\n");
	printf("Neurona en posicion de memoria = %u\n", n );
	printf("Espacio ocupado en memoria = %ubytes\n", neurona_memoria( n ) );
	printf("Valor: %f\n", n->valor);

	printf("Numero de conexiones = %u\n", n->n_conexiones );

	for(int i = 0; i < n->n_conexiones; ++i){
		printf("Conexion %u: conectado con neurona %u con funcion %u\n", i, n->conexiones[i], n->funciones[i] );
	}

}

void neurona_test(){

	puts("Iniciando test de neurona:\n");

	Neurona neurona;

	neurona_iniciar( &neurona );

	puts("Neurona iniciada.\n");

	neurona_conectar( &neurona, 3, 5 );
	neurona_conectar( &neurona, 7, 9 );

	neurona_mostrar( &neurona );

	puts("------");
}
