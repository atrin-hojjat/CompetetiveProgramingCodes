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

const int MAXN = 3e5+6.66;
int seg[2*MAXN];
int arr[MAXN];
int rev[MAXN];
int n;

void alter(int x,int val) {
  for(seg[x+=n] = val;x>1;x>>=1) seg[x>>1] = seg[x] + seg[x^1];
}

int get(int l,int r) {
  int ans = 0;
  for(l+=n,r+=n;l<r;l>>=1,r>>=1) {
    if(l&1) ans += seg[l++];
    if(r&1) ans += seg[--r];
  }
  return ans;
}

void init(int n) {
  alter(1,1);
  for(int i = 1;i<n;i++) if(rev[i]>rev[i+1]) alter(i+1,1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
  cin >> n;
  for(int i = 1;i<=n;i++) cin >> arr[i];
  for(int i = 1;i<=n;i++) rev[arr[i]] = i;
  init(n);
  int Q;cin >>Q;
  while(Q--) {
    int t,x,y;cin >> t >> x >> y;
    if(t==1) {
      cout << get(x+1,y+1) + 1 << endl;
    } else {
      if(arr[x]>arr[y]) swap(x,y);
      rev[arr[x]] = y;
      rev[arr[y]] = x;
      alter(arr[x],rev[arr[x]]<rev[arr[x]-1]);
      alter(arr[y],rev[arr[y]]<rev[arr[y]-1]);
      alter(arr[x]+1,rev[arr[x]+1]<rev[arr[x]]);
      alter(arr[y]+1,rev[arr[y]+1]<rev[arr[y]]);
      swap(arr[x],arr[y]);
    }
  }
	return 0;
}
