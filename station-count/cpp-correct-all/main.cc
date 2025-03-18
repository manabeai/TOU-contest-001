#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int main() {
    string T, U;
    int N;
    
    cin >> T >> U >> N;
    vector<string> stations(N);
    
    for (int i = 0; i < N; i++) {
        cin >> stations[i];
    }

    int start = -1, end = -1;
    for (int i = 0; i < N; i++) {
        if (stations[i] == T) start = i;
        if (stations[i] == U) end = i;
    }

    cout << abs(end - start) - 1 << endl;
    return 0;
}