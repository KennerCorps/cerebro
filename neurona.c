typedef struct neurona{

	float valor;
	uint32 conexiones;
	uint32 funciones;

}Neurona;

void neurona_printear( Neurona* n ){

	printf("Valor: %f\n", n->valor);

}
