#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for (long long i=0;i<(ll)n;i++)
#define vout(a) for (long long i=0;i<(ll)a.size()-1;i++){fout<<a[i]<<" ";}fout<<a[a.size()-1]<<endl
#include "testlib.h"


void make(ll num,string name,ll MIN_N,ll MAX_N,ll MIN_A,ll MAX_A);
void hackbig(ll num,string name);

//メイン
int main(int argc, char* argv[]) {
	registerGen(argc, argv, 1);
	make(10,"50random1_",1,10,1,16);
	make(30,"50random2_",1,400000,1,1000000);
	make(10,"50random3_",1,10,1,1000000);
	make(10,"50random4_",1,400000,1,32);
	make(1,"50hand1_",1,1,1,1);
	make(1,"50hand2_",400000,400000,1000000,1000000);
	make(1,"50hand3_",399999,399999,999999,999999);
	make(1,"50hand4_",2,2,987654,987654);
	make(1,"50hand5_",1,1,1,1000000);
	make(10,"50max1_",399999,399999,1,1000000);
	make(5,"50max1_1",400000,400000,1,1000000);
	hackbig(3,"99HackBig");
	return 0;
}

void make(ll num,string name,ll MIN_N,ll MAX_N,ll MIN_A,ll MAX_A){
	rep(t,num){
		ofstream fout("./"+name+to_string(t+1)+".in");//出力する場合の出力先を指定
		
		ll iswin=1;
		if(num>=2)iswin=rnd.next(0,2);
		
		ll n;
		n=rnd.next(MIN_N,MAX_N);
		if(!iswin&&n%2==1)n++;
		fout<<n<<endl;

		vector<ll> a(n);
		if(!iswin){
			ll xr=0;
			rep(i,n-1){
				a[i]=rnd.next(MIN_A,MAX_A);
				xr^=a[i]-1;
			}
			a[n-1]=xr+1;
			if(a[n-1]>MAX_A)a[n-1]=rnd.next(MIN_A,MAX_A);
		}else{
			rep(i,n){
				a[i]=rnd.next(MIN_A,MAX_A);
			}
		}
		vout(a);
	}
}

void hackbig(ll num,string name){
	rep(t,num){
		ofstream fout("./"+name+to_string(t+1)+".in");//出力する場合の出力先を指定
		
		ll n=399999;
		fout<<n<<endl;

		vector<ll> a(n);
		ll index1 = rnd.next(0LL,n-1);
		ll index2 = rnd.next(0LL,n-1);
		while(index1==index2)index2 = rnd.next(0LL,n-1);
		rep(i,n){
			a[i]=rnd.next(1,(1<<17));
		}

		a[index1]+=(1LL<<19)+(1LL<<17);
		a[index2]+=(1LL<<18)+(1LL<<17);
		
		vout(a);
	}
}