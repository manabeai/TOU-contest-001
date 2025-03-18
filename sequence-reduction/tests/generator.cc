#include "testlib.h"
#include <fstream>
#include <iostream>
#include <random>
#include <string>
using namespace std;

int random_seq = 1;
int hand_seq = 1;

void generateRandom(int MIN_N) {
    try{
        ofstream file("random_" + to_string(random_seq) + ".in");
        if (file.is_open()) {

            int n = rnd.next(max(1,MIN_N),500000);
            int m = rnd.next(1,n);
            file << n << " " << m << "\n";

            int cnt = 0;
            char prev = 'A';
            while(cnt < n){
                int sequence_length = rnd.next(max(1,m - 100),m + 100);
                if(cnt + sequence_length > n)sequence_length = n - cnt;
                cnt += sequence_length;
                char c = 'A' + rnd.next(26);
                while(c == prev){
                    c = 'A' + rnd.next(26);
                }
                prev = c;
                for(int i = 0; i < sequence_length; i++){
                    if(cnt == n && i == sequence_length - 1)
                        file << c;
                    else
                        file << c << " ";
                }
            }
            file << '\n';
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

void generateHand(int n, int m,int char_types) {
    try{
        ofstream file("hand_" + to_string(hand_seq) + ".in");
        if (file.is_open()) {
            file << n << " " << m << "\n";

            int cnt = 0;
            char prev = 'A';
            while(cnt < n){
                int sequence_length = rnd.next(max(1,m - (m / 10 * 9)),m + (m / 10 * 9));
                if(cnt + sequence_length > n)sequence_length = n - cnt;
                cnt += sequence_length;
                char c = 'A' + rnd.next(char_types);
                while(c == prev){
                    c = 'A' + rnd.next(char_types);
                }
                prev = c;
                for(int i = 0; i < sequence_length; i++){
                    if(cnt == n && i == sequence_length - 1)
                        file << c;
                    else
                        file << c << " ";
                }
            }
            file << '\n';
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
    
	generateRandom(1000); //nは1000以上
    generateRandom(10000);
    generateRandom(100000);
    generateRandom(150000);
    generateRandom(200000);
    generateRandom(250000);
    generateRandom(300000);
    generateRandom(350000);
    generateRandom(400000);
    generateRandom(450000);
    generateRandom(500000);
    generateRandom(500000);
    generateRandom(500000);

    generateHand(1,1,26); //n,m,文字種
    generateHand(2,2,26);
    generateHand(5,5,26);
    generateHand(10,10,26);
    generateHand(100,100,26);
    generateHand(100,1,26);
    generateHand(500000,100000,26);
    generateHand(500000,200000,2);
    generateHand(500000,250000,26);
    generateHand(500000,300000,2);
    generateHand(500000,350000,26);
    generateHand(500000,350000,2);
    generateHand(500000,400000,26);
    generateHand(500000,400000,2);
    generateHand(500000,500000,26);
    generateHand(500000,500000,2);

	return 0;
}