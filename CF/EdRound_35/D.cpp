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

const int MAXN = 1.5e3 +6.66;
int BIT[MAXN];

void add(int x,int val) {
  while(x<MAXN)
    BIT[x] += val,x+=x&-x;
}

int get(int x) {
  int ans = 0;
  while(x)
    ans += BIT[x],x^=x&-x;
  return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
  int n;cin >> n;
  ll tot = 0;
  FOR(i,0,n) {
    int w;cin >> w;
    tot += get(MAXN-1) - get(w);
    add(w,1);
  }
  bool od = tot&1;
  int Q;cin >> Q;
  while(Q--) {
    int a,b;cin >> a >> b;
    int sz = b-a+1;
    od ^= (sz %4) == 2 || (sz%4)==3;
    cout << (od?"odd":"even") << endl;
  }
	return 0;
}
