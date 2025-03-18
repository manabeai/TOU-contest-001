#include <bits/stdc++.h>
#include "testlib.h"
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
constexpr ll INF = 9009009009009009009LL;
constexpr int INF32 = 2002002002;
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





const ll MAX5 = 100000LL;
const ll MAX9 = 1000000000LL;

ll n, m, k, x;
vll a;

ll solve() {
	n = inf.readLong(2, 2 * MAX5, "n");
	m = inf.readLong(1, min(n * (n - 1) / 2, 2 * MAX5), "m");
	k = inf.readLong(1, n, "k");
	x = inf.readLong(1, n, "x");
	--x;
	a.resize(n);
	rep(i, n) a[i] = inf.readLong(1, MAX9, "a[i]");
	unordered_set<ll> starts;
	rep(i, k) {
		ll s = inf.readLong(1, n, "s[i]");
		--s;
		starts.insert(s);
	}

	vvll g(n, vll());
	rep(i, m) {
		ll u = inf.readLong(1, n, "u");
		ll v = inf.readLong(1, n, "v");
		--u, --v;
		g[v].push_back(u);
	}



	// 最小コスト
	vector<ll> dp(n, INF);
	auto dfs = [&](auto self, ll u) -> ll {
		if (dp[u] != INF) {
			return dp[u];
		}
		if (starts.count(u)) {
			return dp[u] = a[u];
		}

		ll minCost = INF;
		for (ll v : g[u]) {
			ll cost = self(self, v);
			chmin(minCost, cost);
		}

		if (minCost == INF) return INF;

		return dp[u] = minCost + a[u];
	};

	dfs(dfs, x);

	return dp[x] != INF ? dp[x] : -1;
}




int main(int argc, char* argv[]) {
	registerTestlibCmd(argc, argv);

	ll answer = solve();
	

	ll output_ans = 0;
	ll output_size = ouf.readLong(-1, n, "output");
	if (output_size == -1) {
		output_ans = -1;
	}
	else {
		rep(i, output_size) {
			ll next = ouf.readLong(1, n, "output");
			--next;
			output_ans += a[next];
		}
	}

	if (output_ans != answer) {
		quitf(_wa, "Expected: %lld, Got: %lld", answer, output_ans);
	}
	quitf(_ok, "Accepted: %lld", answer);
}
