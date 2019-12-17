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

const int MAXN = 100;
string str[MAXN];
int n,m;

void operator+=(pii &x,pii &y) {
  x.F += y.F;
  x.S += y.S;
}

inline bool check(pii x,bool W = 1) {
  return x.F<0 || x.S<0 || x.F >=n || x.S >= m || str[x.F][x.S] =='#' || (W&&str[x.F][x.S] =='E');
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
  cin >> n >> m;
  FOR(i,0,n) cin >> str[i];
  int st_pos_x,st_pos_y;
  int en_pos_x,en_pos_y;
  FOR(i,0,n) FOR(j,0,m) if(str[i][j]=='S') st_pos_x = i,st_pos_y = j;else if(str[i][j]=='E') en_pos_x=i,en_pos_y = j;
  string  dir ;cin >> dir;
  vii arr ={mp(1,0),mp(0,1),mp(-1,0),mp(0,-1)};
  sort(arr.begin(),arr.end());
  int ans = 0;
  do {
    pii now = mp(st_pos_x,st_pos_y);
    for(auto ch : dir) {
      now += arr[ch-'0'];
      if(check(now)) break;
    }
    if(!check(now,0) && str[now.F][now.S] == 'E') ans ++;
  } while(next_permutation(arr.begin(),arr.end()));
  cout << ans << endl;
	return 0;
}
