#include <unordered_set>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)

#include "testlib.h"

int main(int argc, char *argv[]) {
    registerValidation(argc, argv);

    int h = inf.readInt(1, 1e6, "h");
    inf.readSpace();
    int n = inf.readInt(1, 1e6, "n");
    inf.readEoln();
    unordered_set<long long> s;
    rep(i, n) {
        long long a = inf.readLong(h, 1000000000000000000LL, "a_i");
        ensure(s.count(a) == 0);
        s.insert(a);

        if (i != n - 1) { inf.readSpace(); }
        else { inf.readEoln(); }
    }
    inf.readEof();
}
