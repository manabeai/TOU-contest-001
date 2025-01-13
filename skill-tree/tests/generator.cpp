#include <cstdint>
#include <cstdlib>
#include <fstream>
#include <set>
#include <vector>
using namespace std;
#define int long long

void generateRandom(int seq);
void generateMaxCase(int seq);

int32_t main() {
    for (int i = 1; i <= 20; i++) {
        generateRandom(i);
    }

    for (int i = 1; i <= 5; i++) {
        generateMaxCase(i);
    }
}

const int MAX_N = 2 * 1e5;
const int MAX_M = 2 * 1e5;
const int MAX_Ai = 1e9;
void generateRandom(int seq) {
    ofstream file = ofstream("random_" + to_string(seq) + ".in");

    int n = rand() % (MAX_N - 1) + 2;
    int m = rand() % (min(MAX_M, n * (n - 1) / 2)) + 1;
    int x = rand() % n + 1;

    file << n << " " << m << " " << x << endl;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        a[i] = rand() % MAX_Ai + 1;
    }

    for (int i = 0; i < n; i++) {
        file << a[i] << " ";
    }
    file << endl;

    // ランダムに頂点を並び替える
    vector<int> randomVertex(n);
    for (int i = 0; i < n; i++) {
        randomVertex[i] = i;
    }
    for (int i = 0; i < n; i++) {
        int j = rand() % n;
        swap(randomVertex[i], randomVertex[j]);
    }

    set<pair<int, int>> used;
    for (int i = 0; i < m; i++) {
        int l = rand() % n;
        int r = rand() % (n - l) + l;
        int u = randomVertex[l];
        int v = randomVertex[r];
        if (used.count({u, v})) {
            i--;
            continue;
        }
        if (u == v) {
            i--;
            continue;
        }

        used.insert({u, v});
        file << u + 1 << " " << v + 1 << endl;
    }
}

void generateMaxCase(int seq) {
    ofstream file = ofstream("max_" + to_string(seq) + ".in");

    int n = MAX_N;
    int m = MAX_M;
    int x = rand() % n + 1;

    file << n << " " << m << " " << x << endl;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        a[i] = MAX_Ai;
    }

    for (int i = 0; i < n; i++) {
        file << a[i] << " ";
    }
    file << endl;

    // ランダムに頂点を並び替える
    vector<int> randomVertex(n);
    for (int i = 0; i < n; i++) {
        randomVertex[i] = i;
    }
    for (int i = 0; i < n; i++) {
        int j = rand() % n;
        swap(randomVertex[i], randomVertex[j]);
    }

    set<pair<int, int>> used;
    for (int i = 0; i < m; i++) {
        int l = rand() % n;
        int r = rand() % (n - l) + l;
        int u = randomVertex[l];
        int v = randomVertex[r];
        if (used.count({u, v})) {
            i--;
            continue;
        }
        if (u == v) {
            i--;
            continue;
        }

        used.insert({u, v});
        file << u + 1 << " " << v + 1 << endl;
    }
}
