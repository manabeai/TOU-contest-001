#include "testlib.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int MIN_N = 1;
const int MAX_N = 300000;
const int MIN_M = 1;
const int MAX_M = 300000;
const int MAX_CHAR_TYPE = 26;
const int MIN_CHAR_TYPE = 1;

int main(int argc, char* argv[]) {
	registerValidation(argc, argv);
	try{
		int N,M;
		N = inf.readInt(MIN_N,MAX_N);
		inf.readSpace();
		M = inf.readInt(MIN_M,MAX_M);
		inf.readEoln();

		if(N < M){
			throw runtime_error("M Is Greater Than N");
		}
		
		for (int i = 0; i < N; i++) {
			char C;
			C = inf.readChar();
			if(i != N - 1)inf.readSpace();
			if (!isupper(C)) {
				throw runtime_error("Char Out Of Range");
			}
		}
		inf.readEof();
		return 0;
	}
	catch (const runtime_error& e) {
		cerr << e.what() << endl;
	}
	catch (const exception& e) {
		cerr << e.what() << endl;
	}
	return 1;
}