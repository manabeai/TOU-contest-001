#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ll n,k;
  cin >> n >> k;
  string S;
  cin >> S;
  
  map<char,char> ab = {{'A', 'B'}, {'B','A'}};
  ll ans = 0;
  ll count = 1;
  for (ll i = 1; i < S.size(); ++i) {
      if (S[i-1] == S[i]) count++;
      else count = 1;

      if (count == k) {
          ans++;
          if (i < n-1 && S[i] != S[i+1]) {
              S[i-1] = ab[S[i]];
              count = 0;
          } else {
              S[i] = ab[S[i]];
              count = 1;
          }
      }
  }
  cout << ans << endl;
}
