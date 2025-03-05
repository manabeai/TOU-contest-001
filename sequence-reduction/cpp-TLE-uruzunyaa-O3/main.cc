#pragma GCC optimize("O3")
#include <iostream>
#include <string>
using namespace std;
#define rep(i,n) for (ll i=0;i<n;i++)
#define loop(i,m,n) for(ll i=m;i<=n;i++)
#define ll int
#define vl vector<long long>
#define vvl vector<vector<long long>>
#define vdbg(a) rep(ii,a.size()){cout<<a[ii]<<" ";}cout<<endl;
#define vvdbg(a) rep(ii,a.size()){rep(jj,a[ii].size()){cout<<a[ii][jj]<<" ";}cout<<endl;}
#define setdbg(a) for(const auto & ii:a){cout<<ii<<" ";}cout<<endl;
#define inf 4000000000000000000LL
#define mod 998244353LL
//メイン
int main(){
	ll n,m;
	cin>>n>>m;
	
	
	string s;
	rep(i,n){
		char c;
		cin>>c;
		s.push_back(c);
		bool f=true;
		if(s.size()<=m)rep(j,m){
			if(s[i-j]!=s[i]){
				f=false;
				break;
			}
		}
		if(f)s.erase(m);
	}
	cout<<s.size()<<endl;
	return 0;
}
