using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)

#include "testlib.h"

int main(int argc, char* argv[]) {
	registerValidation(argc, argv);

	int n = inf.readInt(1, 4 * 1e5, "n");
	inf.readEoln();

	rep(i, n) {
		int a = inf.readInt(1, 1e6, "a_i");
		if (i == n - 1) {
			inf.readEoln();
		} else {
			inf.readSpace();
		}
	}
	inf.readEof();
}
