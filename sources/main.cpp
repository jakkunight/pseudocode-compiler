#include <iostream>
#include <fstream>
#include <cctype>
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

// Declaramos las variables globales:
ifstream filebuffer;
string number_str;
string text_str;
string integer_str;
string boolean_str;
string identifier_str;
string keyword_str;
string symbol_str;

// Declaración de funciones:
int get_token();

int main(int argc, char** argv){
	if(argc < 2){
		return -1;
	}
	filebuffer.open(argv[1]);
	int token = get_token();
	while(token != tok_eof){
		cout << "Token: " << token << ", ";
		switch(token){
			case tok_integer:
				cout << "Integer value: " << integer_str << endl;
				break;
			case tok_text:
				cout << "Text value: " << text_str << endl;
				break;
			case tok_number:
				cout << "Number value: " << number_str << endl;
				break;
			case tok_identifier:
				cout << "Identifier: " << identifier_str << endl;
				break;
			case tok_boolean:
				cout << "Boolean value: " << boolean_str << endl;
				break;
			default:
				if(token >= 0){
					cout << "Operator/Symbol: " << symbol_str << endl;
				}else{
					cout << "Keyword: " << keyword_str << endl;
				}
				break;
		}
		token = get_token();
	}
	return 0;
}

// Implementación de las funciones:
int get_token(){
	int last = ' ';
	string temp = "";
	while(last == ' ' || last == '\n' || last == '\r' || last == '\t'){
		last = filebuffer.get();
	}
	if(isalpha(last) || last == '_'){
		do{
			temp += last;
			last = filebuffer.get();
		}while(isalnum(last) || last == '_');
		if(temp == "INICIO"){
			keyword_str = temp;
			return tok_inicio;
		}
		if(temp == "FIN"){
			keyword_str = temp;
			return tok_fin;
		}
		if(temp == "LEER"){
			keyword_str = temp;
			return tok_leer;
		}
		if(temp == "IMPRIMIR"){
			keyword_str = temp;
			return tok_imprimir;
		}
		if(temp == "SI"){
			keyword_str = temp;
			return tok_si;
		}
		if(temp == "ENTONCES"){
			keyword_str = temp;
			return tok_entonces;
		}
		if(temp == "FINSI"){
			keyword_str = temp;
			return tok_finsi;
		}
		if(temp == "MIENTRAS"){
			keyword_str = temp;
			return tok_mientras;
		}
		if(temp == "HACER"){
			keyword_str = temp;
			return tok_hacer;
		}
		if(temp == "FINMIENTRAS"){
			keyword_str = temp;
			return tok_finmientras;
		}
		if(temp == "REPETIR"){
			keyword_str = temp;
			return tok_repetir;
		}
		if(temp == "HASTAQUE"){
			keyword_str = temp;
			return tok_hastaque;
		}
		if(temp == "DESDE"){
			keyword_str = temp;
			return tok_desde;
		}
		if(temp == "PASO"){
			keyword_str = temp;
			return tok_paso;
		}
		if(temp == "HASTA"){
			keyword_str = temp;
			return tok_hasta;
		}
		if(temp == "FINDESDE"){
			keyword_str = temp;
			return tok_findesde;
		}
		if(temp == "FUNCION"){
			keyword_str = temp;
			return tok_funcion;
		}
		if(temp == "RETORNAR"){
			keyword_str = temp;
			return tok_retornar;
		}
		if(temp == "FINFUNCION"){
			keyword_str = temp;
			return tok_finfuncion;
		}
		if(temp == "CLASE"){
			keyword_str = temp;
			return tok_clase;
		}
		if(temp == "PUBLICO"){
			keyword_str = temp;
			return tok_publico;
		}
		if(temp == "PRIVADO"){
			keyword_str = temp;
			return tok_privado;
		}
		if(temp == "CONSTRUCTOR"){
			keyword_str = temp;
			return tok_constructor;
		}
		if(temp == "FINCLASE"){
			keyword_str = temp;
			return tok_finclase;
		}
		if(temp == "EXTIENDEA"){
			keyword_str = temp;
			return tok_extiendea;
		}
		if(temp == "ENCASOQUE"){
			keyword_str = temp;
			return tok_encasoque;
		}
		if(temp == "SEAIGUALQUE"){
			keyword_str = temp;
			return tok_seaigualque;
		}
		if(temp == "FINCASO"){
			keyword_str = temp;
			return tok_fincaso;
		}
		if(temp == "FINENCASOQUE"){
			keyword_str = temp;
			return tok_finencasoque;
		}
		if(temp == "NUMERO"){
			keyword_str = temp;
			return tok_numero;
		}
		if(temp == "ENTERO"){
			keyword_str = temp;
			return tok_entero;
		}
		if(temp == "TEXTO"){
			keyword_str = temp;
			return tok_texto;
		}
		if(temp == "BOOLEANO"){
			keyword_str = temp;
			return tok_booleano;
		}
		if(temp == "VERDADERO"){
			boolean_str = temp;
			return tok_boolean;
		}
		if(temp == "FALSO"){
			boolean_str = temp;
			return tok_boolean;
		}
		identifier_str = temp;
		return tok_identifier;
	}
	if(isdigit(last)){
		bool dot = false;
		temp += last;
		while(isdigit(last) || last == '.'){
			last = filebuffer.get();
			if(last == '.' && !dot){
				temp += last;
				dot = true;
			}
			if(isdigit(last)){
				temp += last;
			}
		}
		if(dot){
			number_str = temp;
			return tok_number;
		}else{
			integer_str = temp;
			return tok_integer;
		}
	}
	if(last == '\"' || last == '\''){
		temp += last;
		last = filebuffer.get();
		while(last != '\"' || last == '\''){
			temp += last;
			last = filebuffer.get();
		}
		temp += last;
		text_str = temp;
		return tok_text;
	}
	if(last == '#'){
		do{
			last = filebuffer.get();
		}while(last != EOF && last != '\n' && last != '\r');
		if(last != EOF){
			return get_token();
		}
	}
	if(last == EOF){
		return tok_eof;
	}
	symbol_str = last;
	return last;
}
