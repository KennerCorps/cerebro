typedef struct neurona{

	float valor;

	uint32* conexiones;
	uint32* funciones;

	uint32 n_conexiones = 0;


}Neurona;


void neurona_conectar( Neurona* n, uint32 neurona_capa_siguiente, uint32 funcion ){

	n->n_conexiones += 1;

	if( n->n_conexiones == 1 ){
		n->conexiones = malloc( sizeof(uint32) * n->n_conexiones );
		n->funciones  = malloc( sizeof(uint32) * n->n_conexiones );
	}
	else{
		n->conexiones = realloc( n->conexiones, sizeof(uint32) * n->n_conexiones );
		n->funciones  = realloc( n->funciones, sizeof(uint32) * n->n_conexiones );
	}
}


void neurona_printear( Neurona* n ){

	printf("Valor: %f\n", n->valor);

	printf("Numero de conexiones = %d\n", n->n_conexiones );

	for(int i = 0; i < n->n_conexiones; ++i){
		printf("Conexion %d: conectado con neurona %d con funcion %d\n", i, n->conexiones[i], n->funciones[i] );
	}

}
