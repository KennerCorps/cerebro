typedef struct neurona{

	float valor;

	uint32* conexiones;
	float* pesos;
	uint32* funciones;

	uint32 n_conexiones;


}Neurona;

void neurona_iniciar( Neurona* n ){
	n->n_conexiones = 0;
	n->valor = 0.f;

	n->conexiones = 0;
	n->pesos = 0;
	n->funciones = 0;
}

int neurona_buscar_conexion( Neurona* n, uint32 neurona_capa_siguiente ){
	for(int i = 0; i < n->n_conexiones; ++i ){
		if( n->conexiones[ i ] == neurona_capa_siguiente){
			return i;
		}
	}
	return -1;
}

void neurona_adaptar_memoria_a_conexiones( Neurona* n ){

	n->conexiones 	= realloc(n->conexiones, 	sizeof( uint32 ) * 	n->n_conexiones );
	n->pesos		= realloc(n->pesos, 		sizeof(float) 	 * 	n->n_conexiones );
	n->funciones  	= realloc(n->funciones,  	sizeof( uint32 ) * 	n->n_conexiones );

}

void neurona_conectar( Neurona* n, uint32 neurona_capa_siguiente, uint32 funcion ){

	printf("Conectando neurona a neurona %u con funcion %u\n", neurona_capa_siguiente, funcion );
	n->n_conexiones += 1;

	if( n->n_conexiones == 1 ){
		puts("Neurona sin conexiones previas");
		n->conexiones = malloc( sizeof(uint32) * n->n_conexiones );
		n->pesos	  = malloc( sizeof(float)  * n->n_conexiones );
		n->funciones  = malloc( sizeof(uint32) * n->n_conexiones );
	}
	else{
		neurona_adaptar_memoria_a_conexiones( n );
	}

	n->conexiones[ n->n_conexiones - 1 ] = neurona_capa_siguiente;
	n->funciones[ n->n_conexiones - 1 ] = funcion;

}

void neurona_desconectar( Neurona* n, uint32 neurona_capa_siguiente){

	int i_conexion = neurona_buscar_conexion( n, neurona_capa_siguiente );

	if( i_conexion != -1 ){

		printf("Desconectando neurona de %u\n", neurona_capa_siguiente );
		for(int i = i_conexion + 1; i < n->n_conexiones; ++i ){
			n->conexiones[ i - 1 ]	= n->conexiones[ i ];
			n->pesos[ i -1 ]	= n->pesos[ i ];
			n->funciones[  i - 1 ]	= n->funciones[  i ];
		}

		n->n_conexiones -= 1;

		neurona_adaptar_memoria_a_conexiones( n );

	}
	else{
		printf("Neurona_desconectar: La neurona no estaba conectada con %u\n", neurona_capa_siguiente );
	}
}

//////////// DEBUG: ////////////


uint32 neurona_memoria( Neurona* n ){

	puts("Neurona_memoria");
	uint32 t = sizeof( Neurona );
	printf("sizeof( neurona->conexiones ) = %u\n", sizeof(n->conexiones[0]));
	if( n->conexiones ) {
		t += sizeof( n->conexiones[0] ) * n->n_conexiones;
		t += sizeof( n->pesos[0]) * n->n_conexiones;
		t += sizeof( n->funciones[0] ) * n->n_conexiones;
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
		printf("Conexion %u: conectado con neurona %u con funcion %u y peso %f\n", i, n->conexiones[i], n->funciones[i], n->pesos[i] );
	}

}

void neurona_test(){

	puts("Iniciando test de neurona:\n");

	Neurona neurona;

	neurona_iniciar( &neurona );

	puts("Neurona iniciada.\n");

	neurona_conectar( &neurona, 3, 5 );
	neurona_conectar( &neurona, 7, 9 );
	neurona_conectar( &neurona, 11, 13);
	neurona_conectar( &neurona, 15, 17);

	neurona_mostrar( &neurona );

	neurona_desconectar( &neurona, 7 );
	neurona_desconectar( &neurona, 7 );

	neurona_mostrar( &neurona );

	puts("------");
}
