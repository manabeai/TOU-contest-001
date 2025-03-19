#include<bits/stdc++.h>
#include "testlib.h"
using namespace std;
#define ll long long
#define rep(i,n) for (long long i=0;i<(ll)n;i++)
#define vout(a) for (long long i=0;i<(ll)a.size()-1;i++){fout<<a[i]<<" ";}fout<<a[a.size()-1]<<endl

void make(ll num,string name);
void hand(string name);

//メイン
int main(int argc, char* argv[]){
	registerGen(argc, argv, 1);
	make(50,"random_");
	hand("hand_");
	return 0;
}

void make(ll num,string name){
	rep(t,num){
		ll MIN_XY = 5;
		ll MAX_XY = 999999995;
		ofstream fout("./"+name+to_string(t+1)+".in");//出力する場合の出力先を指定
		ll type = rnd.next(1,3);
		
		if(type==1){
			fout<<1<<endl;
			ll x = rnd.next(MIN_XY,MAX_XY);
			ll y = rnd.next(MIN_XY,MAX_XY);
			ll d = rnd.next(0,3);
			fout<<x<<" "<<y<<" "<<d<<endl;
		}else if(type==2){
			fout<<2<<endl;
			ll a = rnd.next(6,100);
			ll absf = rnd.next(0,4);
			ll signf = rnd.next(0,1);
			if(a-absf<6)absf--;
			if(signf==0)signf=-1;
			ll f=absf*signf;
			ll d = rnd.next(0,3);
			ll p = rnd.next(0,5);
			fout<<a<<" "<<f<<" "<<d<<" "<<p<<endl;
		}else{
			fout<<2<<endl;
			ll a = rnd.next(6,100);
			ll absf = rnd.next(0LL,a-6);
			ll signf = rnd.next(0,1);
			if(a-absf<6)absf--;
			if(signf==0)signf=-1;
			ll f=absf*signf;
			ll d = rnd.next(0,3);
			ll p = rnd.next(0,5);
			fout<<a<<" "<<f<<" "<<d<<" "<<p<<endl;
		}
	}
}

void hand(string name){
	rep(t,16){
		ll MIN_XY = 5;
		ll MAX_XY = 999999995;
		ofstream fout("./"+name+to_string(t+1)+".in");//出力する場合の出力先を指定
		fout<<1<<endl;
		ll x,y;
		if((1LL<<3)&t)x=MAX_XY;
		else x=MIN_XY;
		if((1LL<<2)&t)y=MAX_XY;
		else y=MIN_XY;
		ll d=t%4;
		fout<<x<<" "<<y<<" "<<d<<endl;
	}
}