#ifndef EXPRESSIONS_H_INCLUDED
#define EXPRESSIONS_H_INCLUDED

#include <string>
#include <memory>
#include <vector>

using namespace std;

// Definición de los tipos de datos:
enum Type{
	entero = 0,
	numero = 1,
	texto = 2,
	booleano = 3,
	funcion = 4,
	clase = 5,
	objeto = 6,
	vacio = 7,
	array = 8,
	estructura_de_control = 9,
	indefinido = 10
};

// Clase base para las expresiones:
class EXPRESSION{
	protected:
		Type type;
	public:
		EXPRESSION(Type t);
		virtual ~EXPRESSION() = default;
};

// Expresiones literales:
// Números enteros:
class INTEGER : public EXPRESSION{
	private:
		int value;
	public:
		INTEGER(Type t, int v);
};

// Números reales:
class NUMBER : public EXPRESSION{
	private:
		double value;
	public:
		NUMBER(Type t, double v);
};

// Texto:
class TEXT : public EXPRESSION{
	private:
		string value;
	public:
		TEXT(Type t, string v);
};

// Booleanos:
class BOOLEAN : public EXPRESSION{
	private:
		bool value;
	public:
		BOOLEAN(Type t, bool v);
};

// Expresiones complejas:
// Variables:
class VARIABLE : public EXPRESSION{
	private:
		string name;
	public:
		VARIABLE(Type t, const string &n);
};

// Binarias:
class BINARY : public EXPRESSION{
	private:
		char op;
		unique_ptr<EXPRESSION> left_op;
		unique_ptr<EXPRESSION> right_op;
	public:
		BINARY(
			Type t,
			char o,
			unique_ptr<EXPRESSION> l,
			unique_ptr<EXPRESSION> r
		);
};

// Unitarias:
class UNARY : public EXPRESSION{
	private:
		char op;
		unique_ptr<EXPRESSION> unary_op;
	public:
		UNARY(Type t, char o, unique_ptr<EXPRESSION> u);
};

// Expresiones especiales:
// Prototipos de funciones:
class FN_PROTO : public EXPRESSION{
	private:
		string name;
		vector<Type> arguments_types;
		vector<string> arguments;
	public:
		FN_PROTO(
			Type t,
			const string &n,
			vector<Type> args_type,
			vector<string> args
		);
};

// Llamada a función:
class FN_CALL : public EXPRESSION{
	private:
		string name;
		vector<unique_ptr<EXPRESSION>> arguments;
	public:
		FN_CALL(
			Type t,
			const string &n,
			vector<unique_ptr<EXPRESSION>> args
		);
		const string &get_name();
};

class FUNCTION : public EXPRESSION{
	private:
		unique_ptr<FN_PROTO> prototype;
		unique_ptr<EXPRESSION> body;
	public:
		FUNCTION(
			Type t,
			unique_ptr<FN_PROTO> p,
			unique_ptr<EXPRESSION> b 
		);
};

// Declaración de clases:
class CLASS : public EXPRESSION{
	private:
		string name;
		vector<unique_ptr<FN_PROTO>> private_methods;
		vector<unique_ptr<VARIABLE>> private_attributes;
		vector<unique_ptr<FN_PROTO>> public_methods;
		vector<unique_ptr<VARIABLE>> public_attributes;
		unique_ptr<FN_PROTO> constructor;
	public:
		CLASS(
			Type t,
			const string &n,
			vector<unique_ptr<FN_PROTO>> pv_m,
			vector<unique_ptr<VARIABLE>> pv_a,
			vector<unique_ptr<FN_PROTO>> pub_m,
			vector<unique_ptr<VARIABLE>> pub_a,
			unique_ptr<FN_PROTO> c
		);
};

// Definición de clases:
class CLASS_DEF : public EXPRESSION{
	private:
		string class_name;
		vector<unique_ptr<FUNCTION>> methods;
		unique_ptr<FUNCTION> constructor;
	public:
		CLASS_DEF(
			Type t,
			const string &n,
			vector<unique_ptr<FUNCTION>> m,
			unique_ptr<FUNCTION> c
		);
};

// Estructuras de control:
// SI-ENTONCES-FINSI:
class IF_THEN : public EXPRESSION{
	protected:
		unique_ptr<EXPRESSION> condition;
		unique_ptr<EXPRESSION> body;
	public:
		IF_THEN(
			Type t,
			unique_ptr<EXPRESSION> c,
			unique_ptr<EXPRESSION> b
		);
};

// SI-ENTONCES-SINO-FINSI:
class IF_ELSE : public IF_THEN{
	private:
		unique_ptr<EXPRESSION> else_block;
	public:
		IF_ELSE(
			Type t,
			unique_ptr<EXPRESSION> c,
			unique_ptr<EXPRESSION> b,
			unique_ptr<EXPRESSION> e
		);
};

// MIENTRAS-HACER-FINMIENTRAS:
class WHILE : public IF_THEN{
	private:
	public:
		WHILE(
			Type t,
			unique_ptr<EXPRESSION> c,
			unique_ptr<EXPRESSION> b
		);
};

// REPETIR-HASTAQUE:
class REPEAT_UNTIL : public WHILE{
	private:
	public:
		REPEAT_UNTIL(
			Type t,
			unique_ptr<EXPRESSION> c,
			unique_ptr<EXPRESSION> b
		);
};

// DESDE-HASTA-PASO-FINDESDE:
class FOR : public EXPRESSION{
	private:
		string index;
		unique_ptr<EXPRESSION> start;
		unique_ptr<EXPRESSION> end;
		unique_ptr<EXPRESSION> step;
		unique_ptr<EXPRESSION> body;
	public:
		FOR(
			Type t,
			const string &i,
			unique_ptr<EXPRESSION> st,
			unique_ptr<EXPRESSION> e,
			unique_ptr<EXPRESSION> s,
			unique_ptr<EXPRESSION> b
		);
};

// Estructuras de datos:
// Arrays literales:
class ARRAY : public EXPRESSION{
	private:
		vector<unique_ptr<EXPRESSION>> array;
	public:
		ARRAY(
			Type t,
			vector<unique_ptr<EXPRESSION>> a
		);
};

// Declaración de arrays:
class ARR_DECLARATION : public EXPRESSION{
	private:
		string name;
		vector<unsigned int> length;
	public:
		ARR_DECLARATION(
			Type t,
			const string &n,
			vector<const unsigned int&> l
		);
};






#endif
