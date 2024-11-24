#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// 等差数列の和: a::=初項 n::=項数 d::=等差
long long tousa(ll a, ll n, ll d) {
    return (n * (2*a + (n-1)*d)) / 2;
}

void solve() {
    ll h,n;
    cin >> h >> n;
    vector<ll> A(n);
    for (ll i = 0; i < n; ++i) cin >> A[i];
    sort(A.begin(), A.end());

    ll ans = tousa(1, h, 2) * n;

    for (ll i = 1; i < n; ++i) {

        ll dist = A[i] - A[i-1];
        if (dist < h * 2 - 1) {

            if (dist % 2 == 1) {
                ans -= tousa(2, h - (dist+1) / 2, 2);
            } else {
                ans -= tousa(1, h - dist / 2, 2);
            }
        }
    }
    cout << ans << endl;
}

int main() {
    solve();
    return 0;
}