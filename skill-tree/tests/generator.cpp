#include <cassert>
#include <fstream>
#include <queue>
#include <set>
#include <vector>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (n); i++)

#include "testlib.h"

void generateRandom(int seq);
void generateHand1();
void generateHand2();
void generateStarGraph(int seq);

int main(int argc, char* argv[]) {
	registerGen(argc, argv, 1);
    for (int i = 1; i <= 20; i++) {
        generateRandom(i);
    }
	generateHand1();
	generateHand2();
    for (int i = 1; i <= 10; i++) {
		generateStarGraph(i);
    }
}

const ll MAX_N = 2 * 1e5;
const ll MIN_N = 2;
const ll MAX_M = 2 * 1e5;
const ll MIN_M = 1;
const ll MAX_Ai = 1e9;
const ll MIN_Ai = 1;
void generateRandom(int seq) {
    ofstream file = ofstream("random_" + to_string(seq) + ".in");

    ll n = rnd.next(MIN_N, MAX_N);
	ll k = rnd.next(1LL, n);
	ll x = rnd.next(1LL, n);

    vector<ll> a(n);
    rep(i, n) a[i] = rnd.next(MIN_Ai, MAX_Ai);

    // ランダムに頂点を並び替える
    vector<ll> randomVertex(n);
	rep(i, n) randomVertex[i] = i + 1;
	shuffle(randomVertex.begin(), randomVertex.end());

	// ランダムに辺を追加(多重辺、閉路なし)
	ll m = 0;
    set<pair<ll, ll>> used;
    for (int i = 0; i < MAX_M; i++) {
        ll l = rnd.next(0LL, n - 2);
        ll r = rnd.next(l + 1, n - 1);
        ll u = randomVertex[l];
        ll v = randomVertex[r];

		if (used.count({u, v})) continue;
		used.insert({u, v});
		m++;
		if (min(MAX_M, n * (n - 1) / 2) == m) break;
    }

	// xと同じ連結成分の中に1つ以上sが存在するようにする
	vector<vector<ll>> g(n, vector<ll>());
	set<ll> components;
	for (auto [u, v] : used) {
		g[v - 1].push_back(u - 1);
	}
	queue<ll> q;
	q.push(x - 1);
	while (!q.empty()) {
		ll u = q.front();
		q.pop();
		components.insert(u + 1);

		for (ll v : g[u]) {
			if (!components.count(v + 1)) {
				q.push(v);
			}
		}
	}

	// 再度ランダムに頂点を並び替える
	rep(i, n) randomVertex[i] = i + 1;
	shuffle(randomVertex.begin(), randomVertex.end());

	// 最初に習得するスキルをランダムに選ぶ
	vector<ll> s;
	// 最低でも1つはxと同じ連結成分に含まれるようにする
	auto it = components.begin();
	ll firstSkillN = rnd.next(0, (int)components.size() - 1);
	rep(i, firstSkillN) it++;
	assert(it != components.end());
	s.push_back(*it);

	queue<ll> s_q;
	rep(i, n) if (s[0] != randomVertex[i]) s_q.push(randomVertex[i]);
	rep(i, k - 1) {
		s.push_back(s_q.front());
		s_q.pop();
	}



	// 出力
	file << n << " " << m << " " << k << " " << x << "\n";
	rep(i, n) {
		file << a[i];
		if (i != n - 1) file << " ";
	}
	file << "\n";

	rep(i, k) {
		file << s[i];
		if (i != k - 1) file << " ";
	}
	file << "\n";

	vector<pair<ll, ll>> edges;
	for (auto [u, v] : used) {
		edges.push_back({u, v});
	}
	shuffle(edges.begin(), edges.end());
	for (auto [u, v] : edges) {
		file << u << " " << v << "\n";
	}

	cout << flush;
}

void generateHand1() {
	ofstream file = ofstream("hand1.in");

	ll n = 1e5;
	vector<ll> vertex(n);
	rep(i, n) vertex[i] = i + 1;

	ll m = 2 * 1e5 - 4;
	ll x = n;
	vector<ll> a(n);
	rep(i, n) a[i] = 1;

	vector<pair<ll, ll>> edges;
	edges.push_back({n - 1, n});
	for (ll i = n - 2; i >= 2; i--) {
		edges.push_back({i, i + 1});
	}
	for (ll i = n - 1; i >= 2; i--) {
		edges.push_back({1, i});
	}

	assert(edges.size() == m);

	file << n << " " << m << " " << 1 << " " << x << "\n";

	rep(i, n) {
		file << a[i];
		if (i != n - 1) file << " ";
	}
	file << "\n";

	file << 1 << "\n";

	for (auto [u, v] : edges) {
		file << u << " " << v << "\n";
	}
	cout << flush;
}
void generateHand2() {
	ofstream file = ofstream("hand2.in");

	ll n = MAX_N;
	ll m = n - 1;
	ll x = n;
	vector<ll> a(n);
	rep(i, n) a[i] = 1;

	vector<pair<ll, ll>> edges;
	for (ll i = 1; i < n; i++) {
		edges.push_back({i, i + 1});
	}

	assert(edges.size() == m);

	file << n << " " << m << " " << 1 << " " << x << "\n";

	rep(i, n) {
		file << a[i];
		if (i != n - 1) file << " ";
	}
	file << "\n";

	file << 1 << "\n";

	for (auto [u, v] : edges) {
		file << u << " " << v << "\n";
	}
	cout << flush;
}

void generateStarGraph(int seq) {
	ofstream file = ofstream("star_" + to_string(seq) + ".in");

	ll n = MAX_N;
	ll m = n - 1;

	vector<ll> vertex(n);
	rep(i, n) vertex[i] = i + 1;
	shuffle(vertex.begin(), vertex.end());

	vector<ll> a(n);
	rep(i, n) a[i] = rnd.next(MIN_Ai, MAX_Ai);
	
	set<ll> outers; // 外周の頂点
	vector<pair<ll, ll>> edges;
	for (ll i = 1; i < n; i++) {
		edges.push_back({vertex[i], vertex[0]});
		outers.insert(vertex[i]);
	}
	assert(edges.size() == m);

	// xは真ん中の頂点
	ll x = vertex[0];

	// 出力
	file << n << " " << m << " " << outers.size() << " " << x << "\n";

	rep(i, n) {
		file << a[i];
		if (i != n - 1) file << " ";
	}
	file << "\n";

	for (auto v : outers) {
		file << v;
		if (v != *outers.rbegin()) file << " ";
	}
	file << "\n";

	for (auto [u, v] : edges) {
		file << u << " " << v << "\n";
	}
	cout << flush;
}
