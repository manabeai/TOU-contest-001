#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	try{
		int N,M;
		cin >> N >> M;

		if (N < 0 || N > 300000) {
			throw runtime_error("N Out Of Range");
		}
		if (M < 0 || M > 300000) {
			throw runtime_error("M Out Of Range");
		}

		for (int i = 0; i < N; i++) {
			char C;
			cin >> C;
			if (C < 'A' && C > 'Z') {
				throw runtime_error("Char Out Of Range");
			}
		}
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