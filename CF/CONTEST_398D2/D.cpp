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

const int MAXN = 1e6+6.66;
const int MAXV = 1e7+7.77;
int arr[MAXN];
pii arr2[MAXN];
int c1[MAXV];
int c2[MAXV];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
  int n,m,k;cin >> n >> m >> k;
  FOR(i,0,n) cin >> arr[i];
  FOR(i,0,n) c1[arr[i]] ++;
  int sum = 0;
  FOR(i,0,MAXV)
    if(1LL * (sum+=c1[i]) > 1LL*(i+1)*k) {cout << -1 << endl; return 0;}
  FOR(i,0,m) cin >> arr2[i].F,arr2[i].S = i+1;
  FOR(i,0,m) c2[arr2[i].F] ++;
  sort(arr2,arr2+m,greater<pii>());
  int l = 0,r = m;
  while(l<r) {
    int mid = l+(r-l+1)/2;
    int z = mid;
    int ls = MAXV-1;
    for(int i = MAXV-1;z>0 && i>-1;z-=c2[i],i--) c1[i] += min(c2[i],z),ls = i;
    sum = 0;
    bool ok = true;
    FOR(i,0,MAXV)
      if(1LL * (sum+=c1[i]) > 1LL*(i+1)*k) {ok = false;break;}
    for(int i =ls;z <mid && i<MAXV;z+=c2[i],i++) {
      c1[i] -= c2[i] + (z<0?z:0);}
    if(!ok) r = mid-1;
    else l = mid;
  }
  cout << l << endl;
  FOR(i,0,l) cout << arr2[i].S << " ";
  cout << endl;
	return 0;
}
