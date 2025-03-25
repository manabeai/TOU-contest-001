#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 998244353
ll power_mod(ll n, ll k){
	long long result = 1;
	while (k > 0){
		if ((k&1) ==1)result=(result*n)%mod;
		n=n*n%mod;
		k >>= 1;
	}
	return result;
}
int main(){
	int n;
	cin>>n;
	ll ans=n*power_mod(2,(n-1)/2);
  	ans%=mod;
  	cout<<ans<<endl;
}