#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

int main() {
    try {
        string T, U;
        int N;
        cin >> T >> U >> N;
        if (T.length() < 1 || T.length() > 20) {
            throw runtime_error("T Invalid Length");
        }
        for (const char& c : T) {
            if ((c < 'A' || c > 'Z') && (c < 'a' || c > 'z')) {
                throw runtime_error("T Invalid Character");
            }
        }
        if (U.length() < 1 || U.length() > 20) {
            throw runtime_error("U Invalid Length");
        }
        for (const char& c : U) {
            if ((c < 'A' || c > 'Z') && (c < 'a' || c > 'z')) {
                throw runtime_error("U Invalid Character");
            }
        }
        if(T == U){
            throw runtime_error("T And U Are The Same");
        }
        if (N < 2 || N > 1000) {
            throw runtime_error("N Out Of Range");
        }
        unordered_set<string> s_set;
        for (int i = 0; i < N; i++) {
            string S;
            cin >> S;
            if (S.length() < 1 || S.length() > 20) {
                throw runtime_error("S Invalid Length");
            }
            if (!s_set.insert(S).second) {
                throw runtime_error("Duplicated S");
            }
            for (const char& c : S) {
                if ((c < 'A' || c > 'Z') && (c < 'a' || c > 'z')) {
                    throw runtime_error("S Invalid Character");
                }
            }
        }
        if (s_set.insert(T).second) {
            throw runtime_error("T Is Not Included In S");
        }
        if (s_set.insert(U).second) {
            throw runtime_error("U Is Not Included In S");
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