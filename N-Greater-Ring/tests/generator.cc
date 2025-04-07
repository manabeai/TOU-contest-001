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
	make(1,"001sample_",5,5);
	make(1,"002sample2_",1,1);
	make(1,"003sample3_",20250426,20250426);
	make(40,"random_",1,1000000000);
	make(1,"Hand_",998244353,998244353);
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