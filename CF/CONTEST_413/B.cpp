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

const int MAXN = 2e5+6.66;
multiset<pii> s[4];
int p [MAXN],a[MAXN],b[MAXN];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
  int n;cin >> n;
  for(int i = 0;i<n;i++) cin >> p[i];
  for(int i = 0;i<n;i++) cin >> a[i];
  for(int i = 0;i<n;i++) cin >> b[i];
  for(int i = 0;i<n;i++) {
    s[a[i]].insert(mp(p[i],b[i]));
    s[b[i]].insert(mp(p[i],a[i]));
  }
  int m;cin >> m;
  for(int i = 0;i<m;i++) {
    int c;cin >> c;
    if(s[c].size()) {
      pii x = *s[c].begin();
      s[c].erase(s[c].begin());
      cout << x.F << " " ;
      s[x.S].erase(s[x.S].find({x.F,c}));
    } else cout << -1 << " ";
  }
  cout << endl;
	return 0;
}
