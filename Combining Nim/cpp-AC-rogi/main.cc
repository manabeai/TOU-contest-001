#line 2 "/Users/korogi/Desktop/cp-cpp/template.hpp"
#include <bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
using i128 = __int128;
using u32 = unsigned int;
using u64 = unsigned long long;
using u128 = unsigned __int128;
using f32 = double;
using f64 = long double;
using f128 = __float128;

#define DMP(x) cout << "[" << __LINE__ << "]" << " " << #x << ":" << " " << x << endl;

#define FOR1(n)          for(int _ =  0 , n_ = (n); _ < n_; _++)
#define FOR2(i, n)       for(int i =  0 , n_ = (n); i < n_; i++)
#define FOR3(i, s, t)    for(int i = (s), t_ = (t); i < t_; i++)
#define FOR4(i, s, t, d) for(int i = (s), t_ = (t), d_ = (d); i < t_; i += d_)
#define OVERLOAD4(a, b, c, d, e, ...) e
#define FOR(...) OVERLOAD4(__VA_ARGS__, FOR4, FOR3, FOR2, FOR1)(__VA_ARGS__)

#define REV1(n)          for(int _ = (n) - 1; _ >=  0 ; _--)
#define REV2(i, n)       for(int i = (n) - 1; i >=  0 ; i--)
#define REV3(i, s, t)    for(int i = (t) - 1, s_ = (s); i >= s_; i--)
#define REV4(i, s, t, d) for(int i = (t) - 1, s_ = (s), d_ = (d); i >= s_; i -= d_)
#define OVERLOAD3(a, b, c, d, ...) d
#define REV(...) OVERLOAD4(__VA_ARGS__, REV4, REV3, REV2, REV1)(__VA_ARGS__)

#define FOR_SUBSET(T, S) for(int S_ = (S), T = S_; T >= 0; T = (T == 0 ? -1 : (T - 1) & S_))

#define MULTI for(int testcase_ = in(), testcase = 0; testcase < testcase_; testcase++) [&]

template < class T > using heap_max = priority_queue< T, vector< T >, less< T > >;
template < class T > using heap_min = priority_queue< T, vector< T >, greater< T >>;

template < class T, class U > bool chmin(T& a, const U& b) { return a > b ? a = b, 1 : 0; }
template < class T, class U > bool chmax(T& a, const U& b) { return a < b ? a = b, 1 : 0; }

i64 floor_div(const i64 n, const i64 d) { assert(d != 0); return n / d - ((n ^ d) <  0 && n % d != 0); }
i64  ceil_div(const i64 n, const i64 d) { assert(d != 0); return n / d + ((n ^ d) >= 0 && n % d != 0); }

template < class T, class F > T bin_search(T ok, T ng, F check) { while(abs(ok - ng) > 1) { T mid = (ok + ng) / 2; (check(mid) ? ok : ng) = mid; } return ok; }
template < class T, class F > T bin_search_real(T ok, T ng, F check, int step = 100) { FOR(step) { T mid = (ok + ng) / 2; (check(mid) ? ok : ng) = mid; } return ok; }

template < class T, class U > T accum(const vector< U >& a) { return accumulate(a.begin(), a.end(), T(0)); }
template < class T > pair< T, int > min(const vector< T >& a) { auto itr = min_element(a.begin(), a.end()); return {*itr, itr - a.begin()}; }
template < class T > pair< T, int > max(const vector< T >& a) { auto itr = max_element(a.begin(), a.end()); return {*itr, itr - a.begin()}; }
template < class T > void sort(vector< T >& a) { sort(a.begin(), a.end()); }
template < class T > void rsort(vector< T >& a) { sort(a.rbegin(), a.rend()); }
template < class T > void reverse(vector< T >& a) { reverse(a.begin(), a.end()); }
void sort(string& s) { sort(s.begin(), s.end()); }
void rsort(string& s) { sort(s.rbegin(), s.rend()); }
void reverse(string& s) { reverse(s.begin(), s.end()); }
template < class T, class Cmp > void sort(vector< T >& a, Cmp cmp) { sort(a.begin(), a.end(), cmp); }
template < class T > int LB(vector< T >& a, T x) { return distance(a.begin(), lower_bound(a.begin(), a.end(), x)); }
template < class T > int UB(vector< T >& a, T x) { return distance(a.begin(), upper_bound(a.begin(), a.end(), x)); }
template < class T > void unique(vector< T >& a) { sort(a.begin(), a.end()); a.erase(unique(a.begin(), a.end()), a.end()); }
vector<int> iota(int n) { vector<int> a(n); iota(a.begin(), a.end(), 0); return a; }


namespace scan {
struct x0 { template < class T > operator T() { T x; cin >> x; return x; } };
struct x1 { int n; x1(int n) : n(n) {} template < class T > operator vector< T >() { vector< T > a(n); for(T& x : a) cin >> x; return a; } };
struct x2 { int h, w; x2(int h, int w) : h(h), w(w) {} template < class T > operator vector< vector< T > >() { vector m(h, vector< T >(w)); for(vector< T >& a : m) for(T& x : a) cin >> x; return m; } };
struct cppio { cppio() { cin.tie(0); ios::sync_with_stdio(0); } } cppio_instance;
}
scan::x0 in() { return scan::x0(); }
scan::x1 in(int n) { return scan::x1(n); }
scan::x2 in(int h, int w) { return scan::x2(h, w); }

template < class T > ostream& operator << (ostream& os, const vector< T > a) {
    const int n = a.size();
    FOR(i, n) { os << a[i]; if(i + 1 != n) os << ' '; }
    return os;
}
template < class T > int print_n(const vector< T > a) { for(T x : a) cout << x << '\n'; return 0; }
int print() { cout << '\n'; return 0; }
template < class Head, class... Tail > int print(Head&& h, Tail&&... t) { cout << h; if(sizeof...(Tail)) cout << ' '; return print(forward<Tail>(t)...); }
namespace printer {
    void prec(int n) { cout << fixed << setprecision(n); }
    void flush() { cout.flush(); }
}

constexpr pair<int, int> dir4[] = {{-1, 0}, {0, -1}, {+1, 0}, {0, +1}};

vector<int>& operator ++ (vector<int>& a) { for(auto& e : a) e++; return a; }
vector<int>& operator -- (vector<int>& a) { for(auto& e : a) e--; return a; }
vector<int>  operator ++ (vector<int>& a, int) { vector<int> b = a; ++a; return b; }
vector<int>  operator -- (vector<int>& a, int) { vector<int> b = a; --a; return b; }

template < class T > vector<pair< T, int>> RLE(const vector< T >& a) { vector<pair< T, int>> v; for(const T& x : a) { if(not v.empty() and v.back().first == x) v.back().second++; else v.emplace_back(x, 1); } return v; }
vector<pair<char, int>> RLE(const string& s) { vector<pair<char, int>> v; for(const char& c : s) { if(not v.empty() and v.back().first == c) v.back().second++; else v.emplace_back(c, 1); } return v; }
template < class String, class Same > vector<String> RLE(const String& a, const Same same) { vector<String> v; for(const auto& x : a) { if(not v.empty() and same(v.back().back(), x)) v.back().push_back(x); else v.push_back({x}); } return v; }

int YESNO(bool yes) { return print(yes ? "YES" : "NO"); }
int YesNo(bool yes) { return print(yes ? "Yes" : "No"); }

constexpr i32 INF32 = 1e9;
constexpr i64 INF64 = 1e18;
#line 2 "a.cpp"

int main() {
    int N = in();
    vector<i64> A = in(N);

    i64 XOR = 0;
    for(i64 a : A) XOR ^= (a - 1);
    const i64 SUM = accum<i64>(A);

    if(N % 2 == 0) {
        if(XOR != 0) {
            print("Talc");
            i64 ans = INF64;
            for(i64 a : A) {
                const i64 x = XOR ^ (a - 1);
                if(x < a - 1) chmin(ans, SUM + x - (a - 1));
            }
            print(1 + ans);
        } else {
            print("Uruzunyaa");
            print(SUM);
        }
    } else {
        using V = array<pair<i64, int>, 2>;
        array<pair<i64, int>, 4> buf;
        auto push = [&](V& a, V b) {
            buf[0] = a[0];
            buf[1] = a[1];
            buf[2] = b[0];
            buf[3] = b[1];
            sort(buf.rbegin(), buf.rend());
            a[0] = buf[0];
            a[1] = buf[1];
        };
        const int LOG = 20;
        vector dp(LOG, vector<V>());
        FOR(k, LOG) {
            dp[k].resize(1 << (k + 1));
            FOR(p, 1 << (k + 1)) {
                dp[k][p][0] = dp[k][p][1] = {-INF64, -INF32};
            }
        }
        FOR(i, N) FOR(k, LOG) if(((A[i] - 1) >> k & 1) == 0) {
            const int p = (A[i] - 1) & ((1 << (k + 1)) - 1);
            FOR(f, 2) {
                if(dp[k][p][f].second < 0) {
                    dp[k][p][f] = {0, i};
                    break;
                }
            }
        }
        
        FOR(k, LOG) FOR(b, k + 1) FOR(p, 1 << (k + 1)) if(p >> b & 1) {
            const int q = p - (1 << b);
            auto dp_ = dp[k][q];
            push(dp[k][q], dp[k][p]);
            for(auto& e : dp[k][p]) e.first += (1 << b);
            push(dp[k][p], dp_);
        }

        i64 ans = INF64;
        FOR(i, N) {
            const i64 T = XOR ^ (A[i] - 1);
            if(T == 0) {
                chmin(ans, SUM - (A[i] - 1));
            } else {
                int k = LOG; while((T >> k & 1) == 0) k--;
                for(auto e : dp[k][T]) {
                    const int j = e.second;
                    if(j < 0) continue;
                    if(i == j) continue;
                    chmin(ans, SUM - (A[i] - 1) - (A[j] - 1) + (XOR ^ (A[i] - 1) ^ (A[j] - 1)));
                }
            }
        }
        print("Talc");
        print(ans);
    }
}

