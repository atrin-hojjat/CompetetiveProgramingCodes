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
int a[MAXN];
ll s [MAXN];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
  int n,d;cin >> n >> d;
  ll sum = 0;
  ll add = 0,TMP;
  int ans = 0;
  F0R(i,1,n) cin >> a[i];
  F0R(i,1,n) s[i] = s[i-1] + a[i];
  deque<pii> S;
  F0R(i,1,n) {
    while(S.size() && S.front().F < s[i]) S.pop_front();
    S.push_front(mp(s[i],i));
  }
  F0R(i,1,n) {
    int x = a[i];
    while(S.size() && S.back().S < i) S.pop_back();
    if(x) sum+=x;
    else {
      if(sum<0) TMP = d-(S.back().F+add),add += TMP,sum+=TMP,ans ++;
//      cout << S.back().F << " " ;
//      cout << add << endl;
      if(sum<0) {cout << -1 << endl;return 0;}
    }
    if(sum>d) {cout <<-1 << endl;return 0;}
  }
  cout << ans << endl;
	return 0;
}
