#include <bits/stdc++.h>
#ifdef DEBUG
#include "cpp-dump/dump.hpp"
#define dump(...) cpp_dump(__VA_ARGS__)
#else
#define dump(...)
#endif
using namespace std;
typedef long long ll;
int dx[2] = {1, 0};
int dy[2] = {0, 1};

void solve() {
    ulong H, W;
    cin >> H >> W;

    vector<vector<double>> A(H, vector<double>(W));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> A[i][j];
            A[i][j] = A[i][j] / 100.0;
        }
    }

    vector<vector<ll>> state(H, vector<ll>(W, 0));

    auto dfs = [&](auto self, ll i, ll j) -> bool {
        if (i == H - 1 && j == W - 1) return true;

        for (ll r = 0; r < 2; ++r) {
            ll ni = i + dx[r];
            ll nj = j + dy[r];
            if (ni < H && nj < W && !state[ni][nj]) {
                return self(self, ni, nj);
            }
        }
        return false;
    };
    
    double ans = 0.0;

    for (ll i = 0; i < (1ll << (min((ulong)60,H*W))); ++i) {
        double odds = 1.0;
        for (ll p = 0; p < H; ++p) {
            for (ll q = 0; q < W; ++q) {
                if ((i >> (p*W + q)) & 1) {
                    state[p][q] = 1;
                    odds *= A[p][q];
                } else {
                    state[p][q] = 0;
                    odds *= (1.0 - A[p][q]);
                }
            }
        }
        if (state[0][0] == 1) continue;
        if (dfs(dfs, 0, 0)) ans += odds;
    }
    cout << fixed << setprecision(10) << ans << endl;
}

int main() {
    solve();
    return 0;
}