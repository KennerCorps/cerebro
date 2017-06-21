
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

	cerebro_insertar_entrada( c, entrada );
	cerebro_insertar_salida( c, salida );

	cerebro_insertar_capa( c, capa_oculta_0 );
	cerebro_insertar_capa( c, capa_oculta_1 );
	cerebro_insertar_capa( c, capa_oculta_2 );

	return c;

}