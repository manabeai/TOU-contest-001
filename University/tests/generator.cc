#include<bits/stdc++.h>
#include "testlib.h"
using namespace std;
#define ll long long
#define rep(i,n) for (long long i=0;i<(ll)n;i++)
#define vout(a) for (long long i=0;i<(ll)a.size()-1;i++){fout<<a[i]<<" ";}fout<<a[a.size()-1]<<endl

void make(ll num,string name,ll MIN_N,ll MAX_N);

//メイン
int main(int argc, char* argv[]){
	registerGen(argc, argv, 1);
	make(1,"sample_",2000,2000);
	make(1,"sample2_",2022,2022);
	make(20,"random_",2000,3000);
	return 0;
}

void make(ll num,string name,ll MIN_N,ll MAX_N){
	rep(t,num){
		ofstream fout("./"+name+to_string(t+1)+".in");//出力する場合の出力先を指定
		ll n;
		n=rnd.next(MIN_N,MAX_N);
		fout<<n<<endl;
	}
}