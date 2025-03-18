#include "testlib.h"
#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    try {
        string A = inf.readToken("[a-zA-Z]{1,20}");
        inf.readEoln();
        string B = inf.readToken("[a-zA-Z]{1,20}");
        inf.readEoln();
        int N = inf.readInt(2,1000);
        inf.readEoln();

        if(A == B){
            throw runtime_error("A And B Are The Same");
        }

        unordered_set<string> s_set;
        for (int i = 0; i < N; i++) {
            string S = inf.readToken("[a-zA-Z]{1,20}");
            inf.readEoln();
            if (!s_set.insert(S).second) {
                throw runtime_error("Duplicated S");
            }
        }
        if (s_set.insert(A).second) {
            throw runtime_error("A Is Not Included In S");
        }
        if (s_set.insert(B).second) {
            throw runtime_error("B Is Not Included In S");
        }
        inf.readEof();
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