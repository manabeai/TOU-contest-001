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

//メイン
int main(){
	ll n;
	cin>>n;
	vl a(n),b(n),c(n);
	rep(i,n)cin>>a[i];
	rep(i,n)cin>>b[i];
	rep(i,n)cin>>c[i];
	
	ll ans=0;
	rep(i,1LL<<min(n,60LL)){
		ll sc=0,sum=0;
		bool f=false;
		
		rep(j,n){
			if(i&(1LL<<j)){
				sum+=a[j]-b[j];
				sc+=c[j];
			}else{
				if(sum<0){
					f=true;
					break;
				}
				sum=0;
			}
		}
		if(sum<0)f=true;
		if(f)continue;

		ans=max(ans,sc);
	}
	cout<<ans<<endl;
}
