#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (1ll << 60);
bool chmin(ll &a, ll b){return a > b && (a = b, true);}


int main(){
    int N, M, K, X;
    cin >> N >> M >> K >> X;
    X--;
    vector<ll> A(N);
    for (auto &a : A) cin >> a;
    vector<ll> cost(N, INF);
    vector<int> fr(N, -1);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;
    for (int i = 0; i < K; i++){
        int s;
        cin >> s;
        s--;
        if (chmin(cost[s], A[s])) pq.emplace(A[s], s);
    }
    vector<vector<int>> G(N);
    while (M--){
        int a, b;
        cin >> a >> b;
        G[a - 1].push_back(b - 1);
    }
    while (!pq.empty()){
        auto [c, var] = pq.top();
        pq.pop();
        if (cost[var] != c) continue;
        for (auto x : G[var]) if (chmin(cost[x], c + A[x])){
            pq.emplace(cost[x], x);
            fr[x] = var;
        }
    }
    if (cost[X] == INF){
        cout << "-1\n";
        return 0;
    }
    vector<int> ans;
    while (X != -1){
        ans.push_back(X + 1);
        X = fr[X];
    }
    reverse(ans.begin(), ans.end());
    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); i++){
        if (i) cout << " " ;
        cout << ans[i];
    }
    cout << "\n";
}
