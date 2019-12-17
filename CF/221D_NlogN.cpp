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

const int MAXN = 1e5+6.66;
const int SQRT = 450;
int  arr[MAXN];
vii ques[MAXN];
int  ans[MAXN];
deque<int> d[MAXN];
int last[MAXN];

struct BIT {
  int *bit;

  BIT() { bit = new int[MAXN+1](); }

  void add(int x,int val) {
    while(x<=MAXN)
      bit[x] += val,x+=x&-x;
  }

  int get(int x) {
    int ans = 0;
    while(x) 
      ans += bit[x],x^=x&-x;
    return ans;
  }
} S;

void add(int i) {
  if(arr[i]>=MAXN) return ;
  d[arr[i]].pb(i);
  if(d[arr[i]].size() == arr[i]) {
    S.add(d[arr[i]].front(),1);
  } else if(d[arr[i]].size() > arr[i]) {
    int p = d[arr[i]].front();d[arr[i]].pop_front();
    while(d[arr[i]].size() > arr[i]) p = d[arr[i]].front(),d[arr[i]].pop_front();
    if(last[arr[i]]) S.add(last[arr[i]],1);
    S.add(p,-2);
    last[arr[i]] = p;
    S.add(d[arr[i]].front(),1);
  }
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
  int n,m;cin >> n >> m;
  F0R(i,1,n)cin >> arr[i];
  FOR(i,0,m) {
    int x,y; cin >> x >> y;
    ques[y].pb(mp(x,i));
  }
  F0R(i,1,n) {
    add(i);
    for(auto x : ques[i]) 
      ans[x.S] = S.get(MAXN) - S.get(x.F-1);
  }
  FOR(i,0,m) cout << ans[i] << endl;
	return 0;
}
