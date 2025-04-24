using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)

#include "testlib.h"

int main(int argc, char* argv[]) {
	registerValidation(argc, argv);

	int h = inf.readInt(1, 10, "h");
	inf.readSpace();
	int w = inf.readInt(1, 10, "w");
	inf.readEoln();

	rep(i, h) {
		vector<int> a = inf.readInts(w, 0, 100, format("a_%d", i + 1));
		inf.readEoln();
	}
	inf.readEof();
}
