using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)

#include "testlib.h"

int main(int argc, char* argv[]) {
	registerValidation(argc, argv);

	int n = inf.readInt(1, 250, "n");
	inf.readEoln();
	string s = inf.readToken(format("[a-z]{%d}", n), "s");
	inf.readEoln();
	inf.readEof();
}
