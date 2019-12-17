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

const int MAXN = 2e3+6.66;
const int INF = 2e9+17;
ll tab[MAXN][MAXN];
ll par[MAXN][MAXN];
int lpos[MAXN];

void init_parsum(int n) {
  F0R(i,1,n) {
    ll l = 0;
    F0R(j,1,n)
      par[i][j] = par[i-1][j] +(l+=tab[i][j]);
  }
}

inline ll get_sum(int x1,int y1,int x2,int y2) {
  return par[x2][y2] - par[x1-1][y2] - par[x2][y1-1] + par[x1-1][y1-1];
}

void bS(int u,int d,int l,int r,int k) {
  if(u>d || l>r) return ;
  ll x = get_sum(u,l,d,r);
  if(x<k) return ;
  if( x<=2*k) {
    cout << l << " " << u << " " << r << " " << d << endl;
    exit(0);
  }
  int u1 = u,u2 = d;
  while(u1<u2) {
    int w = u1+(u2-u1+1)/2;
//    cout << w << " " << u1 << " " << u2 << endl;
    ll z = get_sum(w,l,d,r);
    if(z<k) u2 = w-1;
    else if(z<=2*k) {
      cout << l << " " << w << " " << r << " " << d << endl;
      exit(0);
    } else u1 = w;
  }
  ll z = get_sum(u1,l,d,r);
  if(z>=k && z<=2*k) {
    cout << l << " " << u << " " << r << " " << d << endl;
    exit(0);
  }
  ll s = 0;
  F0R(i,l,r) {
    s+= tab[u1][i];
    if(s>=k) {
      cout << l << " " << u1 << " " << i << " " << u1 << endl;
      exit(0);
    }
  }
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
  int n,k;cin >> k >> n ;
  F0R(i,1,n) F0R(j,1,n) cin >> tab[i][j];
  init_parsum(n);
  fill(tab[n+1],tab[n+1]+n+1,INF);
  F0R(i,1,n) {
    stack<pii> st;
    int mx = 0;
    F0R(j,1,n+1) {
      if(tab[i][j]>=k && tab[i][j]<=2*k) {
        cout << j << " " << i << " " << j << " " << i << endl;
        return 0;
      }
      if(tab[i][j] >2*k) lpos[j] = i;
      if(j==n+1)lpos[j] = i+10;
      while(st.size() && lpos[j]>lpos[st.top().F]) {
        mx = max(mx,st.top().S);
        int x = lpos[st.top().F];st.pop();
        if(st.size()) {
          if(mx>2*k)
            bS(x+1,i,st.top().F+1,j-1,k);
        } else {
          if(mx>2*k)
            bS(x+1,i,1,j-1,k);
        }
      }
      while(st.size() && lpos[j]==lpos[st.top().F]) mx=max(mx,st.top().S),st.pop();
      st.push(mp(j,mx));
      mx = tab[i+1][j];
    }
  }
  cout << "NIE" << endl;
	return 0;
}
