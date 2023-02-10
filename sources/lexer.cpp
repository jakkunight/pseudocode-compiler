#include "lexer.h"

LEXER::LEXER(char* filepath){
	file.open(filepath);
	filesize = 0;
	buffer = new char[2];
	while(file.is_open() && file.good()){
		buffer[filesize] = file.get();
		filesize++;
	}
}

LEXER::~LEXER(){
	delete[] buffer;
}

char* LEXER::get_buffer(){
	return buffer;
}

int LEXER::get_filesize(){
	return filesize;
}
