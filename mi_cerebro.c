
Cerebro* crear_mi_cerebro(){

	Cerebro* c = cerebro_nuevo_vacio();

	Capa* entrada = capa_nueva( 4 );
	capa_establecer_funcion_en_neuronas( entrada, 0 );
	Capa* salida = capa_nueva( 4 );
	capa_establecer_funcion_en_neuronas( salida, 0 );

	Capa* capa_oculta_0 = capa_nueva( 4 );
	capa_establecer_funcion_en_neuronas( capa_oculta_0, 3 );

	Capa* capa_oculta_1 = capa_nueva( 4 );
	capa_establecer_funcion_en_neuronas( capa_oculta_1, 3 );

	Capa* capa_oculta_2 = capa_nueva( 8 );
	capa_establecer_funcion_en_neuronas( capa_oculta_2, 5 );

	capa_mostrar( capa_oculta_0 );


	neurona_conectar( &entrada->neuronas[ 0 ], 0 );
	neurona_conectar( &entrada->neuronas[ 0 ], 2 );
	neurona_conectar( &entrada->neuronas[ 1 ], 1 );
	neurona_conectar( &entrada->neuronas[ 1 ], 3 );
	neurona_conectar( &entrada->neuronas[ 2 ], 1 );
	neurona_conectar( &entrada->neuronas[ 2 ], 3 );
	neurona_conectar( &entrada->neuronas[ 3 ], 0 );
	neurona_conectar( &entrada->neuronas[ 3 ], 2 );


	neurona_conectar( &capa_oculta_0->neuronas[ 0 ], 0 );
	neurona_conectar( &capa_oculta_0->neuronas[ 0 ], 1 );
	neurona_conectar( &capa_oculta_0->neuronas[ 1 ], 0 );
	neurona_conectar( &capa_oculta_0->neuronas[ 1 ], 1 );
	neurona_conectar( &capa_oculta_0->neuronas[ 2 ], 2 );
	neurona_conectar( &capa_oculta_0->neuronas[ 2 ], 3 );
	neurona_conectar( &capa_oculta_0->neuronas[ 3 ], 2 );
	neurona_conectar( &capa_oculta_0->neuronas[ 3 ], 3 );


	neurona_conectar( &capa_oculta_1->neuronas[ 0 ], 0 );
	neurona_conectar( &capa_oculta_1->neuronas[ 0 ], 1 );
	neurona_conectar( &capa_oculta_1->neuronas[ 1 ], 2 );
	neurona_conectar( &capa_oculta_1->neuronas[ 1 ], 3 );
	neurona_conectar( &capa_oculta_1->neuronas[ 2 ], 4 );
	neurona_conectar( &capa_oculta_1->neuronas[ 2 ], 5 );
	neurona_conectar( &capa_oculta_1->neuronas[ 3 ], 6 );
	neurona_conectar( &capa_oculta_1->neuronas[ 3 ], 7 );


	neurona_conectar( &capa_oculta_2->neuronas[ 0 ], 0 );
	neurona_conectar( &capa_oculta_2->neuronas[ 1 ], 0 );
	neurona_conectar( &capa_oculta_2->neuronas[ 2 ], 1 );
	neurona_conectar( &capa_oculta_2->neuronas[ 3 ], 1 );
	neurona_conectar( &capa_oculta_2->neuronas[ 4 ], 2 );
	neurona_conectar( &capa_oculta_2->neuronas[ 5 ], 2 );
	neurona_conectar( &capa_oculta_2->neuronas[ 6 ], 3 );
	neurona_conectar( &capa_oculta_2->neuronas[ 7 ], 3 );


	cerebro_insertar_entrada( c, entrada );
	cerebro_insertar_salida( c, salida );

	cerebro_insertar_capa( c, capa_oculta_0 );
	cerebro_insertar_capa( c, capa_oculta_1 );
	cerebro_insertar_capa( c, capa_oculta_2 );

	return c;

}