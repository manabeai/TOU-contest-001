#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for (long long i=0;i<(ll)n;i++)
#define loop(i,m,n) for(long long i=m;i<=(ll)n;i++)

//メイン
int main(){
	ll h,w;
	cin>>h>>w;
	vector<vector<double>> a(h,vector<double>(w+h-1,1.0));
	rep(i,h)rep(j,w){
		ll aa;
		cin>>aa;
		a[i][j]=(double)aa/100.00;
	}
	vector<vector<double>> dp(h+w-1,vector<double>(1LL<<h,0));
	dp[0][1]=1.0-a[0][0];
	rep(i,h+w-2){
		rep(j,1LL<<h){
			//次の列として、あり得る最大、1を建てた例を作る
			ll bit=(j|(j<<1LL));
			bit &= (1LL<<(h+1))-1;
			ll tmp=bit;
			while(1){
				double kakuritu=1;
				rep(k,min(h,i+2)){
					if(!(bit&(1LL<<k)))continue;
					if(tmp&(1LL<<k))kakuritu *= 1.0-a[k][i+1-k];
					else kakuritu *= a[k][i+1-k];
				}
				dp[i+1][tmp]+=kakuritu*dp[i][j];
				if(tmp==0)break;
				tmp = (bit&(tmp-1));
			}
		}
	}

	cout<<fixed<<setprecision(15)<<dp[h+w-2][1LL<<(h-1)]<<endl;
	return 0;
}
