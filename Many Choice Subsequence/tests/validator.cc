using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)

#include "testlib.h"

int main(int argc, char* argv[]) {
	registerValidation(argc, argv);

	int n = inf.readInt(1, 2 * 1e5, "n");
	inf.readEoln();

	long long sumA = 0;
	rep(i, n) {
		int a = inf.readInt(0, 2 * 1e5, "a_i");
		sumA += a;
		if (i == n - 1) {
			inf.readEoln();
		} else {
			inf.readSpace();
		}
	}
	ensure(0 <= sumA && sumA <= 2 * 1e5);

	long long sumB = 0;
	rep(i, n) {
		int b = inf.readInt(0, 2 * 1e5, "b_i");
		sumB += b;
		if (i == n - 1) {
			inf.readEoln();
		} else {
			inf.readSpace();
		}
	}
	ensure(0 <= sumB && sumB <= 2 * 1e5);

	rep(i, n) {
		int c = inf.readInt(1, 1e9, "c_i");
		if (i == n - 1) {
			inf.readEoln();
		} else {
			inf.readSpace();
		}
	}

	inf.readEof();
}
