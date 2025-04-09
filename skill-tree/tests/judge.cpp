#include <unordered_set>
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





const ll MAX5 = 100000LL;
const ll MAX9 = 1000000000LL;

int main(int argc, char* argv[]) {
	registerTestlibCmd(argc, argv);

	// ll answer = solve();
	
	ll n = inf.readLong(2, 2 * MAX5, "n");
	ll m = inf.readLong(1, min(n * (n - 1) / 2, 2 * MAX5), "m");
	ll k = inf.readLong(1, n, "k");
	ll x = inf.readLong(1, n, "x");
	--x;
	vll a(n);
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
	
	// 想定解
	ll answer = 0;
	ll ans_size = ans.readLong(-1, n, "answer");
	if (ans_size == -1) {
		answer = -1;
	}
	else {
		rep(i, ans_size) {
			ll next = ans.readLong(1, n, "answer");
			--next;
			answer += a[next];
		}
	}

	// 出力
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
