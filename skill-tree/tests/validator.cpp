#include <stack>
#include <vector>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define nC2(n) (n * (n - 1) / 2)

#include "testlib.h"

// サイクル検出
bool hasCycle(int n, const vector<vector<int>>& g) {
	vector<int> color(n, 0);
	rep(i, n) {
		if (color[i] == 0) {
			stack<int> st;
			st.push(i);
			color[i] = 1;
			while (!st.empty()) {
				int v = st.top();
				bool pushed = false;
				for (int u : g[v]) {
					if (color[u] == 0) {
						st.push(u);
						color[u] = 1;
						pushed = true;
						break;
					} else if (color[u] == 1) {
						return true;
					}
				}
				if (!pushed) {
					st.pop();
					color[v] = 2;
				}
			}
		}
	}
	return false;
}

const int MIN_N = 2;
const int MAX_N = 2 * 1e5;
const int MAX_A = 1e9;
int main(int argc, char* argv[]) {
	registerValidation(argc, argv);

	int n = inf.readInt(MIN_N, MAX_N, "n");
	inf.readSpace();
	ll MAX_M = min(nC2((ll)n), 200000LL);
	int m = inf.readInt(1, MAX_M, "m");
	inf.readSpace();
	int k = inf.readInt(1, n, "k");
	inf.readSpace();
	int x = inf.readInt(1, n, "x");
	inf.readEoln();

	rep(i, n) {
		inf.readInt(1, MAX_A, "a_i");
		if (i == n - 1) {
			inf.readEoln();
		} else {
			inf.readSpace();
		}
	}

	rep(i, k) {
		inf.readInt(1, n, "s_i");
		if (i == k - 1) {
			inf.readEoln();
		} else {
			inf.readSpace();
		}
	}

	vector<vector<int>> g(n, vector<int>());
	set<pair<int, int>> edges;
	rep(i, m) {
		int u = inf.readInt(1, n, "u_i");
		inf.readSpace();
		int v = inf.readInt(1, n, "v_i");
		inf.readEoln();
		ensure(u != v);
		ensure(edges.count({u, v}) == 0);
		ensure(edges.count({v, u}) == 0);
		edges.insert({u, v});
		g[u - 1].push_back(v - 1);
	}
	inf.readEof();

	ensure(!hasCycle(n, g));
	return 0;
}
