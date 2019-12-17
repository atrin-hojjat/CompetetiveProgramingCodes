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

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
  int n;cin >> n;
  ll R = -1,G = -1,B = -1;
  ll mxR = 0,mxB = 0;
  ll ans = 0;
  ll mndis = 1e9+7;
  int CNTG = 0;
  FOR(i,0,n) {
    ll x;char ch;
    cin >> x >> ch;
    switch(ch) {
      case 'G':
        ans += (~R ? x-R : 0) + (~B ? x-B : 0);
        if(~B) mxB = max(mxB,x-B);
        if(~R) mxR = max(mxR,x-R);
        if(~G && ~B && ~R)
          ans += min(0LL,-mxR - mxB + x-G);
        else if(~G)
            ans += -mxR - mxB + x-G;
        mxR = mxB = 0;
        R = B = -1;
        G = x;
        CNTG++;
        break;
#define CASE(X) \
        ans += (~X?x-X:(~G?x-G:0));\
        mx##X = max(mx##X,(~X?x-X:(~G?x-G:0)));\
        X = x;\
        break;
      case 'B':
        if(~R) mndis = min(mndis,x-R);
        CASE(B);
      case 'R':
        if(~B) mndis = min(mndis,x-B);
        CASE(R);
    }
  }
  if(~CNTG && ~R && ~B)ans += mndis;
  cout << ans << endl;
	return 0;
}
