#include <fstream>
#include <iostream>
#include <random>
#include <string>
#include <unordered_set>
using namespace std;

int seq = 0;

string GenerateStationName(mt19937& gen) {
    static uniform_int_distribution<int> dist_string_length(1, 20);
    static uniform_int_distribution<int> dist_upper_or_lower(0, 1);
    static uniform_int_distribution<int> dist_char(0, 25);

    int length = dist_string_length(gen);
    string station;
    for (int j = 0; j < length; j++) {
        char c = (dist_upper_or_lower(gen) ? 'A' : 'a') + dist_char(gen);
        station += c;
    }
    return station;
}

void Generate() {
    try {
        string filename = "50 - random" + to_string(seq) + ".in";
        ofstream file(filename);
        if (!file) {
            throw runtime_error("ファイルを開けませんでした: " + filename);
        }
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<int> dist_n(2, 1000);

        int n = dist_n(gen);
        uniform_int_distribution<int> dist_to_n(0, n - 1);

        unordered_set<string> station_set;
        vector<string> s;
        s.reserve(n);

        while (station_set.size() < n) {
            string station = GenerateStationName(gen);
            if (station_set.insert(station).second) {
                s.push_back(station);
            }
        }

        int t_index = dist_to_n(gen);
        int u_index = dist_to_n(gen);
        while (t_index == u_index) {
            u_index = dist_to_n(gen);
        }

        file << s[t_index] << endl;
        file << s[u_index] << endl;
        file << n << endl;
        for (const string& station : s) {
            file << station << endl;
        }
        seq++;
    }
    catch (const runtime_error& e) {
        cerr << "エラー: " << e.what() << endl;
        exit(1);
    }
}

int main() {
    for (int i = 0; i < 20; i++) {
        Generate();
    }
    return 0;
}
