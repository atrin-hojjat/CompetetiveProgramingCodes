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

map<string,set<string>> m;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
  int n;cin >> n;
  FOR(i,0,n) {
    string name; cin>> name;
    int w ;cin >> w;
    FOR(j,0,w) {
      string z ;cin >> z;
      string zz = string(z.rbegin(),z.rend());
      m[name].insert(zz);
    }
  }
  cout << m .size() << endl;
  for(auto x : m) {
    cout << x.F << " " ;
    string prv = "";
    set<string> ss;
    for(auto it = x.S.rbegin() ; it != x.S.rend(); it++) {
      int cnt = 0;
      FOR(i,0,min(it->length(),prv.length()))
        if((*it)[i] == prv[i]) cnt++;
        else break;
      if(cnt != it->length()) ss.insert( *it );
      prv = *it;
    }
    cout << ss.size() << " " ;
    for(auto s : ss) cout << string(s.rbegin(),s.rend()) << " " ;cout << endl;
  }
	return 0;
}