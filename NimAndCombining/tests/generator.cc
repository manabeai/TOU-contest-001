#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for (long long i=0;i<(ll)n;i++)
#define vout(a) for (long long i=0;i<(ll)a.size()-1;i++){fout<<a[i]<<" ";}fout<<a[a.size()-1]<<endl


//乱数
random_device rnd;// 非決定的な乱数生成器
mt19937_64 mt(rnd());// メルセンヌ・ツイスタの32ビット版、引数は初期シード
#define pmt(mn,mx) (mt()%(mx-mn+1)+mn)

void make(ll num,string name,ll MIN_N,ll MAX_N,ll MIN_A,ll MAX_A){
	rep(t,num){
		ofstream fout("./"+name+to_string(t+1)+".in");//出力する場合の出力先を指定
		
		ll iswin=1;
		if(num>=2)iswin=pmt(0,2);
		
		ll n;
		n=pmt(MIN_N,MAX_N);
		if(!iswin&&n%2==1)n++;
		fout<<n<<endl;

		vector<ll> a(n);
		if(!iswin){
			ll xr=0;
			rep(i,n-1){
				a[i]=pmt(MIN_A,MAX_A);
				xr^=a[i]-1;
			}
			a[n-1]=xr+1;
			if(a[n-1]>MAX_A)a[n-1]=pmt(MIN_A,MAX_A);
		}else{
			rep(i,n){
				a[i]=pmt(MIN_A,MAX_A);
			}
		}
		vout(a);
	}
}


//メイン
int main(){
	make(10,"random1_",1,10,1,16);
	make(50,"random2_",1,400000,1,1000000);
	make(10,"random3_",1,10,1,1000000);
	make(10,"random4_",1,400000,1,32);
	make(1,"hand1_",1,1,1,1);
	make(1,"hand2_",400000,400000,1000000,1000000);
	make(1,"hand3_",399999,399999,999999,999999);
	make(1,"hand4_",2,2,987654,987654);
	make(10,"max1_",399999,399999,1,1000000);
	make(5,"max1_1",400000,400000,1,1000000);
	return 0;
}
