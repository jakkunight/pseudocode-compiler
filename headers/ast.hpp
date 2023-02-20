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
	booleano = 3
};

// Clase base para las expresiones:
class EXPRESSION{
	protected:
		Type type;
	public:
		EXPRESSION(Type _type);
		virtual ~EXPRESSION() = default;
};


// 

#endif
