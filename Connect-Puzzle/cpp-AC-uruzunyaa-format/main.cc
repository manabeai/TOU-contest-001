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
//メイン
int main(){
	ll n;
	cin>>n;
	vvl ans(n,vl(n));
	if(n<=3){
		if(n==1)cout<<"No "<<endl;
		if(n==2){
			cout<<"Yes "<<endl;
			cout<<"1 2"<<endl;
			cout<<"3 4"<<endl;
		}
		if(n==3){
			cout<<"Yes "<<endl;
			cout<<"2 2 3"<<endl;
			cout<<"2 2 3"<<endl;
			cout<<"3 3 1"<<endl;
		}
		return 0;
	}

	vl a={3,3,2,2};
	
	vl tmp;
	rep(i,n-1)tmp.push_back(a[i%4]);

	if(n%4==2){
		tmp.pop_back();
		tmp.push_back(1);
		tmp.push_back(3);
	}else{
		tmp.push_back(1);
	}
	
	if(n==7)tmp={3,3,3,2,3,2,1};

	rep(i,n)rep(j,n)ans[i][(j+i*2)%n]=tmp[j];
	
	cout<<"Yes "<<endl;
	vvdbg(ans);
	return 0;
}
