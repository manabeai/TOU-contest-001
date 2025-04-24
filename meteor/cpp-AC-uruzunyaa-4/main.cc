
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for (long long i=0;i<(ll)n;i++)
#define loop(i,m,n) for(long long i=m;i<=(ll)n;i++)
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
	vector<vector<double>> a(h,vector<double>(w));
	rep(i,h)rep(j,w)cin>>a[i][j],a[i][j]/=100.0;
	
	vector<vector<double>> dp(h+w-1,vector<double>(1<<w,0));
	dp[0][1] = 1.0-a[0][0];
	
	rep(i,h+w-2){
		rep(b,1LL<<w){
			//次,行ける可能性のある場所のリスト
			ll bbit=b|(b<<1);
			bbit &= (1LL<<w)-1;
			
			//次の場所の確率を計算
			rep(c,1<<w){
				//範囲外の場所を行ける場所としていたらcontinue
				bool f=false;
				rep(j,w)if(c&(1LL<<j))if(i+1-j>=h||i+1-j<0)f=true;
				if(f)continue;
				ll cbit= bbit&c;

				double tmp=1;

				loop(j,max(i+2-h,0LL),min(i+1,w-1)){
					if(c&(1LL<<j))tmp*=1.0-a[i+1-j][j];
					else tmp*=a[i+1-j][j];
				}

				dp[i+1][cbit]+=tmp*dp[i][b];
			}
		}
	}
	cout<<fixed<<setprecision(15)<<dp[h+w-2][1LL<<(w-1)]<<endl;

	return 0;
}
