using namespace std;

#include "testlib.h"

int MAX = 1e9;
int main(int argc, char* argv[]) {
	registerValidation(argc, argv);

	int d = inf.readInt(1, MAX, "d");
	inf.readEoln();
	int A = inf.readInt(1, MAX, "A");
	inf.readSpace();
	int Y = inf.readInt(1, MAX, "Y");
	inf.readEoln();
	inf.readEof();

	return 0;
}
