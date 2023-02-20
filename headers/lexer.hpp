#ifndef LEXER_H_INCLUDED
#define LEXER_H_INCLUDED

#include <fstream>
#include <string>
#include <map>

using namespace std;

// Definimos el diccionario de nuestro lenguaje:
enum Token {
	// EOF:
	tok_eof = -1,
	// Identificadores y expresiones de datos:
	tok_integer = -2,
	tok_number = -3,
	tok_text = -4,
	tok_boolean = -5,
	tok_identifier = -6,
	// Keywords:
	tok_inicio = -7,
	tok_fin = -8,
	tok_leer = -9,
	tok_imprimir = -10,
	tok_si = -11,
	tok_entonces = -12,
	tok_finsi = -13,
	tok_mientras = -14,
	tok_hacer = -15,
	tok_finmientras = -16,
	tok_repetir = -17,
	tok_hastaque = -18,
	tok_desde = -19,
	tok_hasta = -20,
	tok_paso = -21,
	tok_findesde = -22,
	tok_encasoque = -23,
	tok_seaigualque = -24,
	tok_fincaso = -26,
	tok_finencasoque = -27,
	// Tipos de datos:
	tok_entero = -28,
	tok_numero = -29,
	tok_texto = -30,
	tok_booleano = -31,
	// Valores especiales:
	tok_verdadero = -32,
	tok_falso = -33,
	// Funciones y subrutinas:
	tok_funcion = -34,
	tok_retornar = -35,
	tok_finfuncion = -36,
	// Clases y objetos:
	tok_clase = -37,
	tok_publico = -38,
	tok_privado = -39,
	tok_constructor = -40,
	tok_extiendea = -41,
	tok_finclase = -42
};

class LEXER{
	public:
	LEXER(string filepath);
	~LEXER();
	ifstream filebuffer;
	string number_str;
	string text_str;
	string integer_str;
	string boolean_str;
	string identifier_str;
	string keyword_str;
	string symbol_str;
	int get_token();
};

#endif
