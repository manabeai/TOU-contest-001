#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
using ll = long long;
using std::cout;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<ll> A(N), B(N);
    ll X = 0;
    rep(i, 0, N) cin >> A[i], B[i] = A[i] - 1;
    rep(i, 0, N) X ^= B[i];
    ll sum = 0;
    rep(i, 0, N) sum += A[i];
    if (X == 0 && N % 2 == 0){
        cout << "Uruzunyaa\n";
        cout << sum << "\n";
        return 0;
    }
    cout << "Talc\n";
    ll ans = 0;
    if (N % 2 == 0){
        ans = sum;
        rep(i, 0, N){
            ll nX = (X ^ B[i]);
            if (nX < B[i]){
                ans = min(ans, sum - B[i] + nX);
            }
        }
        cout << ans + 1 << "\n";
        return 0;
    }
    
    /*
    rep(i, 0, N) rep(j, 0, i){
        ll nX = (X ^ B[i] ^ B[j]);
        if (min(B[i], B[j]) <= nX){
        // if (nX <= B[i] + B[j] && min(B[i], B[j]) <= nX){
            ans = min(ans, sum - B[i] - B[j] + nX);
            //break;
        }
    }*/
   
    struct F{
        ll val = -(1ll << 30);
        int ind = -1;
    };
    const int D = 20;
    
    // array<array<array<F, 2>, (1 << D)>, D> dp;
    vector<vector<array<F, 2>>> dp(D);
    rep(d, 0, D) dp[d].resize(1 << (d + 1));
    rep(i, 0, N){
        rep(j, 0, D) if ((B[i] & (1 << j)) == 0){
            int v = (B[i] & ((1 << (j + 1)) - 1));
            if (dp[j][v][0].ind == -1){
                dp[j][v][0] = {0, i};
            }
            else{
                dp[j][v][1] = {0, i};
            }
        }
    }
    auto add = [&](array<F, 2> &l, array<F, 2> r) -> void {
        rep(i, 0, 2) if (l[1].val < r[i].val){
            l[1] = r[i];
            if (l[0].val < l[1].val) swap(l[0], l[1]);
        }
    };
    rep(d, 0, D){
        rep(i, 0, d + 1) rep(j, 0, 1 << (d + 1)) if (j & (1 << i)){
            int x = j - (1 << i);
            int y = j;
            auto tmp0 = dp[d][x];
            add(dp[d][x], dp[d][y]);
            dp[d][y][0].val += (1 << i);
            dp[d][y][1].val += (1 << i);
            add(dp[d][y], tmp0);
        }
    }
    rep(i, 0, N){
        int tmp = (X ^ B[i]);
        int top = D;
        if (tmp == 0){
            ans = max(ans, X);
            continue;
        }
        while ((tmp & (1 << top)) == 0){
            top--;
        }
        int ind = -1;
        rep(k, 0, 2) if (dp[top][tmp][k].ind != i){
            ind = dp[top][tmp][k].ind;
            break;
        }
        if (ind != -1){
            ans = max(ans, B[i] + B[ind] - (X ^ B[i] ^ B[ind]));
        }
    }
    cout << sum - ans << "\n";
}


