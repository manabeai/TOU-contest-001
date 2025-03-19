#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for (long long i=0;i<(ll)n;i++)
#define loop(i,m,n) for(long long i=m;i<=(ll)n;i++)
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
				reactive_write("-1\n");
				cout << "WA" << endl;
				reactive_end();
				return 0;
			}
			
			x+=dx[d],y+=dy[d];
			ll res = Chebyshev(x,y,a,b);
			
			reactive_write(to_string(res) + "\n");

			if(res==0){
				cout<<"AC"<<endl;
				reactive_end();
				return 0;
			}
		}
		string query = reactive_read();
		reactive_write("-1\n");
		cout << "WA" << endl;
		
	}else{
		ll a,f,d,p;
		cin>>a>>f>>d>>p;

		ll x,y;
		string query = reactive_read();
		sscanf(query.c_str(), "%lld %lld", &x ,&y);

		if(5<=x&&x<=MAX_XY-5&&5<=y&&y<=MAX_XY-5){
			if(p==0){
				reactive_write("0\n");
				cout<<"AC"<<endl;
				reactive_end();
				return 0;
			}
			p--;
		}

		reactive_write(to_string(a)+ "\n");
		//距離Aとなるような、初期解の候補を全列挙
		set<vector<ll>> fans;

		ll souteix,souteiy,souteid=d;

		//向いている方向を全探索
		rep(i,4){
			//小さい方の距離を全探索
			loop(smalldiff,0,a){
				//x軸方向の差の向きの全探索
				loop(signx,-1,1){
					if(signx==0)continue;
					//y軸方向の差の向きの全探索
					loop(signy,-1,1){
						if(signy==0)continue;
						//大きい方がXの時
						ll firstx = x + (a * signx) - dx[i];
						ll firsty = y + (smalldiff * signy) - dy[i];
						if(5<=firstx&&firstx<=MAX_XY-5&&5<=firsty&&firsty<=MAX_XY-5){
							fans.insert({firstx,firsty,i});
							if(i==d&&a-smalldiff==f){
								souteix=firstx;
								souteiy=firsty;
							}
						}
						//大きい方がYの時
						firstx = x + (smalldiff * signx) - dx[i];
						firsty = y + (a * signy) - dy[i];
						if(5<=firstx&&firstx<=MAX_XY-5&&5<=firsty&&firsty<=MAX_XY-5){
							fans.insert({firstx,firsty,i});
							if(i==d&&a-smalldiff==-f){
								souteix=firstx;
								souteiy=firsty;
							}
						}
					}
				}
			}
		}
		//2回目以降のクエリ
		for(ll i=2;i<=MAX_Q;i++){
			query = reactive_read();
			sscanf(query.c_str(), "%lld %lld", &x ,&y);
			
			if(x<0||MAX_XY<x||y<0||MAX_XY<y){
				reactive_write("-1\n");
				cout << "WA" << endl;
				reactive_end();
				return 0;
			}
			
			//答えの物があるのなら
			bool flag =false;
			for(const auto & val:fans){
				if(val[0]+dx[val[2]]*i == x && val[1]+dy[val[2]]*i == y){
					flag=true;
					break;
				}
			}
			if(flag){
				//正解にしたい場合、もしくは1通りになっている場合
				if(p==0||fans.size()==1){
					reactive_write("0\n");
					cout<<"AC"<<endl;
					reactive_end();
					return 0;
				}

				//正解にしたくないが、想定に正解している場合
				if(souteix+dx[souteid]*i == x && souteiy+dy[souteid]*i == y){
					bool flag2=true;
					for(const auto & val:fans){
						if(val[0]+dx[val[2]]*i != x || val[1]+dy[val[2]]*i != y){
							souteix = val[0];
							souteiy = val[1];
							souteid = val[2];
							flag2=false;
							break;
						}
					}
					//実はどの例も正解だった場合
					if(flag2){
						reactive_write("0\n");
						cout<<"AC"<<endl;
						reactive_end();
						return 0;
					}
				}
				p--;
			}

			ll res = Chebyshev(x,y,souteix + dx[souteid] * i,souteiy + dy[souteid] * i);
			reactive_write(to_string(res)+ "\n");
			

			//矛盾する例を消去
			set<vector<ll>> nextfans;
			for(const auto & val:fans){
				if(Chebyshev(val[0]+dx[val[2]]*i,val[1]+dy[val[2]]*i, x,y)==res){
					nextfans.insert(val);
				}
			}
			fans=nextfans;
		}

		query = reactive_read();
		reactive_write("-1\n");
	}
	reactive_end();
    return 0;
}