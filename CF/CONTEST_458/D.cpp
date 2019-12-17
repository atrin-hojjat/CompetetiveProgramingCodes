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

const int MAXN = 5e5+6.66;
const int LOGMAXN = 19;
int seg[MAXN*4];
int arr[MAXN];

int gcd(int x,int y) {
  return y?gcd(y,x%y):x;
}

void build(int x,int l,int r) {
  if(l>=r) return ;
  if(r-l==1) {
    seg[x] = arr[l];
    return ;
  }
  int mid = (l+r)>>1;
  build(x<<1,l,mid);
  build(x<<1|1,mid,r);
  seg[x] = gcd(seg[x<<1],seg[x<<1|1]);
}

void build(int n) {
  for(int i = 0;i<n;i++) seg[i+n] = arr[i];
  for(int i = n-1;i>0;i--) seg[i] = gcd(seg[i<<1] , seg[i<<1|1]);
}

int get(int n,int l,int r) {
  int res = 0;
  for(l+=n,r+=n;l<r;l>>=1,r>>=1) {
    if(l&1) res = gcd(seg[l++],res);
    if(r&1) res = gcd(seg[--r],res);
  }
  return res;
}

void alter(int n,int p,int val) {
  for(seg[p+=n] = val;p>1;p>>=1) seg[p>>1] = gcd(seg[p],seg[p^1]);
}

int get(int x,int l,int r,int b,int e) {
  if(l>=r) return 0;
  if(l>=e || r<=b) return 0;
  if(l>=b && r<=e) return seg[x];
  int mid = (l+r)>>1;
  return gcd(get(x<<1,l,mid,b,e),get(x<<1|1,mid,r,b,e));
}

void alter(int x,int l,int r,int p,int val) {
  if(l>=r) return ;
  if(p>=r || p<l) return ;
  if(r-l==1) {
    seg[x] = val;
    arr[p] = val;
    return ;
  }
  int mid = (l+r)>>1;
  alter(x<<1,l,mid,p,val);
  alter(x<<1|1,mid,r,p,val);
  seg[x] = gcd(seg[x<<1],seg[x<<1|1]);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
  int n;scanf("%d",&n);
  for(int i = 0;i<n;i++) scanf("%d",arr+i);
  build(n);
  int Q;scanf("%d",&Q);
  while(Q--) {
    int t;scanf("%d",&t);
    if(t==1) {
      int l,r,g;scanf("%d %d %d",&l,&r,&g);
      int R = l;
      int cur = 0;
      for(int i = LOGMAXN-1;i>-1;i--) {
        if(R+(1<<i) >r) continue;
        int zz = gcd(cur,get(n,R-1,R+(1<<i)-1));
        if(zz%g==0) R += (1<<i),cur = zz; 
      }
//      cout << l << " " << r << " " << R << " " << get(1,0,n,R,r) << " " ;
      if(gcd(get(n,l-1,R-1),get(n,R,r))%g==0) printf("YES\n");
      else  printf("NO\n") ;
    } else {
      int x,y;scanf("%d %d",&x,&y);
      alter(n,x-1,y);
    }
  }
	return 0;
}
