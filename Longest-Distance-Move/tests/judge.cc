#include "testlib.h"

int main(int argc, char *argv[]) {
	registerTestlibCmd(argc, argv);

	while (!ouf.seekEof()) {
		std::string s = ouf.readToken();
		if (s == "WA") {
			quitf(_wa, "WA");
		}
	}

	quitf(_ok, "AC");
	return 0;
}