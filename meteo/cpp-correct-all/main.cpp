#include <bits/stdc++.h>
#ifdef DEBUG
#include "cpp-dump/dump.hpp"
#define dump(...) cpp_dump(__VA_ARGS__)
#else
#define dump(...)
#endif
using namespace std;
typedef long long ll;
pair<ll, ll> rang(ll x, ll h, ll w) {
    // pair<ll, ll> tmp;

    ll f = max(-max(h-1,w-1)+x,0ll);
    ll b = min(min(h,w), x+1);
    return {f,b};
}

vector<vector<double>> rot(vector<vector<double>> S) {
    vector<vector<double>> G(S[0].size(), vector<double>(S.size()));

    for (ll i = 0; i < S.size(); ++i) {
        for (ll j = 0; j < S[0].size(); ++j) {
            G[j][S.size() - 1 - i] = S[i][j];
        }
    }

    return G;
}

void solve() {
    ll h, w;
    cin >> h >> w;
    vector<vector<double>> A(h, vector<double>(w));

    for (ll i = 0; i < h; ++i) {
        for (ll j = 0; j < w; ++j) {
            // cin >> A[i][j];
        }
    }
    if (h < w) {
        swap(h,w);
        // for (ll i = 0; i < 3; ++i) A = rot(A);
    }


    vector<vector<double>> dp(h+w+1, vector<double>((1ll << (min(h,w))), (double)0));
    dp[0][1] = A[0][0];

    for (ll i = 1; i < h+w-1; ++i) {
        // dump(i, (1ll << rang(i-1,h,w).first)-1);
        // dump((1ll << rang(i-1,h,w).first)-1 | cpp_dump::bin());
        ll span1 = rang(i-1,h,w).second - rang(i-1,h,w).first;
        for (ll bit1 = (1ll << rang(i-1,h,w).first)-1; bit1 < rang(i-1,h,w).first+(1ll << span1); ++bit1) {
            dump(rang(i-1,h,w).first, rang(i-1,h,w).first,i, bit1 | cpp_dump::bin(5));
            // for (ll bit2 = (1ll << rang(i,h,w).first)-1; bit2 < (1ll << rang(i,h,w).second); ++bit2) {
                
            // }
        }
        // for (ll bit = 0; bit < (1ll << (min(h,w))); ++bit) {
        //     for (ll bit2 = 0; bit2 < (1ll << (min(h,w))); ++bit2) {

        //     }

        //     for (ll j = max(-max(h-1,w-1)+i,0ll); j < min(min(h,w),i*2+1); ++j) {
        //         if (j == 0) {
        //             if (bit & 1) {
        //                 // tmp += dp[i-1][j];
        //             }
        //         } 
        //     }
        // }
    }
}

int main() {
    solve();
    return 0;
}