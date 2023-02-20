#include <iostream>
#include "lexer.hpp"

using namespace std;

int main(int argc, char** argv){
	if(argc < 2){
		return -1;
	}
	LEXER lexer = LEXER(argv[1]);
	int token = lexer.get_token();
	while(token != tok_eof){
		cout << "Token: " << token << ", ";
		switch(token){
			case tok_integer:
				cout << "Integer value: " << lexer.integer_str << endl;
				break;
			case tok_text:
				cout << "Text value: " << lexer.text_str << endl;
				break;
			case tok_number:
				cout << "Number value: " << lexer.number_str << endl;
				break;
			case tok_identifier:
				cout << "Identifier: " << lexer.identifier_str << endl;
				break;
			case tok_boolean:
				cout << "Boolean value: " << lexer.boolean_str << endl;
				break;
			default:
				if(token >= 0){
					cout << "Operator/Symbol: " << lexer.symbol_str << endl;
				}else{
					cout << "Keyword: " << lexer.keyword_str << endl;
				}
				break;
		}
		token = lexer.get_token();
	}
	return 0;
}


