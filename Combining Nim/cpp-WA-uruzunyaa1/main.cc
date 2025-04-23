#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for (long long i=0;i<(ll)n;i++)
#define loop(i,m,n) for(long long i=m;i<=(ll)n;i++)
#define vl vector<long long>
#define vvl vector<vector<long long>>
#define vdbg(a) rep(ii,a.size()){cout<<a[ii]<<" ";}cout<<endl;
#define vvdbg(a) rep(ii,a.size()){rep(jj,a[ii].size()){cout<<a[ii][jj]<<" ";}cout<<endl;}
#define setdbg(a) for(const auto & ii:a){cout<<ii<<" ";}cout<<endl;
#define ppdbg(a) cout<<"{"<<a.first.first<<":"<<a.first.second<<"}   {"<<a.second.first<<":"<<a.second.second<<"}"<<endl
#define inf 1000000000
#define ppl pair<pair<ll,ll>,pair<ll,ll>>

//勝敗判定の方法
//奇数山の時、先手必勝。
//偶数山の時、最後の石一つを残した通常のNimに帰着される。

/*
{{bestのindex,bestの値},{second_bestのindex,second_bestの値}}
を2つ受け取り同じindexの重複を除いた上で、計算。
*/
ppl e={{inf,0},{inf,0}};

ppl op(ppl x,ppl y){
	ppl ans=e;
	if(ans.first.second<x.first.second)ans.first=x.first;
	if(ans.first.second<y.first.second)ans.first=y.first;

	if(ans.second.second<x.first.second&&ans.first.first!=x.first.first)ans.second=x.first;
	if(ans.second.second<x.second.second&&ans.first.first!=x.second.first)ans.second=x.second;
	if(ans.second.second<y.first.second&&ans.first.first!=y.first.first)ans.second=y.first;
	if(ans.second.second<y.second.second&&ans.first.first!=y.second.first)ans.second=y.second;
	
	return ans;
}

//メイン
int main(){
	ll n;
	cin>>n;
	vl a(n);
	ll sum=0;
	ll xr=0;
	rep(i,n){
		cin>>a[i];
		sum+=a[i];
		a[i]--;
		xr^=a[i];
	}

	//後手必勝の場合
	if(n%2==0&&xr==0){
		cout<<"Uruzunyaa"<<endl;
		cout<<sum<<endl;
		return 0;
	}

	//先手必勝の場合(偶数山)
	if(n%2==0){
		//最初の一手で取れる最大数を計算する
		ll mx=0;
		rep(i,n)mx=max(mx,a[i]-(xr^a[i]));
		cout<<"Talc"<<endl;
		cout<<sum-mx+1<<endl;
		return 0;
	}

	//先手必勝の場合(奇数山)

	//A_iのビット数の最大値、本番は20にする。デバッグ用
	ll m=21;

	//bitをpopcount毎に分類しておく。
	vector<vvl> bit(m);
	rep(i,m){
		bit[i]=vvl(i+1);
		rep(j,1<<i){
			bit[i][__popcount(j)].push_back(j);
		}
	}

	//subdp[i][j]=以下の条件をみたす、aの要素のindexのリスト（ただし2つ以上は保管しない）
	//i番目のbitが0であって、jのスーパーセットである。
	vector<vvl> subdp(m);

	//dp[i][j]=i番目のbitが0で、jのsubsetの中での{{bestのindex,bestの値},{second_bestのindex,second_bestの値}}
	vector<vector<ppl>> dp(m);

	rep(i,m){
		//0と仮定したbitより上位のbitは要らない
		subdp[i]=vvl(1<<i);
		rep(j,n)if((a[j]&(1<<i))==0&&subdp[i][a[j]&((1<<i)-1)].size()<2)subdp[i][a[j]&((1<<i)-1)].push_back(j);
		//bit数が多いものから小さいものに向かって記録する。
		for(ll j=i;j>0;j--){
			//jはpopcount
			rep(k,bit[i][j].size()){
				//1を減らす場所をi通り列挙
				rep(l,i){
					//subsetに対して記録
					if(bit[i][j][k]&(1<<l)){
						rep(h,subdp[i][bit[i][j][k]].size()){
							if(subdp[i][bit[i][j][k]-(1<<l)].size()>=2)break;
							else if(subdp[i][bit[i][j][k]-(1<<l)].size()==1&&subdp[i][bit[i][j][k]-(1<<l)][0]==subdp[i][bit[i][j][k]][h])continue;
							subdp[i][bit[i][j][k]-(1<<l)].push_back(subdp[i][bit[i][j][k]][h]);
						}
					}
				}
			}
		}
		//cout<<"i="<<i<<endl;
		//vvdbg(subdp[i]);

		//0の値を単位元としても、最適性を損なわない(はず)
		dp[i]=vector<ppl>(1<<i,e);

		//subdpの結果を投入
		rep(j,1<<i){
			if(subdp[i][j].size()>=1)dp[i][j].first={subdp[i][j][0],j};
			if(subdp[i][j].size()==2)dp[i][j].second={subdp[i][j][1],j};
		}
		
		for(ll j=0;j<i;j++){
			//jはpopcount
			rep(k,bit[i][j].size()){
				//1を増やす場所をi通り列挙
				rep(l,i){
					//supersetに対して記録
					if(!(bit[i][j][k]&(1<<l))){
						dp[i][bit[i][j][k]+(1<<l)]=op(dp[i][bit[i][j][k]+(1<<l)],dp[i][bit[i][j][k]]);
					}
				}
			}
		}
		//cout<<"i="<<i<<endl;
		//rep(j,1<<i)ppdbg(dp[i][j]);
	}

	//最初の一手で取れる最大数(ただし、山を消し去るのに取る最後の1個は計算に入れない)
	ll mx=0;

	//それぞれの山について、最適な相方を見つける。
	//bestが自分自身の場合、second_bestを参照する。
	rep(i,n){
		xr^=a[i];
		if(xr==0){
			xr^=a[i];
			mx=max(mx,a[i]);
			continue;
		}
		
		//最上位の1となっているbit
		ll top=0;
		for(ll j=m-1;j>=0;j--){
			if(xr&(1<<j)){
				top=j;
				break;
			}
		}

		//最適な相方の関係ある部分のbit列を取り出す
		ll companion;
		if(dp[m-1][xr-(1<<top)].first.first!=i)companion=dp[m-1][xr-(1<<top)].first.second;
		else companion=dp[m-1][xr-(1<<top)].second.second;

		//1が立っているbitは取る事で減り、立っていないbitは増やすため、全体とのxorを引く
		mx=max(mx,a[i]+companion-(xr^companion));
		
		xr^=a[i];
	}
	
	//奇数の時は先手必勝
	cout<<"Talc"<<endl;

	//山減少分は元々取るはずだった1個としてカウントしてないため、そのまま引けばOK
	cout<<sum-mx<<endl;
	return 0;
}
