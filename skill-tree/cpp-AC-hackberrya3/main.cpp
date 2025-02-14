#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using P = pair<int, int>;
using PP = pair<int, P>;
using PLL = pair<ll, ll>;
using PPLL = pair<ll, PLL>;
#define rep(i, n) for(ll i = 0; i < n; ++i)
#define loop(i, a, b) for(ll i = a; i <= b; ++i)
#define all(v) v.begin(), v.end()
constexpr ll INF = 1001001001001001001LL;
constexpr int INF32 = 1001001001;
constexpr ll MOD = 998244353;
constexpr ll MOD107 = 1000000007;

// Linear Algebra ////////////////////////////////////////////////
const double Rad2Deg = 180.0 / M_PI;
const double Deg2Rad = M_PI / 180.0;
//////////////////////////////////////////////////////////////////

int dx[8] = {0, 1, 0, -1, 1, 1, -1, -1};
int dy[8] = {1, 0, -1, 0, 1, -1, 1, -1};

template <class T>
inline bool chmax(T &a, const T &b) {
	if (a < b) {
		a = b;
		return true;
	}
	return false;
}
template <class T>
inline bool chmin(T &a, const T &b) {
	if (a > b) {
		a = b;
		return true;
	}
	return false;
}

template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    for (size_t i = 0; i < v.size(); ++i) {
        os << v[i];
        if (i != v.size() - 1) os << " ";
    }
    return os;
}
template <typename T>
ostream& operator<<(ostream& os, const vector<vector<T>>& vv) {
	for (size_t i = 0; i < vv.size(); ++i) {
		os << vv[i];
		if (i != vv.size() - 1) os << "\n";
    }
    return os;
}
template <typename T>
istream& operator>>(istream& is, vector<T>& v) {
	assert(v.size() > 0);
	for (size_t i = 0; i < v.size(); ++i) is >> v[i];
	return is;
}
template <typename T>
istream& operator>>(istream& is, vector<vector<T>>& vv) {
	assert(vv.size() > 0);
	for (size_t i = 0; i < vv.size(); ++i) is >> vv[i];
	return is;
}

struct phash {
	template<class T1, class T2>
    inline size_t operator()(const pair<T1, T2> & p) const {
        auto h1 = hash<T1>()(p.first);
        auto h2 = hash<T2>()(p.second);

		size_t seed = h1 + h2; 
		h1 = ((h1 >> 16) ^ h1) * 0x45d9f3b;
        h1 = ((h1 >> 16) ^ h1) * 0x45d9f3b;
        h1 = (h1 >> 16) ^ h1;
        seed ^= h1 + 0x9e3779b9 + (seed << 6) + (seed >> 2);
		h2 = ((h2 >> 16) ^ h2) * 0x45d9f3b;
        h2 = ((h2 >> 16) ^ h2) * 0x45d9f3b;
        h2 = (h2 >> 16) ^ h2;
        seed ^= h2 + 0x9e3779b9 + (seed << 6) + (seed >> 2);
        return seed;
    }
};





int solve() {
	ll n, m, k, x; cin >> n >> m >> k >> x;
	--x;
	vll a(n);
	cin >> a;
	unordered_set<ll> starts;
	rep(i, k) {
		ll s; cin >> s;
		--s;
		starts.insert(s);
	}
	vvll g(n, vll());
	rep(i, m) {
		ll u, v; cin >> u >> v;
		--u, --v;
		g[v].push_back(u);
	}



	// 最小コスト、最適な前の頂点
	vector<pair<ll, ll>> dp(n, {INF, -1});
	auto dfs = [&](auto self, ll u) -> ll {
		if (dp[u].first != INF) {
			return dp[u].first;
		}
		if (starts.count(u)) {
			dp[u] = {a[u], -1};
			return dp[u].first;
		}

		ll minCost = INF;
		ll best = -1;
		for (ll v : g[u]) {
			ll cost = self(self, v);

			if (cost < minCost) {
				minCost = cost;
				best = v;
			}
			else if (cost == minCost && v < best) {
				minCost = cost;
				best = v;
			}
		}

		dp[u] = {minCost + a[u], best};
		return dp[u].first;
	};

	dfs(dfs, x);

	stack<ll> ans;
	for (ll u = x; u != -1; u = dp[u].second) {
		ans.push(u);
	}

	while (!ans.empty()) {
		cout << ans.top() + 1;
		if (ans.size() > 1) cout << " ";
		ans.pop();
	}
	cout << endl;

	return 0;
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	return solve();
}
