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

const int MAXN = 2000;
int arr[MAXN];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
  int n;cin >> n;
  FOR(i,0,n) cin >> arr[i];
  int ones = 0;
  FOR(i,0,n) if(arr[i]==1) ones++;
  if(ones) {
    cout << n-ones << endl;
    return 0;
  }
  map<int,int> gg;
  map<int,int> tot;
  gg[arr[0]] = 1;
  tot[arr[0]] = 1;
  FOR(i,1,n) {
    map<int,int> now;
    for(auto x : gg) {
      int w = __gcd(x.F,arr[i]);
      now[w] = x.S+1;
      if(tot[w]) tot[w] = min(tot[w],now[w]);
      else tot[w] = now[w];
    }
    now[arr[i]] = 1;
    if(tot[arr[i]]) tot[arr[i]] = min(tot[arr[i]],1);
    else tot[arr[i]] = 1;
    gg = now;
  }
  if(tot[1]) cout << tot[1]+n-2 << endl;
  else cout << -1 << endl;
	return 0;
}
