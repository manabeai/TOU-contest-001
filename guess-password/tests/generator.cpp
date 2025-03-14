#include <vector>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)

#include "testlib.h"

void generate_random(int seq);
void generate_max(int seq);
void generate_same(int seq);

int main(int argc, char* argv[]) {
	registerGen(argc, argv, 1);

	rep(i, 5) generate_random(i + 1);
	rep(i, 5) generate_max(i + 1);
	rep(i, 26) generate_same(i + 1);
}

const int MAX_N = 250;

void generate_random(int seq) {
	ofstream file = ofstream("random_" + to_string(seq) + ".in");

	int n = rnd.next(1, MAX_N);

	file << n << endl;
	rep(i, n) file << (char)rnd.next('a', 'z');
	file << endl;
}
void generate_max(int seq) {
	ofstream file = ofstream("max_" + to_string(seq) + ".in");

	int n = MAX_N;

	file << n << endl;
	rep(i, n) file << (char)rnd.next('a', 'z');
	file << endl;
}

void generate_same(int seq) {
	ofstream file = ofstream("hand_" + to_string((seq + 10) % 26 + 1) + ".in");

	int n = MAX_N;

	file << n << endl;
	rep(i, n) file << (char)('a' + (seq - 1));
	file << endl;
}
