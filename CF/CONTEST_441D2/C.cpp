#include <stdio.h>
#include <stdlib.h>
#include <iostream>
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
#define PLOG(x)             cout << "[ !" << __LINE__ << "L ] " \<<x<<endl;

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
typedef pair<int,pii> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<ll> vl;

int calc(int n) {
  int ans = n;
  while(n) {
    ans += n%10;
    n/=10;
  }
  return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int n;cin >> n;
    int l = 1,r = 1e9+2;
    while(l<r) {
      int mid = l+(r-l)/2;
      int x;
      vi t;
      x = calc(mid);
      FOR(i,max(0,mid-100),min(mid+100,n+100))
        if(calc(i)==n)t.pb(i);
      if(t.size()) {
        t.clear();
        FOR(i,max(0,mid-200),min(mid+200,n+1))
          if(calc(i)==n)t.pb(i);
        cout << t.size() << endl;
        for(auto x : t) cout << x << endl;
        exit(0);
      } else if(x<n) l = mid+1;
      else r = mid; 
    }
    cout << 0 << endl;
    return 0;
}
