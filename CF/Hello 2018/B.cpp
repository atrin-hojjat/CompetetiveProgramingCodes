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

typedef unsigned long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
typedef pair<int,pii> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<ll> vl;

const ll INF = ULLONG_MAX;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
  int n,x;cin >> n >> x;
  ll mn = INF;
  ll prv = INF;
  ll sum = 0;
  int lg = 0;
  for(int i = 0;i<30;i++) if((x>>i)&1) lg = i;
  lg++;
  for(int i = 0;i<=max(n,lg);i++) {
    ll WW;
    if(i<n)cin >> WW;
    else WW = INF;
    WW = min(2*prv,WW);
    if((1LL<<i) > x) mn = min(mn,WW);
    else if((x>>i)&1) sum += WW;
    else sum = min(sum,WW);
    prv = WW;
  }
  cout << min(mn,sum) << endl;;
	return 0;
}
