#include <fstream>
#include <iostream>
#include <random>
#include <string>
using namespace std;

int seq = 0;

void Generate() {
    try{
        ofstream file("50 - random" + to_string(seq) + ".in");
        if (file.is_open()) {
            random_device rd;
            mt19937 gen(rd());
            uniform_int_distribution<int> dist_n(0, 300000);
            uniform_int_distribution<int> dist_char(0, 25);

            int n = dist_n(gen);
            file << n << endl;

            for (int i = 0; i < n; i++) {
                char c = 'A' + dist_char(gen);
                file << c << " ";
            }
            file << endl;
        }
        else {
            throw runtime_error("ファイルが開けませんでした！");
        }
        seq++;
        return;
    }catch(const runtime_error& e){
        cerr << e.what() << endl;
        exit(1);
    }
}

int main() {
	for (int i = 0; i < 20; i++) {
		Generate();
	}
	return 0;
}

