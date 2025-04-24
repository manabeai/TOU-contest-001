#include <bits/stdc++.h>

#include "testlib.h"
using namespace std;
#define rep(i,n) for (int i=0;i<n;i++)
#define loop(i,m,n) for(int i=m;i<=n;i++)
#define vi vector<int>
#define vvi vector<vector<int>>

vi dx={1,1,1,0};
vi dy={-1,0,1,1};

int main(int argc, char** argv)
{
    registerTestlibCmd(argc, argv);
    int n = inf.readInt();

	if(n==1){
		string ans=ouf.readToken("[A-Za-z]+", "s");
		if(ans=="No")quitf(_ok, "ok");
		else quitf(_wa, "This tastcase is not buildable");
	}else{
		string ans=ouf.readToken("[A-Za-z]+", "s");
		if(ans!="Yes")quitf(_wa, "This tastcase is buildable");
	}
	int mx=1;
    vvi a(n,vi(n));
    rep(i,n)rep(j,n){
		a[i][j] = ouf.readInt(),mx=max(mx,a[i][j]);
		if(a[i][j]<=0)quitf(_wa,"a_i_j is not positive integer");
	}
	if(n==2){
		if(mx!=4)quitf(_wa,"max(a_i_j) is incorrect");
	}else {
		if(mx!=3)quitf(_wa,"max(a_i_j) is incorrect");
	}

	
	rep(i,n)rep(j,n){
		rep(d,4){
			bool f=true;
			loop(k,1,a[i][j]){
				if(a[i][j]!=a[(i+dx[d]*k)%n][(j+dy[d]*k+n*k)%n]){
					f=false;
					break;
				}
			}
			if(f)quitf(_wa,"numbers not requirement");
		}
	}
    quitf(_ok, "ok");

    return 0;
}