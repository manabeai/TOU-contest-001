#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for (long long i=0;i<(ll)n;i++)
#include "reactive.hpp"


const ll MAX_XY = 1000000000;
const ll MAX_Q = 5;
vector<ll> dx={1,-1,0,0};
vector<ll> dy={0,0,1,-1};

ll Chebyshev(ll x1,ll y1,ll x2,ll y2){
	return max(abs(x1-x2),abs(y1-y2));
}

int main(int argc, char *argv[]) {
    reactive_start(argv[1]);
	
	ll type;
	cin>>type;

    if(type==1){
		ll x,y,d;
		cin>>x>>y>>d;
		rep(i,MAX_Q){
			string query = reactive_read();
			ll a,b;
			sscanf(query.c_str(), "%lld %lld", &a ,&b);

			if(a<0||MAX_XY<a||b<0||MAX_XY<b){
				cout << "WA" << endl;
				reactive_end();
				return 0;
			}
			
			x+=dx[d],y+=dy[d];
			ll res = Chebyshev(x,y,a,b);
			
			reactive_write(to_string(res));

			if(res==0){
				reactive_write("-1");
				cout<<"AC"<<endl;
				reactive_end();
				return 0;
			}
		}
		reactive_write("-1");
		cout << "WA" << endl;
		reactive_end();
		return 0;
	}else{
		
	}
    return 0;
}