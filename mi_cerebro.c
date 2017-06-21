
Cerebro* crear_mi_cerebro(){

	Cerebro* c = cerebro_nuevo_vacio();

	Capa* entrada = capa_nueva( 4 );
	Capa* salida = capa_nueva( 2 );

	Capa* capa_oculta_0 = capa_nueva( 5 );
	Capa* capa_oculta_1 = capa_nueva( 6 );
	Capa* capa_oculta_2 = capa_nueva( 5 );

	capa_mostrar( capa_oculta_0 );

	cerebro_insertar_entrada( c, entrada );
	cerebro_insertar_salida( c, salida );

	cerebro_insertar_capa( c, capa_oculta_0 );
	cerebro_insertar_capa( c, capa_oculta_1 );
	cerebro_insertar_capa( c, capa_oculta_2 );

	return c;

}