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
typedef pair<pii,int> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<ll> vl;

const int MAXN = 2e5+6.666;
piii arr[MAXN];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
  int n,T;cin >> n >> T;
  for(int i = 0;i<n;i++) cin >> arr[i].F.F >> arr[i].F.S,arr[i].S = i+1;
  sort(arr,arr+n);
  int l = 0,r = n;
  while(l<r) {
    int mid = l+(r-l+1)/2;
    int pos = lower_bound(arr,arr+n,mp(mp(mid,0),0)) - arr;
    multiset<int> ss;
    for(int i = pos;i<n;i++) ss.insert(arr[i].F.S);
    int w = 0;
    int sum = 0;
    for(auto x : ss) {
      if(w>=mid) break;
      sum += x;
      w++;
      if(sum > T) break;
    }
    if(mid>w||sum>T) r = mid-1;
    else l = mid;
  }
  cout << l << endl << l << endl;
  int pos = lower_bound(arr,arr+n,mp(mp(l,0),0)) - arr;
  multiset<pii> ss;
  for(int i = pos;i<n;i++) ss.insert(mp(arr[i].F.S,arr[i].S));
  int w = 0;
  for(auto x : ss) {
    if(w>=l) break;
    cout << x.S<< " ";
    w++;
  }
  cout << endl;
	return 0;
}
