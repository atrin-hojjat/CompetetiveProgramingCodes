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
int BIT [MAXN];
int arr [MAXN];
int dp  [MAXN];
bool is [MAXN];

void add(int x,int val) {
  while(x< MAXN)
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
  set<pii> s;
  F0R(i,1,n)
    cin >> arr[i];
  F0R(i,1,n) {
    int w = get(n-arr[i]+1);
    if(!w) is[i] = 1;
    if(w==1) {
      dp[s.begin()->S]++;
    }
    s.insert(mp(-arr[i],i));
    add(n-arr[i]+1,1);
  }
  pii mx = mp(-1,-1000000);
  F0R(i,1,n) {
//    cout << dp[i] << " " << i << " " << arr[i] << endl;
    mx = max(mx,mp(dp[i]-is[i],-arr[i]));
  }
//  cout << mx.F << endl;
  if(mx.F >= 0)cout << -mx.S << endl;
  else {
    F0R(i,1,n) {
      if(!is[i]) {
        cout << i << endl;
        return 0;
      }
    }
    cout << 1 << endl;
  }
	return 0;
}
