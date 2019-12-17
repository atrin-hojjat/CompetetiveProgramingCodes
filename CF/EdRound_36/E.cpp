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

const int MAXN = 6e5+6.66;
vector<piii> s;
set<int,greater<int>> ss;

int find(int x) {
  return *ss.upper_bound(x);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
  int n,q;cin >> n >> q;
  s.push_back({1,n,0});
  int cur = n;
  FOR(i,0,q) {
    int l,r,t;cin >> l >> r >> t;t--;
    auto it1 = lower_bound(s.begin(),s.end(),{find(l),0,0});
    auto it2 = upper_bound(s.begin(),s.end(),{r,0,0});
    int change = 0;
    vector<int> rm;
    vecotr<piii> add;
    for(auto it = it1;it!=it2;it++) {
      if(it.S.F>r || it.F<l) add.push_back({min(l,l});
    }
    ss.insert(l);
    cout << (cur+=change) << endl;
  }
	return 0;
}
