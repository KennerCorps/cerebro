typedef struct neurona{

	float valor;

	uint32* conexiones;
	uint32* funciones;

	uint32 n_conexiones;


}Neurona;

void neurona_iniciar( Neurona* n ){
	n->n_conexiones = 0;
}


void neurona_conectar( Neurona* n, uint32 neurona_capa_siguiente, uint32 funcion ){

	printf("Conectando neurona a neurona %d con funcion %d\n", neurona_capa_siguiente, funcion );
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


void neurona_printear( Neurona* n ){

	printf("Valor: %f\n", n->valor);

	printf("Numero de conexiones = %d\n", n->n_conexiones );

	for(int i = 0; i < n->n_conexiones; ++i){
		printf("Conexion %d: conectado con neurona %d con funcion %d\n", i, n->conexiones[i], n->funciones[i] );
	}

}

void neurona_test(){

	puts("Iniciando test de neurona:\n\n");

	Neurona neurona;

	neurona_iniciar( &neurona );

	puts("Neurona iniciada.\n");

	neurona_conectar( &neurona, 3, 5 );
	neurona_conectar( &neurona, 7, 9 );

	neurona_printear( &neurona );

}
