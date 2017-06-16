
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

void capa_test(){

	puts("Iniciando test de capa\n");

	uint32 n_neuronas = 5;

	Capa* capa = capa_nueva( n_neuronas );

	printf( "sizeof neurona = %d\n", sizeof( capa->neuronas[0] ) );

	capa->neuronas[0].valor = 0.01f;
	capa->neuronas[1].valor = 0.1f;
	capa->neuronas[2].valor = 1.f;
	capa->neuronas[3].valor = 10.0f;
	capa->neuronas[4].valor = 100.0f;

	for(int i = 0; i < n_neuronas; ++i ){
		printf("neurona n %d = %f\n", i, capa->neuronas[i].valor );
	}

}
