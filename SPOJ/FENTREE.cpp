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
ll arr[MAXN];

struct BIT {
  ll *bit;
  int n;

  BIT(int n) : n(n) {
    bit = new ll[n+2]();
  }

  BIT(int n,ll*arr) : n(n) {
    bit = new ll[n+2]();
    F0R(i,1,n) arr[i] += arr[i-1];
    F0R(i,1,n)
      bit[i] = arr[i] - arr[i^(i&-i)];
  }

  void add(int x,ll v) {
    while(x<=n)
      bit[x] += v,x+=x&-x;
  }

  ll get(int x) {
    ll ans = 0;
    while(x)
      ans+=bit[x],x^=x&-x;
    return ans;
  }
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
  int n;cin >> n;
  F0R(i,1,n)
    cin >> arr[i];
  BIT b = BIT(n,arr);
  int q;cin >> q;
  while(q--) {
    char ch;int x;ll v;
    cin >> ch >> x >> v;
    if(ch=='u')b.add(x,v);
    else cout << b.get(v) - b.get(x-1) << endl;
  }
	return 0;
}
