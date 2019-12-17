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

const int MAXN = 25;
const int MAX = 13;
map<pii,piii> ss;
piii ANS;
int a[MAXN],b[MAXN],c[MAXN];
int suma[1+ (1<<MAX)],sumb[1+(1<<MAX)],sumc[1+(1<<MAX)];

void print(int n,pii X) {
  int aa = X.F,bb = X.S;
  for(int i = 0;i<n;i++) {
    if((aa>>i)&1) {
      cout << "L";
      if((bb>>i)&1) cout << "M" << endl;
      else cout << "W" << endl;
    } else cout << "MW" << endl;
  }
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
  int n;cin >> n;
  for(int i = 0;i<n;i++) cin >> a[i] >> b[i] >> c[i];
  int C = min(MAX,n);
  for(int mask = 1;mask<(1<<C);mask++) {
    suma[mask] = a[__builtin_ctz(mask)] + suma[mask ^ (mask&-mask)];
    sumb[mask] = b[__builtin_ctz(mask)] + sumb[mask ^ (mask&-mask)];
    sumc[mask] = c[__builtin_ctz(mask)] + sumc[mask ^ (mask&-mask)];
  }
  for(int mask = 0;mask<(1<<C);mask++) {
    for(int m = mask;;m = (m-1)&mask) {
      int A = suma[mask];
      int B = sumb[m|(((1<<C)-1)&~mask)];
      int CC = sumc[((1<<C)-1)& ~m];
//      cout << mask << " " << m << " " << A << " " << B << " " << CC<< endl;
      if(ss.count({B-A,CC-A}))
        ss[{B-A,CC-A}] = max(ss[{B-A,CC-A}],{A,{mask,m}});
      else ss[{B-A,CC-A}] = {A,{mask,m}};
      if(!m) break;
    }
  }
  if(C==n) {
    if(ss.count({0,0}))
      print (n,ss[{0,0}].S);
    else cout << "Impossible" << endl;
    return 0;
  }
  for(int mask = 1;mask<(1<<(n-C));mask++) {
    suma[mask] = a[__builtin_ctz(mask)+C] + suma[mask ^ (mask&-mask)];
    sumb[mask] = b[__builtin_ctz(mask)+C] + sumb[mask ^ (mask&-mask)];
    sumc[mask] = c[__builtin_ctz(mask)+C] + sumc[mask ^ (mask&-mask)];
  }
  
  ANS = {-2e9-7,{0,0}};
  for(int mask = 0;mask<(1<<(n-C));mask++) {
    for(int m = mask;;m = (m-1)&mask) {
      int A = suma[mask];
      int B = sumb[(m|(((1<<(n-C))-1)&~mask))];
      int CC = sumc[(((1<<(n-C))-1)&~m)];
      if(ss.count({A-B,A-CC})) {
        piii xx = ss[{A-B,A-CC}];
        pii  x  = xx.S;
        if(ANS.F < xx.F+A)
          ANS = {xx.F+A,{x.F|(mask<<C),x.S|(m<<C)}};
      }
      if(!m) break;
    }
  }
  if(ANS.F>-2e9) print(n,ANS.S);
  else cout << "Impossible" << endl;
	return 0;
}
