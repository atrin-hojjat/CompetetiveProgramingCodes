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
typedef vector<piii> viii;
typedef vector<ll> vl;

viii X;
set<pii> S;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
  int n;cin >> n;
  int prv = -1;
  int sz = 0;
  int id = 0;
  FOR(i,0,n) {
    int x;cin >> x;
    if(x==prv) sz++;
    else {
      if(~prv)
        X.pb(mp(prv,mp(++id,sz)));
      sz = 1;
      prv = x;
    }
  }
  X.pb(mp(prv,mp(++id,sz)));
  for(auto x : X)
    S.insert(mp(-x.S.S,x.S.F));
  int steps = 0;
  while(S.size()) {
    pii W = *S.begin();
    S.erase(S.begin());
    X.erase(lower_bound(X.begin(),X.end(),mp(0,mp(W.S,0)),[](piii X,piii Y) {return X.S.F < Y.S.F;}));
    auto ww = upper_bound(X.begin(),X.end(),mp(0,mp(W.S,0)),[](piii X,piii Y) {return X.S.F < Y.S.F;});
    if(ww!=X.end() && ww!=X.begin() && (ww-1)->F==ww->F) {
      auto ZZ = ww-1;
      S.erase(S.find(mp(-ZZ->S.S,ZZ->S.F)));
      S.erase(S.find(mp(-ww->S.S,ww->S.F)));
      ZZ->S.S += ww->F;
      S.insert(mp(-ZZ->S.S,ZZ->S.F));
      X.erase(ww);
    }
    steps++;
  }
  cout << steps << endl;
	return 0;
}
