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
	make(1,"001sample_",4,4);
	make(30,"random_",14,996);
	make(1,"002hand1_",1,1);
	make(1,"hand2_",2,2);
	make(1,"hand3_",3,3);
	make(1,"hand4_",5,5);
	make(1,"hand5_",6,6);
	make(1,"hand6_",7,7);
	make(1,"hand7_",8,8);
	make(1,"hand8_",9,9);
	make(1,"hand9_",10,10);
	make(1,"hand10_",11,11);
	make(1,"hand11_",12,12);
	make(1,"hand12_",13,13);
	make(1,"hand13_",997,997);
	make(1,"hand14_",998,998);
	make(1,"hand15_",999,999);
	make(1,"hand16_",1000,1000);
	make(1,"hand17_",17,17);
	make(1,"hand18_",19,19);
	make(1,"hand19_",23,23);
	
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
