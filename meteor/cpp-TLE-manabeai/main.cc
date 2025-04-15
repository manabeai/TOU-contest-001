#include <bits/stdc++.h>
#define rep(i,n) for (long long i=0;i<(ll)n;i++)
#define loop(i,m,n) for(long long i=m;i<=(ll)n;i++)
using namespace std;
typedef long long ll;
int dx[2] = {1, 0};
int dy[2] = {0, 1};

int correct(ll H,ll W,vector<vector<double>> a) {
    ll h = H;
    ll w = W;
	vector<vector<double>> dp(h+w-1,vector<double>(1LL<<h,0));
	dp[0][1]=1.0-a[0][0];
	rep(i,h+w-2){
		rep(j,1LL<<h){
			//次の列として、あり得る最大、1を建てた列を作る
			ll bit=(j|(j<<1LL));
			bit &= (1LL<<h)-1;
			ll tmp=bit;
			//jからtmpの状態へ遷移する確率を求める。
			while(1){
				double kakuritu=dp[i][j];
				rep(k,min(h,i+2)){
					//前の状態的にどっちでも良いならスキップ
					if(!(bit&(1LL<<k)))continue;
					//前の状態的に影響する場所は、落ちるか落ちないかの確率を計算。
					if(tmp&(1LL<<k))kakuritu *= 1.0-a[k][i+1-k];
					else kakuritu *= a[k][i+1-k];
				}
				dp[i+1][tmp]+=kakuritu;
				if(tmp==0)break;
				tmp = (bit&(tmp-1));
			}
		}
	}
	cout<<fixed<<setprecision(15)<<dp[h+w-2][1LL<<(h-1)]<<endl;
	return 0;
}

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
    ll ct = 0;

    for (ll i = 0; i < (1ll << (min((ulong)60,H*W))); ++i) {
        double odds = 1.0;
        for (ll p = 0; p < H; ++p) {
            for (ll q = 0; q < W; ++q) {
                if (ct > (ll)10000000) {correct(H,W,A); return;}
                ++ct;
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
    cout << ct << endl;
    if (H*W >= 8 || ct > (ll)100000000) {
        correct(H,W,A);
        return;
    }
    cout << fixed << setprecision(10) << ans << endl;
}

int main() {
    solve();
    return 0;
}