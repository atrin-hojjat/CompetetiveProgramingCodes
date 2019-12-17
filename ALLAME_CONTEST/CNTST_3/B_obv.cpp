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
pii arr[MAXN];

int main() {
	freopen("trapped.in", "r", stdin);
	freopen("trapped.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
  int n;cin >> n;
  FOR(i,0,n) {
    cin >> arr[i].S >> arr[i].F;
  }
  sort(arr,arr+n) ;
  ll ans = 0;
  FOR(i,0,n-1) {
    int f = i,l = i+1;
    bool change = true;
    while( f >= 0 && l<n) {
      if(arr[l].F - arr[f].F > arr[l].S) l = l+1;
      else if( arr[l].F - arr[f].F > arr[f].S) f = f-1;
      else break; 
    }
    if( f<0 || l >=n) continue;
    ans += -arr[i].F+arr[i+1].F;
  }
  cout << ans << endl;
	return 0;
}
