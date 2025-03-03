#include "testlib.h"
#include <fstream>
#include <iostream>
#include <random>
#include <string>
using namespace std;
const int MIN_N = 1;
const int MAX_N = 300000;
const int MIN_M = 1;
const int MAX_M = 300000;
const int MAX_CHAR_TYPE = 26;
const int MIN_CHAR_TYPE = 1;

int random_seq = 1;
int hand_seq = 1;

void generateRandom() {
    try{
        ofstream file("50 - random" + to_string(random_seq) + ".in");
        if (file.is_open()) {

            int n = rnd.next(MIN_N,MAX_N);
            int m = rnd.next(MIN_M,n);
            file << n << " " << m << "\n";

            int cnt = 0;
            while(cnt < n){
                int sequence_length = rnd.next(1,m * 2 + 1);
                if(cnt + sequence_length > n)sequence_length = n - cnt;
                cnt += sequence_length;
                char c = 'A' + rnd.next(MAX_CHAR_TYPE);
                for(int i = 0; i < sequence_length; i++){
                    if(cnt == n && i == sequence_length - 1)
                        file << c;
                    else
                        file << c << " ";
                }
            }
            file.flush();
            file.close();
        }
        else {
            throw runtime_error("ファイルが開けませんでした！");
        }
        random_seq++;
        return;
    }catch(const runtime_error& e){
        cerr << e.what() << endl;
        exit(1);
    }
}

void generateHand(int n, int m, int max_sequence_length, int char_types) {
    try{
        ofstream file("hand_" + to_string(hand_seq) + ".in");
        if (file.is_open()) {
            file << n << " " << m << "\n";
            int cnt = 0;
            while(cnt < n){
                int sequence_length = rnd.next(1,max_sequence_length);
                if(cnt + sequence_length > n)sequence_length = n - cnt;
                cnt += sequence_length;
                char c = 'A' + rnd.next(char_types);
                for(int i = 0; i < sequence_length; i++){
                    if(cnt == n && i == sequence_length - 1)
                        file << c;
                    else
                        file << c << " ";
                }
            }
            file.flush();
            file.close();
        }
        else {
            throw runtime_error("ファイルが開けませんでした！");
        }
        hand_seq++;
        return;
    }catch(const runtime_error& e){
        cerr << e.what() << endl;
        exit(1);
    }
}

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    
	for (int i = 0; i < 15; i++) {
		generateRandom();
	}
    generateHand(MAX_N,MAX_M,MAX_N,MAX_CHAR_TYPE);
    generateHand(MAX_N,MIN_M,MAX_N,MAX_CHAR_TYPE);
    generateHand(MAX_N,10,200,MIN_CHAR_TYPE);
    generateHand(MAX_N,MAX_M,MAX_M,MIN_CHAR_TYPE);
    generateHand(MAX_N,MAX_M,1,MAX_CHAR_TYPE);
    generateHand(MIN_N,MIN_M,1,MIN_CHAR_TYPE);
	return 0;
}