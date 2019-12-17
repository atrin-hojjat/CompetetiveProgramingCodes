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
int dp1[MAXN],dp2[MAXN];

void add(int *x,int a,int val) {
  while(a<MAXN)
    x[a] = max(x[a],val),a+=a&-a;
}

int get(int*x,int a) {
  int ans = 0;
  while(a)
    ans = max(ans,x[a]),a ^= a&-a;
  return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
  int n,c,d;cin >> n >> c >> d;
  int ans = 0;
  for(int i = 0;i<n;i++) {
    int a,b;char ch;
    cin >> b >> a >> ch;
    if(ch=='C') {
      if(a>c) continue;
      int z = max(get(dp1,c-a),get(dp2,d));
      if(z)ans = max(ans,b+z);
      add(dp1,a,b);
    } else if(ch=='D') {
      if(a>d) continue;
      int z = max(get(dp1,c),get(dp2,d-a));
      if(z)ans = max(ans,b+z);
      add(dp2,a,b);
    }
  }
  cout << ans << endl;;
	return 0;
}