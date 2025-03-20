#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for (long long i=0;i<(ll)n;i++)
#define loop(i,m,n) for(long long i=m;i<=(ll)n;i++)
#define vl vector<long long>
#define vvl vector<vector<long long>>
#define inf 1000000000

vl dx={1,-1,0,0};
vl dy={0,0,1,-1};

ll Chebyshev(ll x1,ll y1,ll x2,ll y2){
	return max(abs(x1-x2),abs(y1-y2));
}

//メイン
int main(){
	cout<<"0 0"<<endl;
	ll a,b,c,d,x,y;
	cin>>a;
	cout<<inf<<" "<<inf<<endl;
	cin>>b;
	b=inf-b;
	
	vvl ans;
	//{x座標,y座標,方向}
	rep(i,4)ans.push_back({a+dx[i],b,i});
	rep(i,4)ans.push_back({b,a+dy[i],i});

	rep(i,ans.size()){
		ans[i][0]+=dx[ans[i][2]];
		ans[i][1]+=dy[ans[i][2]];
	}
	x=b;
	y=a+2;
	cout<<x<<" "<<y<<endl;
	cin>>c;
	if(c==0)return 0;
	for(ll i=ans.size()-1;i>=0;i--){
		if(Chebyshev(x,y,ans[i][0],ans[i][1])!=c){
			ans.erase(ans.begin()+i);
		}
	}

	rep(i,ans.size()){
		ans[i][0]+=dx[ans[i][2]];
		ans[i][1]+=dy[ans[i][2]];
	}
	sort(ans.begin(),ans.end());
	x=ans[0][0];
	y=ans[0][1];
	cout<<x<<" "<<y<<endl;
	cin>>d;
	if(d==0)return 0;
	for(ll i=ans.size()-1;i>=0;i--){
		if(Chebyshev(x,y,ans[i][0],ans[i][1])!=d){
			ans.erase(ans.begin()+i);
		}
	}

	x=ans[0][0]+dx[ans[0][2]];
	y=ans[0][1]+dy[ans[0][2]];
	cout<<x<<" "<<y<<endl;
	return 0;
}
