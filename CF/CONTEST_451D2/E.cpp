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

const int MAXN = 2e5+6.66;
multiset<int> s11,s2;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
  int n;cin >> n;
  int cnt = 0;
  FOR(i,0,n) {
    int x;cin >> x;
    int s = sqrt(x);
    if(s*s==x) {
      cnt ++;
      int mv = (x==0?2:1) ;
      s11.insert(mv);
    } else 
      s2.insert(min(x-s*s,(s+1)*(s+1)-x));
  }
  ll ans = 0;
  if(cnt>n/2) 
    for(auto x : s11) {
      if(cnt <= n/2) break;
      cnt--;
      ans += x;
    }
  else
    for(auto x : s2) {
      if(cnt >= n/2) break;
      cnt++;
      ans += x;
    }
  cout << ans << endl;
	return 0;
}
