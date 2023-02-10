#include "lexer.h"

using namespace std;

int main(int argc, char** argv){
	if(argc <= 1){
		cout << "[ERROR] No input file." << endl;
		return -1;
	}
	cout << "reading file..." << endl;	
	LEXER test = LEXER(argv[1]);
	cout << "Filesize: " << test.get_filesize() << endl;
	for(int i = 0; i < test.get_filesize(); i++){
		cout << test.get_buffer()[i];
	}
	return 0;
}
