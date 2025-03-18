#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for (long long i=0;i<(ll)n;i++)
#define vout(a) for (long long i=0;i<(ll)a.size()-1;i++){fout<<a[i]<<" ";}fout<<a[a.size()-1]<<endl
#include "testlib.h"


void make(ll num,string name,ll MIN_N,ll MAX_N,ll MIN_AB,ll MAX_AB,ll MIN_C,ll MAX_C,ll MIN_CHOICE_A,ll MAX_CHOICE_A,ll MIN_CHOICE_B,ll MAX_CHOICE_B);


//メイン
int main(int argc, char* argv[]) {
	registerGen(argc, argv, 1);
	make(20,"random",1,200000,0,200000,1,1000000000,1,200000,1,200000);
	make(5,"large",190000,200000,190000,200000,1,1000000000,1,200000,1,200000);
	make(10,"asmall",1,20,0,20,1,20,1,20,1,20);
	make(5,"conner1",190000,200000,100000,200000,1,1000000000,1,1,200000,200000);
	make(5,"conner2",190000,200000,100000,200000,1,1000000000,200000,200000,1,1);
	make(5,"conner3",190000,200000,200000,200000,1,1000000000,1,200000,1,200000);
	make(3,"max",200000,200000,200000,200000,1,1000000000,1,1,1,1);
	return 0;
}

void make(ll num,string name,ll MIN_N,ll MAX_N,ll MIN_AB,ll MAX_AB,ll MIN_C,ll MAX_C,ll MIN_CHOICE_A,ll MAX_CHOICE_A,ll MIN_CHOICE_B,ll MAX_CHOICE_B){
	rep(t,num){
		ofstream fout("./"+name+to_string(t+1)+".in");//出力する場合の出力先を指定
		
		ll n;
		n=rnd.next(MIN_N,MAX_N);
		fout<<n<<endl;
		
		ll sumA=rnd.next(MIN_AB,MAX_AB);
		ll sumB=rnd.next(MIN_AB,MAX_AB);
		if(sumA>sumB)swap(sumA,sumB);

		ll choiceASize = rnd.next(min(n,MIN_CHOICE_A),min(n,MAX_CHOICE_A));
		ll choiceBSize = rnd.next(min(n,MIN_CHOICE_B),min(n,MAX_CHOICE_B));

		vector<ll> choiceA,choiceB;
		rep(i,n)choiceA.push_back(i),choiceB.push_back(i);

		shuffle(choiceA.begin(),choiceA.end());
		shuffle(choiceB.begin(),choiceB.end());

		vector<ll> a(n,0),b(n,0),c(n,0);

		rep(i,sumA)a[choiceA[(int)rnd.next(0LL,choiceASize-1)]]++;
		rep(i,sumB)b[choiceB[(int)rnd.next(0LL,choiceBSize-1)]]++;
		rep(i,n)c[i]=rnd.next(MIN_C,MAX_C);
		vout(a);
		vout(b);
		vout(c);
	}
}

