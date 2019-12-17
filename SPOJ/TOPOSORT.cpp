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

const int MAXN = 1e4 + 6.66;
const int MAXM = 1e6 + 6.66;
vi g[MAXN];
int d[MAXN];
bool mark[MAXN];
int ans[MAXN];

int main() {
	ios::sync_with_stdio(false);
//	cin.tie(NULL);cout.tie(NULL);
  int n,m;
  scanf("%d %d",&n,&m);
//  cin >> n >> m;
  F0R(i,1,m) {
//    int x,y;cin >> x >> y;
    int x,y;
    scanf("%d %d",&x,&y);
    d[y]++;
    g[x].pb(y);
  }
  set<pii> s;
  int* pt = ans;
  F0R(i,1,n) if(!d[i]) s.insert(mp(d[i],i));
  while(s.size()) {
    if(s.begin()->F!=0) break;
    int x = s.begin()->S;
    s.erase(s.begin());
    for(auto w : g[x]) if(!--d[w]) s.insert(mp(d[w],w));
    *pt = x;
    ++pt;
  }
  if(pt-ans!=n)printf("Sandro fails.");
  else 
    FOR(i,0,n) printf("%d ",ans[i]);
  printf("\n");
	return 0;
}
