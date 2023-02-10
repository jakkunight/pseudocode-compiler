#ifndef INCLUDED_LEXER_H
#define INCLUDED_LEXER_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class LEXER {
	private:
		char* buffer;
		ifstream file;
		int filesize;
	public:
		LEXER(char* filepath);
		~LEXER();
		char* get_buffer();
		int get_filesize();
};

#endif
