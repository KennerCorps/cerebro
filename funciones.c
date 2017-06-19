float funciones_identidad( float valor ){
	return valor;
}
float funciones_salto_binario( float valor ){
	if( valor < 0.f ){ return 0.f; }
	return 1.f;
}
float funciones_logistica( float valor ){
	return 1.f / ( 1.f + pow( M_E, -valor ) );
}
float funciones_tanh( float valor ){
	return tanh( valor );
}
float funciones_arctan( float valor ){
	return atan( valor );
}
float funciones_lineal_rectificada( float valor ){
	if( valor < 0.f ){ return 0.f; }
	return valor;
}
float funciones_lineal_rectificada_perdida( float valor ){
	if( valor < 0.f ){ return 0.01f * valor; }
	return valor;
}
float funciones_softplus( float valor ){
	return log( 1 + pow( M_E, valor ) );
}
float funciones_sinusoide( float valor ){
	return sin( valor );
}
float funciones_identidad_curva( float valor ){
	return ( ( sqrt( pow( valor, 2 ) + 1 ) - 1 ) / 2 ) + valor;
}
float funciones_sinc( float valor ){
	if( valor == 0.f ){ return 1.f; }
	return sin( valor ) / valor;
}
float funciones_gauss( float valor ){
	return pow( M_E, pow( -valor, 2 ) );
}
