#include <fstream>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)

#include "testlib.h"

void generate_random(int seq);
void generate_hand();

int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);

	rep(i, 10) generate_random(i);
	generate_hand();

    return 0;
}

const int MAX = 1e9;

void generate_random(int seq) {
	ofstream file("random_" + to_string(seq) + ".in");

	int d = rnd.next(1, MAX);
	int A = rnd.next(1, MAX);
	int Y = rnd.next(1, MAX);

	file << d << endl;
	file << A << " " << Y << endl;
}
void generate_hand() {
	ofstream file("hand_1.in");
	file << MAX << endl;
	file << MAX << " " << MAX << endl;
	file.close();

	file = ofstream("hand_2.in");
	file << 1 << endl;
	file << 1 << " " << 1 << endl;
	file.close();

	file = ofstream("hand_3.in");
	file << 1 << endl;
	file << 1 << " " << MAX << endl;
	file.close();

	file = ofstream("hand_4.in");
	file << 1 << endl;
	file << MAX << " " << 1 << endl;
	file.close();

	file = ofstream("hand_5.in");
	file << MAX << endl;
	file << 1 << " " << 1 << endl;
	file.close();

	file = ofstream("hand_6.in");
	file << MAX << endl;
	file << MAX << " " << 1 << endl;
	file.close();

	file = ofstream("hand_7.in");
	file << MAX << endl;
	file << 1 << " " << MAX << endl;
	file.close();
}
