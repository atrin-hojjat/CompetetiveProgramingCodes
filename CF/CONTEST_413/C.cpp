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
tuple<pii,pii> C[MAXN],D[MAXN];
int DD[MAXN],CC[MAXN];
struct SSS { int a,b;char ch; } XD[MAXN];

template <typename T>
T & stay(T && t) { return t; }

void push(tuple<pii,pii>&x,pii val) {
  if(val > stay(get<0>(x)))
    swap(stay(get<0>(x)),stay(val));
  if(val > stay(get<1>(x)))
    swap(stay(get<1>(x)),stay(val));
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
  int n,d,c;cin >> n >> c >> d;
  int mxc = 0,mxd = 0;
  for(int i =0;i<n;i++ ) {
    int a,b;char ch;
    cin>> a >> b >> ch;
    XD[i] = {a,b,ch};
    if(ch=='D') {
      if(b>d) continue;
      push(D[b],{a,i});
      mxd = max(mxd,a);
    } else {
      if(b>c) continue;
      push(C[b],{a,i});
      mxc = max(mxc,a);
    }
  }
  CC[0] = get<0>(C[0]).F,DD[0] = get<0>(D[0]).F;
  for(int i = 1;i<MAXN;i++) 
    CC[i] = max(CC[i-1],get<0>(C[i]).F),DD[i] = max(DD[i-1],get<0>(D[i]).F);
  int cc = 0,dd = 0;
  for(int i = 0;i<n;i++) {
    int a = XD[i].a,b = XD[i].b;
    char ch = XD[i].ch;
    if(ch=='D') {
      if(b>d) continue;
      if(d-b==b) {
        int zz = max(DD[b-1],get<0>(D[b]).S==i?get<1>(D[b]).F:get<0>(D[b]).S); 
        if(zz)dd = max(dd,zz + a);
      } else if(DD[d-b])dd = max(dd,DD[d-b]);
    } else {
      if(b>c) continue;
      if(c-b==b) {
        int zz = max(CC[b-1],get<0>(C[b]).S==i?get<1>(C[b]).F:get<0>(C[b]).S); 
        if(zz)cc = max(cc,zz + a);
      } else if(CC[c-b])cc = max(cc, CC[c-b]);
    }
  }
  cout << cc << " " << dd << " " << mxc + mxd << endl;
  cout << max({cc,dd,(mxd>0&&mxc>0?mxc+mxd:0)}) << endl;;
	return 0;
}
