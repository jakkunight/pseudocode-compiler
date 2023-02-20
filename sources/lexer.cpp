/* TODO:
*  Añadir la capacidad de operar mediante un diccionario
*  dinámico, definido por el usuario.
*/
#include <cctype>
#include "lexer.hpp"

LEXER::LEXER(string filepath){
	filebuffer.open(filepath);
}
LEXER::~LEXER(){
	
}
int LEXER::get_token(){
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
