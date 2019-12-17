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

map<char,bool> m;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
  int n;cin >> n;
  bool gu = false;
  int ans = 0;
  FOR(i,0,26) {
    m[i+'a'] = true;
  }
  while(n--) {
    if(n==0) break;
    char ch; cin >> ch;
    bool sh = false;
    int po = 0;
    for(auto x : m)
      po += x.S;
    if(po<=1) gu = 1;
    if(ch=='?') {
      cin >> ch ;
      if(n!=0) 
      {
        sh = true;
        if(m.count(ch))
          m.erase(ch);
      }
    } else {
      string str;cin >> str;
      if(ch=='!') sh = true;
      if(ch=='!') {
        map<char,bool> ww;
        for(auto x : str) ww[x] = true;
        FOR(i,0,26)
          if(!ww[i+'a'] && m.count(i+'a'))
            m.erase(i+'a');
      } else {
        map<char,bool> ww;
        for(auto x : str) ww[x] = true;
        for(auto u : ww)
          if(m.count(u.F))
            m.erase(u.F);
      }
    }
//    cout << m.size() << endl;
//    for(auto x : m) cout << x.F << " " ;cout << endl;
    if(gu && sh) ans++;
  }
  cout << ans << endl;
	return 0;
}
