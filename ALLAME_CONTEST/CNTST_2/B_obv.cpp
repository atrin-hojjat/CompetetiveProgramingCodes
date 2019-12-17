#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <math.h>
#include <stack>
#include <deque>

#define mp                  make_pair
#define F                   first
#define S                   second
#define pb                  push_back
#define FOR(i,j,n)          for(int i=j;i<n;i++)
#define F0R(i,j,n)          for(int i=j;i<=n;i++)
#define RFOR(i,j,n)         for(int i=n-1;i>=j;i--)
#define RF0R(i,j,n)         for(int i=n;i>=j;i--)
#define FOREACH(x,v)        for(auto x:v)
#define ITFOR(it,v)         for(__typeof(v.begin()) it =v.begin();it!=v.end();++it)
#define __in_arr__(a,j,n)   FOR(i,j,n)cin >> a[i];
#define __out_arr__(a,j,n)  FOR(i,j,n)cout << a[i];
#define LOG                 cout << "[ !" << __LINE__ << "L ] " << endl;
#define PLOG(x)             cout << "[ !" << __LINE__ << "L ] " <<x<<endl;

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
typedef pair<int,pii> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<ll> vl;

const int MAXN = 5e2+6.66;
const ll  MOD  = 1e9+7;
map<string,ll> m1[MAXN];
map<string,ll> m2[MAXN];
char ch[MAXN][MAXN];
  int n;

void dfs1(int x,int y,string str) {
  if(x+y ==n+1) m1[x][str] ++,m1[x][str]%=MOD;;
  str+= ch[x][y];
  if(x<n) dfs1(x+1,y, str);
  if(y<n) dfs1(x,y+1,str);
}
void dfs2(int x,int y,string str) {
  if(x+y ==n+1)
    m2[x][str] ++,m2[x][str]%=MOD;;
  str+= ch[x][y];
  if(x>1) dfs2(x-1,y, str);
  if(y>1) dfs2(x,y-1,str);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
  cin >> n ;
  F0R(i,1,n)F0R(j,1,n) cin >> ch[i][j];
  dfs1(1,1,"");
  dfs2(n,n,"");
  ll ans = 0;
  F0R(i,1,n){
    for(auto x : m1[i])
      ans = (ans + x.S * m2[n-i+1][x.F]%MOD)%MOD;
  }
  cout << ans << endl;
	return 0;
}
