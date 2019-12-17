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

const ll MOD = 1e9+7;

ll pp(ll base,ll p) {
  if(p==0) return 1;
  if(p&1) return (base * pp((base*base)%MOD,p>>1))%MOD;
  else return pp((base*base)%MOD,p>>1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
  ll n,m,k;
  cin >> n >> m >> k;
  if(n==1 && m%2==0 && k==-1) {
    cout << 0 << endl;
    return 0;
  }
  swap(m,n);
  if(n==1 && m%2==0 && k==-1) {
    cout << 0 << endl;
    return 0;
  }
  ll w = pp(2,n-1)%MOD;
  ll z = pp(w,m-1)%MOD;
  cout << z << endl;
	return 0;
}