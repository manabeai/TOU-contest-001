#include <cassert>
#include <fstream>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define loop(i, start, end) for (ll i = (start); i < (end); i++)

#include "testlib.h"

void generateRandom(int seq);
void generateHand1();
void generateHand2();
void generateStarGraph(int seq);
void generateMaxHeap();
void generateMaxHeap2();
void generateMaxHeap3();
void generateAddAfterPop(int cnt);
void generateSameCost();

int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);

    for (int i = 1; i <= 25; i++) {
        generateRandom(i);
    }
    generateHand1();
    generateHand2();
    for (int i = 1; i <= 3; i++) {
        generateStarGraph(i);
    }
	generateMaxHeap();
	generateMaxHeap2();
	generateMaxHeap3();

	generateAddAfterPop(2);
	generateAddAfterPop(3);

	generateSameCost();

	return 0;
}

const ll MAX_N = 2 * 1e5;
const ll MIN_N = 2;
const ll MAX_M = 2 * 1e5;
const ll MIN_M = 1;
const ll MAX_Ai = 1e9;
const ll MIN_Ai = 1;
void generateRandom(int seq) {
    ofstream file = ofstream("50-random_" + to_string(seq) + ".in");

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

    // 再度ランダムに頂点を並び替える
    rep(i, n) randomVertex[i] = i + 1;
    shuffle(randomVertex.begin(), randomVertex.end());

    vector<ll> s;
    queue<ll> s_q;
    rep(i, n) s_q.push(randomVertex[i]);
    rep(i, k) {
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
    ofstream file = ofstream("99-hand1.in");

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
    ofstream file = ofstream("99-hand2.in");

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
    ofstream file = ofstream("99-star_" + to_string(seq) + ".in");

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


void generateMaxHeap() {
    ofstream file = ofstream("99-max_heap.in");

	ll n = 150000 + 1;
	assert(n % 3 == 1);
	ll x = 1;
	ll k = 1;

	vector<ll> a(n, MIN_Ai);
	for (ll i = 1; i < n; i += 3) {
		a[i] = 10;
	}
	for (ll i = 0, j = 1; i < n; i += 3, j++) {
		a[i] = MIN_Ai + j * 10;
	}

	vector<ll> s(k);
	s[0] = n;

	vector<pair<ll, ll>> edges;
	for (ll i = 0; i <= n - 3; i += 3) {
		edges.push_back({i + 1, i});
		edges.push_back({i + 3, i + 1});
		edges.push_back({i + 2, i});
		edges.push_back({i + 3, i + 2});
	}



	file << n << " " << edges.size() << " " << k << " " << x << "\n";

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

	for (auto [u, v] : edges) {
		file << u + 1 << " " << v + 1 << "\n";
	}

	file << flush;
}
void generateMaxHeap2() {
    ofstream file = ofstream("99-max_heap2.in");

	ll n = 150000 + 1;
	assert(n % 3 == 1);
	ll x = (n - 1) / 3 + 2;
	ll k = 1;

	vector<ll> a(n, MIN_Ai);
	for (ll i = (n - 1) / 3 + 2; i < n; i += 2) {
		a[i] = 10;
	}
	for (ll i = (n - 1) / 3 + 1, j = 1; i < n; i += 2, j++) {
		a[i] = MIN_Ai + j * 10;
	}

	vector<ll> s(k);
	s[0] = 1;

	vector<pair<ll, ll>> edges;
	for (ll i = (n - 1) / 3 + 1, j = 1; i < n - 2; i += 2, j++) {
		edges.push_back({i + 1, i});
		edges.push_back({i + 2, i + 1});
		edges.push_back({j, i});
		edges.push_back({i + 2, j});
	}
	edges.push_back({0, n - 1});
	edges.push_back({n - 1, n - 2});
	edges.push_back({0, (n - 1) / 3});
	edges.push_back({(n - 1) / 3, n - 2});



	file << n << " " << edges.size() << " " << k << " " << x << "\n";

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

	for (auto [u, v] : edges) {
		file << u + 1 << " " << v + 1 << "\n";
	}

	file << flush;
}

void generateMaxHeap3() {
    ofstream file = ofstream("99-max_heap3.in");

	ll n = 133332 - 1;
	ll x = 2;
	ll k = 1;

	vector<ll> a(n, MIN_Ai);
	loop(i, 1, n / 2) {
		a[i] = MIN_Ai + (i - 1) * 10;
	}

	vector<ll> s(k);
	s[0] = 1;

	vector<pair<ll, ll>> edges;
	loop(i, 1, n / 2 - 1) {
		edges.push_back({i + 1, i});
		edges.push_back({i + n / 2, i});
		edges.push_back({i + 1, i + n / 2});
	}
	edges.push_back({0, n / 2});
	edges.push_back({0, n / 2 + n / 2});


	file << n << " " << edges.size() << " " << k << " " << x << "\n";

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

	for (auto [u, v] : edges) {
		file << u + 1 << " " << v + 1 << "\n";
	}

	file << flush;
}

void generateAddAfterPop(int cnt) {
	ofstream file = ofstream("99-add_after_pop" + to_string(cnt) + ".in");

	ll DEF_N = 133332;
	// ll DEF_N = 24;
	ll n = DEF_N + cnt + 1;
	assert(DEF_N % (2 * cnt) == 0);
	ll x = n;
	ll k = 1;

	vector<ll> a(n, MIN_Ai);
	vector<ll> s(k);
	s[0] = 1;

	vector<pair<ll, ll>> edges;

	ll size = (n - (cnt + 1)) / (2 * cnt);
	ll offset = 1;
	rep(_, cnt) {
		rep(i, size) {
			a[i + offset] = i + 1;
			a[i + offset + size] = 2 * size - 2 * i;
		}

		rep(i, size) {
			edges.push_back({offset - 1, offset + i});
			edges.push_back({offset + i, offset + i + size});
			edges.push_back({offset + i + size, offset + 2 * size});
		}

		offset += 2 * size + 1;
	}



	file << n << " " << edges.size() << " " << k << " " << x << "\n";

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

	for (auto [u, v] : edges) {
		file << u + 1 << " " << v + 1 << "\n";
	}
	file << flush;
}

void generateSameCost() {
	ofstream file = ofstream("99-same_cost.in");

	ll n = 150000 + 1;
	assert((n - 1) % 3 == 0);
	assert(n >= 4);
	ll k = 1;
	ll x = n;

	vector<ll> a(n, MAX_Ai);
	vector<ll> s(k);
	s[0] = 1;

	vector<pair<ll, ll>> edges;
	for (ll i = n - 1; i >= 3; i -= 3) {
		edges.push_back({i - 1, i});
		edges.push_back({i - 2, i});
		edges.push_back({i - 3, i - 1});
		edges.push_back({i - 3, i - 2});
	}



	file << n << " " << edges.size() << " " << k << " " << x << "\n";
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

	for (auto [u, v] : edges) {
		file << u + 1 << " " << v + 1 << "\n";
	}
	file << flush;
}
