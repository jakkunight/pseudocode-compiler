#include "ast.hpp"
#include <utility>

// Expresión:
EXPRESSION::EXPRESSION(Type t){
	type = t;
}

// Expresiones literales:
// Enteros:
INTEGER::INTEGER(Type t, int v):EXPRESSION(t){
	value = v;
}

// Reales:
NUMBER::NUMBER(Type t, double v):EXPRESSION(t){
	value = v;
}

// Texto:
TEXT::TEXT(Type t, string v):EXPRESSION(t){
	value = v;
}

// Booleanos:
BOOLEAN::BOOLEAN(Type t, bool v):EXPRESSION(t){
	value = v;
}

// Expresiones complejas:
// Variables:
VARIABLE::VARIABLE(Type t, const string &n):EXPRESSION(t){
	name = n;
}

// Binarias:
BINARY::BINARY(
	Type t,
	char o,
	unique_ptr<EXPRESSION> l,
	unique_ptr<EXPRESSION> r
):EXPRESSION(t){
	op = o;
	left_op = move(l);
	right_op = move(r);
}

// Unitarias:
UNARY::UNARY(Type t, char o, unique_ptr<EXPRESSION> u):EXPRESSION(t){
	op = o;
	unary_op = move(u);
}

// Expresiones especiales:
// Prototipos de funciones:
FN_PROTO::FN_PROTO(
	Type t,
	const string &n,
	vector<Type> args_type,
	vector<string> args
):EXPRESSION(t){
	name = n;
	arguments_types = move(args_type);
	arguments = move(args);
}

// Llamada a función:
FN_CALL::FN_CALL(
	Type t,
	const string &n,
	vector<unique_ptr<EXPRESSION>> args
):EXPRESSION(t){
	name = n;
	arguments = move(args);
}
const string& FN_CALL::get_name(){
	return name;
}

// Funciones:
FUNCTION::FUNCTION(
	Type t,
	unique_ptr<FN_PROTO> p,
	unique_ptr<EXPRESSION> b
):EXPRESSION(t){
	prototype = move(p);
	body = move(b);
}

// Declaración de clases:
CLASS::CLASS(
	Type t,
	const string &n,
	vector<unique_ptr<FN_PROTO>> pv_m,
	vector<unique_ptr<VARIABLE>> pv_a,
	vector<unique_ptr<FN_PROTO>> pub_m,
	vector<unique_ptr<VARIABLE>> pub_a,
	unique_ptr<FN_PROTO> c
):EXPRESSION(t){
	name = n;
	private_methods = move(pv_m);
	private_attributes = move(pv_a);
	public_methods = move(pub_m);
	public_attributes = move(pub_a);
	constructor = move(c);
}


// Definición de clases:
CLASS_DEF::CLASS_DEF(
	Type t,
	const string &n,
	vector<unique_ptr<FUNCTION>> m,
	unique_ptr<FUNCTION> c
):EXPRESSION(t){
	class_name = n;
	methods = move(m);
	constructor = move(c);
}

// Estructuras de control:
// SI-ENTONCES-FINSI:
IF_THEN::IF_THEN(
	Type t,
	unique_ptr<EXPRESSION> c,
	unique_ptr<EXPRESSION> b
):EXPRESSION(t){
	condition = move(c);
	body = move(b);
}

// SI-ENTONCES-SINO-FINSI:
IF_ELSE::IF_ELSE(
	Type t,
	unique_ptr<EXPRESSION> c,
	unique_ptr<EXPRESSION> b,
	unique_ptr<EXPRESSION> e
):IF_THEN(t, move(c), move(b)){
	else_block = move(e);
}

// MIENTRAS-HACER-FINMIENTRAS:
WHILE::WHILE(
	Type t,
	unique_ptr<EXPRESSION> c,
	unique_ptr<EXPRESSION> b
):IF_THEN(t, move(c), move(b)){
	
}

// REPETIR-HASTAQUE:
REPEAT_UNTIL::REPEAT_UNTIL(
	Type t,
	unique_ptr<EXPRESSION> c,
	unique_ptr<EXPRESSION> b
):WHILE(t, move(c), move(b)){
	
}

// DESDE-HASTA-PASO-FINDESDE:
FOR::FOR(
	Type t,
	const string &i,
	unique_ptr<EXPRESSION> st,
	unique_ptr<EXPRESSION> e,
	unique_ptr<EXPRESSION> s,
	unique_ptr<EXPRESSION> b
):EXPRESSION(t){
	
}



