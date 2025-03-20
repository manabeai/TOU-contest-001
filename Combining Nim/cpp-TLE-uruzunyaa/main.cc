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
#define inf 1000000000

//メイン
int main(){
	ll n;
	cin>>n;
	vl a(n);
	ll sum=0;
	ll xr=0;
	rep(i,n){
		cin>>a[i];
		sum+=a[i];
		a[i]--;
		xr^=a[i];
	}

	//後手必勝の場合
	if(n%2==0&&xr==0){
		cout<<"Chappo"<<endl;
		cout<<sum<<endl;
		return 0;
	}

	//先手必勝の場合(偶数山)
	if(n%2==0){
		//最初の一手で取れる最大数を計算する
		ll mx=0;
		rep(i,n)mx=max(mx,a[i]-(xr^a[i]));
		cout<<"Talk"<<endl;
		cout<<sum-mx+1<<endl;
		return 0;
	}

	//先手必勝の場合(奇数山)

	ll mx=0;
	
	rep(i,n){
		if(a[i]==xr)mx=max(mx,a[i]+1);
		rep(j,i){
			if(min(a[i],a[j])<=(xr^a[i]^a[j])){
				mx=max(mx,a[i]+a[j]+1-(xr^a[i]^a[j]));
			}
		}
	}
	
	cout<<"Talk"<<endl;
	cout<<sum-mx+1<<endl;
	return 0;
}
