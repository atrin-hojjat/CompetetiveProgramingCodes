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
typedef pair<pii,pii> piiii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<ll> vl;

const int MAXN = 100+10+1;
char ed[MAXN][MAXN];
bool ans[MAXN][MAXN][2][26];
int arr[MAXN];

struct pos{ 
  int a,b,t,x;

  bool operator< (pos w) const {
    return a+b > w.a + w.b;
  }
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
  int n,m;cin >> n >> m;
  for(int i = 1;i<=n;i++) arr[i] = i;
  for(int i = 0;i<m;i++) {
    int x,y;cin >> x >> y;
    cin >> ed[x][y];
  }
  sort(arr+1,arr+n+1,[](int i,int j) { return (ed[i][j]) ; } );
  for(int i = 1;i<=n;i++) cout << arr[i] << " " ;cout << endl;
  multiset<pos> ss;
  for(int i = 1;i<=n;i++)
    for(int j = 1;j<=n;j++) { 
      for(int x = 0;x<26;x++) {
        ss.insert({i,j,0,x});
        ss.insert({i,j,1,x});
      }
    }
  for(auto u : ss) {
    int A = u.a,B = u.b;
    u.a = arr[u.a],u.b = arr[u.b];
    if(u.t == 0) {
      bool x = false;
      for(int j = A+1;j<=n;j++) {
        int i = arr[j];
        if(ed[u.a][i] && ed[u.a][i]-'a' >= u.x) {
          cout << i << " " ;
          x |= ans[i][u.b][1][ed[u.a][i]-'a'];
        }
      }
      ans[u.a][u.b][0][u.x] = x;
    } else {
      bool x = true;
      for(int j = B+1;j<=n;j++) {
        int i = arr[j];
        if(ed[u.b][i] && ed[u.b][i]-'a' >= u.x) {
          cout<< i << " ";
          x &= ans[u.a][i][0][ed[u.b][i]-'a'];
        }
      }
      ans[u.a][u.b][1][u.x] = x;
    }
    cout << u.a << " " << u.b << " " << u.x << " " << u.t << " " << ans[u.a][u.b][u.t][u.x]<< endl;
  }
  for(int i = 1;i<=n;i++,cout << endl) 
    for(int j = 1;j<=n;j++)
      cout << (ans[i][j][0][0] ? "A" : "B") ;
	return 0;
}
