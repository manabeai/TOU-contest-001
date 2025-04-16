#pragma GCC optimize("O3")
#include<bits/stdc++.h>
#include<boost/multiprecision/cpp_int.hpp>
using namespace std;
#define ll long long
#define rep(i,n) for (long long i=0;i<(ll)n;i++)
#define loop(i,m,n) for(long long i=m;i<=(ll)n;i++)
#define bbi boost::multiprecision::cpp_int
#define vl vector<long long>
#define vvl vector<vector<long long>>
#define vdbg(a) rep(ii,a.size()){cout<<a[ii]<<" ";}cout<<endl;
#define vvdbg(a) rep(ii,a.size()){rep(jj,a[ii].size()){cout<<a[ii][jj]<<" ";}cout<<endl;}
#define setdbg(a) for(const auto & ii:a){cout<<ii<<" ";}cout<<endl;
#define inf 4000000000000000000LL
#define mod 998244353LL
//#define mod 1000000007LL

//メイン
int main(){
	ll h,w;
	cin>>h>>w;
	//a[i][j]の確率で通れない。
	vvl a(h,vl(w));
	rep(i,h)rep(j,w)cin>>a[i][j];
	
	vector<vector<bbi>> dp(h+w-1,vector<bbi>(1<<w,0));
	dp[0][1] = 100-a[0][0];
	
	rep(i,h+w-2){
		rep(b,1<<w){
			if(dp[i][b]==0)continue;
			//次,行ける可能性のある場所のリスト
			ll bbit=b|(b<<1);
			bbit &= (1<<w)-1;
			
			rep(c,1<<w){
				bool f=false;
				rep(j,w)if(c&(1<<j))if(i+1-j>=h||i+1-j<0)f=true;
				if(f)continue;
				ll cbit= bbit&c;
				bbi tmp=1;

				loop(j,max(i+2-h,0LL),min(i+1,w-1)){
					if(c&(1<<j))tmp*=100-a[i+1-j][j];
					else tmp*=a[i+1-j][j];
				}

				dp[i+1][cbit]+=tmp*dp[i][b];
			}
		}
	}
	string ans = dp[h+w-2][1<<(w-1)].str();
	while(ans.size()<=2*h*w)ans.insert(ans.begin(),'0');
	ans.insert(ans.begin()+1,'.');
	cout<<ans<<endl;

	return 0;
}
