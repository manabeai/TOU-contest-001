#include <bits/stdc++.h>
#ifdef DEBUG
#include "cpp-dump/dump.hpp"
#define dump(...) cpp_dump(__VA_ARGS__)
#else
#define dump(...)
#endif
using namespace std;
typedef long long ll;
// pair<ll, ll> rang(ll x, ll h, ll w) {
//     // pair<ll, ll> tmp;

//     ll f = max(-max(h-1,w-1)+x,0ll);
//     ll b = min(min(h,w), x+1);
//     return {f,b};
// }

// vector<vector<double>> rot(vector<vector<double>> S) {
//     vector<vector<double>> G(S[0].size(), vector<double>(S.size()));

//     for (ll i = 0; i < S.size(); ++i) {
//         for (ll j = 0; j < S[0].size(); ++j) {
//             G[j][S.size() - 1 - i] = S[i][j];
//         }
//     }

//     return G;
// }

// void solve() {
//     ll h, w;
//     cin >> h >> w;
//     vector<vector<double>> A(h, vector<double>(w));

//     for (ll i = 0; i < h; ++i) {
//         for (ll j = 0; j < w; ++j) {
//             // cin >> A[i][j];
//         }
//     }
//     if (h < w) {
//         swap(h,w);
//         // for (ll i = 0; i < 3; ++i) A = rot(A);
//     }


//     vector<vector<double>> dp(h+w+1, vector<double>((1ll << (min(h,w))), (double)0));
//     dp[0][1] = A[0][0];

//     for (ll i = 1; i < h+w-1; ++i) {
//         // dump(i, (1ll << rang(i-1,h,w).first)-1);
//         // dump((1ll << rang(i-1,h,w).first)-1 | cpp_dump::bin());
//         ll span1 = rang(i-1,h,w).second - rang(i-1,h,w).first;
//         for (ll bit1 = (1ll << rang(i-1,h,w).first)-1; bit1 < rang(i-1,h,w).first+(1ll << span1); ++bit1) {
//             dump(rang(i-1,h,w).first, rang(i-1,h,w).first,i, bit1 | cpp_dump::bin(5));
//             // for (ll bit2 = (1ll << rang(i,h,w).first)-1; bit2 < (1ll << rang(i,h,w).second); ++bit2) {
                
//             // }
//         }
//         // for (ll bit = 0; bit < (1ll << (min(h,w))); ++bit) {
//         //     for (ll bit2 = 0; bit2 < (1ll << (min(h,w))); ++bit2) {

//         //     }

//         //     for (ll j = max(-max(h-1,w-1)+i,0ll); j < min(min(h,w),i*2+1); ++j) {
//         //         if (j == 0) {
//         //             if (bit & 1) {
//         //                 // tmp += dp[i-1][j];
//         //             }
//         //         } 
//         //     }
//         // }
//     }
// }

// int main() {
//     solve();
//     return 0;
// }

// #include <bits/stdc++.h>
// #ifdef DEBUG
// #include "cpp-dump/dump.hpp"
// #define dump(...) cpp_dump(__VA_ARGS__)
// #else
// #define dump(...)
// #endif
// using namespace std;
// typedef long long ll;

int main() {
    ulong H, W;
    cin >> H >> W;

    vector<vector<double>> A(H, vector<double>(W));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> A[i][j];
            A[i][j] = 1.0 - A[i][j] / 100.0; // 隕石が降らない確率
        }
    }
    dump(A);

    // DPテーブルを用意
    vector<vector<double>> dp((H+W), vector<double>((1ll << W), 0.0));
    ulong min_haba = min(H,W);
    dp[0][0] = A[0][0]; // 初期状態はスタート地点の確率

    // bitset<11> bs_a, bs_j;

    // DPを計算
    for (int i = 1; i <= H+W-2; i++) {
        for (ulong a = 0; a < (1ll << min((ulong)i,min(H+W-i,min_haba))); a++) {
            for (ulong b = 0; b < (1ll << min((ulong)i+1,min(H+W-i-(ulong)1,min_haba))); ++b) {
                bitset<11> bs_a = a;
                bitset<11> bs_b = b;

                dump(i,bs_a, bs_b);
                double tmp = 1.0;
                for (ll j = 0; j < min((ulong)i+1,min(H+W-i-(ulong)1,min_haba)); ++j) {
                    ll x = i - min(H,W) + 1 + j;
                    ll y = i-x;
                    dump(x,y);
                    // if (!bs_b.test(j)) continue;

                    if (x == 0) {
                        // x-> o
                        if (!bs_a.test(0) && bs_b.test(0)) {
                        // x -> x
                        } else if (!bs_a.test(0) && !bs_b.test(0)) {
                            tmp *= 1.0;
                        } else if (bs_a.test(0) && bs_b.test(0)) {
                            tmp *= A[x][y];
                        } else {
                            tmp *= 1.0 - A[x][y];
                        }
                    } else if (y == 0) {
                        // y-> o
                        if (!bs_a.test(0) && bs_b.test(0)) {
                        // y -> y
                        } else if (!bs_a.test(0) && !bs_b.test(0)) {
                            tmp *= 1.0;
                        } else if (bs_a.test(0) && bs_b.test(0)) {
                            tmp *= A[x][y];
                        } else {
                            tmp *= 1.0 - A[x][y];
                        }
                    } else {
                        continue;
                    }
                }

                dp[i][b] = dp[i-1][a] * tmp;
                dump(i,bs_b,dp[i]);
            }
        }
        // if (i > 0) dp[i][j] += dp[i - 1][j] * A[i][j]; // 上からの遷移
        // if (j > 0) dp[i][j] += dp[i][j - 1] * A[i][j]; // 左からの遷移
    }
    cout << fixed << setprecision(3) << dp[H - 1][W - 1] << endl;
    return 0;
}

