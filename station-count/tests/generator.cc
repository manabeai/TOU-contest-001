#include "testlib.h"
#include <fstream>
#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

const int MIN_N = 2;
const int MAX_N = 1000;
const int MIN_LENGTH_OF_STATION_NAME = 1;
const int MAX_LENGTH_OF_STATION_NAME = 20;
int random_seq = 1;
int hand_seq = 1;

string generateStationName(){
    int name_length = rnd.next(MIN_LENGTH_OF_STATION_NAME, MAX_LENGTH_OF_STATION_NAME);
    string stmt;
    if(name_length == 1){
        stmt = "[A-Z]";
    }else if(name_length == 2){
        stmt = "[A-Z][a-z]";
    }else{
        stmt = "[A-Z][a-z]{" + to_string(name_length - 1) + "}";
    }
    string station = rnd.next(stmt);
    return station;
}

void generate() {
    try {
        string filename = "50 - random" + to_string(random_seq) + ".in";
        ofstream file(filename);
        if (!file) {
            throw runtime_error("ファイルを開けませんでした: " + filename);
        }

        int n = rnd.next(MIN_N,MAX_N);
        unordered_set<string> station_set;
        vector<string> s;
        s.reserve(n);

        while (station_set.size() < n) {
            string station = generateStationName();
            if (station_set.insert(station).second) {
                //駅名が重複しなかったら配列に加える
                s.push_back(station);
            }
        }

        int t_index = rnd.next(n);
        int u_index = rnd.next(n);
        while (t_index == u_index) {
            u_index = rnd.next(n);
        }

        file << s[t_index] << endl;
        file << s[u_index] << endl;
        file << n << endl;
        for (int i = 0; i < s.size(); i++) {
            file << s[i];
            if(i != s.size() - 1)file << "\n";
        }
        random_seq++;
        file.flush();
        file.close();
    }
    catch (const runtime_error& e) {
        cerr << "エラー: " << e.what() << endl;
        exit(1);
    }
}

void generateHand(int n) {
    try {
        string filename = "hand" + to_string(hand_seq) + ".in";
        ofstream file(filename);
        if (!file) {
            throw runtime_error("ファイルを開けませんでした: " + filename);
        }
        unordered_set<string> station_set;
        vector<string> s;
        s.reserve(n);

        while (station_set.size() < n) {
            string station = generateStationName();
            if (station_set.insert(station).second) {
                s.push_back(station);
            }
        }

        int t_index = rnd.next(n);
        int u_index = rnd.next(n);
        while (t_index == u_index) {
            u_index = rnd.next(n);
        }

        file << s[t_index] << endl;
        file << s[u_index] << endl;
        file << n << endl;
        for (int i = 0; i < s.size(); i++) {
            file << s[i];
            if(i != s.size() - 1)file << "\n";
        }
        hand_seq++;
        file.flush();
        file.close();
    }
    catch (const runtime_error& e) {
        cerr << "エラー: " << e.what() << endl;
        exit(1);
    }
}

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    for (int i = 0; i < 18; i++) {
        generate();
    }
    generateHand(2);
    generateHand(1000);
    return 0;
}
