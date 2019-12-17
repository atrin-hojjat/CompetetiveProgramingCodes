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
ll h[MAXN];
pii BIT1[MAXN*3];
pii BIT2[MAXN*3];
int prv[MAXN];
map<ll,int> cmp;
int X;

void add(int x,pii val) {
  int w = cmp.size()-x+1;
  while(x<MAXN*3)
    BIT1[x]=max(BIT1[x],val),x+=x&-x;
  while(w<MAXN*3)
    BIT2[w] = max(BIT2[w],val),w+=w&-w;
}

pii get1(int x) {
  pii ans = mp(0,0);
  while(x)
    ans = max(BIT1[x],ans),x^=x&-x;
  return ans;
}

pii get2(int x) {
  x = cmp.size()-x+1;
  pii ans = mp(0,0);
  while(x)
    ans = max(BIT2[x],ans),x^=x&-x;
  return ans;
}

void compress(int n,ll d) {
  F0R(i,1,n) cmp[h[i]] = cmp[max(h[i]-d,0LL)] = cmp[h[i]+d] = 0;
  int i = 0;
  for(auto&x : cmp) x.S = ++i;
  X = cmp.size()+3;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
  int n;
  ll d;
  cin >> n >> d;
  F0R(i,1,n) cin >> h[i];
  compress(n,d);
  F0R(i,1,n) {
    pii ans = max(get1(cmp[max(h[i]-d,0LL)]),get2(cmp[h[i]+d]));
    prv[i] = ans.S;
    add(cmp[h[i]],mp(ans.F+1,i));
  }
  cout << get2(1).F << endl;
  int x = get2(1).S;
  stack<int> s;
  while(x) {s.push(x);x = prv[x];}
  while(s.size()) {cout << s.top() << " ";s.pop();}
  cout << endl;
	return 0;
}
